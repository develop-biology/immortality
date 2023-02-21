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

	long int SetName(const char* name) {
		return bio::organic::Organism::SetName(name);
	}

	const char* GetName() {
		return bio::organic::Organism::GetName().AsCharString();
	}
};

PYBIND11_MODULE(immortality, module) {
//	auto molecule = py::class_< Molecule >(module, "Molecule");
//	molecule.def(py::init<>());

	auto organism = py::class_< Organism >(module, "Organism")
	    .def(py::init<>())
		.def("SetName", &Organism::SetName)
		.def("GetName", &Organism::GetName);
}
