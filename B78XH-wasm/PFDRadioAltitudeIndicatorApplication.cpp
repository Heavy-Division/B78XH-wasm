#include "PFDRadioAltitudeIndicatorApplication.h"

#include "Simplane.h"
#include <cmath>
#include "Tools.h"

using Colors = Tools::Colors;

void PFDRadioAltitudeIndicatorApplication::render(sGaugeDrawData* data) {
	this->altitude = round(Simplane::aircraft::state::altitudeAboveGround());
	if (this->shouldShowRadioAltitude()) {
		if (this->shouldStartStartTimer()) {
			this->deltaTimer.start();
		}
		this->deltaTimer.update(data->dt);
		this->drawBackground(!this->deltaTimer.finished() && this->deltaTimer.started());
		this->drawValue();
	}
	else {
		this->deltaTimer.restart();
		this->deltaTimer.stop();
	}
	this->lastAltitude = this->altitude;
}

void PFDRadioAltitudeIndicatorApplication::drawBackground(bool highlight) {
	nvgFillColor(this->nvgContext, Colors::black);
	nvgStrokeColor(this->nvgContext, Colors::white);
	nvgStrokeWidth(this->nvgContext, 2.0f);
	nvgBeginPath(this->nvgContext);
	{
		nvgRect(this->nvgContext, 0, 0, 100, 40);
	}
	nvgFill(this->nvgContext);
	if (highlight) {
		nvgStroke(this->nvgContext);
	}
}

void PFDRadioAltitudeIndicatorApplication::drawValue() {
	int altitude = static_cast<int>(floor(this->altitude));
	int altitudeToRender;
	if (altitude <= 10) {
		altitudeToRender = altitude;
	}
	else if (altitude > 10 && altitude < 50) {
		altitudeToRender = static_cast<int>(floor(static_cast<double>(altitude) / 5.0) * 5);
	}
	else {
		altitudeToRender = static_cast<int>(floor(static_cast<double>(altitude) / 10.0) * 10);
	}
	nvgFillColor(this->nvgContext, Colors::white);
	nvgFontSize(this->nvgContext, 40.0f);
	nvgTextAlign(this->nvgContext, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
	nvgFontFace(this->nvgContext, "roboto");
	nvgBeginPath(this->nvgContext);
	{
		nvgText(this->nvgContext, 50, 20, std::to_string(altitudeToRender).c_str(), nullptr);
	}
	nvgFill(this->nvgContext);
}

bool PFDRadioAltitudeIndicatorApplication::shouldShowRadioAltitude() const {
	return this->altitude <= 2500;
}

bool PFDRadioAltitudeIndicatorApplication::shouldStartStartTimer() const {
	return this->lastAltitude > 2500 && this->altitude <= 2500;
}
