#include "CheckListLine.h"

void CheckListLine::render() {
    CheckListItem::render();
    if(isInFocus()) {
        drawBorder();
    }
}

void CheckListLine::prepareControls() {
    CheckListItem::prepareControls();

    add(std::make_shared<CheckListLineStateIndicator>("STATE_INDICATOR", this));
}

void CheckListLine::setupControls() {
    CheckListItem::setupControls();

    getControl("STATE_INDICATOR")->position.setPosition(CheckListDimensions::MARGIN, CheckListDimensions::MARGIN, CheckListDimensions::INNER_Y_END, CheckListDimensions::INNER_Y_END);
}
