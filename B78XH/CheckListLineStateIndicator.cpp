#include "CheckListLineStateIndicator.h"
#include "CheckListLine.h"

void CheckListLineStateIndicator::render() {
    CheckListItem::render();

    if (line_->line_type == CheckListLine::CHECKLIST_LINE_TYPE::OPEN_LOOP) {
    }
    else {
        // green check, testing
        nvgStrokeColor(getContext(), Tools::Colors::green);
        nvgStrokeWidth(getContext(), 3);
        nvgBeginPath(getContext());
        {
            nvgMoveTo(getContext(), CheckListDimensions::MARGIN, CheckListDimensions::ONE_FORTH_INNER_HEIGHT * 3);
            nvgLineTo(getContext(), CheckListDimensions::MARGIN + CheckListDimensions::ONE_FORTH_INNER_HEIGHT, CheckListDimensions::INNER_Y_END);
            nvgLineTo(getContext(),  CheckListDimensions::MARGIN + CheckListDimensions::ONE_FORTH_INNER_HEIGHT * 3, CheckListDimensions::MARGIN);
            nvgStroke(getContext());
        }
        nvgClosePath(getContext());
    }
}
