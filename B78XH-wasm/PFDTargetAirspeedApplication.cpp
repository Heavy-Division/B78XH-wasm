#include "PFDTargetAirspeedApplication.h"
#include <cmath>
#include "Simplane.h"
#include "Tools.h"

using Colors = Tools::Colors;

void PFDTargetAirspeedApplication::render(sGaugeDrawData* data) {
	drawBackground();
	drawValue();
}


void PFDTargetAirspeedApplication::drawBackground() const {
	nvgFillColor(this->nvgContext, Colors::black);
	nvgBeginPath(this->nvgContext);
	{
		//nvgRect(context, 155, 30, 78, 38);
		nvgRect(this->nvgContext, 0, 0, 78, 38);
	}
	nvgClosePath(this->nvgContext);
	nvgFill(this->nvgContext);
}

void PFDTargetAirspeedApplication::drawValue() const {
	namespace Autopilot = Simplane::autopilot;
	const auto resolveTargetSpeed = []()-> std::string {
		if (!LVarsGetter::isMachModeActive()) {
			return fmt::format("{:03}", round(Autopilot::airspeed::airspeedHoldVar()));
		}
		return fmt::format("{:.3f}", Autopilot::airspeed::machHoldVar()).substr(1, 4);
	};


	nvgFontFace(this->nvgContext, "roboto");
	nvgFontSize(this->nvgContext, 40.0f);
	nvgFillColor(this->nvgContext, Colors::magenta);
	nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
	nvgBeginPath(this->nvgContext);
	{
		nvgText(this->nvgContext, 74, 19, resolveTargetSpeed().c_str(), nullptr);
	}
	nvgClosePath(this->nvgContext);
	nvgFill(this->nvgContext);
}

