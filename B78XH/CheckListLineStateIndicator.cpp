#include "CheckListLineStateIndicator.h"
#include "CheckListLine.h"

void CheckListLineStateIndicator::drawOpenLoopIndicator() {
    constexpr auto left = 0;
    constexpr auto top = 0;
    const auto width = getRelativePosition().getWidth();
    const auto height = getRelativePosition().getHeight();
    // open loop indicator
    nvgFillColor(getContext(), Tools::Colors::cduButtonGray);
    nvgBeginPath(getContext());
    {
        nvgRect(getContext(), 0, 0, width, height);
        nvgFill(getContext());
    }
    nvgClosePath(getContext());
    
    // top
    nvgFillColor(getContext(), Tools::Colors::cduButtonBorderTopGray);
    nvgBeginPath(getContext());
    {
        nvgMoveTo(getContext(), left, top);
        nvgLineTo(getContext(), (left + width), top);
        nvgLineTo(getContext(), (left + width - CheckListDimensions::BORDER_WIDTH),
                  (top + CheckListDimensions::BORDER_WIDTH));
        nvgLineTo(getContext(), (left + CheckListDimensions::BORDER_WIDTH), (top + CheckListDimensions::BORDER_WIDTH));
        nvgLineTo(getContext(), left, top);
    }
    nvgClosePath(getContext());
    nvgFill(getContext());

    // right
    nvgFillColor(getContext(), Tools::Colors::cduButtonBorderRightGray);
    nvgBeginPath(getContext());
    {
        nvgMoveTo(getContext(), (left + width), top);
        nvgLineTo(getContext(), (left + width), (top + height) + 1);
        nvgLineTo(getContext(), (left + width - CheckListDimensions::BORDER_WIDTH),
                  (top + height - CheckListDimensions::BORDER_WIDTH) + 1);
        nvgLineTo(getContext(), (left + width - CheckListDimensions::BORDER_WIDTH),
                  (top + CheckListDimensions::BORDER_WIDTH));
        nvgLineTo(getContext(), (left + width), (top));
    }
    nvgClosePath(getContext());
    nvgFill(getContext());

    // bottom
    nvgFillColor(getContext(), Tools::Colors::cduButtonBorderBottomGray);
    nvgBeginPath(getContext());
    {
        nvgMoveTo(getContext(), left, (top + height));
        nvgLineTo(getContext(), (left + width), (top + height));
        nvgLineTo(getContext(), (left + width - CheckListDimensions::BORDER_WIDTH),
                  (top + height - CheckListDimensions::BORDER_WIDTH));
        nvgLineTo(getContext(), (left + CheckListDimensions::BORDER_WIDTH),
                  (top + height - CheckListDimensions::BORDER_WIDTH));
        nvgLineTo(getContext(), (left), (top + height));
    }
    nvgClosePath(getContext());
    nvgFill(getContext());

    // left
    nvgFillColor(getContext(), Tools::Colors::cduButtonBorderLeftGray);
    nvgBeginPath(getContext());
    {
        nvgMoveTo(getContext(), left, top);
        nvgLineTo(getContext(), (left + CheckListDimensions::BORDER_WIDTH), (top + CheckListDimensions::BORDER_WIDTH));
        nvgLineTo(getContext(), (left + CheckListDimensions::BORDER_WIDTH),
                  (top + height - CheckListDimensions::BORDER_WIDTH));
        nvgLineTo(getContext(), (left), (top + height));
        nvgLineTo(getContext(), (left), (top));
    }
    nvgClosePath(getContext());
    nvgFill(getContext());
}

void CheckListLineStateIndicator::drawCheckMark() {
    nvgStrokeColor(getContext(), Tools::Colors::green);
    nvgStrokeWidth(getContext(), 3);
    nvgBeginPath(getContext());
    {
        nvgMoveTo(getContext(), CheckListDimensions::BORDER_WIDTH, 25);
        nvgLineTo(getContext(), CheckListDimensions::BORDER_WIDTH + 15,
                  position.height - CheckListDimensions::BORDER_WIDTH);
        nvgLineTo(getContext(), position.width - CheckListDimensions::BORDER_WIDTH, CheckListDimensions::BORDER_WIDTH);
        nvgStroke(getContext());
    }
    nvgClosePath(getContext());
}

void CheckListLineStateIndicator::render() {
    CheckListItem::render();

    if (line_->line_type == CheckListLine::CHECKLIST_LINE_TYPE::OPEN_LOOP) {
        drawOpenLoopIndicator();
    }
    // green check, testing
    drawCheckMark();
}
