#include "MFDCHKLControl.h"

auto MFDCHKLControl::render() -> void {
    MFDBaseControl::render();
}

void MFDCHKLControl::prepareControls() {
    MFDBaseControl::prepareControls();

    add(normalMenuButton_);
    add(resetsButton_);
    add(nonNormalMenuButton_);
    add(normalButton_);
    add(resetChecklistButton_);
    add(preflight_);
}

void MFDCHKLControl::setupControls() {
    MFDBaseControl::setupControls();
    normalMenuButton_->position.setPosition(0, 0, 215, CheckListDimensions::TOTAL_LINE_HEIGHT);
    resetsButton_->position.setPosition(225, 0, 385, CheckListDimensions::TOTAL_LINE_HEIGHT);
    nonNormalMenuButton_->position.setPosition(395, 0, CheckListDimensions::TOTAL_WIDTH,
                                               CheckListDimensions::TOTAL_LINE_HEIGHT);
    normalButton_->position.setPosition(0, position.height - CheckListDimensions::TOTAL_LINE_HEIGHT, 150,
                                        position.height);
    resetChecklistButton_->position.setPosition(300, position.height - CheckListDimensions::TOTAL_LINE_HEIGHT, 450,
                                                position.height);

    preflight_->position.setPosition(0, CheckListDimensions::TOTAL_LINE_HEIGHT, CheckListDimensions::TOTAL_WIDTH,
                                     position.height - CheckListDimensions::TOTAL_LINE_HEIGHT);
}
