#include "EICASGauge.h"

using Tools::Colors;

void EICASGauge::render() {
	Control::render();
}

void EICASGauge::setupControl() {
	Control::setupControl();
	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data;
		return true;
	});
}

auto EICASGauge::drawCircle(double origin_x, double origin_y) -> void {
	nvgStrokeWidth(this->getContext(), 3.0f);
	nvgFillColor(this->getContext(), Colors::black);
	nvgBeginPath(this->getContext());
	fwsColorHandler(10, 20);
	{
		nvgArc(this->getContext(), origin_x, origin_y, this->radius, 0, this->max_angle, NVG_CW);
		nvgStroke(this->getContext());
	}
	nvgFill(this->getContext());
}

auto EICASGauge::drawDataBox(double x_pos, double y_pos, double width, double height) -> void {}
auto EICASGauge::drawLabel(std::string label) -> void {}
auto EICASGauge::drawRedLine() -> void {}
auto EICASGauge::drawDeltaIndicator() -> void {}
auto EICASGauge::fwsColorHandler(double advisory_threshold, double warning_threshold) -> void {

	auto colors = Colors::white;

	if(this->data >= advisory_threshold && this->data <= warning_threshold) {
		colors = Colors::advisoryAmber;
	}

	else if(this->data > warning_threshold) {
		colors = Colors::warningRed;
	}

	return nvgStrokeColor(this->getContext(), colors);
}

