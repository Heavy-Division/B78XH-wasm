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


#include "PFDTargetAirspeedApplication.h"
#include <cmath>

#include "LVars.h"
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
		if (!LVars::get(LVars::XMLVAR_AirSpeedIsInMach).isValue()) {
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

