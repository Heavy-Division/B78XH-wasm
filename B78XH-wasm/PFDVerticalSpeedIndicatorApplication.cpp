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


#include "PFDVerticalSpeedIndicatorApplication.h"

#include "Simplane.h"
#include "Tools.h"
#include <cmath>

using Colors = Tools::Colors;

void PFDVerticalSpeedIndicatorApplication::render(sGaugeDrawData* data) {
	drawBackground();
	drawGraduations();
	drawCursor();
	drawTargetPointer();
	drawValue();
}

auto PFDVerticalSpeedIndicatorApplication::drawBackground() -> void {
	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, 0, 161);
		{
			nvgFillColor(this->nvgContext, nvgRGBA(0, 0, 0, 100));
			nvgStrokeWidth(this->nvgContext, 1.0f);
			nvgStrokeColor(this->nvgContext, nvgRGBA(0, 0, 0, 250));

			nvgBeginPath(this->nvgContext);
			{
				nvgMoveTo(this->nvgContext, 0, -161);
				nvgLineTo(this->nvgContext, 26, -161);
				nvgLineTo(this->nvgContext, 54, -85);
				nvgLineTo(this->nvgContext, 54, 85);
				nvgLineTo(this->nvgContext, 26, 161);
				nvgLineTo(this->nvgContext, 0, 161);
				nvgLineTo(this->nvgContext, 0, 57);
				nvgLineTo(this->nvgContext, 16, 46);
				nvgLineTo(this->nvgContext, 16, -46);
				nvgLineTo(this->nvgContext, 0, -57);
			}
			nvgClosePath(this->nvgContext);
			nvgFill(this->nvgContext);
			nvgStroke(this->nvgContext);
		}
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

auto PFDVerticalSpeedIndicatorApplication::drawValue() -> void {
	const int verticalSpeed = static_cast<int>(round(SimConnectData::Aircraft::state.verticalSpeed));
	const int absoluteVerticalSpeed = abs(verticalSpeed);
	const double modulo50 = absoluteVerticalSpeed % 50;
	const int roundedVerticalSpeed = static_cast<int>(absoluteVerticalSpeed - modulo50 + (modulo50 >= 25 ? 50 : 0));
	constexpr float baseVerticalOffset = 185;
	const float verticalOffsetModifier = (verticalSpeed < 0 ? 1.0 : -1.0);
	if (absoluteVerticalSpeed < 400) {
		return;
	}

	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, 0, 161);
		{
			nvgFillColor(this->nvgContext, Colors::white);
			nvgTextAlign(this->nvgContext, NVG_ALIGN_MIDDLE | NVG_ALIGN_RIGHT);
			nvgFontSize(this->nvgContext, 28.0f);
			nvgFontFace(this->nvgContext, "roboto");
			nvgBeginPath(this->nvgContext);
			{
				nvgText(this->nvgContext, 50, baseVerticalOffset * verticalOffsetModifier,
				        std::to_string(roundedVerticalSpeed).c_str(), nullptr);
			}
			nvgFill(this->nvgContext);
		}
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

auto PFDVerticalSpeedIndicatorApplication::drawGraduations() -> void {
	constexpr auto height = 2.0f;

	/*
	 * DEFINITION:
	 * {offset, width}
	 */
	constexpr int offsetsMajor[4][2] = {{0, 20}, {68, 8}, {116, 8}, {150, 8}};

	constexpr int offsetsMinor[3][2] = {{34, 8}, {92, 8}, {133, 8},};
	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, 14, 161);
		{
			nvgStrokeColor(this->nvgContext, Colors::white);
			/*
			 * Major
			 */

			nvgStrokeWidth(this->nvgContext, 3.0f);
			nvgShapeAntiAlias(this->nvgContext, false);

			nvgBeginPath(this->nvgContext);
			{
				for (int i = 0; i < 4; i++) {
					nvgMoveTo(this->nvgContext, 0, offsetsMajor[i][0]);
					nvgLineTo(this->nvgContext, offsetsMajor[i][1], offsetsMajor[i][0]);
					if (i == 0) {
						continue;
					}
					nvgMoveTo(this->nvgContext, 0, -offsetsMajor[i][0]);
					nvgLineTo(this->nvgContext, offsetsMajor[i][1], -offsetsMajor[i][0]);
				}
			}

			nvgStroke(this->nvgContext);

			/*
			 * Major Texts
			 */

			nvgFontFace(this->nvgContext, "roboto");
			nvgFontSize(this->nvgContext, 20.0f);
			nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
			nvgFillColor(this->nvgContext, Colors::white);
			nvgBeginPath(this->nvgContext);
			{
				nvgText(this->nvgContext, -2, offsetsMajor[1][0], "1", nullptr);
				nvgText(this->nvgContext, -2, -offsetsMajor[1][0], "1", nullptr);
				nvgText(this->nvgContext, -2, offsetsMajor[2][0], "2", nullptr);
				nvgText(this->nvgContext, -2, -offsetsMajor[2][0], "2", nullptr);
				nvgText(this->nvgContext, -2, offsetsMajor[3][0], "6", nullptr);
				nvgText(this->nvgContext, -2, -offsetsMajor[3][0], "6", nullptr);
			}
			nvgClosePath(this->nvgContext);
			nvgFill(this->nvgContext);

			/*
			 * Minor
			 */
			nvgStrokeWidth(this->nvgContext, 2.0f);
			nvgBeginPath(this->nvgContext);
			{
				for (int i = 0; i < 3; i++) {
					nvgMoveTo(this->nvgContext, 0, offsetsMinor[i][0]);
					nvgLineTo(this->nvgContext, offsetsMinor[i][1], offsetsMinor[i][0]);
					nvgMoveTo(this->nvgContext, 0, -offsetsMinor[i][0]);
					nvgLineTo(this->nvgContext, offsetsMinor[i][1], -offsetsMinor[i][0]);
				}
			}
			nvgClosePath(this->nvgContext);
			nvgStroke(this->nvgContext);
			nvgShapeAntiAlias(this->nvgContext, true);
		}
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

