#include <bio.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

// Use of FinalMolecule fails.
//class Molecule : public bio::api::FinalMolecule
//{
//public:
//	Molecule() :
//		bio::api::FinalMolecule()
//	{
//
//	}
//
//	~Molecule()
//	{
//
//	}
//};

class Organism : public  bio::organic::Organism
{
public:
	Organism() :
		bio::organic::Organism(bio::physical::Perspective<bio::Id>::InvalidName())
	{

	}

	Organism(const char* name) :
		bio::organic::Organism(name)
	{

	}

	~Organism()
	{

	}
};

int test()
{
// This works
//	bio::chemical::Atom a;
//	a.FormBond< int >(1234);
//	return *a.As< int* >();

// This fails
//	bio::chemical::Substance s;

// This fails
//	bio::organic::Organism* t = new Organism("Blah");
//	delete t;

	return 22;
}

PYBIND11_MODULE(immortality, module) {
//	auto molecule = py::class_< Molecule >(module, "Molecule");
//	molecule.def(py::init<>());

	auto organism = py::class_< Organism >(module, "Organism");
	organism.def(py::init<>());

	module.def("test", &test, "Bloop");
}
