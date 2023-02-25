#include "CheckListStatus.h"
#include "CheckList.h"

void CheckListStatus::render() {
    Control::render();
    const auto color = parentChecklist_->getItemStateColor();
    const auto displayText = parentChecklist_->getCurrentState() == CheckListItem::CHECKLIST_ITEM_STATE::OVERRIDDEN
                                 ? "CHECKLIST OVERRIDDEN"
                                 : "CHECKLIST COMPLETE";
    nvgFillColor(getContext(), color);
    nvgBeginPath(getContext());
    {
        nvgRoundedRect(getContext(), 0, 0, position.getWidth(), position.getHeight(), position.getHeight() / 2);
        nvgFill(getContext());
    }
    nvgClosePath(getContext());
    nvgFontFace(getContext(), "heavy-mfc");
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
