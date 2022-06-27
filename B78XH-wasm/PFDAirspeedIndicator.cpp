#include "PFDAirspeedIndicator.h"
#include <algorithm>
#include <cmath>
#include "fmt/core.h"

#include "Simplane.h"

/*
 * TODO:
 *	Remove windowWidth/windowHeight params from methods what does not need the params for drawing
 */

void PFDAirspeedIndicator::draw(NVGcontext* context, float windowWidth, float windowHeight) {
	nvgSave(context);
	drawBackground(context, windowWidth, windowHeight);
	drawGraduations(context, windowWidth, windowHeight);
	drawTargetPointer(context, windowWidth, windowHeight);
	drawCursor(context, windowWidth, windowHeight);
	nvgRestore(context);
}

void PFDAirspeedIndicator::drawBackground(NVGcontext* context, float windowWidth, float windowHeight) {
	nvgFillColor(context, nvgRGBA(0, 0, 0, 100));
	nvgStrokeWidth(context, 1.0f);
	nvgStrokeColor(context, nvgRGB(0, 0, 0));
	nvgBeginPath(context);
	nvgRect(context, 0, 0, 80, 465);
	nvgClosePath(context);
	nvgFill(context);
	nvgStroke(context);
	/*
	nvgFillColor(context, nvgRGBA(0, 0, 0, 100));
	nvgStrokeWidth(context, 1.0f);
	nvgStrokeColor(context, nvgRGB(0, 0, 0));
	nvgBeginPath(context);
	nvgRect(context, 154, 80, 80, 465);
	nvgClosePath(context);
	nvgFill(context);
	nvgStroke(context);
	*/
}

void PFDAirspeedIndicator::drawGraduations(NVGcontext* context, float windowWidth, float windowHeight) {
	nvgSave(context);
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

	for(int i = 0; i <= 12; i++) {
		const auto value = next10 + 60 - (i * 10);
		airspeedsToRenderValues[i] = static_cast<int>(value);
		airspeedsToRenderFlag[i] = fmod(value, 20) == 0 ? true : false;
	}


	/*
	 * Middle rendering
	 */

	nvgFontFace(context, "roboto");
	nvgFontSize(context, 20.0f);
	nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
	nvgScissor(context, 0, 0, 84, 465);
	nvgTranslate(context, 0, baseTranslate + 232.5);
	nvgFillColor(context, nvgRGB(255, 255, 255));
	nvgBeginPath(context);

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

	for(int i = 0; i < 13; i++) {
		if(airspeedsToRenderFlag[i]) {
			if(airspeedsToRenderValues[i] >= 30) {
				nvgText(context, 50, offsets[i], fmt::format("{}", airspeedsToRenderValues[i]).c_str(), nullptr);
			}
		}
	}

	for(int i = 0; i < 13; i++) {
		if(airspeedsToRenderValues[i] >= 30) {
			nvgRect(context, 65, offsets[i] - 3 * 0.5f, 15, 3);
		}
	}

	nvgClosePath(context);
	nvgFill(context);
	nvgResetTransform(context);
	nvgResetScissor(context);
	nvgRestore(context);
}


