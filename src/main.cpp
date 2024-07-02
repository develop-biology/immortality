
#include <bio.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace immortality {
class ImmutableString : public ::bio::ImmutableString {
    void ImmutableString(const ImmutableString && toMove) {
        ::bio::ImmutableString::ImmutableString(const ImmutableString && toMove);
    }
    ImmutableString & operator=(const ImmutableString & toCopy) {
        return ::bio::ImmutableString::operator=(const ImmutableString & toCopy);
    }
    int Length() {
        return ::bio::ImmutableString::Length();
    }
    int Find(const ImmutableString & substring) {
        return ::bio::ImmutableString::Find(const ImmutableString & substring);
    }
    ImmutableString GetImmutableSubString(int start, int length) {
        return ::bio::ImmutableString::GetImmutableSubString(int start, int length);
    }

};
class String : public ::bio::String {
    const char * GetCloneOf(const char * source, int length) {
        return ::bio::String::GetCloneOf(const char * source, int length);
    }
    String SetMode(const String & string, Mode desiredMode) {
        return ::bio::String::SetMode(const String & string, Mode desiredMode);
    }
    void String(const String && toMove) {
        ::bio::String::String(const String && toMove);
    }
    auto FromObject(::py::object T) {
        return ::bio::String::From<::py::object>(::py::object T);
    }
    auto FromInt(::py::int_ T) {
        return ::bio::String::From<::py::int_>(::py::int_ T);
    }
    auto FromFloat(::py::float_ T) {
        return ::bio::String::From<::py::float_>(::py::float_ T);
    }
    auto FromBool(::py::bool_ T) {
        return ::bio::String::From<::py::bool_>(::py::bool_ T);
    }
    auto FromStr(::py::str T) {
        return ::bio::String::From<::py::str>(::py::str T);
    }
    auto FromBytes(::py::bytes T) {
        return ::bio::String::From<::py::bytes>(::py::bytes T);
    }
    auto FromTuple(::py::tuple T) {
        return ::bio::String::From<::py::tuple>(::py::tuple T);
    }
    auto FromList(::py::list T) {
        return ::bio::String::From<::py::list>(::py::list T);
    }
    auto FromDict(::py::dict T) {
        return ::bio::String::From<::py::dict>(::py::dict T);
    }
    auto FromIterable(::py::iterable T) {
        return ::bio::String::From<::py::iterable>(::py::iterable T);
    }
    auto FromFunction(::py::function T) {
        return ::bio::String::From<::py::function>(::py::function T);
    }
    auto FromArray(::py::array T) {
        return ::bio::String::From<::py::array>(::py::array T);
    }
    auto FromImmutableString(::bio::ImmutableString T) {
        return ::bio::String::From<::bio::ImmutableString>(::bio::ImmutableString T);
    }
    auto FromByteStream(::bio::ByteStream T) {
        return ::bio::String::From<::bio::ByteStream>(::bio::ByteStream T);
    }
    auto FromThreadSafe(::bio::ThreadSafe T) {
        return ::bio::String::From<::bio::ThreadSafe>(::bio::ThreadSafe T);
    }
    auto FromSmartIterator(::bio::SmartIterator T) {
        return ::bio::String::From<::bio::SmartIterator>(::bio::SmartIterator T);
    }
    String & operator=(int string) {
        PYBIND11_OVERRIDE(String &, String, operator=)
    }
    bool operator==(const int & other) {
        PYBIND11_OVERRIDE(bool, String, operator==)
    }
    Mode GetMode() {
        PYBIND11_OVERRIDE(Mode, String, GetMode)
    }
    String SubString(int start, int length) {
        PYBIND11_OVERRIDE(String, String, SubString)
    }
    int AsStdString() {
        return ::bio::String::AsStdString();
    }
    const char * AsCharString() {
        PYBIND11_OVERRIDE(const char *, String, AsCharString)
    }
    bool AsBool() {
        PYBIND11_OVERRIDE(bool, String, AsBool)
    }
    int AsInt() {
        return ::bio::String::AsInt();
    }
    int AsUInt() {
        return ::bio::String::AsUInt();
    }
    float AsFloat() {
        PYBIND11_OVERRIDE(float, String, AsFloat)
    }
    void Clear() {
        PYBIND11_OVERRIDE(void, String, Clear)
    }

};
class ByteStream : public ::bio::ByteStream {
    void ByteStream(const ByteStream & other) {
        ::bio::ByteStream::ByteStream(const ByteStream & other);
    }
    void operator=(const ByteStream & other) {
        ::bio::ByteStream::operator=(const ByteStream & other);
    }
    bool operator==(const ByteStream & other) {
        return ::bio::ByteStream::operator==(const ByteStream & other);
    }
    auto AsObject() {
        return ::bio::ByteStream::As<::py::object>();
    }
    auto AsInt() {
        return ::bio::ByteStream::As<::py::int_>();
    }
    auto AsFloat() {
        return ::bio::ByteStream::As<::py::float_>();
    }
    auto AsBool() {
        return ::bio::ByteStream::As<::py::bool_>();
    }
    auto AsStr() {
        return ::bio::ByteStream::As<::py::str>();
    }
    auto AsBytes() {
        return ::bio::ByteStream::As<::py::bytes>();
    }
    auto AsTuple() {
        return ::bio::ByteStream::As<::py::tuple>();
    }
    auto AsList() {
        return ::bio::ByteStream::As<::py::list>();
    }
    auto AsDict() {
        return ::bio::ByteStream::As<::py::dict>();
    }
    auto AsIterable() {
        return ::bio::ByteStream::As<::py::iterable>();
    }
    auto AsFunction() {
        return ::bio::ByteStream::As<::py::function>();
    }
    auto AsArray() {
        return ::bio::ByteStream::As<::py::array>();
    }
    auto AsImmutableString() {
        return ::bio::ByteStream::As<::bio::ImmutableString>();
    }
    auto AsString() {
        return ::bio::ByteStream::As<::bio::String>();
    }
    auto AsThreadSafe() {
        return ::bio::ByteStream::As<::bio::ThreadSafe>();
    }
    auto AsSmartIterator() {
        return ::bio::ByteStream::As<::bio::SmartIterator>();
    }
    auto operator type-parameter-0-0Object() {
        return ::bio::ByteStream::operator type-parameter-0-0<::py::object>();
    }
    auto operator type-parameter-0-0Int() {
        return ::bio::ByteStream::operator type-parameter-0-0<::py::int_>();
    }
    auto operator type-parameter-0-0Float() {
        return ::bio::ByteStream::operator type-parameter-0-0<::py::float_>();
    }
    auto operator type-parameter-0-0Bool() {
        return ::bio::ByteStream::operator type-parameter-0-0<::py::bool_>();
    }
    auto operator type-parameter-0-0Str() {
        return ::bio::ByteStream::operator type-parameter-0-0<::py::str>();
    }
    auto operator type-parameter-0-0Bytes() {
        return ::bio::ByteStream::operator type-parameter-0-0<::py::bytes>();
    }
    auto operator type-parameter-0-0Tuple() {
        return ::bio::ByteStream::operator type-parameter-0-0<::py::tuple>();
    }
    auto operator type-parameter-0-0List() {
        return ::bio::ByteStream::operator type-parameter-0-0<::py::list>();
    }
    auto operator type-parameter-0-0Dict() {
        return ::bio::ByteStream::operator type-parameter-0-0<::py::dict>();
    }
    auto operator type-parameter-0-0Iterable() {
        return ::bio::ByteStream::operator type-parameter-0-0<::py::iterable>();
    }
    auto operator type-parameter-0-0Function() {
        return ::bio::ByteStream::operator type-parameter-0-0<::py::function>();
    }
    auto operator type-parameter-0-0Array() {
        return ::bio::ByteStream::operator type-parameter-0-0<::py::array>();
    }
    auto operator type-parameter-0-0ImmutableString() {
        return ::bio::ByteStream::operator type-parameter-0-0<::bio::ImmutableString>();
    }
    auto operator type-parameter-0-0String() {
        return ::bio::ByteStream::operator type-parameter-0-0<::bio::String>();
    }
    auto operator type-parameter-0-0ThreadSafe() {
        return ::bio::ByteStream::operator type-parameter-0-0<::bio::ThreadSafe>();
    }
    auto operator type-parameter-0-0SmartIterator() {
        return ::bio::ByteStream::operator type-parameter-0-0<::bio::SmartIterator>();
    }
    auto operator const type-parameter-0-0Object() {
        return ::bio::ByteStream::operator const type-parameter-0-0<::py::object>();
    }
    auto operator const type-parameter-0-0Int() {
        return ::bio::ByteStream::operator const type-parameter-0-0<::py::int_>();
    }
    auto operator const type-parameter-0-0Float() {
        return ::bio::ByteStream::operator const type-parameter-0-0<::py::float_>();
    }
    auto operator const type-parameter-0-0Bool() {
        return ::bio::ByteStream::operator const type-parameter-0-0<::py::bool_>();
    }
    auto operator const type-parameter-0-0Str() {
        return ::bio::ByteStream::operator const type-parameter-0-0<::py::str>();
    }
    auto operator const type-parameter-0-0Bytes() {
        return ::bio::ByteStream::operator const type-parameter-0-0<::py::bytes>();
    }
    auto operator const type-parameter-0-0Tuple() {
        return ::bio::ByteStream::operator const type-parameter-0-0<::py::tuple>();
    }
    auto operator const type-parameter-0-0List() {
        return ::bio::ByteStream::operator const type-parameter-0-0<::py::list>();
    }
    auto operator const type-parameter-0-0Dict() {
        return ::bio::ByteStream::operator const type-parameter-0-0<::py::dict>();
    }
    auto operator const type-parameter-0-0Iterable() {
        return ::bio::ByteStream::operator const type-parameter-0-0<::py::iterable>();
    }
    auto operator const type-parameter-0-0Function() {
        return ::bio::ByteStream::operator const type-parameter-0-0<::py::function>();
    }
    auto operator const type-parameter-0-0Array() {
        return ::bio::ByteStream::operator const type-parameter-0-0<::py::array>();
    }
    auto operator const type-parameter-0-0ImmutableString() {
        return ::bio::ByteStream::operator const type-parameter-0-0<::bio::ImmutableString>();
    }
    auto operator const type-parameter-0-0String() {
        return ::bio::ByteStream::operator const type-parameter-0-0<::bio::String>();
    }
    auto operator const type-parameter-0-0ThreadSafe() {
        return ::bio::ByteStream::operator const type-parameter-0-0<::bio::ThreadSafe>();
    }
    auto operator const type-parameter-0-0SmartIterator() {
        return ::bio::ByteStream::operator const type-parameter-0-0<::bio::SmartIterator>();
    }
    void Set(const ByteStream & other) {
        ::bio::ByteStream::Set(const ByteStream & other);
    }
    void Release() {
        ::bio::ByteStream::Release();
    }
    bool IsEmpty() {
        return ::bio::ByteStream::IsEmpty();
    }
    auto IsObject(::py::object T) {
        return ::bio::ByteStream::Is<::py::object>(::py::object T);
    }
    auto IsInt(::py::int_ T) {
        return ::bio::ByteStream::Is<::py::int_>(::py::int_ T);
    }
    auto IsFloat(::py::float_ T) {
        return ::bio::ByteStream::Is<::py::float_>(::py::float_ T);
    }
    auto IsBool(::py::bool_ T) {
        return ::bio::ByteStream::Is<::py::bool_>(::py::bool_ T);
    }
    auto IsStr(::py::str T) {
        return ::bio::ByteStream::Is<::py::str>(::py::str T);
    }
    auto IsBytes(::py::bytes T) {
        return ::bio::ByteStream::Is<::py::bytes>(::py::bytes T);
    }
    auto IsTuple(::py::tuple T) {
        return ::bio::ByteStream::Is<::py::tuple>(::py::tuple T);
    }
    auto IsList(::py::list T) {
        return ::bio::ByteStream::Is<::py::list>(::py::list T);
    }
    auto IsDict(::py::dict T) {
        return ::bio::ByteStream::Is<::py::dict>(::py::dict T);
    }
    auto IsIterable(::py::iterable T) {
        return ::bio::ByteStream::Is<::py::iterable>(::py::iterable T);
    }
    auto IsFunction(::py::function T) {
        return ::bio::ByteStream::Is<::py::function>(::py::function T);
    }
    auto IsArray(::py::array T) {
        return ::bio::ByteStream::Is<::py::array>(::py::array T);
    }
    auto IsImmutableString(::bio::ImmutableString T) {
        return ::bio::ByteStream::Is<::bio::ImmutableString>(::bio::ImmutableString T);
    }
    auto IsString(::bio::String T) {
        return ::bio::ByteStream::Is<::bio::String>(::bio::String T);
    }
    auto IsThreadSafe(::bio::ThreadSafe T) {
        return ::bio::ByteStream::Is<::bio::ThreadSafe>(::bio::ThreadSafe T);
    }
    auto IsSmartIterator(::bio::SmartIterator T) {
        return ::bio::ByteStream::Is<::bio::SmartIterator>(::bio::SmartIterator T);
    }
    String GetTypeName() {
        return ::bio::ByteStream::GetTypeName();
    }
    int GetSize() {
        return ::bio::ByteStream::GetSize();
    }
    void TakeHold() {
        ::bio::ByteStream::TakeHold();
    }
    void * DirectAccess() {
        return ::bio::ByteStream::DirectAccess();
    }

};
class ThreadSafe : public ::bio::ThreadSafe {
    void ThreadSafe(const ThreadSafe & toCopy) {
        ::bio::ThreadSafe::ThreadSafe(const ThreadSafe & toCopy);
    }
    ThreadSafe & operator=(const ThreadSafe & toCopy) {
        return ::bio::ThreadSafe::operator=(const ThreadSafe & toCopy);
    }
    void LockThread() {
        ::bio::ThreadSafe::LockThread();
    }
    void UnlockThread() {
        ::bio::ThreadSafe::UnlockThread();
    }
    void CommonConstructor() {
        ::bio::ThreadSafe::CommonConstructor();
    }

};
class SmartIterator : public ::bio::SmartIterator {
    void SmartIterator(const Container * container, Index index) {
        ::bio::SmartIterator::SmartIterator(const Container * container, Index index);
    }
    bool IsValid() {
        return ::bio::SmartIterator::IsValid();
    }
    void Invalidate() {
        ::bio::SmartIterator::Invalidate();
    }
    const Iterator * GetImplementation() {
        return ::bio::SmartIterator::GetImplementation();
    }
    Index GetIndex() {
        return ::bio::SmartIterator::GetIndex();
    }
    bool MoveTo(Index index) {
        return ::bio::SmartIterator::MoveTo(Index index);
    }
    bool IsBeforeBeginning() {
        return ::bio::SmartIterator::IsBeforeBeginning();
    }
    bool IsAfterEnd() {
        return ::bio::SmartIterator::IsAfterEnd();
    }
    const ByteStream operator*() {
        PYBIND11_OVERRIDE(const ByteStream, SmartIterator, operator*)
    }
    auto AsObject() {
        return ::bio::SmartIterator::As<::py::object>();
    }
    auto AsInt() {
        return ::bio::SmartIterator::As<::py::int_>();
    }
    auto AsFloat() {
        return ::bio::SmartIterator::As<::py::float_>();
    }
    auto AsBool() {
        return ::bio::SmartIterator::As<::py::bool_>();
    }
    auto AsStr() {
        return ::bio::SmartIterator::As<::py::str>();
    }
    auto AsBytes() {
        return ::bio::SmartIterator::As<::py::bytes>();
    }
    auto AsTuple() {
        return ::bio::SmartIterator::As<::py::tuple>();
    }
    auto AsList() {
        return ::bio::SmartIterator::As<::py::list>();
    }
    auto AsDict() {
        return ::bio::SmartIterator::As<::py::dict>();
    }
    auto AsIterable() {
        return ::bio::SmartIterator::As<::py::iterable>();
    }
    auto AsFunction() {
        return ::bio::SmartIterator::As<::py::function>();
    }
    auto AsArray() {
        return ::bio::SmartIterator::As<::py::array>();
    }
    auto AsImmutableString() {
        return ::bio::SmartIterator::As<::bio::ImmutableString>();
    }
    auto AsString() {
        return ::bio::SmartIterator::As<::bio::String>();
    }
    auto AsByteStream() {
        return ::bio::SmartIterator::As<::bio::ByteStream>();
    }
    auto AsThreadSafe() {
        return ::bio::SmartIterator::As<::bio::ThreadSafe>();
    }
    auto operator type-parameter-0-0Object() {
        return ::bio::SmartIterator::operator type-parameter-0-0<::py::object>();
    }
    auto operator type-parameter-0-0Int() {
        return ::bio::SmartIterator::operator type-parameter-0-0<::py::int_>();
    }
    auto operator type-parameter-0-0Float() {
        return ::bio::SmartIterator::operator type-parameter-0-0<::py::float_>();
    }
    auto operator type-parameter-0-0Bool() {
        return ::bio::SmartIterator::operator type-parameter-0-0<::py::bool_>();
    }
    auto operator type-parameter-0-0Str() {
        return ::bio::SmartIterator::operator type-parameter-0-0<::py::str>();
    }
    auto operator type-parameter-0-0Bytes() {
        return ::bio::SmartIterator::operator type-parameter-0-0<::py::bytes>();
    }
    auto operator type-parameter-0-0Tuple() {
        return ::bio::SmartIterator::operator type-parameter-0-0<::py::tuple>();
    }
    auto operator type-parameter-0-0List() {
        return ::bio::SmartIterator::operator type-parameter-0-0<::py::list>();
    }
    auto operator type-parameter-0-0Dict() {
        return ::bio::SmartIterator::operator type-parameter-0-0<::py::dict>();
    }
    auto operator type-parameter-0-0Iterable() {
        return ::bio::SmartIterator::operator type-parameter-0-0<::py::iterable>();
    }
    auto operator type-parameter-0-0Function() {
        return ::bio::SmartIterator::operator type-parameter-0-0<::py::function>();
    }
    auto operator type-parameter-0-0Array() {
        return ::bio::SmartIterator::operator type-parameter-0-0<::py::array>();
    }
    auto operator type-parameter-0-0ImmutableString() {
        return ::bio::SmartIterator::operator type-parameter-0-0<::bio::ImmutableString>();
    }
    auto operator type-parameter-0-0String() {
        return ::bio::SmartIterator::operator type-parameter-0-0<::bio::String>();
    }
    auto operator type-parameter-0-0ByteStream() {
        return ::bio::SmartIterator::operator type-parameter-0-0<::bio::ByteStream>();
    }
    auto operator type-parameter-0-0ThreadSafe() {
        return ::bio::SmartIterator::operator type-parameter-0-0<::bio::ThreadSafe>();
    }
    auto operator const type-parameter-0-0Object() {
        return ::bio::SmartIterator::operator const type-parameter-0-0<::py::object>();
    }
    auto operator const type-parameter-0-0Int() {
        return ::bio::SmartIterator::operator const type-parameter-0-0<::py::int_>();
    }
    auto operator const type-parameter-0-0Float() {
        return ::bio::SmartIterator::operator const type-parameter-0-0<::py::float_>();
    }
    auto operator const type-parameter-0-0Bool() {
        return ::bio::SmartIterator::operator const type-parameter-0-0<::py::bool_>();
    }
    auto operator const type-parameter-0-0Str() {
        return ::bio::SmartIterator::operator const type-parameter-0-0<::py::str>();
    }
    auto operator const type-parameter-0-0Bytes() {
        return ::bio::SmartIterator::operator const type-parameter-0-0<::py::bytes>();
    }
    auto operator const type-parameter-0-0Tuple() {
        return ::bio::SmartIterator::operator const type-parameter-0-0<::py::tuple>();
    }
    auto operator const type-parameter-0-0List() {
        return ::bio::SmartIterator::operator const type-parameter-0-0<::py::list>();
    }
    auto operator const type-parameter-0-0Dict() {
        return ::bio::SmartIterator::operator const type-parameter-0-0<::py::dict>();
    }
    auto operator const type-parameter-0-0Iterable() {
        return ::bio::SmartIterator::operator const type-parameter-0-0<::py::iterable>();
    }
    auto operator const type-parameter-0-0Function() {
        return ::bio::SmartIterator::operator const type-parameter-0-0<::py::function>();
    }
    auto operator const type-parameter-0-0Array() {
        return ::bio::SmartIterator::operator const type-parameter-0-0<::py::array>();
    }
    auto operator const type-parameter-0-0ImmutableString() {
        return ::bio::SmartIterator::operator const type-parameter-0-0<::bio::ImmutableString>();
    }
    auto operator const type-parameter-0-0String() {
        return ::bio::SmartIterator::operator const type-parameter-0-0<::bio::String>();
    }
    auto operator const type-parameter-0-0ByteStream() {
        return ::bio::SmartIterator::operator const type-parameter-0-0<::bio::ByteStream>();
    }
    auto operator const type-parameter-0-0ThreadSafe() {
        return ::bio::SmartIterator::operator const type-parameter-0-0<::bio::ThreadSafe>();
    }
    SmartIterator operator++(int ) {
        return ::bio::SmartIterator::operator++(int );
    }
    SmartIterator operator--(int ) {
        return ::bio::SmartIterator::operator--(int );
    }

};
} // immortality namespace
PYBIND11_MODULE(immortality, m) {
    py::class_< ::immortality::ImmutableString >(m, "ImmutableString")
    .def(py::init<>())
    .def("ImmutableString", &ImmutableString::ImmutableString)
    .def("operator=", &ImmutableString::operator=)
    .def("Length", &ImmutableString::Length)
    .def("Find", &ImmutableString::Find)
    .def("GetImmutableSubString", &ImmutableString::GetImmutableSubString);

    py::class_< ::immortality::String >(m, "String")
    .def(py::init<>())
    .def("GetCloneOf", &String::GetCloneOf)
    .def("SetMode", &String::SetMode)
    .def("String", &String::String)
    .def("From", &String::From)
    .def("operator=", &String::operator=)
    .def("operator==", &String::operator==)
    .def("GetMode", &String::GetMode)
    .def("SubString", &String::SubString)
    .def("AsStdString", &String::AsStdString)
    .def("AsCharString", &String::AsCharString)
    .def("AsBool", &String::AsBool)
    .def("AsInt", &String::AsInt)
    .def("AsUInt", &String::AsUInt)
    .def("AsFloat", &String::AsFloat)
    .def("Clear", &String::Clear);

    py::class_< ::immortality::ByteStream >(m, "ByteStream")
    .def(py::init<>())
    .def("ByteStream", &ByteStream::ByteStream)
    .def("operator=", &ByteStream::operator=)
    .def("operator==", &ByteStream::operator==)
    .def("As", &ByteStream::As)
    .def("operator type-parameter-0-0", &ByteStream::operator type-parameter-0-0)
    .def("operator const type-parameter-0-0", &ByteStream::operator const type-parameter-0-0)
    .def("Set", &ByteStream::Set)
    .def("Release", &ByteStream::Release)
    .def("IsEmpty", &ByteStream::IsEmpty)
    .def("Is", &ByteStream::Is)
    .def("GetTypeName", &ByteStream::GetTypeName)
    .def("GetSize", &ByteStream::GetSize)
    .def("TakeHold", &ByteStream::TakeHold)
    .def("DirectAccess", &ByteStream::DirectAccess);

    py::class_< ::immortality::ThreadSafe >(m, "ThreadSafe")
    .def(py::init<>())
    .def("ThreadSafe", &ThreadSafe::ThreadSafe)
    .def("operator=", &ThreadSafe::operator=)
    .def("LockThread", &ThreadSafe::LockThread)
    .def("UnlockThread", &ThreadSafe::UnlockThread)
    .def("CommonConstructor", &ThreadSafe::CommonConstructor);

    py::class_< ::immortality::SmartIterator >(m, "SmartIterator")
    .def(py::init<>())
    .def("SmartIterator", &SmartIterator::SmartIterator)
    .def("IsValid", &SmartIterator::IsValid)
    .def("Invalidate", &SmartIterator::Invalidate)
    .def("GetImplementation", &SmartIterator::GetImplementation)
    .def("GetIndex", &SmartIterator::GetIndex)
    .def("MoveTo", &SmartIterator::MoveTo)
    .def("IsBeforeBeginning", &SmartIterator::IsBeforeBeginning)
    .def("IsAfterEnd", &SmartIterator::IsAfterEnd)
    .def("operator*", &SmartIterator::operator*)
    .def("As", &SmartIterator::As)
    .def("operator type-parameter-0-0", &SmartIterator::operator type-parameter-0-0)
    .def("operator const type-parameter-0-0", &SmartIterator::operator const type-parameter-0-0)
    .def("operator++", &SmartIterator::operator++)
    .def("operator--", &SmartIterator::operator--);

}
