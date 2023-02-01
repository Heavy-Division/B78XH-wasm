#include "MFDLeftInboardMasterControl.h"
#include "EICASControl.h"

void MFDLeftInboardMasterControl::prepareControls() {
	MasterControl::prepareControls();
	add(std::make_unique<EICASControl>("EICASControl"));

	auto& control = getControl("EICASControl");

	control->position.setPosition(0, 0, 0, 0);
}

void MFDLeftInboardMasterControl::setupControls() {
	MasterControl::setupControls();
}
