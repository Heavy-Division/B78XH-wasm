#include "MFDCDUControl.h"

#include "Tools/Console.h"

auto MFDCDUControl::prepareControls() -> void {
	MFDBaseControl::prepareControls();
	add(backgroundControl_);
	add(currentPage_);
}

auto MFDCDUControl::setupControl() -> void {
	MFDBaseControl::setupControl();
}

auto MFDCDUControl::setupControls() -> void {
	MFDBaseControl::setupControls();
	backgroundControl_->position.setPosition(0, 0, getPosition().getWidth(), getPosition().getHeight());
	currentPage_->position.setPosition(getPosition().getWidth() / 2 - 249, 34,  getPosition().getWidth() / 2 + 249, 398 + 34);

	Console::error("Width: {}", getPosition().getWidth());
	Console::error("Center: {}", getPosition().getWidth() / 2);
	//windowWidth / 2 - 249, 34
	//nvgRect(this->context, 0, 0, 498, 398);
}

auto MFDCDUControl::setCurrentPage(std::shared_ptr<CDUPageControl> currentPage) -> void {
}
