#include "LineSeparatorControl.h"

#include "Tools/Console.h"
#include "Tools/Tools.h"


void LineSeparatorControl::render() {
	Control::render();

    // nvgSave(this->getContext());
    {
        Console::log("test");
        nvgStrokeColor(this->getContext(), Tools::Colors::white);
        nvgStrokeWidth(this->getContext(), 4.0f);
        nvgBeginPath(this->getContext());
        {
            // nvgMoveTo(this->getContext(), 80, 0);
            nvgLineTo(this->getContext(), 84, 0);
            nvgLineTo(this->getContext(), 84, 465);
        }
        nvgClosePath(this->getContext());
        nvgStroke(this->getContext());
    }
    // nvgRestore(this->getContext());
    nvgResetTransform(this->getContext());
}

void LineSeparatorControl::setupControl() {
	Control::setupControl();
}
