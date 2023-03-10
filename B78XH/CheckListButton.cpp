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
    nvgTextAlign(getContext(), NVG_ALIGN_CENTER | NVG_ALIGN_TOP);
    nvgBeginPath(getContext());
    {
        nvgTextBoxBounds(getContext(), 0, position.height / 2, position.width, displayText_.c_str(), nullptr, textBounds_);
        const auto boundsHeight = textBounds_[3] - textBounds_[1];
        nvgTextBox(getContext(), 0, position.height / 2 - boundsHeight / 2 + CheckListDimensions::BORDER_WIDTH, position.width, displayText_.c_str(), nullptr);
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
