#include "femcontroller.h"

extern "C" {
	#include "petsc.h"
}

#undef __FUNCT__
#define __FUNCT__ "main"
int main(int argc, char **argv)
{
	PetscErrorCode ierr;

	PetscInitialize(&argc, &argv, (char*) 0, 0);

	FEMController *fc = new FEMController(argc, argv);
	delete fc;

	ierr = PetscFinalize(); CHKERRQ(ierr);
	return 0;
}