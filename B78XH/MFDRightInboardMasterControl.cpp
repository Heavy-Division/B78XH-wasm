#include "MFDRightInboardMasterControl.h"
#include "EICASControl.h"

void MFDRightInboardMasterControl::prepareControls() {
	MasterControl::prepareControls();
	add(std::make_unique<EICASControl>("EICASControl"));
}

void MFDRightInboardMasterControl::setupControls() {
	MasterControl::setupControls();
}
