#include "OilPressControl.h"
#include "Simplane.h"
#include "Tools/Tools.h"

using Tools::Colors;

void OilPressControl::render() {
	Control::render();

	double eng1_oilPress = Simplane::aircraft::systems::powerplant::engine_1::oilPressure();
	double eng2_oilPress = Simplane::aircraft::systems::powerplant::engine_2::oilPressure();



	nvgStrokeColor(this->getContext(), Colors::white);
	nvgFillColor(this->getContext(), Colors::white);
	nvgStrokeWidth(this->getContext(), 2.5f);
	nvgTextAlign(this->getContext(), NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
	nvgFontFace(this->getContext(), "heavy-fmc");
	nvgFontSize(this->getContext(), 25.0f);

	nvgBeginPath(this->getContext());
	{
		nvgRect(this->getContext(), 745, 545, 40, 30);
		if (Simplane::aircraft::systems::fuel::switches::eng1_cutoff() == true || eng1_oilPress > 20.) {
			nvgText(this->getContext(), 755, 550, fmt::format("{:.0f}", eng1_oilPress).c_str(), nullptr);
		}
		nvgStroke(this->getContext());
	}

	nvgFillColor(this->getContext(), Colors::cyan);
	nvgFontSize(this->getContext(), 17.0f);
	nvgBeginPath(this->getContext());
	{
		nvgText(this->getContext(), 834, 546, "OIL", nullptr);
		nvgText(this->getContext(), 825, 566, "PRESS", nullptr);
	}

	nvgFontSize(this->getContext(), 25.0f);
	nvgFillColor(this->getContext(), Colors::white);
	nvgBeginPath(this->getContext());
	{
		nvgRect(this->getContext(), 905, 545, 40, 30);
		if (Simplane::aircraft::systems::fuel::switches::eng2_cutoff() == true || eng2_oilPress > 20.) {
			nvgText(this->getContext(), 915, 550, fmt::format("{:.0f}", eng2_oilPress).c_str(), nullptr);
		}
		nvgStroke(this->getContext());
	}

	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 795, 595);
		nvgLineTo(this->getContext(), 795, 523);
		nvgStroke(this->getContext());
	}

	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 895, 595);
		nvgLineTo(this->getContext(), 895, 523);
		nvgStroke(this->getContext());
	}


	nvgStrokeColor(this->getContext(), Colors::red);
	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 789, 595);
		nvgLineTo(this->getContext(), 807, 595);
		nvgStroke(this->getContext());
	}

	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 901, 595);
		nvgLineTo(this->getContext(), 883, 595);
		nvgStroke(this->getContext());
	}



	double oilPressGauge1 = eng1_oilPress * (523 - 592) / 145;

	nvgFillColor(this->getContext(), Colors::white);
	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 795, 595 + oilPressGauge1);
		nvgLineTo(this->getContext(), 809, 589 + oilPressGauge1);
		nvgLineTo(this->getContext(), 809, 601 + oilPressGauge1);
		nvgClosePath(this->getContext());
		nvgFill(this->getContext());
	}

	double oilPressGauge2 = eng2_oilPress * (523 - 592) / 145;
	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 795, 595 + oilPressGauge2);
		nvgLineTo(this->getContext(), 809, 589 + oilPressGauge2);
		nvgLineTo(this->getContext(), 809, 601 + oilPressGauge2);
		nvgClosePath(this->getContext());
		nvgFill(this->getContext());
	}


}

void OilPressControl::setupControl() {
	Control::setupControl();
}
