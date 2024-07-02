import eons
import ebbs
import logging
import clang.cindex
import os
import re

class SignatureCollector(ebbs.Builder):
    def __init__(this, name="Signature Collector"):
        super().__init__(name)

        this.arg.kw.required.append("dir")
        this.arg.kw.required.append("out")
        this.arg.kw.required.append("lib")
        this.arg.kw.required.append("module")

        this.arg.kw.optional["supported_filetypes"] = [".h", ".hpp"]
        this.arg.kw.optional["parsing_flags"] = ["-x", "c++", "--std=c++11"]
        this.arg.kw.optional["clang_lib"] = "/usr/lib/llvm-18/lib/libclang.so.1"

        # These are types supported by Pybind11.
        this.arg.kw.optional["allowed_template_types"] = {
            "Object": "::py::object",
            "Int": "::py::int_", 
            "Float": "::py::float_",
            "Bool": "::py::bool_",
            "Str": "::py::str",
            "Bytes": "::py::bytes",
            "Tuple": "::py::tuple",
            "List": "::py::list",
            "Dict": "::py::dict",
            "Iterable": "::py::iterable",
            "Function": "::py::function",
            "Array": "::py::array",
        }

        this.collected = eons.util.DotDict()
        this.collected.classes = eons.util.DotDict()

        this.tmp = eons.util.DotDict()
        this.tmp.ns = []
    
    def Build(this):
        clang.cindex.Config.set_library_file(this.clang_lib)

        logging.info(f"Searching {this.dir} for supported files")

        for root, _, files in os.walk(this.dir):
            for file in files:
                if (f".{file.split('.')[-1]}" not in this.supported_filetypes):
                    logging.debug(f"Skipping {file}")
                    continue
                logging.info(f"Parsing {file}")
                file_path = os.path.join(root, file)
                this.index = clang.cindex.Index.create()
                this.tu = this.index.parse(file_path, args=this.parsing_flags)
                this.Collect(this.tu.cursor)
        this.Prune()
        this.Prepare()
        this.GeneratePybind11Classes()
        this.GeneratePybind11Main()

    def Collect(this, cursor):
        logging.debug(f"Collecting {cursor.spelling} of kind {cursor.kind}")

        if cursor.kind == clang.cindex.CursorKind.TRANSLATION_UNIT:
            for child in cursor.get_children():
                this.Collect(child)
        
        if (cursor.kind == clang.cindex.CursorKind.NAMESPACE):
            logging.debug(f"Entering namespace {cursor.spelling}")
            this.tmp.ns.append(cursor.spelling)
            for child in cursor.get_children():
                this.Collect(child)
            this.tmp.ns.pop()
            logging.debug(f"Exiting namespace {cursor.spelling}")

        if (cursor.kind == clang.cindex.CursorKind.CLASS_DECL):

            # Skip all template classes, since we can't handle them in Python yet.
            if (cursor.get_num_template_arguments() > 0):
                return

            logging.info(f"Collecting class ::{'::'.join(this.tmp.ns)}::{cursor.spelling}")

            this.collected.classes[cursor.spelling] = eons.util.DotDict()
            this.collected.classes[cursor.spelling].ns = "::".join(this.tmp.ns)
            this.collected.classes[cursor.spelling].methods = eons.util.DotDict()
            for child in cursor.get_children():
                if (child.kind in [
                    clang.cindex.CursorKind.CXX_METHOD,
                    clang.cindex.CursorKind.CONSTRUCTOR,
                    # clang.cindex.CursorKind.DESTRUCTOR,
                    clang.cindex.CursorKind.FUNCTION_DECL,
                    clang.cindex.CursorKind.FUNCTION_TEMPLATE,
                ]):

                    logging.debug(f"Collecting ::{'::'.join(this.tmp.ns)}::{cursor.spelling}::{child.spelling} ({child.kind})")

                    this.collected.classes[cursor.spelling].methods[child.spelling] = eons.util.DotDict()
                    this.collected.classes[cursor.spelling].methods[child.spelling].signature = child.type.spelling
                    this.collected.classes[cursor.spelling].methods[child.spelling].returnType = child.result_type.spelling
                    this.collected.classes[cursor.spelling].methods[child.spelling].isVirtual = child.is_virtual_method()
                    this.collected.classes[cursor.spelling].methods[child.spelling].isTemplate = child.kind == clang.cindex.CursorKind.FUNCTION_TEMPLATE
                    this.collected.classes[cursor.spelling].methods[child.spelling].templateArgs = []
                    this.collected.classes[cursor.spelling].methods[child.spelling].args = {}

                    for arg in child.get_arguments():
                        logging.debug(f"Collecting ::{'::'.join(this.tmp.ns)}::{cursor.spelling}::{child.spelling}::{arg.spelling} ({arg.type.spelling})")
                        this.collected.classes[cursor.spelling].methods[child.spelling].args[arg.spelling] = arg.type.spelling

                    if (this.collected.classes[cursor.spelling].methods[child.spelling].isTemplate):
                        for grandchild in child.get_children():
                            if (grandchild.kind == clang.cindex.CursorKind.TEMPLATE_TYPE_PARAMETER):
                                this.collected.classes[cursor.spelling].methods[child.spelling].templateArgs.append(grandchild.spelling)

                        # Parse the display name to capture any template arguments that are apparently ignored by get_arguments, above.
                        # NOTE: I consider template args not showing up in args to be a bug of clang. But there's nothing we can do about that now.
                        sig = child.displayname
                        sig = sig[sig.find("(")+1:sig.find(")")]
                        args = sig.split(", ")
                        for i, arg in enumerate(args):
                            templateName = None
                            for templateArg in this.collected.classes[cursor.spelling].methods[child.spelling].templateArgs:
                                if (re.search(rf"\b{templateArg}\b", arg)):
                                    logging.debug(f"Found previously missed template arg {templateArg} in {arg}")
                                    templateName = templateArg
                                    break
                            if (templateName):
                                # Really python?? C'mon.
                                try:
                                    keys = list(this.collected.classes[cursor.spelling].methods[child.spelling].args.keys())
                                    values = list(this.collected.classes[cursor.spelling].methods[child.spelling].args.values())
                                    keys.insert(i, templateName)
                                    values.insert(i, "TEMPLATE")
                                    this.collected.classes[cursor.spelling].methods[child.spelling].args = dict(zip(keys, values))
                                except Exception as e:
                                    logging.error(f"Failed to insert template arg {templateName} into args: {e}")
                                    logging.error(f"keys: {keys}")
                                    logging.error(f"values: {values}")
                                    logging.error(f"i: {i}")
                                    logging.error(f"templateName: {templateName}")
                                    logging.error(f"args: {this.collected.classes[cursor.spelling].methods[child.spelling].args}")

                else:
                    logging.debug(f"Skipping ::{'::'.join(this.tmp.ns)}::{cursor.spelling}::{child.spelling} ({child.kind})")
        else:
            logging.debug(f"Skipping ::{'::'.join(this.tmp.ns)}::{cursor.spelling} ({cursor.kind})")

        # Let's hold off on recursion for now
        # for child in cursor.get_children():
        #     this.Collect(child)

    # Remove any methods with duplicate names, as they are not allowed in Python
    # Currently just keeps the first method found.
    def Prune(this):
        classesToPrune = []
        for className, classData in this.collected.classes.items():
            
            hasValidConstructor = False
            for methodName, methodData in classData.methods.items():
                if (methodName == className and not methodData.isTemplate):
                    hasValidConstructor = True
                    break
            if (not hasValidConstructor):
                logging.debug(f"Pruning ::{classData.ns}::{className}: no valid constructor")
                classesToPrune.append(className)
                continue

            methodNames = []
            for methodName, methodData in classData.methods.items():
                if (methodName in methodNames):
                    logging.debug(f"Pruning ::{classData.ns}::{className}::{methodName}: duplicate method name")
                    del this.collected.classes[className].methods[methodName]
                else:
                    methodNames.append(methodName)
        
        for className in classesToPrune:
            del this.collected.classes[className]


    # Do anything needed before generating Pybind11 code
    def Prepare(this):
        for className, classData in this.collected.classes.items():
            this.allowed_template_types[className] = f"::{classData.ns}::{className}"


    # Create Pybind11 code for each class & method we've collected
    def GeneratePybind11Classes(this):
        outputFile = open(this.out, "w+")
        outputFile.write(f"""
#include <{this.lib}.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace {this.module} {{
""")
        for className, classData in this.collected.classes.items():
            logging.info(f"Generating Pybind11 code for class ::{classData.ns}::{className}")
            outputFile.write(f"class {className} : public ::{classData.ns}::{className} {{\n")
            for methodName, methodData in classData.methods.items():

                # logging.debug(f"Method ::{classData.ns}::{className}::{methodName}")

                argstr = eons.util.DotDict()
                argstr.declaration = ""
                argstr.call = ""
                for arg_name, arg_type in methodData.args.items():
                    argstr.declaration += f"{arg_type} {arg_name}, "
                    argstr.call += f"{arg_name}, "
                argstr.declaration = argstr.declaration[:-2]
                argstr.call = argstr.call[:-2]

                # We'll only support 1 template arg for the time being.
                # If there is more than one arg, it likely implies an organizational differentiation that we do not support.
                if (methodData.isTemplate):
                    logging.debug(f"Generating Pybind11 code for templated method ::{classData.ns}::{className}::{methodName}")

                    for templateName, templateType in this.allowed_template_types.items():
                        if (templateName == className):
                            continue

                        templated = eons.util.DotDict()
                        templated.returnType = "auto"
                        templated.name = f"{methodName}{templateName}"
                        templated.method = f"{methodName}<{templateType}>"
                        templated.argstr = eons.util.DotDict()
                        templated.argstr.declaration = argstr.declaration.replace("TEMPLATE", templateType)
                        templated.argstr.call = argstr.call

                        outputFile.write(f"    {templated.returnType} {templated.name}({templated.argstr.declaration}) {{\n")
                        if (methodData.isVirtual):
                            outputFile.write(f"        PYBIND11_OVERRIDE({templated.returnType}, {className}, {templated.method})")
                        else:
                            if (methodData.returnType == "void"):
                                outputFile.write(f"        ::{classData.ns}::{className}::{templated.method}({argstr.call});")
                            else:
                                outputFile.write(f"        return ::{classData.ns}::{className}::{templated.method}({argstr.call});")
                        outputFile.write("\n    }\n")

                else:
                    logging.debug(f"Generating Pybind11 code for method ::{classData.ns}::{className}::{methodName}")
                    outputFile.write(f"    {methodData.returnType} {methodName}({argstr.declaration}) {{\n")
                    if (methodData.isVirtual):
                        outputFile.write(f"        PYBIND11_OVERRIDE({methodData.returnType}, {className}, {methodName})")
                    else:
                        if (methodData.returnType == "void"):
                            outputFile.write(f"        ::{classData.ns}::{className}::{methodName}({argstr.call});")
                        else:
                            outputFile.write(f"        return ::{classData.ns}::{className}::{methodName}({argstr.call});")
                    outputFile.write("\n    }\n")

            outputFile.write("\n};\n")

        outputFile.write(f"}} // {this.module} namespace\n")
        outputFile.close()

    def GeneratePybind11Main(this):
        logging.info(f"Generating Pybind11 main code")
        outputFile = open(this.out, "a")
        outputFile.write(f"PYBIND11_MODULE({this.module}, m) {{\n")
        for className, classData in this.collected.classes.items():
            outputFile.write(f"    py::class_< ::{this.module}::{className} >(m, \"{className}\")")
            outputFile.write("\n    .def(py::init<>())")
            for methodName, methodData in classData.methods.items():
                outputFile.write(f"\n    .def(\"{methodName}\", &{className}::{methodName})")
            outputFile.write(";\n\n")

        outputFile.write("}")

        outputFile.close()