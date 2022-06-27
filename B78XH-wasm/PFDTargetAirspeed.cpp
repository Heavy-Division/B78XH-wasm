#include "PFDTargetAirspeed.h"
#include <cmath>
#include "Simplane.h"
#include "fmt/core.h"

void PFDTargetAirspeed::draw(NVGcontext* context, float windowWidth, float windowHeight) {
	nvgSave(context);
	drawBackground(context, windowWidth, windowHeight);
	drawValue(context, windowWidth, windowHeight);
	nvgRestore(context);
}

void PFDTargetAirspeed::drawBackground(NVGcontext* context, float windowWidth, float windowHeight) {
	nvgFillColor(context, nvgRGB(0, 0, 0));
	nvgBeginPath(context);
	{
		//nvgRect(context, 155, 30, 78, 38);
		nvgRect(context, 0, 0, 78, 38);
	}
	nvgClosePath(context);
	nvgFill(context);
}

void PFDTargetAirspeed::drawValue(NVGcontext* context, float windowWidth, float windowHeight) {
	namespace Autopilot = Simplane::autopilot;
	const auto resolveTargetSpeed = []()-> std::string {
		if(!LVars::isMachModeActive()) {
			return fmt::format("{:03}", round(Autopilot::airspeed::airspeedHoldVar()));
		}
		return fmt::format("{:.3f}", Autopilot::airspeed::machHoldVar()).substr(1, 4);
	};


	nvgFontFace(context, "roboto");
	nvgFontSize(context, 40.0f);
	nvgFillColor(context, nvgRGB(213, 112, 255));
	nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
	nvgBeginPath(context);
	{
		nvgText(context, 74, 19, resolveTargetSpeed().c_str(), nullptr);
	}
	nvgClosePath(context);
	nvgFill(context);
}
