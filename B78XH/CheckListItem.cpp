#include "CheckListItem.h"

auto CheckListItem::setCurrentState(const CHECKLIST_ITEM_STATE state) -> void {
    currentState_ = state;
}

auto CheckListItem::getCurrentState() const -> CHECKLIST_ITEM_STATE {
    return currentState_;
}

auto CheckListItem::isInFocus() -> bool {
    calculateBounds();
    if (mouseMove_.x >= bounds_[0] &&
        mouseMove_.x <= bounds_[1] &&
        mouseMove_.y >= bounds_[2] &&
        mouseMove_.y < bounds_[3]) {
        return true;
    }
    return false;
}

auto CheckListItem::shouldTriggerEvent() -> bool {
    calculateBounds();
    if (mouseClick_.x >= bounds_[0] &&
        mouseClick_.x <= bounds_[1] &&
        mouseClick_.y >= bounds_[2] &&
        mouseClick_.y <= bounds_[3]) {
        return true;
    }
    return false;
}

auto CheckListItem::getItemStateColor() const -> NVGcolor {
    switch (currentState_) {
    case CHECKLIST_ITEM_STATE::OPEN: return Tools::Colors::white;
    case CHECKLIST_ITEM_STATE::COMPLETED: return Tools::Colors::green;
    case CHECKLIST_ITEM_STATE::OVERRIDDEN: return Tools::Colors::cyan;
    default: return Tools::Colors::white;
    }
}

auto CheckListItem::drawBorder() -> void {
    nvgStrokeColor(getContext(), Tools::Colors::magenta);
    nvgStrokeWidth(getContext(), CheckListDimensions::BORDER_WIDTH);
    nvgBeginPath(getContext());
    {
        nvgMoveTo(getContext(), CheckListDimensions::BORDER_WIDTH / 2, CheckListDimensions::BORDER_WIDTH / 2);
        nvgLineTo(getContext(), position.width - CheckListDimensions::BORDER_WIDTH / 2,
                  CheckListDimensions::BORDER_WIDTH / 2);
        nvgLineTo(getContext(), position.width - CheckListDimensions::BORDER_WIDTH / 2,
                  position.height - CheckListDimensions::BORDER_WIDTH / 2);
        nvgLineTo(getContext(), CheckListDimensions::BORDER_WIDTH / 2,
                  position.height - CheckListDimensions::BORDER_WIDTH / 2);
        nvgLineTo(getContext(), CheckListDimensions::BORDER_WIDTH / 2, CheckListDimensions::BORDER_WIDTH / 2);
        nvgStroke(getContext());
    }
    nvgClosePath(getContext());
}

auto CheckListItem::drawButtonBorder(const NVGcolor background, const NVGcolor top, const NVGcolor right, const NVGcolor bottom,
                                     const NVGcolor left) -> void {
    constexpr auto leftPos = 0;
    constexpr auto topPos = 0;
    const auto width = getRelativePosition().getWidth();
    const auto height = getRelativePosition().getHeight();

    nvgFillColor(getContext(), background);
    nvgBeginPath(getContext());
    {
        nvgRect(getContext(), 0, 0, width, height);
        nvgFill(getContext());
    }
    nvgClosePath(getContext());

    // top
    nvgFillColor(getContext(), top);
    nvgBeginPath(getContext());
    {
        nvgMoveTo(getContext(), leftPos, topPos);
        nvgLineTo(getContext(), leftPos + width, topPos);
        nvgLineTo(getContext(), leftPos + width - CheckListDimensions::BORDER_WIDTH,
                  topPos + CheckListDimensions::BORDER_WIDTH);
        nvgLineTo(getContext(), leftPos + CheckListDimensions::BORDER_WIDTH, topPos + CheckListDimensions::BORDER_WIDTH);
        nvgLineTo(getContext(), leftPos, topPos);
    }
    nvgClosePath(getContext());
    nvgFill(getContext());

    // right
    nvgFillColor(getContext(), right);
    nvgBeginPath(getContext());
    {
        nvgMoveTo(getContext(), leftPos + width, topPos);
        nvgLineTo(getContext(), leftPos + width, topPos + height + 1);
        nvgLineTo(getContext(), leftPos + width - CheckListDimensions::BORDER_WIDTH,
                  topPos + height - CheckListDimensions::BORDER_WIDTH + 1);
        nvgLineTo(getContext(), leftPos + width - CheckListDimensions::BORDER_WIDTH,
                  topPos + CheckListDimensions::BORDER_WIDTH);
        nvgLineTo(getContext(), leftPos + width, topPos);
    }
    nvgClosePath(getContext());
    nvgFill(getContext());

    // bottom
    nvgFillColor(getContext(), bottom);
    nvgBeginPath(getContext());
    {
        nvgMoveTo(getContext(), leftPos, topPos + height);
        nvgLineTo(getContext(), leftPos + width, topPos + height);
        nvgLineTo(getContext(), leftPos + width - CheckListDimensions::BORDER_WIDTH,
                  topPos + height - CheckListDimensions::BORDER_WIDTH);
        nvgLineTo(getContext(), leftPos + CheckListDimensions::BORDER_WIDTH,
                  topPos + height - CheckListDimensions::BORDER_WIDTH);
        nvgLineTo(getContext(), leftPos, topPos + height);
    }
    nvgClosePath(getContext());
    nvgFill(getContext());

    // left
    nvgFillColor(getContext(), left);
    nvgBeginPath(getContext());
    {
        nvgMoveTo(getContext(), leftPos, topPos);
        nvgLineTo(getContext(), leftPos + CheckListDimensions::BORDER_WIDTH, topPos + CheckListDimensions::BORDER_WIDTH);
        nvgLineTo(getContext(), leftPos + CheckListDimensions::BORDER_WIDTH,
                  topPos + height - CheckListDimensions::BORDER_WIDTH);
        nvgLineTo(getContext(), leftPos, topPos + height);
        nvgLineTo(getContext(), leftPos, topPos);
    }
    nvgClosePath(getContext());
    nvgFill(getContext());
}

auto CheckListItem::calculateBounds() -> void {
    bounds_[0] = absolutePosition.left;
    bounds_[1] = absolutePosition.left + position.width;
    bounds_[2] = absolutePosition.top;
    bounds_[3] = absolutePosition.top + position.height;
}
