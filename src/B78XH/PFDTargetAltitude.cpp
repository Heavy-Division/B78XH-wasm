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


#include "PFDTargetAltitude.h"
#include <cmath>
#include "fmt/core.h"
#include "Simplane.h"
#include "Tools/Tools.h"

using Colors = Tools::Colors;

void PFDTargetAltitude::draw(NVGcontext* context) {
	nvgSave(context);
	drawBackground(context);
	drawValue(context);
	nvgRestore(context);
}

void PFDTargetAltitude::drawBackground(NVGcontext* context) {
	nvgFillColor(context, Colors::black);
	nvgBeginPath(context);
	{
		//nvgRect(context, 635, 30, 80, 38);
		nvgRect(context, 0, 0, 80, 38);
	}
	nvgClosePath(context);
	nvgFill(context);
}

void PFDTargetAltitude::drawValue(NVGcontext* context) {
	namespace Autopilot = Simplane::autopilot;

	const double selectedAltitude = Autopilot::altitude::altitudeLockVar();
	const int integral = floor(selectedAltitude / 1000);
	const int modulo = floor(selectedAltitude - (integral * 1000));
	const auto cstrModulo = fmt::format("{:03}", modulo).c_str();
	float moduloBounds[4];

	nvgFontFace(context, "roboto");
	nvgFontSize(context, 30.0f);
	nvgFillColor(context, Colors::magenta);
	nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_BOTTOM);


	nvgTextBounds(context, 77, 37, cstrModulo, nullptr, moduloBounds);
	nvgBeginPath(context);
	{
		nvgText(context, 77, 37, cstrModulo, nullptr);
		nvgFontSize(context, 40.0f);
		nvgText(context, moduloBounds[0], moduloBounds[3] + 2, std::to_string(integral).c_str(), nullptr);
	}
	nvgClosePath(context);
	nvgFill(context);
}
