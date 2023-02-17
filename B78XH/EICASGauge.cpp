#include "EICASGauge.h"

using Tools::Colors;

void EICASGauge::setupControl() {
	Control::setupControl();
}

auto EICASGauge::drawCircle(double data) -> void {

	// Outline 
	nvgStrokeWidth(getContext(), 4.0f);
	nvgFillColor(getContext(), Colors::black);
	nvgStrokeColor(getContext(), fwsColorHandler(data, Colors::white));
	nvgBeginPath(getContext());
	{
		nvgArc(getContext(), x, y, radius, 0, max_angle, NVG_CW);
		nvgStroke(getContext());
		nvgFill(getContext());
	}

	// red line
	double x_distance_to_edge = radius * std::cos(max_angle);
	double y_distance_to_edge = radius * std::sin(max_angle);

	double const line_length = 14;

	double line_x_end = x_distance_to_edge + line_length * std::cos(max_angle);
	double line_y_end = y_distance_to_edge + line_length * std::sin(max_angle);


	nvgStrokeWidth(getContext(), 2.5f);
	nvgStrokeColor(getContext(), Colors::red);
	nvgBeginPath(getContext());
	{
		nvgMoveTo(getContext(), x_distance_to_edge, y_distance_to_edge);
		nvgLineTo(getContext(), line_x_end, line_y_end);
		nvgStroke(getContext());
	}

}

auto EICASGauge::drawArc(double data, double max) -> void {

	double angle = (max_angle / max) * data;

	nvgFillColor(getContext(), fwsColorHandler(data, Colors::cduButtonGray));
	nvgBeginPath(getContext());
	{
		nvgMoveTo(getContext(), x, y);
		nvgArc(getContext(), x, y, radius, 0, angle, NVG_CW);
		nvgFill(getContext());
	}

	nvgStrokeColor(getContext(), fwsColorHandler(data, Colors::white));
	nvgStrokeWidth(getContext(), 3.0f);
	nvgBeginPath(getContext());
	{
		nvgMoveTo(getContext(), x, y);
		nvgLineTo(getContext(), x + 60 * std::cos(angle), y + 60 * std::sin(angle));
		nvgStroke(getContext());
	}


}

auto EICASGauge::drawHeader(double data) -> void {
	auto header = Tools::formatToFixed(data, 1);

	nvgFillColor(getContext(), Colors::greenPure);
	nvgFontFace(getContext(), "heavy-fmc");
	nvgFontSize(getContext(), 19.0f);
	nvgTextAlign(getContext(), NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
	nvgBeginPath(getContext());
	{
		nvgText(getContext(), 0, 27, header.c_str(), nullptr);
	}
}

auto EICASGauge::drawHeader(std::string header) -> void {

	nvgFillColor(getContext(), Colors::greenPure);
	nvgFontFace(getContext(), "heavy-fmc");
	nvgFontSize(getContext(), 19.0f);
	nvgTextAlign(getContext(), NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
	nvgBeginPath(getContext());
	{
		nvgText(getContext(), 0, 27, header.c_str(), nullptr);
	}
}
auto EICASGauge::drawDataBox(double width, double height, double data, int decimals, Side side) -> void {

	bool eng_cutoff = Simplane::aircraft::systems::fuel::switches::eng1_cutoff();;

	// set box position relative to drawCircle() 
	double box_x = x - 2;
	double box_y = y - 35;

	if(side == RIGHT) {
		eng_cutoff = Simplane::aircraft::systems::fuel::switches::eng2_cutoff();
	}

	nvgFontFace(getContext(), "heavy-fmc");
	nvgFillColor(getContext(), fwsColorHandler(data, Colors::white));
	nvgStrokeColor(getContext(), fwsColorHandler(data, Colors::white));
	nvgStrokeWidth(getContext(), 2.5f);
	nvgFontSize(getContext(), 19.0f);
	nvgTextAlign(getContext(), NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
	nvgBeginPath(getContext());
	{
		if (eng_cutoff == true || data > this->render_cutoff) {
			nvgText(getContext(), box_x+6, box_y+6, Tools::formatToFixed(data, decimals).c_str(), nullptr);
		}
		nvgRect(getContext(), box_x, box_y, width, height);
		nvgStroke(getContext());
	}
}

auto EICASGauge::fwsColorHandler(double data, NVGcolor defaultColor) -> NVGcolor {

	NVGcolor color = defaultColor;

	if(data >= this->advisory_threshold && data <= this->warning_threshold) {
		color = Colors::advisoryAmber;
	}

	if(data > this->warning_threshold) {
		color = Colors::warningRed;
	}

	return color;
}

auto EICASGauge::drawLabel(std::string label) -> void {}
auto EICASGauge::drawRedLine() -> void {}
auto EICASGauge::drawDeltaIndicator() -> void {}