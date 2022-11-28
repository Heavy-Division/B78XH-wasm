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


#include "PFDAttitudeApplication.h"

#include <cmath>

#include "SimConnectData.h"
#include "Tools.h"

void PFDAttitudeApplication::render(sGaugeDrawData* data) {
	this->renderMainBackground();
	this->renderAttitude();
	this->renderPitch();

	this->renderTriangle();
	this->renderDashes();
	this->renderCursor();
	this->renderSlipSkid();
}

void PFDAttitudeApplication::postInstall() {
	this->slipSkidVariableId = get_aircraft_var_enum("TURN COORDINATOR BALL");
	this->slipSkidUnitsId = get_units_enum("position");
}

void PFDAttitudeApplication::renderMainBackground() {
	nvgFillColor(nvgContext, Tools::Colors::black);
	nvgBeginPath(nvgContext);
	nvgRect(nvgContext, 0, 0, this->width, this->height);
	nvgFill(nvgContext);
	nvgClosePath(nvgContext);
}

void PFDAttitudeApplication::renderAttitude() {
	/*
	 * Pitch graduation:
	 *		is linear: true
	 *		+ resolution in degrees: +45
	 *		- resolution in degrees: -45
	 *		full resolution in degrees: 90
	 *
	 *	Ingame PFD values:
	 *		full resolution in pixels (height): 622
	 *		half resolution in pixels (height): 311
	 *		pixels per degree: 6.91111111111
	 *		size of attitude: 1057.3121
	 *		middle of size = 528.65605
	 */


	// top  - nvgRGB(4,113,203)
	// bottom - nvgRGB(112,78,5)

	const float size = sqrt(this->width * this->width + this->height * this->height);
	const float h = size * 0.5f + -(6.91111111111 * SimConnectData::Aircraft::state.pitch);

	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, this->width * 0.5f, this->height * 0.5f);
		nvgRotate(this->nvgContext, SimConnectData::Aircraft::state.bank * M_PI / 180.0f);
		nvgFillColor(this->nvgContext, nvgRGB(4, 113, 203));
		nvgBeginPath(this->nvgContext);
		nvgRect(this->nvgContext, -(size * 0.5f), -(size * 0.5f), size, h);
		nvgClosePath(this->nvgContext);
		nvgFill(this->nvgContext);


		nvgFillColor(this->nvgContext, nvgRGB(112, 78, 5));
		nvgBeginPath(this->nvgContext);
		nvgRect(this->nvgContext, -(size * 0.5f), -(size * 0.5f) + h, size, size - h);
		nvgClosePath(this->nvgContext);
		nvgFill(this->nvgContext);
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

