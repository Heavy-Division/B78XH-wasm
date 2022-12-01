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


#include "PFDAltitudeIndicatorApplication.h"

#include "Tools/Tools.h"
#include "Simplane.h"
#include <cmath>

using Colors = Tools::Colors;

void PFDAltitudeIndicatorApplication::render(sGaugeDrawData* data) {
	drawBackground();
	drawGraduations();
	drawGroundRibbon(data->dt);
	drawCursor();
	drawTargetPointer();
}


void PFDAltitudeIndicatorApplication::drawGroundRibbon(double deltaTime) {
	namespace Aircraft = Simplane::aircraft;

	const double indicatedAltitude = Aircraft::state::indicatedAltitude();
	const double altitudeAboveGround = Aircraft::state::altitudeAboveGround();

	this->groundReference = Tools::smoothPow(this->groundReference, indicatedAltitude - altitudeAboveGround, 1.2, deltaTime);;

	const double delta = (indicatedAltitude - this->groundReference);
	const double translateYPosition = delta * 0.58125 + 232.5;
	constexpr double lineHeight = 0.58125 * 500;
	nvgSave(this->nvgContext);
	{
		nvgScissor(this->nvgContext, -10, 0, 88, 465);
		nvgTranslate(this->nvgContext, -8, translateYPosition);
		{
			//nvgFillColor(this->nvgContext, nvgRGBA(255, 0, 0, 255));
			nvgStrokeWidth(this->nvgContext, 4.0f);
			nvgLineCap(this->nvgContext, NVG_ROUND);
			nvgBeginPath(this->nvgContext);
			{
				/*
				 * Vertical White
				 */
				nvgStrokeColor(this->nvgContext, Colors::white);
				nvgMoveTo(this->nvgContext, 0, -lineHeight);
				nvgLineTo(this->nvgContext, 0, -(lineHeight * 2));
				nvgLineTo(this->nvgContext, 6, -(lineHeight * 2));
			}
			nvgStroke(this->nvgContext);

			nvgBeginPath(this->nvgContext);
			{
				/*
				 * Vertical Orange
				 */
				nvgStrokeColor(this->nvgContext, Colors::amber);
				nvgMoveTo(this->nvgContext, 0, 0);
				nvgLineTo(this->nvgContext, 0, -lineHeight);
				nvgLineTo(this->nvgContext, 6, -lineHeight);

				/*
				 * Horizontal
				 */
				nvgMoveTo(this->nvgContext, 0, 0);
				nvgLineTo(this->nvgContext, 87, 0);

				/*
				 * Ribbon left
				 */
				nvgMoveTo(this->nvgContext, 15, 8);
				nvgLineTo(this->nvgContext, 30, 25);

				nvgMoveTo(this->nvgContext, 15, 19);
				nvgLineTo(this->nvgContext, 21, 25);

				/*
				 * Ribbon Full
				 */
				nvgMoveTo(this->nvgContext, 17, 0);
				nvgLineTo(this->nvgContext, 39, 25);
				nvgMoveTo(this->nvgContext, 26, 0);
				nvgLineTo(this->nvgContext, 48, 25);
				nvgMoveTo(this->nvgContext, 35, 0);
				nvgLineTo(this->nvgContext, 57, 25);
				nvgMoveTo(this->nvgContext, 44, 0);
				nvgLineTo(this->nvgContext, 66, 25);
				nvgMoveTo(this->nvgContext, 53, 0);
				nvgLineTo(this->nvgContext, 75, 25);
				nvgMoveTo(this->nvgContext, 62, 0);
				nvgLineTo(this->nvgContext, 84, 25);

				/*
				 * Ribbon right
				 */

				nvgMoveTo(this->nvgContext, 71, 0);
				nvgLineTo(this->nvgContext, 84, 14);

				nvgMoveTo(this->nvgContext, 80, 0);
				nvgLineTo(this->nvgContext, 84, 3);

			}
			nvgStroke(this->nvgContext);
		}
		nvgResetTransform(this->nvgContext);
		nvgResetScissor(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

void PFDAltitudeIndicatorApplication::drawBackground() {
	nvgFillColor(this->nvgContext, nvgRGBA(0, 0, 0, 100));
	nvgStrokeWidth(this->nvgContext, 1.0f);
	nvgStrokeColor(this->nvgContext, Colors::black);
	nvgBeginPath(this->nvgContext);
	{
		nvgRect(this->nvgContext, 0, 0, 80, 465);
	}
	nvgClosePath(this->nvgContext);
	nvgFill(this->nvgContext);
	nvgStroke(this->nvgContext);
}

void PFDAltitudeIndicatorApplication::drawGraduations() {
	namespace Aircraft = Simplane::aircraft;

	const double indicatedAltitude = Aircraft::state::indicatedAltitude();

	const double modulo = fmod(indicatedAltitude, 100);
	const double pixelPerFeet = 0.58125;
	const double next100 = indicatedAltitude + (100 - modulo);
	const double baseTranslate = -((next100 - indicatedAltitude) * pixelPerFeet);


	int altitudesToRenderValues[11];
	bool altitudesToRenderFlag[11];

	for (int i = 0; i <= 10; i++) {
		const auto value = next100 + 500 - (i * 100);
		altitudesToRenderValues[i] = static_cast<int>(value);
		altitudesToRenderFlag[i] = fmod(value, 200) == 0 ? true : false;
	}


	/*
	 * Middle rendering
	 */

	nvgSave(this->nvgContext);
	{
		nvgFontFace(this->nvgContext, "roboto");
		nvgFontSize(this->nvgContext, 20.0f);
		nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgScissor(this->nvgContext, 0, 0, 84, 465);
		nvgTranslate(this->nvgContext, 0, baseTranslate + 232.5);
		{
			nvgFillColor(this->nvgContext, Colors::white);
			nvgBeginPath(this->nvgContext);

			/*
			 * Static implementation
			 */

			constexpr float offsets[11] = { -290, -232, -174, -116, -58, -0, 58, 116, 174, 232, 290 };

			for (int i = 0; i < 11; i++) {
				if (altitudesToRenderFlag[i]) {
					const double altitude = altitudesToRenderValues[i];
					nvgText(this->nvgContext, 75, offsets[i], fmt::format("{:03}", altitude).c_str(), nullptr);
					if (fmod(altitude, 1000) == 0) {
						nvgRect(this->nvgContext, 18, offsets[i] - 15 - 3 * 0.5f, 62, 3);
						nvgRect(this->nvgContext, 18, offsets[i] + 15 - 3 * 0.5f, 62, 3);
					}
				}
			}

			for (int i = 0; i < 11; i++) {
				const double altitude = altitudesToRenderValues[i];
				if (fmod(altitude, 1000) == 0) {
					nvgRect(this->nvgContext, -4, offsets[i] - 7 * 0.5f, 22, 7);
				}
				else if (fmod(altitude, 500) == 0) {
					nvgRect(this->nvgContext, -2, offsets[i] - 7 * 0.5f, 22, 7);
				}
				else {
					nvgRect(this->nvgContext, -2, offsets[i] - 3 * 0.5f, 22, 3);
				}
			}

			nvgClosePath(this->nvgContext);
			nvgFill(this->nvgContext);
		}
		nvgResetTransform(this->nvgContext);
		nvgResetScissor(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

void PFDAltitudeIndicatorApplication::drawCursor() {
	namespace Aircraft = Simplane::aircraft;

	nvgStrokeWidth(this->nvgContext, 3.0f);
	nvgStrokeColor(this->nvgContext, Colors::white);
	nvgFillColor(this->nvgContext, Colors::black);
	nvgBeginPath(this->nvgContext);
	{
		nvgMoveTo(this->nvgContext, 26, 232.5 - 29);
		nvgLineTo(this->nvgContext, 26 + 84, 232.5 - 29);
		nvgLineTo(this->nvgContext, 26 + 84, 232.5 + 29);
		nvgLineTo(this->nvgContext, 26, 232.5 + 29);
		nvgLineTo(this->nvgContext, 26, 232.5 + 10);
		nvgLineTo(this->nvgContext, 15, 232.5);
		nvgLineTo(this->nvgContext, 26, 232.5 - 10);
		nvgLineTo(this->nvgContext, 26, 232.5 - 29);
	}
	nvgClosePath(this->nvgContext);

	nvgFill(this->nvgContext);
	nvgStroke(this->nvgContext);


	nvgScissor(this->nvgContext, 15, 232.5 - 25, 100, 50);

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

	nvgSave(this->nvgContext);
	{
		nvgStrokeWidth(this->nvgContext, 3.0f);
		nvgStrokeColor(this->nvgContext, Colors::white);
		nvgFillColor(this->nvgContext, Colors::white);
		nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgFontSize(this->nvgContext, 30.0f);
		nvgTranslate(this->nvgContext, 16 + 90, tensWithOnes + 232.5);
		{
			nvgBeginPath(this->nvgContext);
			{
				nvgText(this->nvgContext, 0, -120, "20", nullptr);
				nvgText(this->nvgContext, 0, -100, "00", nullptr);
				nvgText(this->nvgContext, 0, -80, "80", nullptr);
				nvgText(this->nvgContext, 0, -60, "60", nullptr);
				nvgText(this->nvgContext, 0, -40, "40", nullptr);
				nvgText(this->nvgContext, 0, -20, "20", nullptr);
				nvgText(this->nvgContext, 0, 0, "00", nullptr);
				nvgText(this->nvgContext, 0, 20, "80", nullptr);
			}
			nvgClosePath(this->nvgContext);

			nvgFill(this->nvgContext);
			nvgResetTransform(this->nvgContext);
		}
	}
	nvgRestore(this->nvgContext);

	/*
	 * Hundreds
	 */

	const double hundredsOffset = hundreds * 40 + (tensWithOnes > 80 ? fmod(tensWithOnes, 80) * 2 : 0);


	nvgSave(this->nvgContext);
	{
		nvgStrokeWidth(this->nvgContext, 3.0f);
		nvgStrokeColor(this->nvgContext, Colors::white);
		nvgFillColor(this->nvgContext, Colors::white);
		nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgFontSize(this->nvgContext, 30.0f);
		nvgTranslate(this->nvgContext, 16 + 63, hundredsOffset + 232.5);
		{
			nvgBeginPath(this->nvgContext);
			{
				nvgText(this->nvgContext, 0, -400, "0", nullptr);
				nvgText(this->nvgContext, 0, -360, "9", nullptr);
				nvgText(this->nvgContext, 0, -320, "8", nullptr);
				nvgText(this->nvgContext, 0, -280, "7", nullptr);
				nvgText(this->nvgContext, 0, -240, "6", nullptr);
				nvgText(this->nvgContext, 0, -200, "5", nullptr);
				nvgText(this->nvgContext, 0, -160, "4", nullptr);
				nvgText(this->nvgContext, 0, -120, "3", nullptr);
				nvgText(this->nvgContext, 0, -80, "2", nullptr);
				nvgText(this->nvgContext, 0, -40, "1", nullptr);
				nvgText(this->nvgContext, 0, 0, "0", nullptr);
				nvgText(this->nvgContext, 0, 40, "9", nullptr);
			}
			nvgClosePath(this->nvgContext);

			nvgFill(this->nvgContext);
		}
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);


	/*
	 * Thousands
	 */

	const double thousandsOffset = thousands * 40 + (
		tensWithOnes > 80 && hundreds == 9 ? fmod(tensWithOnes, 80) * 2 : 0);

	nvgSave(this->nvgContext);
	{
		nvgStrokeWidth(this->nvgContext, 3.0f);
		nvgStrokeColor(this->nvgContext, Colors::white);
		nvgFillColor(this->nvgContext, Colors::white);
		nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgFontSize(this->nvgContext, 42.0f);

		nvgTranslate(this->nvgContext, 16 + 49, thousandsOffset + 232.5);
		{
			nvgBeginPath(this->nvgContext);
			{
				nvgText(this->nvgContext, 0, -400, "0", nullptr);
				nvgText(this->nvgContext, 0, -360, "9", nullptr);
				nvgText(this->nvgContext, 0, -320, "8", nullptr);
				nvgText(this->nvgContext, 0, -280, "7", nullptr);
				nvgText(this->nvgContext, 0, -240, "6", nullptr);
				nvgText(this->nvgContext, 0, -200, "5", nullptr);
				nvgText(this->nvgContext, 0, -160, "4", nullptr);
				nvgText(this->nvgContext, 0, -120, "3", nullptr);
				nvgText(this->nvgContext, 0, -80, "2", nullptr);
				nvgText(this->nvgContext, 0, -40, "1", nullptr);
				nvgText(this->nvgContext, 0, 0, "0", nullptr);
				nvgText(this->nvgContext, 0, 40, "9", nullptr);
			}
			nvgClosePath(this->nvgContext);

			nvgFill(this->nvgContext);
		}
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);


	/*
	 * Ten Thousands
	 */

	const double tenThousandsOffset = tenThousands * 40 + (tensWithOnes > 80 && hundreds == 9 && thousands == 9
		? fmod(tensWithOnes, 80) * 2
		: 0);
	if (indicatedAltitude > 9980) {
		nvgSave(this->nvgContext);
		{
			nvgStrokeWidth(this->nvgContext, 3.0f);
			nvgStrokeColor(this->nvgContext, Colors::white);
			nvgFillColor(this->nvgContext, Colors::white);
			nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
			nvgFontSize(this->nvgContext, 40.0f);
			nvgTranslate(this->nvgContext, 16 + 30, tenThousandsOffset + 232.5);
			{
				nvgBeginPath(this->nvgContext);
				{
					nvgText(this->nvgContext, 0, -240, "6", nullptr);
					nvgText(this->nvgContext, 0, -200, "5", nullptr);
					nvgText(this->nvgContext, 0, -160, "4", nullptr);
					nvgText(this->nvgContext, 0, -120, "3", nullptr);
					nvgText(this->nvgContext, 0, -80, "2", nullptr);
					nvgText(this->nvgContext, 0, -40, "1", nullptr);
				}
				nvgClosePath(this->nvgContext);

				nvgFill(this->nvgContext);
			}
			nvgResetTransform(this->nvgContext);
		}
		nvgRestore(this->nvgContext);
	}
	else {
		const auto offsetX = 4;
		nvgSave(this->nvgContext);
		{
			nvgTranslate(this->nvgContext, 16 + 15, 232.5);
			{
				nvgStrokeColor(this->nvgContext, Colors::green);
				nvgStrokeWidth(this->nvgContext, 1.0f);
				nvgScissor(this->nvgContext, 0, -12, 15, 24);
				nvgBeginPath(this->nvgContext);
				{
					nvgMoveTo(this->nvgContext, -15, -12);
					for (int i = 1; i < 9; i++) {
						nvgLineTo(this->nvgContext, (i * offsetX), 12);
						nvgMoveTo(this->nvgContext, -15 + (i * offsetX), -12);
					}
					//nvgRect(this->nvgContext, 0, -12, 15, 24);
				}
				nvgClosePath(this->nvgContext);
				nvgStroke(this->nvgContext);
				nvgResetScissor(this->nvgContext);
			}
			nvgResetTransform(this->nvgContext);
		}
		nvgRestore(this->nvgContext);
	}
	nvgResetScissor(this->nvgContext);

}

void PFDAltitudeIndicatorApplication::drawTargetPointer() {
	namespace Aircraft = Simplane::aircraft;
	namespace Autopilot = Simplane::autopilot;
	const double pixelPerFeet = 0.58125;
	const double indicatedAltitude = Aircraft::state::indicatedAltitude();
	const double selectedAltitude = Autopilot::altitude::altitudeLockVar3();
	const double diff = (indicatedAltitude - selectedAltitude);
	double offset = pixelPerFeet * diff;
	if (abs(offset) > 232.5) {
		offset = (offset < 0 ? -232.5 : 232.5);
	}

	nvgSave(this->nvgContext);
	nvgTranslate(this->nvgContext, 0, 232.5);
	{
		nvgScissor(this->nvgContext, -10, -232.5, 68, 465);
		nvgTranslate(this->nvgContext, 0, offset);
		{
			nvgStrokeColor(this->nvgContext, Colors::magenta);
			nvgStrokeWidth(this->nvgContext, 3.0f);
			nvgLineJoin(this->nvgContext, NVG_ROUND);
			nvgBeginPath(this->nvgContext);
			{
				nvgMoveTo(this->nvgContext, 0, 0);
				nvgLineTo(this->nvgContext, -8, -10);
				nvgLineTo(this->nvgContext, -8, -28);
				nvgLineTo(this->nvgContext, 37, -28);
				nvgLineTo(this->nvgContext, 37, 30);
				nvgLineTo(this->nvgContext, -8, 30);
				nvgLineTo(this->nvgContext, -8, 10);
			}
			nvgClosePath(this->nvgContext);
			nvgStroke(this->nvgContext);
		}
		nvgResetScissor(this->nvgContext);
	}
	nvgResetTransform(this->nvgContext);
	nvgRestore(this->nvgContext);
}
