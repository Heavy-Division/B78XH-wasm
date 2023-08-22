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


#include "PFDAltitudeIndicator.h"
#include "Simplane.h"
#include <cmath>
#include "Tools/Tools.h"
#include "fmt/core.h"

using Colors = Tools::Colors;

void PFDAltitudeIndicator::draw(NVGcontext* context, double deltaTime) {
	nvgSave(context);
	drawBackground(context);
	drawGraduations(context);
	drawGroundRibbon(context, deltaTime);
	drawCursor(context);
	drawTargetPointer(context);
	nvgRestore(context);
}

void PFDAltitudeIndicator::drawGroundRibbon(NVGcontext* context, double deltaTime) {
	namespace Aircraft = Simplane::aircraft;
	
	const double indicatedAltitude = Aircraft::state::indicatedAltitude();
	const double altitudeAboveGround = Aircraft::state::altitudeAboveGround();

	this->groundReference = Tools::smoothPow(this->groundReference, indicatedAltitude - altitudeAboveGround, 1.2, deltaTime);;
	
	const double delta = (indicatedAltitude - PFDAltitudeIndicator::groundReference);
	const double translateYPosition = delta * 0.58125 + 232.5;
	constexpr double lineHeight = 0.58125 * 500;
	nvgSave(context);
	{
		nvgScissor(context, -10, 0, 88, 465);
		nvgTranslate(context, -8, translateYPosition);
		{
			//nvgFillColor(context, nvgRGBA(255, 0, 0, 255));
			nvgStrokeWidth(context, 4.0f);
			nvgLineCap(context, NVG_ROUND);
			nvgBeginPath(context);
			{
				/*
				 * Vertical White
				 */
				nvgStrokeColor(context, Colors::white);
				nvgMoveTo(context, 0, -lineHeight);
				nvgLineTo(context, 0, -(lineHeight * 2));
				nvgLineTo(context, 6, -(lineHeight * 2));
			}
			nvgStroke(context);

			nvgBeginPath(context);
			{
				/*
				 * Vertical Orange
				 */
				nvgStrokeColor(context, Colors::amber);
				nvgMoveTo(context, 0, 0);
				nvgLineTo(context, 0, -lineHeight);
				nvgLineTo(context, 6, -lineHeight);

				/*
				 * Horizontal
				 */
				nvgMoveTo(context, 0, 0);
				nvgLineTo(context, 87, 0);

				/*
				 * Ribbon left
				 */
				nvgMoveTo(context, 15, 8);
				nvgLineTo(context, 30, 25);

				nvgMoveTo(context, 15, 19);
				nvgLineTo(context, 21, 25);

				/*
				 * Ribbon Full
				 */
				nvgMoveTo(context, 17, 0);
				nvgLineTo(context, 39, 25);
				nvgMoveTo(context, 26, 0);
				nvgLineTo(context, 48, 25);
				nvgMoveTo(context, 35, 0);
				nvgLineTo(context, 57, 25);
				nvgMoveTo(context, 44, 0);
				nvgLineTo(context, 66, 25);
				nvgMoveTo(context, 53, 0);
				nvgLineTo(context, 75, 25);
				nvgMoveTo(context, 62, 0);
				nvgLineTo(context, 84, 25);

				/*
				 * Ribbon right
				 */

				nvgMoveTo(context, 71, 0);
				nvgLineTo(context, 84, 14);

				nvgMoveTo(context, 80, 0);
				nvgLineTo(context, 84, 3);

			}
			nvgStroke(context);
		}
		nvgResetTransform(context);
		nvgResetScissor(context);
	}
	nvgRestore(context);
}

void PFDAltitudeIndicator::drawBackground(NVGcontext* context) {
	nvgFillColor(context, nvgRGBA(0, 0, 0, 100));
	nvgStrokeWidth(context, 1.0f);
	nvgStrokeColor(context, Colors::black);
	nvgBeginPath(context);
	{
		nvgRect(context, 0, 0, 80, 465);
	}
	nvgClosePath(context);
	nvgFill(context);
	nvgStroke(context);
}

