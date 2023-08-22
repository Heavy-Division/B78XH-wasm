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


#include "PFDAirspeedIndicatorApplication.h"

#include <cmath>

#include "Tools/Tools.h"
#include "Simplane.h"

using Colors = Tools::Colors;

void PFDAirspeedIndicatorApplication::render(sGaugeDrawData* data) {
	nvgSave(this->nvgContext);
	drawBackground();
	drawGraduations();
	drawTargetPointer();
	drawCursor();
	drawStallStrips();
	drawOverSpeedStrips();
	drawSpeedMarkers(data->dt);
	nvgRestore(this->nvgContext);
}

void PFDAirspeedIndicatorApplication::drawVSpeedMarkers(double v1, double v2, double vR, double deltaTime) {
	const double fixedIndicatedAirspeed = std::max<double>(30, Simplane::aircraft::state::indicatedAirspeed());

	v1SpeedMarker.draw(this->nvgContext, v1, fixedIndicatedAirspeed);
	v2SpeedMarker.draw(this->nvgContext, v2, fixedIndicatedAirspeed, deltaTime);
	vRSpeedMarker.draw(this->nvgContext, vR, fixedIndicatedAirspeed);
}

void PFDAirspeedIndicatorApplication::drawNOVSpeedMessage() {
	nvgSave(this->nvgContext);
	{
		float noBounds[4] = {};
		nvgTranslate(this->nvgContext, 88, 165);
		{

			nvgFillColor(this->nvgContext, Colors::black);
			nvgBeginPath(this->nvgContext);
			{
				nvgRect(this->nvgContext, -2, -15, 26, 78);
			}
			nvgFill(this->nvgContext);


			nvgTextAlign(this->nvgContext, NVG_ALIGN_LEFT);
			nvgFillColor(this->nvgContext, Colors::amber);
			nvgBeginPath(this->nvgContext);
			{
				nvgText(this->nvgContext, 0, 0, "NO", nullptr);
				nvgTextBounds(this->nvgContext, 0, 0, "NO", nullptr, noBounds);
				nvgTextAlign(this->nvgContext, NVG_ALIGN_CENTER);
				nvgText(this->nvgContext, noBounds[2] / 2, 15, "V", nullptr);
				nvgText(this->nvgContext, noBounds[2] / 2, 30, "S", nullptr);
				nvgText(this->nvgContext, noBounds[2] / 2, 45, "P", nullptr);
				nvgText(this->nvgContext, noBounds[2] / 2, 60, "D", nullptr);
			}
			nvgFill(this->nvgContext);
			nvgClosePath(this->nvgContext);
		}
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

void PFDAirspeedIndicatorApplication::drawSpeedMarkers(double deltaTime) {
	const double v1 = Simplane::instruments::cdu::v1();
	const double v2 = Simplane::instruments::cdu::v2();
	const double vR = Simplane::instruments::cdu::vR();
	if ((v1 == 0 || v2 == 0 || vR == 0) && Simplane::aircraft::state::isGrounded()) {
		PFDAirspeedIndicatorApplication::drawNOVSpeedMessage();
	}
	else {
		PFDAirspeedIndicatorApplication::drawVSpeedMarkers(v1, v2, vR, deltaTime);
	}

	vRefSpeedMarker.draw(this->nvgContext, Simplane::instruments::cdu::vREF(),
		std::max<double>(30, Simplane::aircraft::state::indicatedAirspeed()));

	const double indicatedAltitude = Simplane::aircraft::state::indicatedAltitude();
	const double flightPhase = Simplane::flight::flightPhase();

	if (PFDAirspeedIndicatorApplication::shouldDrawFlapsMarkers(indicatedAltitude, flightPhase)) {
		const double flapsHandleIndex = Simplane::aircraft::state::flapsHandleIndex();
		if (flapsHandleIndex > 0) {
			const double indicatedAirspeed = Simplane::aircraft::state::indicatedAirspeed();
			const double target = Simplane::aircraft::state::flapsSpeedLimit(flapsHandleIndex);

			currentFlapsMarker.draw(this->nvgContext, target,
				indicatedAirspeed,
				flapsHandleIndex);

			const double nextFlapsHandleIndex = (static_cast<int>(flightPhase) <= static_cast<int>(
				SimFlightPhase::FLIGHT_PHASE_CLIMB)
				|| static_cast<int>(flightPhase) == static_cast<int>(
					SimFlightPhase::FLIGHT_PHASE_CRUISE)
				? flapsHandleIndex - 1
				: flapsHandleIndex + 1);

			if (!(nextFlapsHandleIndex < 0 || nextFlapsHandleIndex > 9)) {
				const double nextTarget = (nextFlapsHandleIndex == 0
					? Simplane::aircraft::state::flapsSpeedLimit(1) + 20
					: Simplane::aircraft::state::flapsSpeedLimit(nextFlapsHandleIndex));
				nextFlapsMarker.draw(this->nvgContext, nextTarget,
					indicatedAirspeed,
					nextFlapsHandleIndex);
			}
		}
	}
}

bool PFDAirspeedIndicatorApplication::shouldDrawFlapsMarkers(double indicatedAltitude, double flightPhase) {
	if (static_cast<int>(flightPhase) >= static_cast<int>(SimFlightPhase::FLIGHT_PHASE_TAKEOFF) || indicatedAltitude <
		20000) {
		return true;
	}
	return false;
}

void PFDAirspeedIndicatorApplication::drawOverSpeedStrips() {
	const double maxSpeed = Simplane::aircraft::state::maxSpeed();
	const double indicatedAirspeed = Simplane::aircraft::state::indicatedAirspeed();
	const double delta = indicatedAirspeed - maxSpeed;
	constexpr double pixelPerKnot = 3.875;
	const double deltaPixels = pixelPerKnot * delta;
	constexpr double baseOffset = (465.0 / 2.0 - (464.0));
	double offset = baseOffset + (deltaPixels);

	/*
	 * Do not render strips if they are not visible
	 */
	if (offset < -465) {
		return;
	}

	/*
	 * Min strips position (Strips overdraw protection for extreme overspeed)
	 */
	if (offset > 0) {
		offset = 0;
	}

	nvgSave(this->nvgContext);
	{
		nvgScissor(this->nvgContext, 77, 0, 8.6875, 465);
		{
			nvgSave(this->nvgContext);
			{
				nvgTranslate(this->nvgContext, 0, offset);
				{
					drawStrips();
				}
				nvgResetTransform(this->nvgContext);
			}
			nvgRestore(this->nvgContext);
		}
		nvgResetScissor(this->nvgContext);
	}
	nvgRestore(this->nvgContext);

}

void PFDAirspeedIndicatorApplication::drawStallStrips() {
	const double altitudeAboveGround = Simplane::aircraft::state::altitudeAboveGround();
	/*
	 * Do not show stall strips on ground
	 */
	if (altitudeAboveGround < 10) {
		return;
	}


	const double indicatedAirspeed = Simplane::aircraft::state::indicatedAirspeed();
	const double stallProtMaxSpeed = Simplane::aircraft::state::stallProtectionMaxSpeed();
	const double stallProtMinSpeed = Simplane::aircraft::state::stallProtectionMinSpeed();
	const double delta = indicatedAirspeed - stallProtMaxSpeed;
	const double deltaProt = stallProtMinSpeed - stallProtMaxSpeed;
	/*
	* Do not render non visible min protection and strips (Airspeed indicator resolution is cca +-60 knots)
	*/
	if (delta - deltaProt < 60) {
		constexpr double pixelPerKnot = 3.875;
		const double deltaPixels = pixelPerKnot * delta;
		const double deltaProtPixels = pixelPerKnot * deltaProt;
		constexpr double baseOffset = (465.0 / 2.0 + 8.6875 * 2.0);
		double offset = baseOffset + (deltaPixels);
		if (offset < 8.6875) {
			offset = 8.6875;
		}

		double offsetProt = offset - (deltaProtPixels)-(8.6875 * 2.0);

		nvgSave(this->nvgContext);
		{
			nvgScissor(this->nvgContext, 77, 0, 8.6875, 465.0);
			{
				nvgSave(this->nvgContext);
				{
					nvgTranslate(this->nvgContext, 0, offsetProt);
					{
						drawProtStrip();
					}
					nvgResetTransform(this->nvgContext);
				}
				nvgRestore(this->nvgContext);
				/*
				 * Do not render non visible strips (Airspeed indicator resolution is cca +-60 knots)
				 */
				if (delta < 60) {
					nvgSave(this->nvgContext);
					{
						nvgTranslate(this->nvgContext, 0, offset);
						{
							drawStrips();
						}
						nvgResetTransform(this->nvgContext);
					}
					nvgRestore(this->nvgContext);
				}
			}
			nvgResetScissor(this->nvgContext);
		}
		nvgRestore(this->nvgContext);
	}
}

void PFDAirspeedIndicatorApplication::drawProtStrip() {
	nvgSave(this->nvgContext);
	{
		nvgStrokeColor(this->nvgContext, Colors::amber);
		nvgBeginPath(this->nvgContext);
		{
			nvgMoveTo(this->nvgContext, 80, 0);
			nvgLineTo(this->nvgContext, 84, 0);
			nvgLineTo(this->nvgContext, 84, 465);
		}
		nvgStroke(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

void PFDAirspeedIndicatorApplication::drawStrips() {
	nvgSave(this->nvgContext);
	{
		nvgFillColor(this->nvgContext, Colors::black);
		nvgBeginPath(this->nvgContext);
		{
			nvgRect(this->nvgContext, 77, -8.6875, 9.6875, 464 + 8.6875);
		}
		nvgFill(this->nvgContext);

		nvgFillColor(this->nvgContext, Colors::red);
		nvgBeginPath(this->nvgContext);
		{
			nvgRect(this->nvgContext, 77, -9.6875, 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875, 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 2.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 4.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 6.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 8.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 10.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 12.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 14.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 16.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 18.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 20.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 22.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 24.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 26.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 28.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 30.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 32.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 34.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 36.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 38.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 40.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 42.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 44.0), 9.6875, 9.6875);
			nvgRect(this->nvgContext, 77, 9.6875 + (9.6875 * 46.0), 9.6875, 9.6875);
		}
		nvgFill(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

void PFDAirspeedIndicatorApplication::drawBackground() {
	nvgFillColor(this->nvgContext, nvgRGBA(0, 0, 0, 100));
	nvgStrokeWidth(this->nvgContext, 1.0f);
	nvgStrokeColor(this->nvgContext, Colors::black);
	nvgBeginPath(this->nvgContext);
	nvgRect(this->nvgContext, 0, 0, 80, 465);
	nvgClosePath(this->nvgContext);
	nvgFill(this->nvgContext);
	nvgStroke(this->nvgContext);
}

void PFDAirspeedIndicatorApplication::drawGraduations() {
	nvgSave(this->nvgContext);
	{
		namespace Aircraft = Simplane::aircraft;

		const double indicatedAirspeed = std::max<double>(30, Aircraft::state::indicatedAirspeed());

		const double modulo = fmod(indicatedAirspeed, 10);
		constexpr double pixelPerKnot = 3.875;
		const double next20 = indicatedAirspeed + (10 - modulo);
		const double baseTranslate = -((next20 - indicatedAirspeed) * pixelPerKnot);
		const double next10modulo = fmod(indicatedAirspeed, 10);
		const double next10 = indicatedAirspeed + (10 - next10modulo);

		int airspeedsToRenderValues[13];
		bool airspeedsToRenderFlag[13];

		for (int i = 0; i <= 12; i++) {
			const auto value = next10 + 60 - (i * 10);
			airspeedsToRenderValues[i] = static_cast<int>(value);
			airspeedsToRenderFlag[i] = fmod(value, 20) == 0 ? true : false;
		}


		/*
		 * Middle rendering
		 */

		nvgFontFace(this->nvgContext, "roboto");
		nvgFontSize(this->nvgContext, 20.0f);
		nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgScissor(this->nvgContext, 0, 0, 84, 465);
		nvgTranslate(this->nvgContext, 0, baseTranslate + 232.5);
		nvgFillColor(this->nvgContext, Colors::white);
		nvgBeginPath(this->nvgContext);

		/*
		 * Static implementation
		 */

		const float offsets[13] = {
			-232.5,
			-193.75,
			-155,
			-116.25,
			-77.5,
			-38.75,
			0,
			38.75,
			77.5,
			116.25,
			155,
			193.75,
			232.5
		};

		for (int i = 0; i < 13; i++) {
			if (airspeedsToRenderFlag[i]) {
				if (airspeedsToRenderValues[i] >= 30) {
					nvgText(this->nvgContext, 50, offsets[i], fmt::format("{}", airspeedsToRenderValues[i]).c_str(), nullptr);
				}
			}
		}

		for (int i = 0; i < 13; i++) {
			if (airspeedsToRenderValues[i] >= 30) {
				nvgRect(this->nvgContext, 65, offsets[i] - 3 * 0.5f, 15, 3);
			}
		}

		nvgClosePath(this->nvgContext);
		nvgFill(this->nvgContext);
		nvgResetTransform(this->nvgContext);
		nvgResetScissor(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}


void PFDAirspeedIndicatorApplication::drawCursor() {
	namespace Aircraft = Simplane::aircraft;

	nvgStrokeWidth(this->nvgContext, 3.0f);
	nvgStrokeColor(this->nvgContext, Colors::white);
	nvgFillColor(this->nvgContext, Colors::black);
	nvgBeginPath(this->nvgContext);
	{
		nvgMoveTo(this->nvgContext, -4, 232.5 - 10 - 19);
		nvgLineTo(this->nvgContext, -4 + 58, 232.5 - 10 - 19);
		nvgLineTo(this->nvgContext, -4 + 58, 232.5 - 10);
		nvgLineTo(this->nvgContext, -4 + 58 + 11, 232.5);
		nvgLineTo(this->nvgContext, -4 + 58, 232.5 + 10);
		nvgLineTo(this->nvgContext, -4 + 58, 232.5 + 10 + 19);
		nvgLineTo(this->nvgContext, -4, 232.5 + 10 + 19);
	}
	nvgClosePath(this->nvgContext);

	nvgFill(this->nvgContext);
	nvgStroke(this->nvgContext);


	nvgScissor(this->nvgContext, -4, 236.5 - 10 - 19, 58, 50);

	const double indicatedAirspeed = std::max<double>(30, Aircraft::state::indicatedAirspeed());
	const int hundreds = floor(indicatedAirspeed / 100);
	const int tensWithOnes = floor(indicatedAirspeed - (hundreds * 100));
	const int tens = floor(tensWithOnes / 10);
	const double ones = indicatedAirspeed - (tens * 10) - (hundreds * 100);

	/**
	 * Ones
	 */

	const double onesOffset = ones * 30;
	nvgSave(this->nvgContext);
	{
		nvgStrokeWidth(this->nvgContext, 3.0f);
		nvgStrokeColor(this->nvgContext, Colors::white);
		nvgFillColor(this->nvgContext, Colors::white);
		nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgFontSize(this->nvgContext, 42.0f);
		nvgTranslate(this->nvgContext, 52, onesOffset + 232.5);
		nvgBeginPath(this->nvgContext);
		{
			nvgText(this->nvgContext, 0, -300, "0", nullptr);
			nvgText(this->nvgContext, 0, -270, "9", nullptr);
			nvgText(this->nvgContext, 0, -240, "8", nullptr);
			nvgText(this->nvgContext, 0, -210, "7", nullptr);
			nvgText(this->nvgContext, 0, -180, "6", nullptr);
			nvgText(this->nvgContext, 0, -150, "5", nullptr);
			nvgText(this->nvgContext, 0, -120, "4", nullptr);
			nvgText(this->nvgContext, 0, -90, "3", nullptr);
			nvgText(this->nvgContext, 0, -60, "2", nullptr);
			nvgText(this->nvgContext, 0, -30, "1", nullptr);
			nvgText(this->nvgContext, 0, 0, "0", nullptr);
			nvgText(this->nvgContext, 0, 30, "9", nullptr);
		}
		nvgClosePath(this->nvgContext);

		nvgFill(this->nvgContext);
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);

	/*
	 * Tens
	 */

	const double tensOffset = tens * 40 + (ones > 8 ? fmod(ones, 8) * 20 : 0);

	nvgSave(this->nvgContext);
	{
		nvgStrokeWidth(this->nvgContext, 3.0f);
		nvgStrokeColor(this->nvgContext, Colors::white);
		nvgFillColor(this->nvgContext, Colors::white);
		nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgFontSize(this->nvgContext, 42.0f);
		nvgTranslate(this->nvgContext, 33, tensOffset + 232.5);
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
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);

	/*
	* Hundreds
	*/

	if (indicatedAirspeed > 90) {
		const double hundredsOffset = hundreds * 40 + (ones > 8 && tens == 9 ? fmod(ones, 8) * 20 : 0);
		nvgSave(this->nvgContext);
		{
			nvgStrokeWidth(this->nvgContext, 3.0f);
			nvgStrokeColor(this->nvgContext, Colors::white);
			nvgFillColor(this->nvgContext, Colors::white);
			nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
			nvgFontSize(this->nvgContext, 42.0f);
			nvgTranslate(this->nvgContext, 15, hundredsOffset + 232.5);
			nvgBeginPath(this->nvgContext);
			{
				nvgText(this->nvgContext, 0, -200, "5", nullptr);
				nvgText(this->nvgContext, 0, -160, "4", nullptr);
				nvgText(this->nvgContext, 0, -120, "3", nullptr);
				nvgText(this->nvgContext, 0, -80, "2", nullptr);
				nvgText(this->nvgContext, 0, -40, "1", nullptr);
			}
			nvgClosePath(this->nvgContext);

			nvgFill(this->nvgContext);
			nvgResetTransform(this->nvgContext);
		}
		nvgRestore(this->nvgContext);
	}
	nvgResetScissor(this->nvgContext);
}

void PFDAirspeedIndicatorApplication::drawTargetPointer() {
	namespace Aircraft = Simplane::aircraft;
	namespace Autopilot = Simplane::autopilot;

	constexpr double pixelPerKnot = 3.875;
	/*
	 * DESC:
	 *	Indicated airspeed and selected airspeed has to be 30+. Airspeed indicator does not show speeds under 30 knots.
	 */
	const double indicatedAirspeed = std::max<double>(30, Aircraft::state::indicatedAirspeed());

	const double targetAirspeed = std::max<double>(30, Autopilot::airspeed::airspeedHoldVar());
	const double diff = (indicatedAirspeed - targetAirspeed);
	double offset = pixelPerKnot * diff;
	if (abs(offset) > 232.5) {
		offset = (offset < 0 ? -232.5 : 232.5);
	}

	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, 65, 232.5);
		{
			nvgScissor(this->nvgContext, -4, -232.5, 56, 465);
			nvgTranslate(this->nvgContext, 0, offset);
			{
				nvgStrokeColor(this->nvgContext, Tools::Colors::magenta);
				nvgStrokeWidth(this->nvgContext, 3.0f);
				nvgLineJoin(this->nvgContext, NVG_ROUND);
				nvgBeginPath(this->nvgContext);
				{
					nvgMoveTo(this->nvgContext, 0, 0);
					nvgLineTo(this->nvgContext, 12, -10);
					nvgLineTo(this->nvgContext, 36, -10);
					nvgLineTo(this->nvgContext, 36, 10);
					nvgLineTo(this->nvgContext, 10, 10);
				}
				nvgClosePath(this->nvgContext);
				nvgStroke(this->nvgContext);
			}
			nvgResetScissor(this->nvgContext);
		}
	}
	nvgResetTransform(this->nvgContext);
	nvgRestore(this->nvgContext);
}
