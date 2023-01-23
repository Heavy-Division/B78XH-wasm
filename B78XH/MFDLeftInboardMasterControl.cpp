#include "MFDLeftInboardMasterControl.h"
#include "EICASControl.h"

void MFDLeftInboardMasterControl::prepareControls() {
	MasterControl::prepareControls();
	add(std::make_unique<EICASControl>("EICASControl"));
}

void MFDLeftInboardMasterControl::setupControls() {
	MasterControl::setupControls();
}
