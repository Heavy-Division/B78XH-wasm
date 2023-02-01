#include "EngineVibrationControl.h"

#include "Tools/Tools.h"

using Tools::Colors;
using Tools::formatToFixed;

// TODO: Simconnect is not clear if Vibration is N1 or N2, one of them will need to be simulated LVAR.

void EngineVibrationControl::render() {
	Control::render();

	nvgStrokeColor(this->getContext(), Colors::white);
	nvgFillColor(this->getContext(), Colors::white);
	nvgStrokeWidth(this->getContext(), 2.5f);
	nvgTextAlign(this->getContext(), NVG_ALIGN_RIGHT | NVG_ALIGN_TOP);
	nvgFontFace(this->getContext(), "heavy-fmc");
	nvgFontSize(this->getContext(), 24.0f);

	nvgBeginPath(this->getContext());
	{
		nvgRect(this->getContext(), 740, 825, 45, 30);
		nvgText(this->getContext(), 780, 830, formatToFixed(this->eng1_vib, 1).c_str(), nullptr);
		nvgStroke(this->getContext());

	}

	nvgBeginPath(this->getContext());
	{
		nvgRect(this->getContext(), 905, 825, 45, 30);
		nvgText(this->getContext(), 945, 830, formatToFixed(this->eng2_vib, 1).c_str(), nullptr);
		nvgStroke(this->getContext());
	}

	nvgFillColor(this->getContext(), Colors::cyan);
	nvgFontSize(this->getContext(), 17.0f);
	nvgBeginPath(this->getContext());
	// TODO: check if centered
	{
		nvgText(this->getContext(), 859, 834, "VIB", nullptr);
		nvgFill(this->getContext());
	}

	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 795, 875);
		nvgLineTo(this->getContext(), 795, 805);
		nvgStroke(this->getContext());
	}

	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 895, 875);
		nvgLineTo(this->getContext(), 895, 805);
		nvgStroke(this->getContext());
	}

	nvgFillColor(this->getContext(), Colors::white);
	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 799, 851 + vib_gauge_1);
		nvgLineTo(this->getContext(), 813, 857 + vib_gauge_1);
		nvgLineTo(this->getContext(), 813, 845 + vib_gauge_1);
		nvgClosePath(this->getContext());
		nvgFill(this->getContext());
	}

	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 891, 851 + vib_gauge_2);
		nvgLineTo(this->getContext(), 879, 857 + vib_gauge_2);
		nvgLineTo(this->getContext(), 879, 845 + vib_gauge_2);
		nvgClosePath(this->getContext());
		nvgFill(this->getContext());
	}

}

void EngineVibrationControl::setupControl() {
	Control::setupControl();
	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->eng1_vib = Simplane::aircraft::systems::powerplant::engine_1::vibration();
		this->eng2_vib = Simplane::aircraft::systems::powerplant::engine_2::vibration();

		this->gauge_height = 70;
		this->max_vib = 20.;
		this->gauge_constant = -1 * this->gauge_height / this->max_vib;
		this->vib_gauge_1 = this->eng1_vib * this->gauge_constant;
		this->vib_gauge_2 = this->eng2_vib * this->gauge_constant;

		return true;
	});
}
