#include "MFDCHKLControl.h"

#include "CheckListLineSingle.h"

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

    add(std::make_shared<CheckListTitle>("TEST_TITLE", CheckListTitle::TITLE_TYPE::NORMAL_CHECKLIST, "PREFLIGHT"));
    const auto l1 = std::make_shared<CheckListLineSingle>("TEST_LINE", CheckListLine::CHECKLIST_LINE_TYPE::OPEN_LOOP, "Oxygen . . . . . . . . . . . . . . . . . . . . . . Tested,100%");
    l1->setCurrentState(CheckListItem::CHECKLIST_ITEM_STATE::COMPLETED);
    l1->setIsCurrent(true);
    add(l1);
    const auto l2 = std::make_shared<CheckListLine>("TEST_LINE_2", CheckListLine::CHECKLIST_LINE_TYPE::OPEN_LOOP);
    l2->setCurrentState(CheckListItem::CHECKLIST_ITEM_STATE::COMPLETED);
    add(l2);
}

void MFDCHKLControl::setupControls() {
    MFDBaseControl::setupControls();
    normalMenuButton_->position.setPosition(0, 0, 215, CheckListDimensions::TOTAL_LINE_HEIGHT);
    resetsButton_->position.setPosition(225, 0, 385, CheckListDimensions::TOTAL_LINE_HEIGHT);
    nonNormalMenuButton_->position.setPosition(395, 0, CheckListDimensions::TOTAL_WIDTH,
                                               CheckListDimensions::TOTAL_LINE_HEIGHT);
    getControl("TEST_TITLE")->position.setPosition(200, CheckListDimensions::TOTAL_LINE_HEIGHT, 500,
                                                   CheckListDimensions::TOTAL_LINE_HEIGHT * 2);
    getControl("TEST_LINE")->position.setPosition(0, CheckListDimensions::TOTAL_LINE_HEIGHT * 2,
                                                  CheckListDimensions::TOTAL_WIDTH,
                                                  CheckListDimensions::TOTAL_LINE_HEIGHT * 3);
    getControl("TEST_LINE_2")->position.setPosition(0, CheckListDimensions::TOTAL_LINE_HEIGHT * 3,
                                                    CheckListDimensions::TOTAL_WIDTH,
                                                    CheckListDimensions::TOTAL_LINE_HEIGHT * 4);
}
