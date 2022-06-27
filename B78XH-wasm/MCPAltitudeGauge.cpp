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


#include "BaseGauge.h"
#include "MCPAltitudeGauge.h"
#include "SimConnectData.h"

bool MCPAltitudeGauge::preInstall() {
	return true;
}

bool MCPAltitudeGauge::postInstall(FsContext context) {
	this->fsContext = context;
	NVGparams params;
	params.userPtr = context;
	params.edgeAntiAlias = true;
	this->nvgContext = nvgCreateInternal(&params);
	this->altitudeFont = nvgCreateFont(this->nvgContext, "dseg7", "./data/DSEG7ClassicMini-Italic.ttf");
	return true;
}

bool MCPAltitudeGauge::preDraw(sGaugeDrawData* data) {
	if(GaugesInvalidateFlags.MCPAltitudeGauge != true) {
		return true;
	}
	GaugesInvalidateFlags.MCPAltitudeGauge = false;

	

	const FLOAT64 fAltitude = SimConnectData::Autopilot::altitude.altitudeLockVar3;
	const std::string sAltitude = std::to_string(static_cast<int>(fAltitude));
	const float pxRatio = static_cast<float>(data->fbWidth) / static_cast<float>(data->winWidth);
	const auto winWidth = static_cast<float>(data->winWidth);
	const auto winHeight = static_cast<float>(data->winHeight);

	nvgBeginFrame(this->nvgContext, winWidth, winHeight, pxRatio);
	{
		nvgFillColor(this->nvgContext, nvgRGB(0, 0, 0));
		nvgBeginPath(this->nvgContext);
		nvgRect(this->nvgContext, 0, 0, winWidth, winHeight);
		nvgFill(this->nvgContext);
		nvgFontSize(this->nvgContext, 90.0f);
		nvgFontFace(this->nvgContext, "dseg7");
		nvgFillColor(this->nvgContext, nvgRGBA(255, 255, 255, 255));

		nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_TOP);
		nvgText(this->nvgContext, 500, 12, sAltitude.c_str(), nullptr);
	}
	nvgEndFrame(this->nvgContext);
	return true;
}

bool MCPAltitudeGauge::preKill() {
	nvgDeleteInternal(this->nvgContext);
	return true;
}
