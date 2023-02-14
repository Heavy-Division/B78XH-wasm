#include "MFDCHKLControl.h"

auto MFDCHKLControl::render() -> void {
	MFDBaseControl::render();
}

void MFDCHKLControl::prepareControls() {
	MFDBaseControl::prepareControls();

	add(std::make_shared<CheckListLine>("TEST_LINE", CheckListLine::CHECKLIST_LINE_TYPE::CLOSED_LOOP));
}

void MFDCHKLControl::setupControls() {
	MFDBaseControl::setupControls();
	getControl("TEST_LINE")->position.setPosition(0, 0, CheckListDimensions::TOTAL_LINE_WIDTH, CheckListDimensions::TOTAL_LINE_HEIGHT);
}
