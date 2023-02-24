#include "CheckListLine.h"

auto CheckListLine::setIsCurrent(bool current) -> void {
    isCurrent_ = current;
}

auto CheckListLine::getIsCurrent() const -> bool {
    return isCurrent_;
}

void CheckListLine::render() {
    CheckListItem::render();
    if (isInFocus()) {
        drawBorder();
    }
    if(isCurrent_) {
        drawIsCurrentBorder();
    }
}

void CheckListLine::prepareControls() {
    CheckListItem::prepareControls();
    add(stateIndicator_);
}

void CheckListLine::setupControls() {
    CheckListItem::setupControls();

    stateIndicator_->position.setPosition(CheckListDimensions::MARGIN, CheckListDimensions::MARGIN,
                                          CheckListDimensions::INNER_Y_END, CheckListDimensions::INNER_Y_END);
}

auto CheckListLine::drawIsCurrentBorder() -> void {
    const float xStart = CheckListDimensions::INNER_Y_END + CheckListDimensions::MARGIN;
    const float xEnd = position.width - CheckListDimensions::BORDER_WIDTH - CheckListDimensions::MARGIN;
    const float yStart = CheckListDimensions::BORDER_WIDTH / 2 + CheckListDimensions::MARGIN;
    const float yEnd = position.height - CheckListDimensions::BORDER_WIDTH - CheckListDimensions::MARGIN;
    nvgStrokeColor(getContext(), Tools::Colors::white);
    nvgStrokeWidth(getContext(), CheckListDimensions::BORDER_WIDTH);
    nvgBeginPath(getContext());
    {
        nvgMoveTo(getContext(), xStart, yStart);
        nvgLineTo(getContext(), xStart, yEnd);
        nvgLineTo(getContext(), xEnd, yEnd);
        nvgLineTo(getContext(), xEnd, yStart);
        nvgLineTo(getContext(), xStart, yStart);
        nvgStroke(getContext());
    }
    nvgClosePath(getContext());
}
