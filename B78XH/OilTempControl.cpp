#include "OilTempControl.h"
#include "Simplane.h"
#include "Tools/Console.h"
#include "Tools/Tools.h"

using Tools::Colors;

void OilTempControl::render() {
	// TODO: Understand and implement advisory (orange lines) logic 
	Control::render();
	double oilTemp_1 = Simplane::aircraft::systems::powerplant::engine_1::oilTemperature();
	double oilTemp_2 = Simplane::aircraft::systems::powerplant::engine_2::oilTemperature();

	nvgStrokeColor(this->getContext(), Colors::white);
	nvgFillColor(this->getContext(), Colors::white);
	nvgStrokeWidth(this->getContext(), 2.5f);
	nvgTextAlign(this->getContext(), NVG_ALIGN_RIGHT | NVG_ALIGN_TOP);
	nvgFontFace(this->getContext(), "heavy-fmc");
	nvgFontSize(this->getContext(), 24.0f);

	nvgBeginPath(this->getContext());
	{
		nvgRect(this->getContext(), 740, 645, 45, 30);
		if (Simplane::aircraft::systems::fuel::switches::eng1_cutoff() == true || oilTemp_1 > 1.) {
			nvgText(this->getContext(), 780, 650, fmt::format("{:.0f}", oilTemp_1).c_str(), nullptr);
		}
		nvgStroke(this->getContext());
	}

	nvgBeginPath(this->getContext());
	{
		nvgRect(this->getContext(), 905, 645, 45, 30);
		nvgText(this->getContext(), 945, 650, fmt::format("{:.0f}", oilTemp_2).c_str(), nullptr);
		nvgStroke(this->getContext());
		
	}

	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 795, 691);
		nvgLineTo(this->getContext(), 795, 624);
		nvgStroke(this->getContext());
	}

	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 895, 691);
		nvgLineTo(this->getContext(), 895, 624);
		nvgStroke(this->getContext());
	}

	nvgStrokeColor(this->getContext(), Colors::red);
	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 789, 691);
		nvgLineTo(this->getContext(), 807, 691);
		nvgStroke(this->getContext());
	}

	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 789, 624);
		nvgLineTo(this->getContext(), 807, 624);
		nvgStroke(this->getContext());
	}

	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 901, 691);
		nvgLineTo(this->getContext(), 883, 691);
		nvgStroke(this->getContext());
	}

	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 901, 624);
		nvgLineTo(this->getContext(), 883, 624);
		nvgStroke(this->getContext());
	}

	// TODO: refactor to generic gauge & confirm max value
	double maxOilTemp = 225.;
	double gaugeHeight = 67;
	double gaugeConstant = -gaugeHeight / maxOilTemp;
	
	double oilTemp1Gauge = oilTemp_1 * gaugeConstant;

	nvgFillColor(this->getContext(), Colors::white);
	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 799, 691 + oilTemp1Gauge);
		nvgLineTo(this->getContext(), 813, 697 + oilTemp1Gauge);
		nvgLineTo(this->getContext(), 813, 685 + oilTemp1Gauge);
		nvgClosePath(this->getContext());
		nvgFill(this->getContext());
	}

	double oilTemp2Gauge = oilTemp_2 * gaugeConstant;

	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 891, 691 + oilTemp2Gauge);
		nvgLineTo(this->getContext(), 879, 697 + oilTemp2Gauge);
		nvgLineTo(this->getContext(), 879, 685 + oilTemp2Gauge);
		nvgClosePath(this->getContext());
		nvgFill(this->getContext());
	}

	nvgFillColor(this->getContext(), Colors::cyan);
	nvgFontSize(this->getContext(), 17.0f);
	nvgBeginPath(this->getContext());
	// TODO: clean this up.....
	{
		nvgText(this->getContext(), 795 + 13 + (895 - 795) / 2, 624 + (-17) + (691 - 624) / 2, "OIL", nullptr);
		nvgText(this->getContext(), 795 + 19 + (895 - 795) / 2, 624 + (691 - 624) / 2, "TEMP", nullptr);
		nvgFill(this->getContext());
	}
	
}

void OilTempControl::setupControl() {
	Control::setupControl();
}
