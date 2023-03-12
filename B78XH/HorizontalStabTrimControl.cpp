#include "HorizontalStabTrimControl.h"

void HorizontalStabTrimControl::render() {
	EICASBaseControl::render();

	drawLineGauge(0, 0, 100, NONE);
}

void HorizontalStabTrimControl::setupControl() {
	EICASBaseControl::setupControl();

	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft

		return true;
	});
}

void HorizontalStabTrimControl::drawDataBox(double width, double height, int decimals, float fontSize) {
	EICASBaseControl::drawDataBox(width, height, decimals, fontSize);
	nvgStrokeColor(getContext(), fwsColorHandler(Tools::Colors::greenPure));
}