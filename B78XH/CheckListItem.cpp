#include "CheckListItem.h"

auto CheckListItem::setCurrentState(CHECKLIST_ITEM_STATE state) -> void {
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
    nvgStrokeWidth(getContext(), 5.0f);
    nvgBeginPath(getContext());
    {
        nvgMoveTo(getContext(), 0, 0);
        nvgLineTo(getContext(), position.width, 0);
        nvgLineTo(getContext(),  position.width,  position.height);
        nvgLineTo(getContext(), 0, position.height);
        nvgStroke(getContext());
    }
    nvgClosePath(getContext());
}

auto CheckListItem::calculateBounds() -> void {
    bounds_[0] = absolutePosition.left;
    bounds_[1] = absolutePosition.left + position.width;
    bounds_[2] = absolutePosition.top;
    bounds_[3] = absolutePosition.top + position.height;
}
