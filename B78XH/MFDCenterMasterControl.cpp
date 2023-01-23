#include "MFDCenterMasterControl.h"
#include "EICASControl.h"

void MFDCenterMasterControl::prepareControls() {
	MasterControl::prepareControls();
	add(std::make_unique<EICASControl>("EICASControl"));
}

void MFDCenterMasterControl::setupControls() {
	MasterControl::setupControls();
}
