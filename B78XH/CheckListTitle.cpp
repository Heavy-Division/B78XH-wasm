#include "CheckListTitle.h"

void CheckListTitle::render() {
    Control::render();

    constexpr float triangleSize = 24;
    constexpr float halfTriangleSize = triangleSize / 2;
    const float halfHeight = position.height / 2;
    const float halfWidth = position.width / 2;
    nvgFontFace(getContext(), "heavy-fmc");
    nvgFontSize(getContext(), 28.0f);
    nvgFillColor(getContext(), type_ == TITLE_TYPE::NON_NORMAL_CHECKLIST ? Tools::Colors::amber : Tools::Colors::white);
    nvgTextAlign(getContext(), NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
    nvgBeginPath(getContext());
    {
        nvgText(getContext(), halfWidth, halfHeight, titleText_.c_str(), nullptr);
        nvgFill(getContext());
    }
    nvgClosePath(getContext());
    if(type_ != TITLE_TYPE::MENU) {
        // draw front triangle
        nvgBeginPath(getContext());
        {
            nvgMoveTo(getContext(), 0, halfHeight - halfTriangleSize);
            nvgLineTo(getContext(), triangleSize, halfHeight);
            nvgLineTo(getContext(), 0, halfHeight + halfTriangleSize);
            nvgLineTo(getContext(), 0, halfHeight - halfTriangleSize);
            nvgFill(getContext());
        }
        nvgClosePath(getContext());

        // draw end triangle
        nvgBeginPath(getContext());
        {
            nvgMoveTo(getContext(), position.width, halfHeight - halfTriangleSize);
            nvgLineTo(getContext(), position.width - triangleSize, halfHeight);
            nvgLineTo(getContext(), position.width, halfHeight + halfTriangleSize);
            nvgLineTo(getContext(), position.width, halfHeight - halfTriangleSize);
            nvgFill(getContext());
        }
        nvgClosePath(getContext());
    }
}
