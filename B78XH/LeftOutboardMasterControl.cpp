#include "LeftOutboardMasterControl.h"
#include "EICASControl.h"


void ::LeftOutBoardMasterControl::prepareControls() {
	MasterControl::prepareControls();
	add(std::make_unique<EICASControl>("EICASControl"));
}

void ::LeftOutBoardMasterControl::setupControls() {
	MasterControl::setupControls();
	getControl("EICASControl")->position.setPosition(100, 1000, 0, 0);
}

