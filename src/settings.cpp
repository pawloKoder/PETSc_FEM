#include "settings.h"

#include <sstream>
#include <boost/program_options.hpp>

extern "C" {
	#include "petsc.h"
}


Settings::Settings():
	inputFile("input.mesh"),
	outDir("out"),
	skip(false)
{}


Settings::~Settings() {
}


Settings & Settings::self() {
	static Settings instance;
	return instance;
}


void Settings::init(int argc, char **argv) {
	self().init_impl(argc, argv);
}


void Settings::init_impl(int argc, char **argv)
{
	try {
		boost::program_options::options_description desc("");
		
		desc.add_options()
		("help,h", "print this message")
		("input,i", boost::program_options::value<std::string>()->default_value(inputFile), 
			"Path to input file")
		("output,o", boost::program_options::value<std::string>()->default_value(outDir), 
			"Path to output directory");

		boost::program_options::variables_map vm;
		boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);

		if (vm.count("help")) {
			std::stringstream str;
			str << desc;
			PetscPrintf(PETSC_COMM_WORLD, "%s\n", str.str().c_str());
			skip = true;
		}

		boost::program_options::notify(vm);

		try {
			if (vm.count("input")) {
				inputFile = vm["input"].as<std::string>();
				PetscPrintf(PETSC_COMM_WORLD, "Input file set as: %s\n", inputFile.c_str());
			}

			if (vm.count("output")) {
				outDir = vm["output"].as<std::string>();
				PetscPrintf(PETSC_COMM_WORLD, "Output directory set as: %s\n", outDir.c_str());
			}
		} catch (const boost::bad_any_cast& ex) {
			PetscPrintf(PETSC_COMM_WORLD, "At parsing options: %s\n", ex.what());
			skip = true;
		}
	}
	catch (std::exception& e) {
		PetscPrintf(PETSC_COMM_WORLD, "At parsing options: %s\n", e.what());
		skip = true;
	}
}
