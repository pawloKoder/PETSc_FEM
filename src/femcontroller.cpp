#include "femcontroller.h"
#include "settings.h"

extern "C" {
	#include "petsc.h"
}


#undef __FUNCT__
#define __FUNCT__ "FEMController::FEMController"
FEMController::FEMController(int argc, char **argv) {
	PetscMPIInt rank;
	PetscMPIInt size;
	
	MPI_Comm_rank(PETSC_COMM_WORLD, &rank);
	MPI_Comm_size(PETSC_COMM_WORLD, &size);
	PetscPrintf(PETSC_COMM_SELF, "[%d] rank  %d/%d\n", rank, rank, size);
	
	Settings::init(argc, argv);
}


FEMController::~FEMController() {
}
