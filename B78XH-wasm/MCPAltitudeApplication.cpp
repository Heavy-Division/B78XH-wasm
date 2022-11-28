#include "MCPAltitudeApplication.h"

#include "GaugesInvalidateFlags.h"
#include "SimConnectData.h"
#include "Tools.h"

using Colors = Tools::Colors;

void MCPAltitudeApplication::render(sGaugeDrawData* data) {
	if (GaugesInvalidateFlags.MCPAltitudeGauge != true) {
		return;
	}
	GaugesInvalidateFlags.MCPAltitudeGauge = false;
	this->clearApplication();

	const FLOAT64 fAltitude = SimConnectData::Autopilot::altitude.altitudeLockVar3;
	const std::string sAltitude = std::to_string(static_cast<int>(fAltitude));

	nvgFontSize(this->nvgContext, 90.0f);
	nvgFontFace(this->nvgContext, "dseg7");
	nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_TOP);
	nvgFillColor(this->nvgContext, Colors::white);

	nvgBeginPath(this->nvgContext);
	{
		nvgText(this->nvgContext, 500, 12, sAltitude.c_str(), nullptr);
	}
}

auto MCPAltitudeApplication::clearApplication() -> void {
	nvgFillColor(this->nvgContext, Colors::black);
	nvgBeginPath(this->nvgContext);
	{
		nvgRect(this->nvgContext, 0, 0, this->getWidth(), this->getHeight());
	}
	nvgFill(this->nvgContext);
}
