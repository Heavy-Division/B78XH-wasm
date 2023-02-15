#include "CheckListButton.h"

void CheckListButton::render() {
    Control::render();
    drawButtonBorder();

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

auto CheckListButton::drawButtonBorder() -> void {
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
        nvgLineTo(getContext(), left + width, top);
        nvgLineTo(getContext(), left + width - CheckListDimensions::BORDER_WIDTH,
                  top + CheckListDimensions::BORDER_WIDTH);
        nvgLineTo(getContext(), left + CheckListDimensions::BORDER_WIDTH, top + CheckListDimensions::BORDER_WIDTH);
        nvgLineTo(getContext(), left, top);
    }
    nvgClosePath(getContext());
    nvgFill(getContext());

    // right
    nvgFillColor(getContext(), Tools::Colors::cduButtonBorderRightGray);
    nvgBeginPath(getContext());
    {
        nvgMoveTo(getContext(), left + width, top);
        nvgLineTo(getContext(), left + width, top + height + 1);
        nvgLineTo(getContext(), left + width - CheckListDimensions::BORDER_WIDTH,
                  top + height - CheckListDimensions::BORDER_WIDTH + 1);
        nvgLineTo(getContext(), left + width - CheckListDimensions::BORDER_WIDTH,
                  top + CheckListDimensions::BORDER_WIDTH);
        nvgLineTo(getContext(), left + width, top);
    }
    nvgClosePath(getContext());
    nvgFill(getContext());

    // bottom
    nvgFillColor(getContext(), Tools::Colors::cduButtonBorderBottomGray);
    nvgBeginPath(getContext());
    {
        nvgMoveTo(getContext(), left, top + height);
        nvgLineTo(getContext(), left + width, top + height);
        nvgLineTo(getContext(), left + width - CheckListDimensions::BORDER_WIDTH,
                  top + height - CheckListDimensions::BORDER_WIDTH);
        nvgLineTo(getContext(), left + CheckListDimensions::BORDER_WIDTH,
                  top + height - CheckListDimensions::BORDER_WIDTH);
        nvgLineTo(getContext(), left, top + height);
    }
    nvgClosePath(getContext());
    nvgFill(getContext());

    // left
    nvgFillColor(getContext(), Tools::Colors::cduButtonBorderLeftGray);
    nvgBeginPath(getContext());
    {
        nvgMoveTo(getContext(), left, top);
        nvgLineTo(getContext(), left + CheckListDimensions::BORDER_WIDTH, top + CheckListDimensions::BORDER_WIDTH);
        nvgLineTo(getContext(), left + CheckListDimensions::BORDER_WIDTH,
                  top + height - CheckListDimensions::BORDER_WIDTH);
        nvgLineTo(getContext(), left, top + height);
        nvgLineTo(getContext(), left, top);
    }
    nvgClosePath(getContext());
    nvgFill(getContext());
}
