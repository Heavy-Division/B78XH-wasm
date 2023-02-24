#include "LowerEICASControl.h"

void LowerEICASControl::drawDataBox(double width, double height, int decimals, float fontSize) {

	bool eng_cutoff = Simplane::aircraft::systems::fuel::switches::eng1_cutoff();;

	// set box position relative to drawCircle() 
	double box_x = x - 2;
	double box_y = y - 35;

	if (fuel_valve_connection == RIGHT) {
		eng_cutoff = Simplane::aircraft::systems::fuel::switches::eng2_cutoff();
	}

	nvgFontFace(getContext(), "heavy-fmc");
	// nvgFillColor(getContext(), fillColor);
	nvgStrokeColor(getContext(), Tools::Colors::white);
	nvgStrokeWidth(getContext(), 2.5f);
	nvgFontSize(getContext(), fontSize);
	nvgTextAlign(getContext(), NVG_ALIGN_LEFT | NVG_ALIGN_TOP);

	nvgBeginPath(getContext());
	{
		nvgRect(getContext(), box_x, box_y, width, height);
		nvgStroke(getContext());
		nvgFill(getContext());
	}


	nvgFillColor(getContext(), Tools::Colors::white);
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

		nvgFill(getContext());
	}

}

bool LowerEICASControl::isDataNonNormal() {
	if(minmax == MAX) {
		return data > advisory_threshold;
	}

	if(minmax == MIN) {
		return data < advisory_threshold;
	}

	return true;
}

auto LowerEICASControl::setBoxStyle() -> void {
	if (isDataNonNormal()) {
		fillColor = Tools::Colors::white;
		textColor = Tools::Colors::black;
	};
}
