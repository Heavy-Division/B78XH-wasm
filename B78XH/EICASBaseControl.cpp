#include "EICASBaseControl.h"

using Tools::Colors;

auto EICASBaseControl::drawLineGauge(double x_pos, double y_pos, double line_height, MaxLines red_lines) -> void {

	double const gauge_constant = line_height / max;

	double const yOffset = data * gauge_constant;

	// line 
	nvgStrokeColor(getContext(), Colors::white);
	nvgStrokeWidth(getContext(), 2.0f);
	nvgBeginPath(getContext());
	{
		nvgMoveTo(getContext(), x_pos, y_pos);
		nvgLineTo(getContext(), x_pos, y_pos - line_height);
		nvgStroke(getContext());
	}


	nvgFillColor(getContext(), Colors::white);
	if (fuel_valve_connection == RIGHT) {

		drawRedLines(x_pos, y_pos, line_height, red_lines);

		// indicator
		nvgStrokeColor(getContext(), Colors::white);
		nvgBeginPath(this->getContext());
		{
			nvgMoveTo(this->getContext(), x_pos - 4, y_pos - yOffset);
			nvgLineTo(this->getContext(), x_pos - 16, y_pos - (6 + yOffset));
			nvgLineTo(this->getContext(), x_pos - 16, y_pos - (yOffset - 6));
			nvgClosePath(this->getContext());
			nvgStroke(getContext());
			nvgFill(this->getContext());
		}



	}

	if (fuel_valve_connection == LEFT) {

		drawRedLines(x_pos, y_pos, line_height, red_lines);

		nvgStrokeColor(getContext(), Colors::white);
		nvgBeginPath(this->getContext());
		{
			nvgMoveTo(this->getContext(), x_pos + 4, y_pos - yOffset);
			nvgLineTo(this->getContext(), x_pos + 16, y_pos - (6 + yOffset));
			nvgLineTo(this->getContext(), x_pos + 16, y_pos - (yOffset - 6));
			nvgClosePath(this->getContext());
			nvgStroke(getContext());
			nvgFill(this->getContext());
		}

	}
}

auto EICASBaseControl::drawDataBox(double width, double height, int decimals, float fontSize) -> void {

	bool eng_cutoff = Simplane::aircraft::systems::fuel::valves::eng1_cutoff();;

	// set box position relative to drawCircle() 
	double box_x = x - 2;
	double box_y = y - 35;

	if (fuel_valve_connection == RIGHT) {
		eng_cutoff = Simplane::aircraft::systems::fuel::valves::eng2_cutoff();
	}

	nvgFontFace(getContext(), "heavy-fmc");
	nvgFillColor(getContext(), fwsColorHandler(Colors::white));
	nvgStrokeColor(getContext(), fwsColorHandler(Colors::white));
	nvgStrokeWidth(getContext(), 1.5f);
	nvgFontSize(getContext(), fontSize);
	nvgTextAlign(getContext(), NVG_ALIGN_LEFT | NVG_ALIGN_TOP);

	nvgBeginPath(getContext());
	{

		if (!render_on_start) {
			if (eng_cutoff == true || data > this->render_cutoff) {
				nvgText(getContext(), box_x + 5, box_y + 4, Tools::formatToFixed(data, decimals).c_str(), nullptr);
			}
		}

		if (render_on_start) {
			nvgText(getContext(), box_x + 5, box_y + 4, Tools::formatToFixed(data, decimals).c_str(), nullptr);
		}

		nvgRect(getContext(), box_x, box_y, width, height);
		nvgStroke(getContext());
	}

}

auto EICASBaseControl::fwsColorHandler(NVGcolor defaultColor) -> NVGcolor {

	NVGcolor color = defaultColor;

	if (data >= this->advisory_threshold && data <= this->warning_threshold) {
		color = Colors::advisoryAmber;
	}

	if (data > this->warning_threshold) {
		color = Colors::warningRed;
	}

	return color;
}

void EICASBaseControl::render() {
	Control::render();
}

void EICASBaseControl::setupControl() {
	Control::setupControl();
}

auto EICASBaseControl::getGaugeType() -> GaugeType {
	return this->gauge_type;
}

auto EICASBaseControl::drawRedLines(double x, double y, double line_height, MaxLines line_type) -> void {

	nvgStrokeColor(getContext(), Colors::red);

	auto side = this->fuel_valve_connection;

	switch (line_type) {
		case BOTTOM:

			if (side == LEFT) {
				nvgBeginPath(getContext());
				{
					nvgMoveTo(getContext(), x + 14, y);
					nvgLineTo(getContext(), x - 8, y);
					nvgStroke(getContext());
				}
			} else if(side == RIGHT) {
				nvgBeginPath(getContext());
				{
					nvgMoveTo(getContext(), x - 14, y);
					nvgLineTo(getContext(), x + 8, y);
					nvgStroke(getContext());
				}
			}
			break;

		case TOP:

			if (side == LEFT) {
				nvgBeginPath(getContext());
				{
					nvgMoveTo(getContext(), x + 14, y - line_height);
					nvgLineTo(getContext(), x - 8, y - line_height);
					nvgStroke(getContext());
				}
			}
			else if (side == RIGHT) {
				nvgBeginPath(getContext());
				{
					nvgMoveTo(getContext(), x - 14, y - line_height);
					nvgLineTo(getContext(), x + 8, y - line_height);;
					nvgStroke(getContext());
				}
			}
			break;

		case NONE:

			break;

		case DUAL: // gauge on RR option

			nvgBeginPath(getContext());
			{
				nvgMoveTo(getContext(), x + 14, y);
				nvgLineTo(getContext(), x - 8, y);
				nvgStroke(getContext());
			}

			nvgBeginPath(getContext());
			{
				nvgMoveTo(getContext(), x + 14, y - line_height);
				nvgLineTo(getContext(), x - 8, y - line_height);
				nvgStroke(getContext());
			}
			break;

			default:

				return;
	}
}

