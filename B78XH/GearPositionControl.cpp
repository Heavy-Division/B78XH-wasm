#include "GearPositionControl.h"


void GearPositionControl::render() {
	EICASBaseControl::render();
	nvgFontFace(getContext(), "heavy-fmc");
	nvgFontSize(getContext(), 18.0f);
	nvgTextAlign(getContext(), NVG_ALIGN_CENTER);
	nvgFillColor(getContext(), Tools::Colors::white);
	nvgBeginPath(getContext());
	{
		nvgText(getContext(), x, y, "GEAR", nullptr);
		nvgFill(getContext());
	}
}

