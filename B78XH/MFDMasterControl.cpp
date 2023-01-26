#include "MFDMasterControl.h"

#include "Tools/Console.h"

void MFDMasterControl::prepareControls() {
	MasterControl::prepareControls();
	add(MFD::resolver.getMFD(mfdIndex_)->getLeftSide());
	add(MFD::resolver.getMFD(mfdIndex_)->getRightSide());
}

void MFDMasterControl::setupControls() {
	MasterControl::setupControls();

	auto& leftSide = getControl("LEFT_SIDE");
	auto& rightSide = getControl("RIGHT_SIDE");
	leftSide->position.setPosition(0, 0, position.width / 2, position.height);
	rightSide->position.setPosition(position.width / 2, 0, position.width, position.height);
}

void MFDMasterControl::setupControl() {
	MasterControl::setupControl();

	addOnBeforeRender([this](BaseControl& control) -> bool {
		//if(MFD::resolver.getMFD(mfdIndex_).isInvalid()) {
		//	MFD::resolver.getMFD(mfdIndex_).setInvalid(false);
		//	Console::error("restarting");
		//	restart();
		//}
		restart();
		return true;
	});
}
