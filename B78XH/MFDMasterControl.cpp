#include "MFDMasterControl.h"
#include "MFDControl.h"

void MFDMasterControl::prepareControls() {
	MasterControl::prepareControls();
	add(std::make_unique<MFDControl>("MFDMasterControl"));
}

void MFDMasterControl::setupControls() {
	MasterControl::setupControls();
	addOnValidate([](BaseControl& control) -> bool {
		return false;
		});
}

