#include "OilQuantityControl.h"

#include "Tools/Console.h"
#include "Tools/Tools.h"

using Tools::Colors;
using Tools::formatToFixed;

// TODO: Oil consumption model

void ::OilQuantityControl::render() {
	Control::render();

	nvgStrokeColor(this->getContext(), Colors::white);
	nvgFillColor(this->getContext(), Colors::white);
	nvgStrokeWidth(this->getContext(), 2.5f);
	nvgTextAlign(this->getContext(), NVG_ALIGN_RIGHT | NVG_ALIGN_TOP);
	nvgFontFace(this->getContext(), "heavy-fmc");
	nvgFontSize(this->getContext(), 24.0f);

	nvgBeginPath(this->getContext());
	{
		nvgRect(this->getContext(), 740, 725, 45, 30);
		nvgText(this->getContext(), 780, 730, formatToFixed(this->oilQty_eng1, 0).c_str(), nullptr);
		nvgStroke(this->getContext());
	
	}

	nvgBeginPath(this->getContext());
	{
		nvgRect(this->getContext(), 905, 725, 45, 30);
		nvgText(this->getContext(), 945, 730, formatToFixed(this->oilQty_eng2, 0).c_str(), nullptr);
		nvgStroke(this->getContext());

	}

	nvgFillColor(this->getContext(), Colors::cyan);
	nvgFontSize(this->getContext(), 17.0f);
	nvgBeginPath(this->getContext());
	// TODO: check if centered
	{
		nvgText(this->getContext(), 875, 734, "OIL QTY", nullptr);
		nvgFill(this->getContext());
	}
}

void ::OilQuantityControl::setupControl() {
	Control::setupControl();
	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->oilQty_eng1 = Simplane::aircraft::systems::powerplant::engine_1::oilQty();
		this->oilQty_eng2 = Simplane::aircraft::systems::powerplant::engine_2::oilQty();

		return true;
	});
}
