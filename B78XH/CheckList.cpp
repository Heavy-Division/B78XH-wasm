#include "CheckList.h"

void CheckList::setupControls() {
    CheckListItem::setupControls();
    addOnBeforeRender([this](BaseControl&) -> bool {
        serviceChecklistUpdateLoop();
        return true;
    });
    setupChecklistLayout();
}

auto CheckList::setupChecklistLayout() -> void {
    title_->position.setPosition(200, CheckListDimensions::TOTAL_LINE_HEIGHT, 500,
                                 CheckListDimensions::TOTAL_LINE_HEIGHT * 2);
    for (auto i = 0; i < lines_.size(); i++) {
        const std::shared_ptr<CheckListLine> line = lines_.at(i);
        line->position.setPosition(0, CheckListDimensions::TOTAL_LINE_HEIGHT * i + 2,
                                   CheckListDimensions::TOTAL_WIDTH,
                                   CheckListDimensions::TOTAL_LINE_HEIGHT * i + 3);
    }
}

auto CheckList::checkChecklistCompleted() -> void {
    if (getCurrentState() == CHECKLIST_ITEM_STATE::OVERRIDDEN) {
        return; // overridden checklist must be explicitly cleared
    }
    for (const std::shared_ptr<CheckListLine> l : lines_) {
        if (l->getCurrentState() == CHECKLIST_ITEM_STATE::OPEN) {
            setCurrentState(CHECKLIST_ITEM_STATE::OPEN);
            break;
        }
    }
}

auto CheckList::advanceCurrentLine() -> void {
    if (currentLine_ >= lines_.size()) {
        return;
    }
    const std::shared_ptr<CheckListLine> currentLine = lines_.at(currentLine_);
    currentLine->setIsCurrent(false);
    currentLine_++;
    if (currentLine_ >= lines_.size()) {
        return;
    }
    const std::shared_ptr<CheckListLine> nextLine = lines_.at(currentLine_);
    nextLine->setIsCurrent(true);
}

auto CheckList::resetChecklist() -> void {
    for (const std::shared_ptr<CheckListLine> l : lines_) {
        l->setCurrentState(CHECKLIST_ITEM_STATE::OPEN);
    }
    setCurrentState(CHECKLIST_ITEM_STATE::OPEN);
}

auto CheckList::checkClosedLoopItems() -> void {
}

auto CheckList::serviceChecklistUpdateLoop() -> void {
    checkClosedLoopItems();
    if (currentLine_ >= lines_.size()) {
        return;
    }
    const std::shared_ptr<CheckListLine> currentLine = lines_.at(currentLine_);
    if (currentLine->getCurrentState() != CHECKLIST_ITEM_STATE::OPEN) {
        advanceCurrentLine();
    }
}
