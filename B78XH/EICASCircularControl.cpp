#include "EICASCircularControl.h"

using Tools::Colors;

auto EICASCircularControl::drawCircle() -> void {

	// Outline
	nvgStrokeWidth(getContext(), 1.5f);
	nvgStrokeColor(getContext(), fwsColorHandler(Colors::white));
	nvgBeginPath(getContext());
	{
		nvgArc(getContext(), x, y, radius, 0, max_angle, NVG_CW);
		nvgStroke(getContext());
	}

	// operating limit line
	double line_x_begin = radius * std::cos(max_angle);
	double line_y_begin = radius * std::sin(max_angle);

	double const line_length = 14;

	double line_x_end = line_x_begin + line_length * std::cos(max_angle);
	double line_y_end = line_y_begin + line_length * std::sin(max_angle);

	nvgStrokeWidth(getContext(), 2.5f);
	nvgStrokeColor(getContext(), Colors::red);
	nvgBeginPath(getContext());
	{
		nvgMoveTo(getContext(), line_x_begin, line_y_begin);
		nvgLineTo(getContext(), line_x_end, line_y_end);
		nvgStroke(getContext());
	}

}

auto EICASCircularControl::drawArc(double max, bool momentaryDifference) -> void {

	double angle = (max_angle / max) * data;

	nvgFillColor(getContext(), fwsColorHandler(Colors::cduButtonGray));
	nvgBeginPath(getContext());
	{
		nvgMoveTo(getContext(), x, y);
		nvgArc(getContext(), x, y, radius + 1, 0, angle, NVG_CW);
		nvgFill(getContext());
	}


	double needle_length = radius;
	double data_difference = std::fabs(commanded_data - data);

	if (momentaryDifference) {
		if (data_difference > 1.0) {
			needle_length = radius + 10;
		}
	}

	double needle_end_x = needle_length * std::cos(angle);
	double needle_end_y = needle_length * std::sin(angle);

	double target_angle = (max_angle / max) * commanded_data;

	double diff_begin_x = radius * std::cos(target_angle);
	double diff_begin_y = radius * std::sin(target_angle);

	double diff_end_x = (10 + radius) * std::cos(target_angle);
	double diff_end_y = (10 + radius) * std::sin(target_angle);

	auto arc = NVG_CW;
	if(commanded_data < data) {
		arc = NVG_CCW;
	}

	// momentary difference
	// TODO: (Failure handling) if data doesn't approach commanded data set arc to amber

	if (momentaryDifference) {
		if (data_difference > 1.0) {
			nvgStrokeColor(getContext(), Colors::white);
			nvgBeginPath(getContext());
			{
				nvgMoveTo(getContext(), x + diff_begin_x, y + diff_begin_y);
				nvgLineTo(getContext(), x + diff_end_x, y + diff_end_y);
				nvgStroke(getContext());
			}

			nvgStrokeWidth(getContext(), 2.0f);
			nvgStrokeColor(getContext(), Colors::white);
			nvgBeginPath(getContext());
			{
				nvgArc(getContext(), x, y, 10 + radius, angle, target_angle, arc);
				nvgStroke(getContext());

			}
		}
	}

	// Gauge needle
	nvgStrokeColor(getContext(), fwsColorHandler(Colors::white));
	nvgStrokeWidth(getContext(), 3.0f);
	nvgBeginPath(getContext());
	{
		nvgMoveTo(getContext(), x, y);
		nvgLineTo(getContext(), x + needle_end_x, y + needle_end_y);
		nvgStroke(getContext());
	}


}

auto EICASCircularControl::drawHeader(double data) -> void {
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

auto EICASCircularControl::drawHeader(std::string header) -> void {

	nvgFillColor(getContext(), Colors::greenPure);
	nvgFontFace(getContext(), "heavy-fmc");
	nvgFontSize(getContext(), 19.0f);
	nvgTextAlign(getContext(), NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
	nvgBeginPath(getContext());
	{
		nvgText(getContext(), 0, 27, header.c_str(), nullptr);
	}
}

