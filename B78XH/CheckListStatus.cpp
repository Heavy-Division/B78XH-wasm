#include "CheckListStatus.h"
#include "CheckList.h"

void CheckListStatus::render() {
    Control::render();
    const auto currentState = parentChecklist_->getCurrentState();
    if (currentState == CheckListItem::CHECKLIST_ITEM_STATE::OPEN) {
        return;
    }
    const auto color = parentChecklist_->getItemStateColor();
    const auto displayText = currentState == CheckListItem::CHECKLIST_ITEM_STATE::OVERRIDDEN
                                 ? "CHECKLIST OVERRIDDEN"
                                 : "CHECKLIST COMPLETED";
    nvgFillColor(getContext(), color);
    nvgBeginPath(getContext());
    {
        nvgRoundedRect(getContext(), 0, 0, position.getWidth(), position.getHeight(), position.getHeight() / 2);
        nvgFill(getContext());
    }
    nvgClosePath(getContext());
    nvgFontFace(getContext(), "heavy-fmc");
    nvgFontSize(getContext(), 24);
    nvgFillColor(getContext(), Tools::Colors::white);
    nvgTextAlign(getContext(), NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
    nvgBeginPath(getContext());
    {
        nvgText(getContext(), position.getWidth() / 2, position.getHeight() / 2, displayText, nullptr);
        nvgFill(getContext());
    }
    nvgClosePath(getContext());
}
