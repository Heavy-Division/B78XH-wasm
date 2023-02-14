#include "CheckListLineStateIndicator.h"
#include "CheckListLine.h"

void CheckListLineStateIndicator::drawOpenLoopIndicator() {
    constexpr auto left = 0;
    constexpr auto top = 0;
    const auto width = getRelativePosition().getWidth();
    const auto height = getRelativePosition().getHeight();
    const auto topGray = line_->getCurrentState() == CheckListItem::CHECKLIST_ITEM_STATE::COMPLETED
                             ? Tools::Colors::cduButtonBorderBottomGray
                             : Tools::Colors::cduButtonBorderTopGray;
    const auto bottomGray = line_->getCurrentState() == CheckListItem::CHECKLIST_ITEM_STATE::COMPLETED
                                ? Tools::Colors::cduButtonBorderTopGray
                                : Tools::Colors::cduButtonBorderBottomGray;
    const auto leftGray = line_->getCurrentState() == CheckListItem::CHECKLIST_ITEM_STATE::COMPLETED
                              ? Tools::Colors::cduButtonBorderRightGray
                              : Tools::Colors::cduButtonBorderLeftGray;
    const auto rightGray = line_->getCurrentState() == CheckListItem::CHECKLIST_ITEM_STATE::COMPLETED
                               ? Tools::Colors::cduButtonBorderLeftGray
                               : Tools::Colors::cduButtonBorderRightGray;
    // open loop indicator
    nvgFillColor(getContext(), Tools::Colors::cduButtonGray);
    nvgBeginPath(getContext());
    {
        nvgRect(getContext(), 0, 0, width, height);
        nvgFill(getContext());
    }
    nvgClosePath(getContext());

    // top
    nvgFillColor(getContext(), topGray);
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
    nvgFillColor(getContext(), rightGray);
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
    nvgFillColor(getContext(), bottomGray);
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
    nvgFillColor(getContext(), leftGray);
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
    nvgStrokeWidth(getContext(), 4);
    nvgBeginPath(getContext());
    {
        constexpr float sideOffset = 10;
        nvgMoveTo(getContext(), sideOffset, 30);
        nvgLineTo(getContext(), sideOffset+ 12,
                  position.height - sideOffset);
        nvgLineTo(getContext(), position.width - sideOffset, sideOffset);
        nvgStroke(getContext());
    }
    nvgClosePath(getContext());
}

void CheckListLineStateIndicator::render() {
    Control::render();

    if (line_->line_type == CheckListLine::CHECKLIST_LINE_TYPE::OPEN_LOOP) {
        drawOpenLoopIndicator();
    }
    if (line_->getCurrentState() == CheckListItem::CHECKLIST_ITEM_STATE::COMPLETED) {
        drawCheckMark();
    }
}
