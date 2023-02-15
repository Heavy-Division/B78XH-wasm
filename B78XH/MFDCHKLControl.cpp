#include "MFDCHKLControl.h"

auto MFDCHKLControl::render() -> void {
    MFDBaseControl::render();
}

void MFDCHKLControl::prepareControls() {
    MFDBaseControl::prepareControls();

    normalMenuButton_ = std::make_shared<CheckListButton>("NORMAL_MENU", nullptr, "NORMAL MENU");
    add(normalMenuButton_);
    resetsButton_ = std::make_shared<CheckListButton>("RESETS", nullptr, "RESETS");
    add(resetsButton_);
    nonNormalMenuButton_ = std::make_shared<CheckListButton>("NON_NORMAL_MENU", nullptr, "NON-NORMAL MENU");
    add(nonNormalMenuButton_);
    
    add(std::make_shared<CheckListLine>("TEST_LINE", CheckListLine::CHECKLIST_LINE_TYPE::OPEN_LOOP));
    const auto l2 = std::make_shared<CheckListLine>("TEST_LINE_2", CheckListLine::CHECKLIST_LINE_TYPE::OPEN_LOOP);
    l2->setCurrentState(CheckListItem::CHECKLIST_ITEM_STATE::COMPLETED);
    l2->setIsCurrent(true);
    add(l2);
}

void MFDCHKLControl::setupControls() {
    MFDBaseControl::setupControls();
    normalMenuButton_->position.setPosition(0, 0, 220, CheckListDimensions::TOTAL_LINE_HEIGHT);
    resetsButton_->position.setPosition(220, 0, 390, CheckListDimensions::TOTAL_LINE_HEIGHT);
    nonNormalMenuButton_->position.setPosition(390, 0, CheckListDimensions::TOTAL_WIDTH, CheckListDimensions::TOTAL_LINE_HEIGHT);
    getControl("TEST_LINE")->position.setPosition(0, CheckListDimensions::TOTAL_LINE_HEIGHT, CheckListDimensions::TOTAL_WIDTH,
                                                  CheckListDimensions::TOTAL_LINE_HEIGHT * 2);
    getControl("TEST_LINE_2")->position.setPosition(0, CheckListDimensions::TOTAL_LINE_HEIGHT * 2,
                                                  CheckListDimensions::TOTAL_WIDTH,
                                                  CheckListDimensions::TOTAL_LINE_HEIGHT * 3);
}