void PFDAirspeedIndicator::drawCursor(NVGcontext* context, float windowWidth, float windowHeight) {
	namespace Aircraft = Simplane::aircraft;

	nvgStrokeWidth(context, 3.0f);
	nvgStrokeColor(context, nvgRGB(255, 255, 255));
	nvgFillColor(context, nvgRGB(0, 0, 0));
	nvgBeginPath(context);
	{
		nvgMoveTo(context, -4, 232.5 - 10 - 19);
		nvgLineTo(context, -4 + 58, 232.5 - 10 - 19);
		nvgLineTo(context, -4 + 58, 232.5 - 10);
		nvgLineTo(context, -4 + 58 + 11, 232.5);
		nvgLineTo(context, -4 + 58, 232.5 + 10);
		nvgLineTo(context, -4 + 58, 232.5 + 10 + 19);
		nvgLineTo(context, -4, 232.5 + 10 + 19);
	}
	nvgClosePath(context);

	nvgFill(context);
	nvgStroke(context);


	nvgScissor(context, -4, 236.5 - 10 - 19, 58, 50);

	const double indicatedAirspeed = std::max<double>(30, Aircraft::state::indicatedAirspeed());
	const int hundreds = floor(indicatedAirspeed / 100);
	const int tensWithOnes = floor(indicatedAirspeed - (hundreds * 100));
	const int tens = floor(tensWithOnes / 10);
	const double ones = indicatedAirspeed - (tens * 10) - (hundreds * 100);

	/**
	 * Ones
	 */

	const double onesOffset = ones * 30;
	nvgSave(context);
	{
		nvgStrokeWidth(context, 3.0f);
		nvgStrokeColor(context, nvgRGB(255, 255, 255));
		nvgFillColor(context, nvgRGB(255, 255, 255));
		nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgFontSize(context, 42.0f);
		nvgTranslate(context, 52, onesOffset + 232.5);
		nvgBeginPath(context);
		{
			nvgText(context, 0, -300, "0", nullptr);
			nvgText(context, 0, -270, "9", nullptr);
			nvgText(context, 0, -240, "8", nullptr);
			nvgText(context, 0, -210, "7", nullptr);
			nvgText(context, 0, -180, "6", nullptr);
			nvgText(context, 0, -150, "5", nullptr);
			nvgText(context, 0, -120, "4", nullptr);
			nvgText(context, 0, -90, "3", nullptr);
			nvgText(context, 0, -60, "2", nullptr);
			nvgText(context, 0, -30, "1", nullptr);
			nvgText(context, 0, 0, "0", nullptr);
			nvgText(context, 0, 30, "9", nullptr);
		}
		nvgClosePath(context);

		nvgFill(context);
		nvgResetTransform(context);
	}
	nvgRestore(context);

	/*
	 * Tens
	 */

	const double tensOffset = tens * 40 + (ones > 8 ? fmod(ones, 8) * 20 : 0);

	nvgSave(context);
	{
		nvgStrokeWidth(context, 3.0f);
		nvgStrokeColor(context, nvgRGB(255, 255, 255));
		nvgFillColor(context, nvgRGB(255, 255, 255));
		nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgFontSize(context, 42.0f);
		nvgTranslate(context, 33, tensOffset + 232.5);
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
		nvgResetTransform(context);
	}
	nvgRestore(context);

	/*
	* Hundreds
	*/

	if(indicatedAirspeed > 90) {
		const double hundredsOffset = hundreds * 40 + (ones > 8 && tens == 9 ? fmod(ones, 8) * 20 : 0);
		nvgSave(context);
		{
			nvgStrokeWidth(context, 3.0f);
			nvgStrokeColor(context, nvgRGB(255, 255, 255));
			nvgFillColor(context, nvgRGB(255, 255, 255));
			nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
			nvgFontSize(context, 42.0f);
			nvgTranslate(context, 15, hundredsOffset + 232.5);
			nvgBeginPath(context);
			{
				nvgText(context, 0, -200, "5", nullptr);
				nvgText(context, 0, -160, "4", nullptr);
				nvgText(context, 0, -120, "3", nullptr);
				nvgText(context, 0, -80, "2", nullptr);
				nvgText(context, 0, -40, "1", nullptr);
			}
			nvgClosePath(context);

			nvgFill(context);
			nvgResetTransform(context);
		}
		nvgRestore(context);
	}
	nvgResetScissor(context);
}

void PFDAirspeedIndicator::drawTargetPointer(NVGcontext* context, float windowWidth, float windowHeight) {
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
	if(abs(offset) > 232.5) {
		offset = (offset < 0 ? -232.5 : 232.5);
	}

	nvgSave(context);
	{
		nvgTranslate(context, 65, 232.5);
		{
			nvgScissor(context, -4, -232.5, 56, 465);
			nvgTranslate(context, 0, offset);
			{
				nvgStrokeColor(context, nvgRGB(213, 112, 255));
				nvgStrokeWidth(context, 3.0f);
				nvgLineJoin(context, NVG_ROUND);
				nvgBeginPath(context);
				{
					nvgMoveTo(context, 0, 0);
					nvgLineTo(context, 12, -10);
					nvgLineTo(context, 36, -10);
					nvgLineTo(context, 36, 10);
					nvgLineTo(context, 10, 10);
				}
				nvgClosePath(context);
				nvgStroke(context);
			}
			nvgResetScissor(context);
		}
	}
	nvgResetTransform(context);
	nvgRestore(context);
}
