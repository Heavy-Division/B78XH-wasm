//    B78XH-wasm
//    Copyright (C) 2022  Heavy Division
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.


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
