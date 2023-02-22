#include "CheckListLine.h"

void CheckListLineStateIndicator::drawOpenLoopIndicator() {
    const auto topGray = line_->getCurrentState() == CHECKLIST_ITEM_STATE::COMPLETED
                             ? Tools::Colors::cduButtonBorderBottomGray
                             : Tools::Colors::cduButtonBorderTopGray;
    const auto bottomGray = line_->getCurrentState() == CHECKLIST_ITEM_STATE::COMPLETED
                                ? Tools::Colors::cduButtonBorderTopGray
                                : Tools::Colors::cduButtonBorderBottomGray;
    const auto leftGray = line_->getCurrentState() == CHECKLIST_ITEM_STATE::COMPLETED
                              ? Tools::Colors::cduButtonBorderRightGray
                              : Tools::Colors::cduButtonBorderLeftGray;
    const auto rightGray = line_->getCurrentState() == CHECKLIST_ITEM_STATE::COMPLETED
                               ? Tools::Colors::cduButtonBorderLeftGray
                               : Tools::Colors::cduButtonBorderRightGray;
    drawButtonBorder(Tools::Colors::cduButtonGray, topGray, rightGray, bottomGray, leftGray);
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
    CheckListItem::render();

    if (line_->line_type == CheckListLine::CHECKLIST_LINE_TYPE::OPEN_LOOP) {
        drawOpenLoopIndicator();
    }
    if (line_->getCurrentState() == CheckListItem::CHECKLIST_ITEM_STATE::COMPLETED) {
        drawCheckMark();
    }
}
