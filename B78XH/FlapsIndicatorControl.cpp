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

	nvgFillColor(getContext(), Colors::white);
	nvgBeginPath(getContext());
	{
		nvgRect(getContext(), 0, 0, 15, flapsPercent * 135);
		nvgFill(getContext());
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

	Console::log("Index: {}", this->flapsAngleIndex());
	Console::log("Pct: {}", this->flapsPercent);

	drawFlapsAngleIndex();

}

void FlapsIndicatorControl::setupControl() {
	Control::setupControl();

	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		// TODO: Not based on individual flaps pct, will need to update with new LVar
		this->flapsPercent = Simplane::aircraft::flight_surfaces::trailingEdgeFlapsLeftPercent();
		return true;
	});
}

int FlapsIndicatorControl::flapsAngleIndex() {
	int index = static_cast<int>(Simplane::aircraft::state::flapsHandleIndex());

	switch (index) {
		case 0:
			return 0;

		case 1:
			return 1;

		case 2:
			return 5;

		case 3:
			return 10;

		case 4:
			return 15;

		case 5:
			return 17;

		case 6:
			return 18;

		case 7:
			return 20;

		case 8:
			return 25;

		case 9:
			return 30;

		default:
			return 0;
	}
}

void FlapsIndicatorControl::drawFlapsAngleIndex() {

	double line_y_offset = flapsIndexIndicatorHeight() * 135;

	nvgStrokeColor(getContext(), Colors::greenPure);
	nvgStrokeWidth(getContext(), 2.0f);
	nvgBeginPath(getContext());
	{
		nvgMoveTo(getContext(), -5, line_y_offset);
		nvgLineTo(getContext(), 20, line_y_offset);
		nvgStroke(getContext());
	}

	nvgFillColor(getContext(), Colors::greenPure);
	nvgFontFace(getContext(), "heavy-fmc");
	nvgFontSize(getContext(), 13.0f);
	nvgBeginPath(getContext());
	{
		nvgText(getContext(), 23, line_y_offset + 5, std::to_string(flapsAngleIndex()).c_str(), nullptr);
		nvgFill(getContext());
	}
}

double FlapsIndicatorControl::flapsIndexIndicatorHeight() {
	int index = static_cast<int>(Simplane::aircraft::state::flapsHandleIndex());

	switch (index) {
	case 0:
		return 0;

	case 1:
		return 1.0 / 30;

	case 2:
		return 3.0 / 30;

	case 3:
		return 5.0 / 30;

	case 4:
		return 15.0 / 30;

	case 5:
		return 17.0 / 30;

	case 6:
		return 18.0 / 30;

	case 7:
		return 20.0 / 30;

	case 8:
		return 22.0 / 30;

	case 9:
		return 30.0 / 30;

	default:
		return 0;
	}
}
