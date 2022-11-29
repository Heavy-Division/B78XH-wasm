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


#include "MCPHeadingApplication.h"

#include "GaugesInvalidateFlags.h"
#include "SimConnectData.h"
#include "Tools.h"

#include <cmath>

#include "LVars.h"

using Colors = Tools::Colors;

auto MCPHeadingApplication::render(sGaugeDrawData* data) -> void {
	this->trackModeActive = LVars::get(LVars::XMLVAR_TRK_MODE_ACTIVE).isValue();
	this->trackValue = this->getTrack();
	if(!this->isControlInvalid()) {
		return;
	}

	GaugesInvalidateFlags.MCPHeadingGaugeHeading = false;
	GaugesInvalidateFlags.MCPHeadingGaugeTrack = false;

	this->lastTrackModeActive = this->trackModeActive;
	this->lastTrackValue = this->trackValue;

	this->clearApplication();

	this->renderMode();
	this->renderValue();
}

auto MCPHeadingApplication::renderMode() -> void {
	nvgFontSize(this->nvgContext, 80.0f);
	nvgFontFace(this->nvgContext, "roboto");
	nvgFillColor(this->nvgContext, Colors::white);
	nvgTextAlign(this->nvgContext, NVG_ALIGN_LEFT | NVG_ALIGN_TOP);

	nvgBeginPath(this->nvgContext);
	{
		nvgText(this->nvgContext, 12, -10, (this->lastTrackModeActive ? "TRK" : "HDG"), nullptr);
	}
}

auto MCPHeadingApplication::renderValue() -> void {
	nvgFontSize(this->nvgContext, 90.0f);
	nvgFontFace(this->nvgContext, "dseg7");
	nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_TOP);
	nvgFillColor(this->nvgContext, Colors::white);

	nvgBeginPath(this->nvgContext);
	{
		nvgText(this->nvgContext, 500, 12, fmt::format("{:03}", (this->lastTrackModeActive ? this->trackValue : this->getHeading())).c_str(), nullptr);
	}
}

auto MCPHeadingApplication::getTrack() -> int {
	return static_cast<int>(round(SimConnectData::Aircraft::state.headingMagnetic));
}

auto MCPHeadingApplication::getHeading() -> int {
	return static_cast<int>(round(SimConnectData::Autopilot::heading.headingLockVar1));
}

auto MCPHeadingApplication::clearApplication() -> void {
	nvgFillColor(this->nvgContext, Colors::black);
	nvgBeginPath(this->nvgContext);
	{
		nvgRect(this->nvgContext, 0, 0, this->getWidth(), this->getHeight());
	}
	nvgFill(this->nvgContext);
}

auto MCPHeadingApplication::isControlInvalid() -> bool {
	if(this->lastTrackModeActive != this->trackModeActive) {
		return true;
	}

	if(this->trackModeActive == true && GaugesInvalidateFlags.MCPHeadingGaugeTrack == true && this->lastTrackValue != this->trackValue) {
		return true;
	}

	if (this->trackModeActive == false && GaugesInvalidateFlags.MCPHeadingGaugeHeading == true) {
		return true;
	}

	return false;
}
