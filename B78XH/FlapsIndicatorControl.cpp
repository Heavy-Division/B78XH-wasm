#include "FlapsIndicatorControl.h"
#include "Simplane.h"
#include "Tools/Console.h"
#include "Tools/Tools.h"


using Tools::Colors;

void FlapsIndicatorControl::render() {
	Control::render();
	
	nvgStrokeColor(getContext(), Colors::white);
	nvgStrokeWidth(getContext(), 2.0f);
	nvgBeginPath(getContext());
	{
		nvgRect(getContext(), 0, 0, 15, 135);
		nvgStroke(getContext());
	}

	nvgFontFace(getContext(), "heavy-fmc");
	nvgFillColor(getContext(), Colors::lightBlue);
	nvgFontSize(getContext(), 15.0f);
	nvgBeginPath(getContext());
	{
		nvgText(getContext(), -16, 40, "F", nullptr);
		nvgText(getContext(), -16, 55, "L", nullptr);
		nvgText(getContext(), -16, 70, "A", nullptr);
		nvgText(getContext(), -16, 85, "P", nullptr);
		nvgText(getContext(), -16, 100, "S", nullptr);
		nvgFill(getContext());
	}

	Console::log("Flaps: {}", Simplane::aircraft::state::flapsHandleIndex());
}

void FlapsIndicatorControl::setupControl() {
	Control::setupControl();
}