void PFDAltitudeIndicator::drawGraduations(NVGcontext* context) {
	namespace Aircraft = Simplane::aircraft;

	const double indicatedAltitude = Aircraft::state::indicatedAltitude();

	const double modulo = fmod(indicatedAltitude, 100);
	const double pixelPerFeet = 0.58125;
	const double next100 = indicatedAltitude + (100 - modulo);
	const double baseTranslate = -((next100 - indicatedAltitude) * pixelPerFeet);


	int altitudesToRenderValues[11];
	bool altitudesToRenderFlag[11];

	for(int i = 0; i <= 10; i++) {
		const auto value = next100 + 500 - (i * 100);
		altitudesToRenderValues[i] = static_cast<int>(value);
		altitudesToRenderFlag[i] = fmod(value, 200) == 0 ? true : false;
	}


	/*
	 * Middle rendering
	 */

	nvgSave(context);
	{
		nvgFontFace(context, "roboto");
		nvgFontSize(context, 20.0f);
		nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgScissor(context, 0, 0, 84, 465);
		nvgTranslate(context, 0, baseTranslate + 232.5);
		{
			nvgFillColor(context, Colors::white);
			nvgBeginPath(context);

			/*
			 * Static implementation
			 */

			constexpr float offsets[11] = {-290, -232, -174, -116, -58, -0, 58, 116, 174, 232, 290};

			for(int i = 0; i < 11; i++) {
				if(altitudesToRenderFlag[i]) {
					const double altitude = altitudesToRenderValues[i];
					nvgText(context, 75, offsets[i], fmt::format("{:03}", altitude).c_str(), nullptr);
					if(fmod(altitude, 1000) == 0) {
						nvgRect(context, 18, offsets[i] - 15 - 3 * 0.5f, 62, 3);
						nvgRect(context, 18, offsets[i] + 15 - 3 * 0.5f, 62, 3);
					}
				}
			}

			for(int i = 0; i < 11; i++) {
				const double altitude = altitudesToRenderValues[i];
				if(fmod(altitude, 1000) == 0) {
					nvgRect(context, -4, offsets[i] - 7 * 0.5f, 22, 7);
				} else if(fmod(altitude, 500) == 0) {
					nvgRect(context, -2, offsets[i] - 7 * 0.5f, 22, 7);
				} else {
					nvgRect(context, -2, offsets[i] - 3 * 0.5f, 22, 3);
				}
			}

			nvgClosePath(context);
			nvgFill(context);
		}
		nvgResetTransform(context);
		nvgResetScissor(context);
	}
	nvgRestore(context);
}

