#include "CheckListLineSingle.h"

void CheckListLineSingle::render() {
    CheckListLine::render();

    nvgFillColor(getContext(), getItemStateColor());
    nvgFontFace(getContext(), "roboto");
    nvgFontSize(getContext(), 38.0f);
    nvgTextAlign(getContext(), NVG_ALIGN_MIDDLE | NVG_ALIGN_LEFT);
    nvgBeginPath(getContext());
    {
        nvgText(getContext(), CheckListDimensions::INNER_TEXT_X_START, position.height / 2, textDisplayed_.c_str(),
                nullptr);
    }
    nvgClosePath(getContext());
    nvgFill(getContext());
}
