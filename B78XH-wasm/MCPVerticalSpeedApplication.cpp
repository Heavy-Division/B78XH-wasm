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


#include "MCPVerticalSpeedApplication.h"

#include "GaugesInvalidateFlags.h"
#include "LVars.h"
#include "SimConnectData.h"
#include "Tools.h"

using Colors = Tools::Colors;

auto MCPVerticalSpeedApplication::render(sGaugeDrawData* data) -> void {
	this->verticalSpeedModeActive = LVars::get(LVars::AP_VS_ACTIVE).isValue();
	this->fpaModeActive = LVars::get(LVars::XMLVAR_FPA_MODE_ACTIVE).isValue();

	if (this->needRedraw()) {
		this->invalidateControl();
	}

	if (this->isControlInvalid()) {
		GaugesInvalidateFlags.MCPVSpeedGauge = false;
		this->clearApplication();
	}
	else {
		return;
	}

	this->lastVerticalSpeedModeActive = this->verticalSpeedModeActive;
	this->lastFPAModeActive = this->fpaModeActive;

	if (this->lastVerticalSpeedModeActive) {
		this->renderMode();
		this->renderValue();
	}
	else {
		this->renderMode();
	}
}

auto MCPVerticalSpeedApplication::renderMode() -> void {
	nvgFontSize(this->nvgContext, 80.0f);
	nvgFontFace(this->nvgContext, "roboto");
	nvgFillColor(this->nvgContext, Colors::white);
	nvgTextAlign(this->nvgContext, NVG_ALIGN_LEFT | NVG_ALIGN_TOP);

	nvgBeginPath(this->nvgContext);
	{
		nvgText(this->nvgContext, 12, -10, (this->lastFPAModeActive ? "FPA" : "V/S"), nullptr);
	}
}

auto MCPVerticalSpeedApplication::renderValue() -> void {
	const int verticalSpeedValue = static_cast<int>(SimConnectData::Autopilot::verticalSpeed.verticalSpeedHoldVar1);
	nvgFontSize(this->nvgContext, 85.0f);
	nvgFontFace(this->nvgContext, "dseg7");
	nvgFillColor(this->nvgContext, Colors::white);
	nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_TOP);

	nvgBeginPath(this->nvgContext);
	{
		nvgText(this->nvgContext, 500, 12,
		        (this->lastFPAModeActive
			         ? fmt::format("{}", verticalSpeedValue / 100).c_str()
			         : fmt::format("{}", verticalSpeedValue).c_str()), nullptr);
	}
}

auto MCPVerticalSpeedApplication::clearApplication() -> void {
	nvgFillColor(this->nvgContext, Colors::black);
	nvgBeginPath(this->nvgContext);
	{
		nvgRect(this->nvgContext, 0, 0, this->getWidth(), this->getHeight());
	}
	nvgFill(this->nvgContext);
}

auto MCPVerticalSpeedApplication::isControlInvalid() -> bool {
	if (GaugesInvalidateFlags.MCPVSpeedGauge == true) {
		return true;
	}

	return false;
}

auto MCPVerticalSpeedApplication::invalidateControl() -> void {
	GaugesInvalidateFlags.MCPVSpeedGauge = true;
}

auto MCPVerticalSpeedApplication::needRedraw() -> bool {
	if (this->lastFPAModeActive != this->fpaModeActive || this->lastVerticalSpeedModeActive != this->
		verticalSpeedModeActive) {
		return true;
	}
	return false;
}
