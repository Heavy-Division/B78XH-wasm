#include "CheckList.h"

void CheckList::setupControls() {
    CheckListItem::setupControls();
    addOnBeforeRender([this](BaseControl&) -> bool {
        serviceChecklistUpdateLoop();
        return true;
    });
    setupChecklistLayout();
}

void CheckList::prepareControls() {
    CheckListItem::prepareControls();
    addChecklistControls();
}

auto CheckList::setupChecklistLayout() -> void {
    title_->position.setPosition(200, 0, 500,
                                 CheckListDimensions::TOTAL_LINE_HEIGHT * 1);
    for (auto i = 0; i < lines_.size(); i++) {
        // TODO: No pagination yet, no normal checklist needs pagination
        const std::shared_ptr<CheckListLine> line = lines_.at(i);
        line->position.setPosition(0, CheckListDimensions::TOTAL_LINE_HEIGHT * (i + 1),
                                   CheckListDimensions::TOTAL_WIDTH,
                                   CheckListDimensions::TOTAL_LINE_HEIGHT * (i + 2));
    }
    status_->position.setPosition(200, position.getHeight() - CheckListDimensions::TOTAL_LINE_HEIGHT / 2 - CheckListDimensions::MARGIN, 500,
                                  position.getHeight() - CheckListDimensions::MARGIN);
}

auto CheckList::checkChecklistCompleted() -> void {
    if (getCurrentState() == CHECKLIST_ITEM_STATE::OVERRIDDEN) {
        return; // overridden checklist must be explicitly cleared
    }
    for (const std::shared_ptr<CheckListLine> l : lines_) {
        if (l->getCurrentState() == CHECKLIST_ITEM_STATE::OPEN) {
            setCurrentState(CHECKLIST_ITEM_STATE::OPEN);
            return;
        }
    }
    setCurrentState(CHECKLIST_ITEM_STATE::COMPLETED);
}

auto CheckList::advanceCurrentLine() -> void {
    toggleCurrentLineHighlight(false);
    currentLine_++;
    toggleCurrentLineHighlight(true);
    checkChecklistCompleted();
}

auto CheckList::resetChecklist() -> void {
    for (const std::shared_ptr<CheckListLine> l : lines_) {
        l->setCurrentState(CHECKLIST_ITEM_STATE::OPEN);
    }
    setCurrentState(CHECKLIST_ITEM_STATE::OPEN);
    currentLine_ = 0;
    toggleCurrentLineHighlight(true);
}

auto CheckList::checkClosedLoopItems() -> void {
}

auto CheckList::addChecklistControls() -> void {
    add(title_);
    add(status_);
    for (std::shared_ptr<CheckListLine> l : lines_) {
        add(l);
    }
}

auto CheckList::serviceChecklistUpdateLoop() -> void {
    if (currentLine_ >= lines_.size()) {
        // overrun, so the checklist is either completed or overridden.
        return;
    }
    checkClosedLoopItems();
    const std::shared_ptr<CheckListLine> currentLine = lines_.at(currentLine_);
    if (currentLine->getCurrentState() != CHECKLIST_ITEM_STATE::OPEN) {
        advanceCurrentLine();
    }
}

auto CheckList::toggleCurrentLineHighlight(bool isCurrent) -> void {
    if (currentLine_ >= lines_.size()) {
        return;
    }
    const std::shared_ptr<CheckListLine> currentLine = lines_.at(currentLine_);
    currentLine->setIsCurrent(isCurrent);
}
