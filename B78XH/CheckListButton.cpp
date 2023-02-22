#include "CheckListButton.h"

void CheckListButton::render() {
    Control::render();
    drawButtonBorder(Tools::Colors::cduButtonGray,
        Tools::Colors::cduButtonBorderTopGray,
        Tools::Colors::cduButtonBorderRightGray,
        Tools::Colors::cduButtonBorderBottomGray,
        Tools::Colors::cduButtonBorderLeftGray);

    nvgFontFace(getContext(), "heavy-fmc");
    nvgFontSize(getContext(), 24.0f);
    nvgFillColor(getContext(), Tools::Colors::white);
    nvgTextAlign(getContext(), NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
    nvgBeginPath(getContext());
    {
        nvgText(getContext(), position.width / 2, position.height / 2, displayText_.c_str(), nullptr);
        nvgFill(getContext());
    }
    nvgClosePath(getContext());
    
    if (shouldTriggerEvent()) {
        Console::log("Checklist button triggered {}", displayText_.c_str());
        if(invoke_ != nullptr) {
            invoke_();
        }
    }
}