void PFDAltitudeIndicator::drawCursor(NVGcontext* context) {
	namespace Aircraft = Simplane::aircraft;

	nvgStrokeWidth(context, 3.0f);
	nvgStrokeColor(context, Colors::white);
	nvgFillColor(context, Colors::black);
	nvgBeginPath(context);
	{
		nvgMoveTo(context, 26, 232.5 - 29);
		nvgLineTo(context, 26 + 84, 232.5 - 29);
		nvgLineTo(context, 26 + 84, 232.5 + 29);
		nvgLineTo(context, 26, 232.5 + 29);
		nvgLineTo(context, 26, 232.5 + 10);
		nvgLineTo(context, 15, 232.5);
		nvgLineTo(context, 26, 232.5 - 10);
		nvgLineTo(context, 26, 232.5 - 29);
	}
	nvgClosePath(context);

	nvgFill(context);
	nvgStroke(context);


	nvgScissor(context,  15, 232.5 - 25, 100, 50);

	const double indicatedAltitude = Aircraft::state::indicatedAltitude();
	const int tenThousands = floor(indicatedAltitude / 10000);
	const int thousands = floor((indicatedAltitude - tenThousands * 10000) / 1000);
	const int hundreds = floor((indicatedAltitude - (thousands * 1000) - (tenThousands * 10000)) / 100);
	const int tensWithOnes = floor(indicatedAltitude - (hundreds * 100) - (thousands * 1000) - (tenThousands * 10000));
	const int tens = floor(tensWithOnes / 10);
	const double ones = indicatedAltitude - (tens * 10) - (hundreds * 100) - (thousands * 1000) - (tenThousands *
		10000);

	/**
	 * Tens
	 */

	nvgSave(context);
	{
		nvgStrokeWidth(context, 3.0f);
		nvgStrokeColor(context, Colors::white);
		nvgFillColor(context, Colors::white);
		nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgFontSize(context, 30.0f);
		nvgTranslate(context,  16 + 90, tensWithOnes + 232.5);
		{
			nvgBeginPath(context);
			{
				nvgText(context, 0, -120, "20", nullptr);
				nvgText(context, 0, -100, "00", nullptr);
				nvgText(context, 0, -80, "80", nullptr);
				nvgText(context, 0, -60, "60", nullptr);
				nvgText(context, 0, -40, "40", nullptr);
				nvgText(context, 0, -20, "20", nullptr);
				nvgText(context, 0, 0, "00", nullptr);
				nvgText(context, 0, 20, "80", nullptr);
			}
			nvgClosePath(context);

			nvgFill(context);
			nvgResetTransform(context);
		}
	}
	nvgRestore(context);

	/*
	 * Hundreds
	 */

	const double hundredsOffset = hundreds * 40 + (tensWithOnes > 80 ? fmod(tensWithOnes, 80) * 2 : 0);


	nvgSave(context);
	{
		nvgStrokeWidth(context, 3.0f);
		nvgStrokeColor(context, Colors::white);
		nvgFillColor(context, Colors::white);
		nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgFontSize(context, 30.0f);
		nvgTranslate(context, 16 + 63, hundredsOffset + 232.5);
		{
			nvgBeginPath(context);
			{
				nvgText(context, 0, -400, "0", nullptr);
				nvgText(context, 0, -360, "9", nullptr);
				nvgText(context, 0, -320, "8", nullptr);
				nvgText(context, 0, -280, "7", nullptr);
				nvgText(context, 0, -240, "6", nullptr);
				nvgText(context, 0, -200, "5", nullptr);
				nvgText(context, 0, -160, "4", nullptr);
				nvgText(context, 0, -120, "3", nullptr);
				nvgText(context, 0, -80, "2", nullptr);
				nvgText(context, 0, -40, "1", nullptr);
				nvgText(context, 0, 0, "0", nullptr);
				nvgText(context, 0, 40, "9", nullptr);
			}
			nvgClosePath(context);

			nvgFill(context);
		}
		nvgResetTransform(context);
	}
	nvgRestore(context);


	/*
	 * Thousands
	 */

	const double thousandsOffset = thousands * 40 + (
		tensWithOnes > 80 && hundreds == 9 ? fmod(tensWithOnes, 80) * 2 : 0);

	nvgSave(context);
	{
		nvgStrokeWidth(context, 3.0f);
		nvgStrokeColor(context, Colors::white);
		nvgFillColor(context, Colors::white);
		nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgFontSize(context, 42.0f);

		nvgTranslate(context, 16 + 49, thousandsOffset + 232.5);
		{
			nvgBeginPath(context);
			{
				nvgText(context, 0, -400, "0", nullptr);
				nvgText(context, 0, -360, "9", nullptr);
				nvgText(context, 0, -320, "8", nullptr);
				nvgText(context, 0, -280, "7", nullptr);
				nvgText(context, 0, -240, "6", nullptr);
				nvgText(context, 0, -200, "5", nullptr);
				nvgText(context, 0, -160, "4", nullptr);
				nvgText(context, 0, -120, "3", nullptr);
				nvgText(context, 0, -80, "2", nullptr);
				nvgText(context, 0, -40, "1", nullptr);
				nvgText(context, 0, 0, "0", nullptr);
				nvgText(context, 0, 40, "9", nullptr);
			}
			nvgClosePath(context);

			nvgFill(context);
		}
		nvgResetTransform(context);
	}
	nvgRestore(context);


	/*
	 * Ten Thousands
	 */

	const double tenThousandsOffset = tenThousands * 40 + (tensWithOnes > 80 && hundreds == 9 && thousands == 9
		                                                       ? fmod(tensWithOnes, 80) * 2
		                                                       : 0);
	if(indicatedAltitude > 9980) {
		nvgSave(context);
		{
			nvgStrokeWidth(context, 3.0f);
			nvgStrokeColor(context, Colors::white);
			nvgFillColor(context, Colors::white);
			nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
			nvgFontSize(context, 40.0f);
			nvgTranslate(context, 16 + 30, tenThousandsOffset + 232.5);
			{
				nvgBeginPath(context);
				{
					nvgText(context, 0, -240, "6", nullptr);
					nvgText(context, 0, -200, "5", nullptr);
					nvgText(context, 0, -160, "4", nullptr);
					nvgText(context, 0, -120, "3", nullptr);
					nvgText(context, 0, -80, "2", nullptr);
					nvgText(context, 0, -40, "1", nullptr);
				}
				nvgClosePath(context);

				nvgFill(context);
			}
			nvgResetTransform(context);
		}
		nvgRestore(context);
	} else {
		const auto offsetX = 4;
		nvgSave(context);
		{
			nvgTranslate(context, 16 + 15, 232.5);
			{
				nvgStrokeColor(context, Colors::green);
				nvgStrokeWidth(context, 1.0f);
				nvgScissor(context, 0, -12, 15, 24);
				nvgBeginPath(context);
				{
					nvgMoveTo(context, -15, -12);
					for (int i = 1; i < 9; i++) {
						nvgLineTo(context, (i * offsetX), 12);
						nvgMoveTo(context, -15 + (i * offsetX), -12);
					}
					//nvgRect(context, 0, -12, 15, 24);
				}
				nvgClosePath(context);
				nvgStroke(context);
				nvgResetScissor(context);
			}
			nvgResetTransform(context);
		}
		nvgRestore(context);
	}
	nvgResetScissor(context);

}