auto PFDVerticalSpeedIndicatorApplication::drawCursor() -> void {
	namespace Aircraft = Simplane::aircraft;
	const double verticalSpeed = Aircraft::state::verticalSpeed();
	/*
	 * grad 1 -> 34px = 500 feet = 0.68 px per feet
	 * grad 2 -> 34px = 500 feet = 0.68 px per feet
	 * grad 3 -> 24px = 500 feet = 0.48 px per feet
	 * grad 4 -> 24px = 500 feet = 0.48 px per feet
	 * grad 5 -> 17px = 2000 feet = 0.085 px per feet
	 * grad 6 -> 17px = 2000 feet = 0.085 px per feet
	 */

	const bool isVerticalSpeedNegative = verticalSpeed < 0;
	const double absoluteVerticalSpeed = abs(verticalSpeed);
	const double numberOf2000 = absoluteVerticalSpeed / 2000;
	double offset = 0;

	if (numberOf2000 >= 3) {
		offset = 150;
	}
	else if (absoluteVerticalSpeed <= 1000) {
		offset = (absoluteVerticalSpeed * 0.068);
	}
	else if (absoluteVerticalSpeed <= 2000) {
		offset = ((absoluteVerticalSpeed - 1000) * 0.048) + 68;
	}
	else if (absoluteVerticalSpeed <= 6000) {
		offset = ((absoluteVerticalSpeed - 2000) * 0.0085) + 116;
	}

	offset = (isVerticalSpeedNegative ? offset : -offset);

	nvgSave(this->nvgContext);
	{
		nvgStrokeWidth(this->nvgContext, 3.0f);
		nvgStrokeColor(this->nvgContext, Colors::white);
		nvgLineCap(this->nvgContext, NVG_ROUND);
		nvgTranslate(this->nvgContext, 120, 161);
		{
			nvgScissor(this->nvgContext, -105, -160, 38, 320);
			nvgBeginPath(this->nvgContext);
			{
				nvgMoveTo(this->nvgContext, -25, 0);
				nvgLineTo(this->nvgContext, -100, offset);
			}
			nvgClosePath(this->nvgContext);
			nvgStroke(this->nvgContext);
			nvgResetScissor(this->nvgContext);
		}
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

auto PFDVerticalSpeedIndicatorApplication::drawTargetPointer() -> void {
	namespace Autopilot = Simplane::autopilot;
	if (!Autopilot::verticalSpeed::verticalSpeedHold()) {
		return;
	}
	const double verticalSpeedSelected = Autopilot::verticalSpeed::verticalSpeedHoldVar();

	const bool isVerticalSpeedNegative = verticalSpeedSelected < 0;
	const double absoluteVerticalSpeed = abs(verticalSpeedSelected);
	const double numberOf2000 = absoluteVerticalSpeed / 2000;
	double offset = 0;

	if (numberOf2000 >= 3) {
		offset = 150;
	}
	else if (absoluteVerticalSpeed <= 1000) {
		offset = (absoluteVerticalSpeed * 0.068);
	}
	else if (absoluteVerticalSpeed <= 2000) {
		offset = ((absoluteVerticalSpeed - 1000) * 0.048) + 68;
	}
	else if (absoluteVerticalSpeed <= 6000) {
		offset = ((absoluteVerticalSpeed - 2000) * 0.0085) + 116;
	}

	offset = (isVerticalSpeedNegative ? offset : -offset);

	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, 14, 161);
		{
			nvgStrokeWidth(this->nvgContext, 4);
			nvgStrokeColor(this->nvgContext, Colors::magenta);
			nvgBeginPath(this->nvgContext);
			{
				nvgMoveTo(this->nvgContext, 0, offset);
				nvgLineTo(this->nvgContext, 10, offset);
			}
			nvgClosePath(this->nvgContext);
			nvgStroke(this->nvgContext);
		}
		nvgResetTransform(this->nvgContext);
	}

	nvgRestore(this->nvgContext);
}
