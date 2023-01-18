#include "MFDControl.h"

#include "Tools/Console.h"
#include "Tools/Tools.h"


using Colors = Tools::Colors;

void MFDControl::render() {
	Control::render();
	nvgFillColor(this->getContext(), Colors::red);
	nvgFontSize(this->getContext(), 90.0f);
	nvgFontFace(this->getContext(), "heavy-fmc");
	nvgTextAlign(this->getContext(), NVG_ALIGN_CENTER | NVG_ALIGN_TOP);
	nvgBeginPath(this->getContext());
	{
		nvgText(this->getContext(), 10, 10, "Hello B78XH!", nullptr);
	}
	nvgFill(this->getContext());
}

void MFDControl::setupControl() {
	Control::setupControl();
}
