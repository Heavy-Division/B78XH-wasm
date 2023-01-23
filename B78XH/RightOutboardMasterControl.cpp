#include "RightOutboardMasterControl.h"
#include "EICASControl.h"

void RightOutboardMasterControl::prepareControls() {
	MasterControl::prepareControls();
	add(std::make_unique<EICASControl>("EICASControl"));
}

void RightOutboardMasterControl::setupControls() {
	MasterControl::setupControls();
}
