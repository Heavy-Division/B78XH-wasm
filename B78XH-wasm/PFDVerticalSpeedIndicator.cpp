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


#include "PFDVerticalSpeedIndicator.h"
#include "Simplane.h"
#include <cstdlib>
#include "Tools/Tools.h"

using Colors = Tools::Colors;

void PFDVerticalSpeedIndicator::draw(NVGcontext* context) {
	nvgSave(context);
	drawBackground(context);
	drawGraduations(context);
	drawCursor(context);
	drawTargetPointer(context);
	nvgRestore(context);
}

void PFDVerticalSpeedIndicator::drawBackground(NVGcontext* context) {
	nvgSave(context);
	{
		nvgTranslate(context, 0, 161);
		{
			nvgFillColor(context, nvgRGBA(0, 0, 0, 100));
			nvgStrokeWidth(context, 1.0f);
			nvgStrokeColor(context, nvgRGBA(0, 0, 0, 250));

			nvgBeginPath(context);
			{
				nvgMoveTo(context, 0, -161);
				nvgLineTo(context, 26, -161);
				nvgLineTo(context, 54, -85);
				nvgLineTo(context, 54, 85);
				nvgLineTo(context, 26, 161);
				nvgLineTo(context, 0, 161);
				nvgLineTo(context, 0, 57);
				nvgLineTo(context, 16, 46);
				nvgLineTo(context, 16, -46);
				nvgLineTo(context, 0, -57);
			}
			nvgClosePath(context);
			nvgFill(context);
			nvgStroke(context);
		}
		nvgResetTransform(context);
	}
	nvgRestore(context);
}

void PFDVerticalSpeedIndicator::drawGraduations(NVGcontext* context) {
	constexpr auto height = 2.0f;

	/*
	 * DEFINITION:
	 * {offset, width}
	 */
	constexpr int offsetsMajor[4][2] = {{0, 20}, {68, 8}, {116, 8}, {150, 8}};

	constexpr int offsetsMinor[3][2] = {{34, 8}, {92, 8}, {133, 8},};
	nvgSave(context);
	{
		nvgTranslate(context, 14, 161);
		{
			
			nvgStrokeColor(context, Colors::white);
			/*
			 * Major
			 */
			
			nvgStrokeWidth(context, 3.0f);
			nvgShapeAntiAlias(context, false);
			
			nvgBeginPath(context);
			{
				for (int i = 0; i < 4; i++) {
					nvgMoveTo(context, 0, offsetsMajor[i][0]);
					nvgLineTo(context, offsetsMajor[i][1], offsetsMajor[i][0]);
					if (i == 0) {
						continue;
					}
					nvgMoveTo(context, 0, -offsetsMajor[i][0]);
					nvgLineTo(context, offsetsMajor[i][1], -offsetsMajor[i][0]);
				}
			}
			
			nvgStroke(context);
			
			/*
			 * Major Texts
			 */
			 
			nvgFontFace(context, "roboto");
			nvgFontSize(context, 20.0f);
			nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
			nvgFillColor(context, Colors::white);
			nvgBeginPath(context);
			{
				nvgText(context, -2, offsetsMajor[1][0], "1", nullptr);
				nvgText(context, -2, -offsetsMajor[1][0], "1", nullptr);
				nvgText(context, -2, offsetsMajor[2][0], "2", nullptr);
				nvgText(context, -2, -offsetsMajor[2][0], "2", nullptr);
				nvgText(context, -2, offsetsMajor[3][0], "6", nullptr);
				nvgText(context, -2, -offsetsMajor[3][0], "6", nullptr);
			}
			nvgClosePath(context);
			nvgFill(context);
			
			/*
			 * Minor
			 */
			nvgStrokeWidth(context, 2.0f);
			nvgBeginPath(context);
			{
				for (int i = 0; i < 3; i++) {
					nvgMoveTo(context, 0, offsetsMinor[i][0]);
					nvgLineTo(context, offsetsMinor[i][1], offsetsMinor[i][0]);
					nvgMoveTo(context, 0, -offsetsMinor[i][0]);
					nvgLineTo(context, offsetsMinor[i][1], -offsetsMinor[i][0]);
				}
			}
			nvgClosePath(context);
			nvgStroke(context);
			nvgShapeAntiAlias(context, true);
		}
		nvgResetTransform(context);
	}
	nvgRestore(context);
}

void PFDVerticalSpeedIndicator::drawCursor(NVGcontext* context) {
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

	if(numberOf2000 >= 3) {
		offset = 150;
	} else if(absoluteVerticalSpeed <= 1000) {
		offset = (absoluteVerticalSpeed * 0.068);
	} else if(absoluteVerticalSpeed <= 2000) {
		offset = ((absoluteVerticalSpeed - 1000) * 0.048) + 68;
	} else if(absoluteVerticalSpeed <= 6000) {
		offset = ((absoluteVerticalSpeed - 2000) * 0.0085) + 116;
	}

	offset = (isVerticalSpeedNegative ? offset : -offset);

	nvgSave(context);
	{
		nvgStrokeWidth(context, 3.0f);
		nvgStrokeColor(context, Colors::white);
		nvgLineCap(context, NVG_ROUND);
		nvgTranslate(context, 120, 161);
		{
			nvgScissor(context, -105, -160, 38, 320);
			nvgBeginPath(context);
			{
				nvgMoveTo(context, -25, 0);
				nvgLineTo(context, -100, offset);
			}
			nvgClosePath(context);
			nvgStroke(context);
			nvgResetScissor(context);
		}
		nvgResetTransform(context);
	}
	nvgRestore(context);
}

void PFDVerticalSpeedIndicator::drawTargetPointer(NVGcontext* context) {
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

	nvgSave(context);
	{
		nvgTranslate(context, 14, 161);
		{
			nvgStrokeWidth(context, 4);
			nvgStrokeColor(context, Colors::magenta);
			nvgBeginPath(context);
			{
				nvgMoveTo(context, 0, offset);
				nvgLineTo(context, 10, offset);
			}
			nvgClosePath(context);
			nvgStroke(context);
		}
		nvgResetTransform(context);
	}
	
	nvgRestore(context);
}
