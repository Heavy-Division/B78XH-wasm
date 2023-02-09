#include "MFDMasterControl.h"

#include "CDUButtonControl.h"
#include "Tools/Console.h"

auto MFDMasterControl::prepareControls() -> void {
	MasterControl::prepareControls();
	add(MFD::resolver.getMFD(mfdIndex_)->getLeftSide());
	add(MFD::resolver.getMFD(mfdIndex_)->getRightSide());
	add(mouseCursor_);
}

auto MFDMasterControl::setupControls() -> void {
	MasterControl::setupControls();

	auto& leftSide = getControl("LEFT_SIDE");
	auto& rightSide = getControl("RIGHT_SIDE");

	leftSide->position.setPosition(0, 0, position.width / 2, position.height);
	rightSide->position.setPosition(position.width / 2, 0, position.width, position.height);

	mouseCursor_->addOnBeforeRender([this](BaseControl& control)-> bool {
		control.getRelativePosition().setPosition(mouseMove_.x - 15, mouseMove_.y - 15, 0, 0);
		return true;
	});

}

void MFDMasterControl::setupControl() {
	MasterControl::setupControl();
	addOnValidate(SKIP_VALIDATION_EVENT);
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
