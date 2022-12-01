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


#include "PFDILSIndicator.h"
#include "Tools/Tools.h"
#include "Systems.h"
#include <cmath>
#include "fmt/core.h"

using Colors = Tools::Colors;

void PFDILSIndicator::draw(NVGcontext* context) {
	//this->approachType = Simplane::autopilot::approach::approachType();
	//this->isApproachLoaded = Simplane::autopilot::approach::approachLoaded();
	this->beacon = Systems::radioNav.getBestILSBeacon(UseNavSource::YES_FALLBACK);

	if(this->beacon.getType() != NavEquipmentType::UNKNOWN) {
		PFDILSIndicator::drawGlideSlopeIndicator(context);
		PFDILSIndicator::drawGlideSlopeCursor(context);
		PFDILSIndicator::drawLocalizerIndicator(context);
		PFDILSIndicator::drawlocalizerCursor(context);
		PFDILSIndicator::drawInfo(context);
	}
}

void PFDILSIndicator::drawLocalizerIndicator(NVGcontext* context) {
	nvgSave(context);
	{
		nvgFillColor(context, nvgRGBA(0, 0, 0, 100));
		nvgBeginPath(context);
		{
			nvgRect(context, -120, 260, 240, 35);
		}
		nvgFill(context);
		nvgStrokeColor(context, Colors::white);
		nvgStrokeWidth(context, 2.0f);
		nvgBeginPath(context);
		{
			nvgMoveTo(context, 0, 260);
			nvgLineTo(context, 0, 295);
			nvgCircle(context, -50, 277.5, 5);
			nvgCircle(context, -100, 277.5, 5);
			nvgCircle(context, 50, 277.5, 5);
			nvgCircle(context, 100, 277.5, 5);
		}
		nvgStroke(context);
	}
	nvgRestore(context);
}

void PFDILSIndicator::drawGlideSlopeIndicator(NVGcontext* context) {
	nvgSave(context);
	{
		nvgFillColor(context, nvgRGBA(0, 0, 0, 100));
		nvgBeginPath(context);
		{
			nvgRect(context, 158, -120, 35, 240);
		}
		nvgFill(context);

		nvgStrokeColor(context, Colors::white);
		nvgStrokeWidth(context, 2.0f);
		nvgBeginPath(context);
		{
			nvgMoveTo(context, 158, 0);
			nvgLineTo(context, 192, 0);
			nvgCircle(context, 175.5, -50, 5);
			nvgCircle(context, 175.5, -100, 5);
			nvgCircle(context, 175.5, 50, 5);
			nvgCircle(context, 175.5, 100, 5);
		}
		nvgStroke(context);
	}
	nvgRestore(context);
}

void PFDILSIndicator::drawlocalizerCursor(NVGcontext* context) {
	if (this->beacon.getType() != NavEquipmentType::ILS || !this->beacon.hasLocalizer()) {
		return;
	}

	constexpr double maxCDIDeviation = 120.0;
	constexpr double halfCDIResolution = 127.0;
	const double cdi = this->beacon.getCDI() / halfCDIResolution;
	const double deviationInPixels = maxCDIDeviation * cdi;
	const bool shouldFillCursor = maxCDIDeviation != std::abs(deviationInPixels);

	nvgSave(context);
	{
		nvgTranslate(context, deviationInPixels, 0);
		{
			nvgStrokeColor(context, Colors::magenta);
			nvgFillColor(context, Colors::magenta);
			nvgStrokeWidth(context, 2.0f);
			nvgBeginPath(context);
			{
				nvgMoveTo(context, 0, 260 + 7);
				nvgLineTo(context, -20, 277.5);
				nvgLineTo(context, 0, 295 - 7);
				nvgLineTo(context, 20, 277.5);
			}
			nvgClosePath(context);
			nvgStroke(context);
			if (shouldFillCursor) {
				nvgFill(context);
			}
		}
	}
	nvgRestore(context);

}


void PFDILSIndicator::drawGlideSlopeCursor(NVGcontext* context) {
	if (this->beacon.getType() != NavEquipmentType::ILS || !this->beacon.hasGlideSlope()) {
		return;
	}

	constexpr double maxGSIDeviation = 120.0;

	/*
	 * GlideSlope Error implementation
	 */
	/*
	constexpr double maxGlideSlopeErrorDeviation = 0.7;
	constexpr double gsiDeviationBasePixelScale = maxGSIDeviation / 1000; // 0.1% in pixels
	constexpr double glideSlopeErrorBasePseudoScale = maxGlideSlopeErrorDeviation / 1000; // 0.1% in pseudoscale
	const double rawGlideSlopeError = this->beacon.getGlideSlopeError();
	double limitedGlideSlopeError = 0.0;
	if(std::abs(rawGlideSlopeError) > 0.7) {
		limitedGlideSlopeError = ((rawGlideSlopeError < 0) ? -maxGlideSlopeErrorDeviation : maxGlideSlopeErrorDeviation);
	} else {
		limitedGlideSlopeError = rawGlideSlopeError;
	}

	const double calculatedGlideSlopeErrorPercents = limitedGlideSlopeError / glideSlopeErrorBasePseudoScale;
	const double deviationInPixels = calculatedGlideSlopeErrorPercents * gsiDeviationBasePixelScale;
	const bool shouldFillCursor = maxGSIDeviation != std::abs(deviationInPixels);
	*/

	constexpr double halfGSIResolution = 119.0;
	const double gsi = this->beacon.getGSI() / halfGSIResolution;
	const double deviationInPixels = maxGSIDeviation * gsi;
	const bool shouldFillCursor = maxGSIDeviation != std::abs(deviationInPixels);

	nvgSave(context);
	{
		nvgTranslate(context, 0, deviationInPixels);
		{
			nvgStrokeColor(context, Colors::magenta);
			nvgFillColor(context, Colors::magenta);
			nvgStrokeWidth(context, 2.0f);
			nvgBeginPath(context);
			{
				nvgMoveTo(context, 158 + 7, 0);
				nvgLineTo(context, 175.5, -20);
				nvgLineTo(context, 193 - 7, 0);
				nvgLineTo(context, 175.5, 20);
			}
			nvgClosePath(context);
			nvgStroke(context);
			if(shouldFillCursor) {
				nvgFill(context);
			}
		}
		nvgResetTransform(context);
	}
	nvgRestore(context);
}

void PFDILSIndicator::drawInfo(NVGcontext* context) {
	nvgSave(context);
	{
		nvgFontFace(context, "roboto");
		nvgTextAlign(context, NVG_ALIGN_LEFT);
		nvgTextLetterSpacing(context, 1.0f);
		nvgFontSize(context, 22.0f);
		nvgFillColor(context, Colors::white);
		nvgTranslate(context, -160, -220);
		{
			nvgBeginPath(context);
			{
				nvgText(context, 0, 0, this->beacon.getIdent().c_str(), nullptr);
				nvgText(context, 0, 15, fmt::format("{:.2f}", this->beacon.getFrequency()).c_str(), nullptr);
				if(this->beacon.hasDME()) {
					nvgText(context, 0, 30, fmt::format("{:.1f}NM", this->beacon.getDME()).c_str(), nullptr);
				}
				nvgFontSize(context, 25.0f);
				nvgText(context, 0, 50, "ILS/FMC", nullptr);
			}
			nvgFill(context);
		}
		nvgResetTransform(context);
	}
	nvgRestore(context);
}