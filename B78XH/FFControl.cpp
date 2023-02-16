#include "FFControl.h"
#include "Simplane.h"
#include "Tools/Console.h"
#include "Tools/Tools.h"

using Tools::Colors;

void FFControl::render() {
	Control::render();

	double eng1_ff = Simplane::aircraft::systems::powerplant::engine_1::fuelFlowPPH() / 1000;
	double eng2_ff = Simplane::aircraft::systems::powerplant::engine_2::fuelFlowPPH() / 1000;

	nvgStrokeColor(this->getContext(), Colors::white);
	nvgFillColor(this->getContext(), Colors::white);
	nvgStrokeWidth(this->getContext(), 2.5f);
	nvgFontFace(this->getContext(), "heavy-fmc");
	nvgFontSize(this->getContext(), 24.0f);
	// TODO: Problem: Text "Grows" from the right to left irl, how to make nvgAlign emulate this?
	nvgTextAlign(this->getContext(), NVG_ALIGN_LEFT | NVG_ALIGN_TOP);

	// Eng 1 - FF

	nvgBeginPath(this->getContext());
	{
		if (Simplane::aircraft::systems::fuel::switches::eng1_cutoff() == true) {
			nvgText(this->getContext(), 737, 475, fmt::format("{:.1f}", eng1_ff).c_str(), nullptr);
		}
		nvgRect(this->getContext(), 730, 470, 55, 29);
		nvgStroke(this->getContext());
	}


	nvgFillColor(this->getContext(), Colors::cyan);
	nvgFontSize(this->getContext(), 19.0f);
	nvgBeginPath(this->getContext());
	{
		nvgText(this->getContext(), 829, 475, "FF", nullptr);
	}


	// Eng 2 - FF

	nvgFillColor(this->getContext(), Colors::white);
	nvgFontSize(this->getContext(), 24.0f);
	nvgBeginPath(this->getContext());
	{
		if (Simplane::aircraft::systems::fuel::switches::eng2_cutoff() == true) {
			nvgText(this->getContext(), 910, 475, fmt::format("{:.1f}", eng2_ff).c_str(), nullptr);
		}
		nvgRect(this->getContext(), 903, 470, 55, 29);
		nvgStroke(this->getContext());
	}


}

void FFControl::setupControl() {
	Control::setupControl();
}
