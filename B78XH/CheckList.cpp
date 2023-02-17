#include "CheckList.h"

void CheckList::setupControls() {
    CheckListItem::setupControls();
    addOnBeforeRender([this](BaseControl&) -> bool {
        serviceChecklistUpdateLoop();
        return true;
    });
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
    currentLine++;
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
    if(currentLine_ >= lines_.size()) {
        return;
    }
    const std::shared_ptr<CheckListLine> currentLine = lines_.at(currentLine_);
    if (currentLine->getCurrentState() != CHECKLIST_ITEM_STATE::OPEN) {
        advanceCurrentLine();
    }
}
