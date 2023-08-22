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


#include "PFDBaroIndicator.h"
#include "Tools/Tools.h"
#include "Simplane.h"
#include "fmt/core.h"
#include <cmath>

using Colors = Tools::Colors;

auto PFDBaroIndicator::draw(NVGcontext* context) -> void {
	if (Simplane::barometer::setting::forcedToSTD()) {
		drawSTD(context);
	}
	else {
		const bool hpa = Simplane::barometer::setting::isBaroInHPA();
		drawValue(context, hpa);
		drawUnits(context, hpa);
	}
}

auto PFDBaroIndicator::drawValue(NVGcontext* context, bool isBaroInHPA) -> void {
	double value = (isBaroInHPA
		                ? Simplane::barometer::setting::kohlsmanMB()
		                : Simplane::barometer::setting::kohlsmanHG());
	std::string valueToRender;
	if (isBaroInHPA) {
		value = roundf(static_cast<float>(value));
		valueToRender = std::to_string(static_cast<int>(value));
	}
	else {
		value = round(static_cast<float>(value * 100)) / 100.0;
		valueToRender = fmt::format("{:.2f}", value);
	}

	nvgFillColor(context, Colors::green);
	nvgTextAlign(context, NVG_ALIGN_LEFT);
	nvgFontSize(context, 25.0f);
	nvgFontFace(context, "roboto");
	nvgBeginPath(context);
	{
		nvgText(context, 0, 0, valueToRender.c_str(), nullptr);
	}
	nvgFill(context);
}

auto PFDBaroIndicator::drawUnits(NVGcontext* context, bool isBaroInHPA) -> void {
	nvgFillColor(context, Colors::green);
	nvgTextAlign(context, NVG_ALIGN_RIGHT);
	nvgFontSize(context, 25.0f);
	nvgFontFace(context, "roboto");
	nvgBeginPath(context);
	{
		nvgText(context, 80, 0, (isBaroInHPA ? "HPA" : "IN"), nullptr);
	}
	nvgFill(context);
}

auto PFDBaroIndicator::drawSTD(NVGcontext* context) -> void {
	nvgFillColor(context, Colors::green);
	nvgTextAlign(context, NVG_ALIGN_CENTER);
	nvgFontSize(context, 35.0f);
	nvgBeginPath(context);
	{
		nvgText(context, 40, 5, "STD", nullptr);
	}
	nvgFill(context);
}
