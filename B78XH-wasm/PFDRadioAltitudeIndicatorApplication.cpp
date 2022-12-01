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


#include "PFDRadioAltitudeIndicatorApplication.h"

#include "Simplane.h"
#include <cmath>
#include "Tools/Tools.h"

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
