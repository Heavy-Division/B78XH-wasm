#include "PFDILSIndicatorApplication.h"

#include "Tools.h"
#include "Systems.h"
#include <cmath>

using Colors = Tools::Colors;

void PFDILSIndicatorApplication::render(sGaugeDrawData* data) {
	//this->approachType = Simplane::autopilot::approach::approachType();
	//this->isApproachLoaded = Simplane::autopilot::approach::approachLoaded();
	this->beacon = Systems::radioNav.getBestILSBeacon(UseNavSource::YES_FALLBACK);

	if (this->beacon.getType() != NavEquipmentType::UNKNOWN) {
		this->drawGlideSlopeIndicator();
		this->drawGlideSlopeCursor();
		this->drawLocalizerIndicator();
		this->drawlocalizerCursor();
		this->drawInfo();
	}
}


void PFDILSIndicatorApplication::drawLocalizerIndicator() {
	nvgSave(this->nvgContext);
	{
		nvgFillColor(this->nvgContext, nvgRGBA(0, 0, 0, 100));
		nvgBeginPath(this->nvgContext);
		{
			nvgRect(this->nvgContext, -120, 260, 240, 35);
		}
		nvgFill(this->nvgContext);
		nvgStrokeColor(this->nvgContext, Colors::white);
		nvgStrokeWidth(this->nvgContext, 2.0f);
		nvgBeginPath(this->nvgContext);
		{
			nvgMoveTo(this->nvgContext, 0, 260);
			nvgLineTo(this->nvgContext, 0, 295);
			nvgCircle(this->nvgContext, -50, 277.5, 5);
			nvgCircle(this->nvgContext, -100, 277.5, 5);
			nvgCircle(this->nvgContext, 50, 277.5, 5);
			nvgCircle(this->nvgContext, 100, 277.5, 5);
		}
		nvgStroke(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

void PFDILSIndicatorApplication::drawGlideSlopeIndicator() {
	nvgSave(this->nvgContext);
	{
		nvgFillColor(this->nvgContext, nvgRGBA(0, 0, 0, 100));
		nvgBeginPath(this->nvgContext);
		{
			nvgRect(this->nvgContext, 158, -120, 35, 240);
		}
		nvgFill(this->nvgContext);

		nvgStrokeColor(this->nvgContext, Colors::white);
		nvgStrokeWidth(this->nvgContext, 2.0f);
		nvgBeginPath(this->nvgContext);
		{
			nvgMoveTo(this->nvgContext, 158, 0);
			nvgLineTo(this->nvgContext, 192, 0);
			nvgCircle(this->nvgContext, 175.5, -50, 5);
			nvgCircle(this->nvgContext, 175.5, -100, 5);
			nvgCircle(this->nvgContext, 175.5, 50, 5);
			nvgCircle(this->nvgContext, 175.5, 100, 5);
		}
		nvgStroke(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

void PFDILSIndicatorApplication::drawlocalizerCursor() {
	if (this->beacon.getType() != NavEquipmentType::ILS || !this->beacon.hasLocalizer()) {
		return;
	}

	constexpr double maxCDIDeviation = 120.0;
	constexpr double halfCDIResolution = 127.0;
	const double cdi = this->beacon.getCDI() / halfCDIResolution;
	const double deviationInPixels = maxCDIDeviation * cdi;
	const bool shouldFillCursor = maxCDIDeviation != std::abs(deviationInPixels);

	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, deviationInPixels, 0);
		{
			nvgStrokeColor(this->nvgContext, Colors::magenta);
			nvgFillColor(this->nvgContext, Colors::magenta);
			nvgStrokeWidth(this->nvgContext, 2.0f);
			nvgBeginPath(this->nvgContext);
			{
				nvgMoveTo(this->nvgContext, 0, 260 + 7);
				nvgLineTo(this->nvgContext, -20, 277.5);
				nvgLineTo(this->nvgContext, 0, 295 - 7);
				nvgLineTo(this->nvgContext, 20, 277.5);
			}
			nvgClosePath(this->nvgContext);
			nvgStroke(this->nvgContext);
			if (shouldFillCursor) {
				nvgFill(this->nvgContext);
			}
		}
	}
	nvgRestore(this->nvgContext);

}


void PFDILSIndicatorApplication::drawGlideSlopeCursor() {
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

	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, 0, deviationInPixels);
		{
			nvgStrokeColor(this->nvgContext, Colors::magenta);
			nvgFillColor(this->nvgContext, Colors::magenta);
			nvgStrokeWidth(this->nvgContext, 2.0f);
			nvgBeginPath(this->nvgContext);
			{
				nvgMoveTo(this->nvgContext, 158 + 7, 0);
				nvgLineTo(this->nvgContext, 175.5, -20);
				nvgLineTo(this->nvgContext, 193 - 7, 0);
				nvgLineTo(this->nvgContext, 175.5, 20);
			}
			nvgClosePath(this->nvgContext);
			nvgStroke(this->nvgContext);
			if (shouldFillCursor) {
				nvgFill(this->nvgContext);
			}
		}
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

void PFDILSIndicatorApplication::drawInfo() {
	nvgSave(this->nvgContext);
	{
		nvgFontFace(this->nvgContext, "roboto");
		nvgTextAlign(this->nvgContext, NVG_ALIGN_LEFT);
		nvgTextLetterSpacing(this->nvgContext, 1.0f);
		nvgFontSize(this->nvgContext, 22.0f);
		nvgFillColor(this->nvgContext, Colors::white);
		nvgTranslate(this->nvgContext, -160, -220);
		{
			nvgBeginPath(this->nvgContext);
			{
				nvgText(this->nvgContext, 0, 0, this->beacon.getIdent().c_str(), nullptr);
				nvgText(this->nvgContext, 0, 15, fmt::format("{:.2f}", this->beacon.getFrequency()).c_str(), nullptr);
				if (this->beacon.hasDME()) {
					nvgText(this->nvgContext, 0, 30, fmt::format("{:.1f}NM", this->beacon.getDME()).c_str(), nullptr);
				}
				nvgFontSize(this->nvgContext, 25.0f);
				nvgText(this->nvgContext, 0, 50, "ILS/FMC", nullptr);
			}
			nvgFill(this->nvgContext);
		}
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}