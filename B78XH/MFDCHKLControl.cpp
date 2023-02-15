#include "MFDCHKLControl.h"

auto MFDCHKLControl::render() -> void {
    MFDBaseControl::render();
}

void MFDCHKLControl::prepareControls() {
    MFDBaseControl::prepareControls();

    add(std::make_shared<CheckListLine>("TEST_LINE", CheckListLine::CHECKLIST_LINE_TYPE::OPEN_LOOP));
    const auto l2 = std::make_shared<CheckListLine>("TEST_LINE_2", CheckListLine::CHECKLIST_LINE_TYPE::OPEN_LOOP);
    l2->setCurrentState(CheckListItem::CHECKLIST_ITEM_STATE::COMPLETED);
    l2->setIsCurrent(true);
    add(l2);
}

void MFDCHKLControl::setupControls() {
    MFDBaseControl::setupControls();
    getControl("TEST_LINE")->position.setPosition(0, 0, CheckListDimensions::TOTAL_WIDTH,
                                                  CheckListDimensions::TOTAL_LINE_HEIGHT);
    getControl("TEST_LINE_2")->position.setPosition(0, CheckListDimensions::TOTAL_LINE_HEIGHT,
                                                  CheckListDimensions::TOTAL_WIDTH,
                                                  CheckListDimensions::TOTAL_LINE_HEIGHT * 2);
}