void PFDAltitudeIndicator::drawTargetPointer(NVGcontext* context) {
	namespace Aircraft = Simplane::aircraft;
	namespace Autopilot = Simplane::autopilot;
	const double pixelPerFeet = 0.58125;
	const double indicatedAltitude = Aircraft::state::indicatedAltitude();
	const double selectedAltitude = Autopilot::altitude::altitudeLockVar3();
	const double diff = (indicatedAltitude - selectedAltitude);
	double offset = pixelPerFeet * diff;
	if(abs(offset) > 232.5) {
		offset = (offset < 0 ? -232.5 : 232.5);
	}

	nvgSave(context);
	nvgTranslate(context, 0, 232.5);
	{
		nvgScissor(context, -10, -232.5, 68, 465);
		nvgTranslate(context, 0, offset);
		{
			nvgStrokeColor(context, Colors::magenta);
			nvgStrokeWidth(context, 3.0f);
			nvgLineJoin(context, NVG_ROUND);
			nvgBeginPath(context);
			{
				nvgMoveTo(context, 0, 0);
				nvgLineTo(context, -8, -10);
				nvgLineTo(context, -8, -28);
				nvgLineTo(context, 37, -28);
				nvgLineTo(context, 37, 30);
				nvgLineTo(context, -8, 30);
				nvgLineTo(context, -8, 10);
			}
			nvgClosePath(context);
			nvgStroke(context);
		}
		nvgResetScissor(context);
	}
	nvgResetTransform(context);
	nvgRestore(context);
}