void PFDAttitudeApplication::renderPitch() {
	const float size = sqrt(this->width * this->width + this->height * this->height);
	//const float h = size * 0.5f * (1.0f - sin(SimConnectData::Aircraft::state.pitch / 2 * M_PI / 180.0f));
	const float h = size * 0.5f + -(6.91111111111 * SimConnectData::Aircraft::state.pitch);
	const double center = -(size * 0.5f) + h - 1.5;
	const double pitchFactor = 6.91111111111;
	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, this->width * 0.5f, this->height * 0.5f);
		{
			nvgRotate(this->nvgContext, SimConnectData::Aircraft::state.bank * M_PI / 180.0f);
			nvgScissor(this->nvgContext, -85, -130, 170, 280);
			{
				nvgFillColor(this->nvgContext, Tools::Colors::white);
				nvgBeginPath(this->nvgContext);
				nvgRect(this->nvgContext, -20, center + pitchFactor * -2.5 - 2 / 2, 40, 2);
				nvgRect(this->nvgContext, -30, center + pitchFactor * -5 - 3 / 2, 60, 3);
				nvgRect(this->nvgContext, -20, center + pitchFactor * -7.5 - 2 / 2, 40, 2);
				nvgRect(this->nvgContext, -60, center + pitchFactor * -10 - 3 / 2, 120, 3);
				nvgRect(this->nvgContext, -20, center + pitchFactor * -12.5 - 2 / 2, 40, 2);
				nvgRect(this->nvgContext, -30, center + pitchFactor * -15 - 3 / 2, 60, 3);
				nvgRect(this->nvgContext, -20, center + pitchFactor * -17.5 - 2 / 2, 40, 2);
				nvgRect(this->nvgContext, -60, center + pitchFactor * -20 - 3 / 2, 120, 3);
				nvgRect(this->nvgContext, -20, center + pitchFactor * -22.5 - 2 / 2, 40, 2);
				nvgRect(this->nvgContext, -30, center + pitchFactor * -25 - 3 / 2, 60, 3);
				nvgRect(this->nvgContext, -60, center + pitchFactor * -30 - 3 / 2, 120, 3);
				nvgRect(this->nvgContext, -60, center + pitchFactor * -40 - 3 / 2, 120, 3);
				nvgRect(this->nvgContext, -60, center + pitchFactor * -50 - 3 / 2, 120, 3);
				nvgRect(this->nvgContext, -60, center + pitchFactor * -60 - 3 / 2, 120, 3);
				nvgRect(this->nvgContext, -60, center + pitchFactor * -70 - 3 / 2, 120, 3);
				nvgRect(this->nvgContext, -60, center + pitchFactor * -80 - 3 / 2, 120, 3);

				nvgRect(this->nvgContext, -20, center + pitchFactor * 2.5 + 2 / 2, 40, 2);
				nvgRect(this->nvgContext, -30, center + pitchFactor * 5 + 3 / 2, 60, 3);
				nvgRect(this->nvgContext, -20, center + pitchFactor * 7.5 + 2 / 2, 40, 2);
				nvgRect(this->nvgContext, -60, center + pitchFactor * 10 + 3 / 2, 120, 3);
				nvgRect(this->nvgContext, -20, center + pitchFactor * 12.5 + 2 / 2, 40, 2);
				nvgRect(this->nvgContext, -30, center + pitchFactor * 15 + 3 / 2, 60, 3);
				nvgRect(this->nvgContext, -20, center + pitchFactor * 17.5 + 2 / 2, 40, 2);
				nvgRect(this->nvgContext, -60, center + pitchFactor * 20 + 3 / 2, 120, 3);
				nvgRect(this->nvgContext, -20, center + pitchFactor * 22.5 + 2 / 2, 40, 2);
				nvgRect(this->nvgContext, -30, center + pitchFactor * 25 + 3 / 2, 60, 3);
				nvgRect(this->nvgContext, -60, center + pitchFactor * 30 + 3 / 2, 120, 3);
				nvgRect(this->nvgContext, -60, center + pitchFactor * 40 + 3 / 2, 120, 3);
				nvgRect(this->nvgContext, -60, center + pitchFactor * 50 + 3 / 2, 120, 3);
				nvgRect(this->nvgContext, -60, center + pitchFactor * 60 + 3 / 2, 120, 3);
				nvgRect(this->nvgContext, -60, center + pitchFactor * 70 + 3 / 2, 120, 3);
				nvgRect(this->nvgContext, -60, center + pitchFactor * 80 + 3 / 2, 120, 3);

				nvgFontSize(this->nvgContext, 20.0f);
				nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
				nvgText(this->nvgContext, -65, center + pitchFactor * 10 + 1.5, "10", nullptr);
				nvgText(this->nvgContext, -65, center + pitchFactor * -10 - 1.5, "10", nullptr);
				nvgText(this->nvgContext, -65, center + pitchFactor * 20 + 1.5, "20", nullptr);
				nvgText(this->nvgContext, -65, center + pitchFactor * -20 - 1.5, "20", nullptr);
				nvgText(this->nvgContext, -65, center + pitchFactor * 30 + 1.5, "30", nullptr);
				nvgText(this->nvgContext, -65, center + pitchFactor * -30 - 1.5, "30", nullptr);
				nvgText(this->nvgContext, -65, center + pitchFactor * 40 + 1.5, "40", nullptr);
				nvgText(this->nvgContext, -65, center + pitchFactor * -40 - 1.5, "40", nullptr);
				nvgText(this->nvgContext, -65, center + pitchFactor * 50 + 1.5, "50", nullptr);
				nvgText(this->nvgContext, -65, center + pitchFactor * -50 - 1.5, "50", nullptr);
				nvgText(this->nvgContext, -65, center + pitchFactor * 60 + 1.5, "60", nullptr);
				nvgText(this->nvgContext, -65, center + pitchFactor * -60 - 1.5, "60", nullptr);
				nvgText(this->nvgContext, -65, center + pitchFactor * 70 + 1.5, "70", nullptr);
				nvgText(this->nvgContext, -65, center + pitchFactor * -70 - 1.5, "70", nullptr);
				nvgText(this->nvgContext, -65, center + pitchFactor * 80 + 1.5, "80", nullptr);
				nvgText(this->nvgContext, -65, center + pitchFactor * -80 - 1.5, "80", nullptr);

				nvgTextAlign(this->nvgContext, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
				nvgText(this->nvgContext, 65, center + pitchFactor * 10 + 1.5, "10", nullptr);
				nvgText(this->nvgContext, 65, center + pitchFactor * -10 - 1.5, "10", nullptr);
				nvgText(this->nvgContext, 65, center + pitchFactor * 20 + 1.5, "20", nullptr);
				nvgText(this->nvgContext, 65, center + pitchFactor * -20 - 1.5, "20", nullptr);
				nvgText(this->nvgContext, 65, center + pitchFactor * 30 + 1.5, "30", nullptr);
				nvgText(this->nvgContext, 65, center + pitchFactor * -30 - 1.5, "30", nullptr);
				nvgText(this->nvgContext, 65, center + pitchFactor * 40 + 1.5, "40", nullptr);
				nvgText(this->nvgContext, 65, center + pitchFactor * -40 - 1.5, "40", nullptr);
				nvgText(this->nvgContext, 65, center + pitchFactor * 50 + 1.5, "50", nullptr);
				nvgText(this->nvgContext, 65, center + pitchFactor * -50 - 1.5, "50", nullptr);
				nvgText(this->nvgContext, 65, center + pitchFactor * 60 + 1.5, "60", nullptr);
				nvgText(this->nvgContext, 65, center + pitchFactor * -60 - 1.5, "60", nullptr);
				nvgText(this->nvgContext, 65, center + pitchFactor * 70 + 1.5, "70", nullptr);
				nvgText(this->nvgContext, 65, center + pitchFactor * -70 - 1.5, "70", nullptr);
				nvgText(this->nvgContext, 65, center + pitchFactor * 80 + 1.5, "80", nullptr);
				nvgText(this->nvgContext, 65, center + pitchFactor * -80 - 1.5, "80", nullptr);


				nvgClosePath(this->nvgContext);
				nvgFill(this->nvgContext);
			}

			nvgResetScissor(this->nvgContext);
		}

		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

void PFDAttitudeApplication::renderTriangle() {
	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, this->width * 0.5f, this->height * 0.5f);
		nvgStrokeColor(this->nvgContext, Tools::Colors::white);
		nvgStrokeWidth(this->nvgContext, 1.0f);
		nvgFillColor(this->nvgContext, Tools::Colors::white);
		nvgBeginPath(this->nvgContext);
		nvgMoveTo(this->nvgContext, 0, -160);
		nvgLineTo(this->nvgContext, -6, -169);
		nvgLineTo(this->nvgContext, 6, -169);
		nvgLineTo(this->nvgContext, 0, -160);
		nvgFill(this->nvgContext);
		nvgStroke(this->nvgContext);
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

void PFDAttitudeApplication::renderDashes() {
	this->renderDash(-60, 16);
	this->renderDash(-45, 10);
	this->renderDash(-30, 24);
	this->renderDash(-20, 10);
	this->renderDash(-10, 10);
	this->renderDash(10, 10);
	this->renderDash(20, 10);
	this->renderDash(30, 24);
	this->renderDash(45, 10);
	this->renderDash(60, 16);
}

void PFDAttitudeApplication::renderDash(int angle, int length) {
	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, this->width * 0.5f, this->height * 0.5f);
		nvgRotate(this->nvgContext, angle * NVG_PI / 180);
		nvgStrokeColor(this->nvgContext, Tools::Colors::white);
		nvgStrokeWidth(this->nvgContext, 3.0f);

		nvgBeginPath(this->nvgContext);
		nvgMoveTo(this->nvgContext, 0, -160);
		nvgLineTo(this->nvgContext, 0, -160 - length);
		nvgStroke(this->nvgContext);
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

void PFDAttitudeApplication::renderCursor() {
	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, this->width * 0.5f, this->height * 0.5f);
		nvgStrokeColor(this->nvgContext, Tools::Colors::white);
		nvgStrokeWidth(this->nvgContext, 2.0f);
		nvgFillColor(this->nvgContext, Tools::Colors::black);

		/*
		 * Center
		 */

		nvgBeginPath(this->nvgContext);
		nvgRect(this->nvgContext, -4, -4, 8, 8);
		nvgClosePath(this->nvgContext);
		nvgFill(this->nvgContext);
		nvgStroke(this->nvgContext);

		/*
		 * Left side
		 */

		nvgBeginPath(this->nvgContext);
		nvgRect(this->nvgContext, -61, -4, -6, 24);
		nvgRect(this->nvgContext, -61, -4, -67, 6);
		nvgClosePath(this->nvgContext);
		nvgFill(this->nvgContext);

		nvgBeginPath(this->nvgContext);
		nvgMoveTo(this->nvgContext, -61, -4);
		nvgLineTo(this->nvgContext, -61, 20);
		nvgLineTo(this->nvgContext, -67, 20);
		nvgLineTo(this->nvgContext, -67, 2);
		nvgLineTo(this->nvgContext, -128, 2);
		nvgLineTo(this->nvgContext, -128, -4);
		nvgLineTo(this->nvgContext, -61, -4);
		nvgClosePath(this->nvgContext);
		nvgStroke(this->nvgContext);

		/*
		 * Right side
		 */

		nvgBeginPath(this->nvgContext);
		nvgRect(this->nvgContext, 61, -4, 6, 24);
		nvgRect(this->nvgContext, 61, -4, 67, 6);
		nvgClosePath(this->nvgContext);
		nvgFill(this->nvgContext);

		nvgBeginPath(this->nvgContext);
		nvgMoveTo(this->nvgContext, 61, -4);
		nvgLineTo(this->nvgContext, 61, 20);
		nvgLineTo(this->nvgContext, 67, 20);
		nvgLineTo(this->nvgContext, 67, 2);
		nvgLineTo(this->nvgContext, 128, 2);
		nvgLineTo(this->nvgContext, 128, -4);
		nvgLineTo(this->nvgContext, 61, -4);
		nvgClosePath(this->nvgContext);
		nvgStroke(this->nvgContext);
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

void PFDAttitudeApplication::renderSlipSkid() {
	const double position = aircraft_varget(this->slipSkidVariableId, this->slipSkidUnitsId, 0);

	nvgStrokeColor(this->nvgContext, Tools::Colors::white);
	nvgStrokeWidth(this->nvgContext, 2.0f);
	nvgFillColor(this->nvgContext, Tools::Colors::black);


	/*
	 * SlipSkid Triangle
	 */
	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, this->width * 0.5f, this->height * 0.5f);
		nvgRotate(this->nvgContext, SimConnectData::Aircraft::state.bank * M_PI / 180.0f);
		nvgBeginPath(this->nvgContext);
		nvgMoveTo(this->nvgContext, 0, -160);
		nvgLineTo(this->nvgContext, -13, -142);
		nvgLineTo(this->nvgContext, 13, -142);
		nvgLineTo(this->nvgContext, 0, -160);
		nvgClosePath(this->nvgContext);
		nvgResetTransform(this->nvgContext);

		nvgStroke(this->nvgContext);
	}
	nvgRestore(this->nvgContext);


	/*
	 * SlipSkid
	 */
	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, this->width * 0.5f, this->height * 0.5f);
		nvgRotate(this->nvgContext, SimConnectData::Aircraft::state.bank * M_PI / 180.0f);
		nvgTranslate(this->nvgContext, position * 40, 0);
		nvgBeginPath(this->nvgContext);
		nvgMoveTo(this->nvgContext, -14, -134);
		nvgLineTo(this->nvgContext, -14, -140);
		nvgLineTo(this->nvgContext, 14, -140);
		nvgLineTo(this->nvgContext, 14, -134);
		nvgLineTo(this->nvgContext, -14, -134);
		nvgClosePath(this->nvgContext);
		nvgResetTransform(this->nvgContext);
		nvgStroke(this->nvgContext);

		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}
