#include "HelloWorldControl.h"
#include "Tools/Tools.h"

using Colors = Tools::Colors;

void HelloWorldControl::render() {
	Control::render();
	nvgFillColor(this->getContext(), Colors::red);
	nvgFontSize(this->getContext(), 90.0f);
	nvgFontFace(this->getContext(), "heavy-fmc");
	nvgTextAlign(this->getContext(), NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
	nvgBeginPath(this->getContext());
	{
		nvgText(this->getContext(), 10, 10, "Hello B78XH!", nullptr);
	}
	nvgFill(this->getContext());
}

void HelloWorldControl::setupControl() {
	Control::setupControl();
}
