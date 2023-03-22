#include "LineSeparatorControl.h"

#include "Tools/Console.h"
#include "Tools/Tools.h"


void LineSeparatorControl::render() {
	Control::render();

    nvgSave(this->getContext());
    {
        nvgStrokeColor(this->getContext(), Tools::Colors::white);
        nvgStrokeWidth(this->getContext(), 4.0f);
        nvgBeginPath(this->getContext());
        {
            nvgMoveTo(this->getContext(), 700, 0);
            nvgLineTo(this->getContext(), 700, 1050);
        }
        nvgClosePath(this->getContext());
        nvgStroke(this->getContext());
    }
    nvgResetTransform(this->getContext());
}

void LineSeparatorControl::setupControl() {
	Control::setupControl();
}
