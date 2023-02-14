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
            nvgMoveTo(getContext(), CheckListDimensions::LINE_MARGIN, CheckListDimensions::ONE_FORTH_INNER_LINE_HEIGHT * 3);
            nvgLineTo(getContext(), CheckListDimensions::LINE_MARGIN + CheckListDimensions::ONE_FORTH_INNER_LINE_HEIGHT, CheckListDimensions::INNER_LINE_END_Y);
            nvgLineTo(getContext(),  CheckListDimensions::LINE_MARGIN + CheckListDimensions::ONE_FORTH_INNER_LINE_HEIGHT * 3, CheckListDimensions::LINE_MARGIN);
            nvgStroke(getContext());
        }
        nvgClosePath(getContext());
    }
}
