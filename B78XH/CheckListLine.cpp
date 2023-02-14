#include "CheckListLine.h"

void CheckListLine::prepareControls() {
    CheckListItem::prepareControls();

    add(std::make_shared<CheckListLineStateIndicator>("STATE_INDICATOR", this));
}

void CheckListLine::setupControls() {
    CheckListItem::setupControls();

    getControl("STATE_INDICATOR")->position.setPosition(CheckListDimensions::LINE_MARGIN, CheckListDimensions::LINE_MARGIN, CheckListDimensions::INNER_LINE_END_Y, CheckListDimensions::INNER_LINE_END_Y);
}
