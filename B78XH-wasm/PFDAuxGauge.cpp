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


#include "PFDAuxGauge.h"

#include <cmath>
#include <ctime>

#include "fmt/core.h"
#include "SimConnectConnector.h"

bool PFDAuxGauge::preInstall() {
	return true;
}

bool PFDAuxGauge::postInstall(FsContext context) {
	this->fsContext = context;
	NVGparams params;
	params.userPtr = context;
	params.edgeAntiAlias = true;

	nvgContext = nvgCreateInternal(&params);
	nvgCreateFont(nvgContext, "heavy-fmc", "./data/Heavy787FMC.ttf");
	return true;
}

bool PFDAuxGauge::preDraw(sGaugeDrawData* data) {
	return true;
}

bool PFDAuxGauge::preDraw(FsContext context, sGaugeDrawData* data) {
	this->chronoTime += data->dt;
	this->throttleTimeCheck += data->dt;
	if (this->throttleTimeCheck < 0.05) {
		return true;
	}
	this->throttleTimeCheck = 0;

	if (this->flightStartTime == 0) {
		this->flightStartTime = SimConnectData::Misc::time.absoluteTime;
	}

	this->devicePixelRatio = static_cast<float>(data->fbWidth) / static_cast<float>(data->winWidth);
	this->devicePixelRatio = 2;
	this->windowWidth = static_cast<float>(data->winWidth);
	this->windowHeight = static_cast<float>(data->winHeight);

	nvgBeginFrame(nvgContext, windowWidth, windowHeight, devicePixelRatio);
	{
		
		this->renderMainBackground();
		this->renderBackground();
		this->renderMainBorders();
		this->renderBorders();
		this->renderAnalogClock();

		this->renderTexts();
		this->renderChronoDigital();
		this->renderBottomSection();
		
	}
	nvgEndFrame(nvgContext);
	return true;
}

void PFDAuxGauge::renderMainBackground() {
	nvgFillColor(nvgContext, nvgRGB(0, 0, 0));
	nvgBeginPath(nvgContext);
	nvgRect(nvgContext, 0, 0, this->windowWidth, this->windowHeight);
	nvgFill(nvgContext);
	nvgClosePath(nvgContext);
}

void PFDAuxGauge::renderBackground() {
	nvgFillColor(nvgContext, nvgRGB(49, 49, 51));
	nvgBeginPath(nvgContext);
	nvgRect(nvgContext, 0, 0, this->windowWidth, 250);
	nvgFill(nvgContext);
	nvgClosePath(nvgContext);
}

void PFDAuxGauge::renderMainBorders() {
	nvgBeginPath(nvgContext);
	nvgMoveTo(nvgContext, this->windowWidth - 2, 0);
	nvgLineTo(nvgContext, this->windowWidth - 2, this->windowHeight);
	nvgStrokeColor(nvgContext, nvgRGB(78, 78, 80));
	nvgStrokeWidth(nvgContext, 4.0f);
	nvgStroke(nvgContext);
	nvgClosePath(nvgContext);
}

void PFDAuxGauge::renderBorders() {
	nvgBeginPath(nvgContext);
	nvgMoveTo(nvgContext, 2, 0);
	nvgLineTo(nvgContext, 2, 250);
	nvgLineTo(nvgContext, this->windowWidth, 250);
	nvgMoveTo(nvgContext, 2, 200);
	nvgLineTo(nvgContext, this->windowWidth, 200);


	//nvgMoveTo(nvgContext, 0, 200);
	//nvgLineTo(nvgContext, this->windowWidth, 200);
	nvgStrokeColor(nvgContext, nvgRGB(78, 78, 80));
	nvgStrokeWidth(nvgContext, 4.0f);
	nvgStroke(nvgContext);
	nvgClosePath(nvgContext);
}

void PFDAuxGauge::renderAnalogClock() {
	this->renderAnalogClockBody();
	this->renderAnalogClockMarkers();

	this->drawAnalogClockHands(3, 30, this->chronoTime);
}

void PFDAuxGauge::renderAnalogClockBody() {
	constexpr float centerX = 348;
	constexpr float centerY = 75;
	constexpr float radius = 67;
	nvgBeginPath(nvgContext);
	//nvgMoveTo(nvgContext, 100, 100);
	nvgArc(nvgContext, centerX, centerY, radius, 0, 2 * NVG_PI, NVG_CW);
	nvgFillColor(nvgContext, nvgRGB(30, 27, 28));
	nvgFill(nvgContext);
	nvgStrokeColor(nvgContext, nvgRGB(255, 255, 255));
	nvgStrokeWidth(nvgContext, 4.0f);
	nvgStroke(nvgContext);
	nvgClosePath(nvgContext);
}

void PFDAuxGauge::renderAnalogClockMarkers() {
	this->drawAnalogClockMarker(30);
	this->drawAnalogClockMarker(60);
	this->drawAnalogClockMarker(90, true);
	this->drawAnalogClockMarker(120);
	this->drawAnalogClockMarker(150);
	this->drawAnalogClockMarker(180, true);
	this->drawAnalogClockMarker(210);
	this->drawAnalogClockMarker(240);
	this->drawAnalogClockMarker(270, true);
	this->drawAnalogClockMarker(300);
	this->drawAnalogClockMarker(330);
	this->drawAnalogClockMarker(360, true);
}

void PFDAuxGauge::renderTexts() {
	constexpr float titleHorizontalOffset = 15.0f;
	constexpr float valueHorizontalOffset = 95.0f;
	constexpr int verticalOffsets[5] = {25, 62, 99, 136, 175};


	nvgResetTransform(this->nvgContext);
	nvgSave(this->nvgContext);
	nvgFontFace(this->nvgContext, "heavy-fmc");
	nvgFontSize(this->nvgContext, 18.0f);
	nvgTextAlign(this->nvgContext, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
	nvgFillColor(this->nvgContext, nvgRGB(59, 183, 213));

	/*
	 * Titles
	 */
	nvgText(this->nvgContext, titleHorizontalOffset, verticalOffsets[0], "FLT #", nullptr);
	nvgText(this->nvgContext, titleHorizontalOffset, verticalOffsets[1], "MIC", nullptr);
	nvgText(this->nvgContext, titleHorizontalOffset, verticalOffsets[2], "XPDR", nullptr);
	nvgText(this->nvgContext, titleHorizontalOffset, verticalOffsets[3], "SELCAL", nullptr);
	nvgText(this->nvgContext, titleHorizontalOffset, verticalOffsets[4], "TAIL #", nullptr);


	/*
	 * Values
	 */
	nvgFillColor(this->nvgContext, nvgRGB(255, 255, 255));
	nvgFontSize(this->nvgContext, 35.0f);
	nvgText(this->nvgContext, valueHorizontalOffset, verticalOffsets[0], "ETD654", nullptr);
	nvgFontSize(this->nvgContext, 23.0f);
	nvgText(this->nvgContext, valueHorizontalOffset, verticalOffsets[1], "118.100", nullptr);
	nvgText(this->nvgContext, valueHorizontalOffset, verticalOffsets[2], "7344", nullptr);
	nvgText(this->nvgContext, valueHorizontalOffset, verticalOffsets[3], "JM-GP", nullptr);
	nvgText(this->nvgContext, valueHorizontalOffset, verticalOffsets[4], "AL-BLN", nullptr);
	nvgRestore(this->nvgContext);
}

void PFDAuxGauge::drawAnalogClockMarker(int angle, bool isBold) {
	constexpr float centerX = 348;
	constexpr float centerY = 75;
	constexpr float radius = 67;
	const float rotation = angle * NVG_PI / 180;
	nvgSave(nvgContext);
	nvgBeginPath(nvgContext);
	nvgTranslate(nvgContext, centerX, centerY);
	nvgRotate(nvgContext, rotation);
	nvgTranslate(nvgContext, 0, -radius);
	nvgMoveTo(nvgContext, 0, 0);
	nvgLineTo(nvgContext, 0, (isBold ? 10.0f : 8.0f));
	nvgStrokeWidth(nvgContext, (isBold ? 4.0f : 2.5f));
	nvgStroke(nvgContext);
	nvgClosePath(nvgContext);
	nvgRestore(nvgContext);
}

void PFDAuxGauge::drawAnalogClockHands(int hours, int minutes, double seconds) {
	constexpr float centerX = 348;
	constexpr float centerY = 75;
	constexpr float radius = 67;
	constexpr float length = 54;
	constexpr float width = 8;


	const double angle = seconds * NVG_PI / 30;
	nvgSave(nvgContext);

	nvgBeginPath(nvgContext);
	nvgTranslate(nvgContext, centerX, centerY);
	nvgRotate(nvgContext, -NVG_PI);
	nvgRotate(nvgContext, angle);
	nvgMoveTo(nvgContext, 0, 0);


	nvgMoveTo(nvgContext, -width / 2, 0);

	// ok
	nvgLineTo(nvgContext, -width / 2, length);
	// ok
	nvgLineTo(nvgContext, 0, (length + 12));

	nvgLineTo(nvgContext, width / 2, length);
	nvgLineTo(nvgContext, width / 2, 0);
	nvgLineTo(nvgContext, -width / 2, 0);
	nvgLineJoin(nvgContext, NVG_ROUND);
	nvgFillColor(nvgContext, nvgRGB(255, 255, 255));
	nvgFill(nvgContext);
	nvgStrokeColor(nvgContext, nvgRGB(255, 255, 255));
	nvgStrokeWidth(nvgContext, 1.0f);
	nvgStroke(nvgContext);
	nvgClosePath(nvgContext);


	nvgBeginPath(nvgContext);
	nvgArc(nvgContext, 0, 0, 4, 0, 2 * NVG_PI, NVG_CW);
	nvgFillColor(nvgContext, nvgRGB(0, 0, 0));
	nvgFill(nvgContext);
	nvgStrokeWidth(nvgContext, 3.0f);
	nvgStroke(nvgContext);
	nvgClosePath(nvgContext);
}

void PFDAuxGauge::renderChronoDigital() {
	const int minutes = floor(this->chronoTime) / 60;
	const int seconds = floor(this->chronoTime) - (minutes * 60);
	nvgTextAlign(this->nvgContext, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
	nvgFillColor(this->nvgContext, nvgRGB(255, 255, 255));
	nvgFontSize(this->nvgContext, 23.0f);
	nvgText(this->nvgContext, 348, 175.0f, fmt::format("{:02}:{:02}", minutes, seconds).c_str(), nullptr);
}

void PFDAuxGauge::renderBottomSection() {

	nvgFontFace(this->nvgContext, "heavy-fmc");
	nvgFontSize(this->nvgContext, 18.0f);
	nvgTextAlign(this->nvgContext, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
	nvgFillColor(this->nvgContext, nvgRGB(59, 183, 213));
	nvgText(this->nvgContext, 70.0f, 215.0f, "UTC", nullptr);
	nvgText(this->nvgContext, 212.5, 215.0f, "DATE", nullptr);
	nvgText(this->nvgContext, 348, 215.0f, "ELAPSED TIME", nullptr);


	std::string elapsedTime = "00:00";
	if (this->flightStartTime != 0) {
		const int diff = floor(SimConnectData::Misc::time.absoluteTime - this->flightStartTime);
		const int hours = floor(diff / 3600);
		const int minutes = floor((diff - (hours * 3600)) / 60);
		elapsedTime = fmt::format("{:02}:{:02}", hours, minutes);
	}

	nvgFillColor(this->nvgContext, nvgRGB(255, 255, 255));
	nvgFontSize(this->nvgContext, 23.0f);
	nvgText(this->nvgContext, 348, 236.0f, fmt::format("{}", elapsedTime).c_str(), nullptr);

	/*
	 * Date
	 */
	const std::string months[12] = { "JAN", "FEB", "MAR", "APR", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
	const std::string year = std::to_string(SimConnectData::Misc::time.localYear).substr(2,2);
	const std::string date = fmt::format("{:02} {} {}", SimConnectData::Misc::time.localDayOfMonth, months[static_cast<int>(SimConnectData::Misc::time.localMonthOfYear) - 1], year);
	nvgText(this->nvgContext, 212.5f, 236.0f, fmt::format("{}", date).c_str(), nullptr);

	/*
	 * UTC - Zulu
	 */

	const int zulu = floor(SimConnectData::Misc::time.zuluTime);
	const int hours = floor(zulu) / 3600;
	const int minutes = floor(zulu - (hours * 3600)) / 60;
	const int seconds = floor(zulu - (minutes * 60) - (hours * 3600));
	nvgText(this->nvgContext, 70.0f, 236.0f, fmt::format("{:02}:{:02}:{:02}z", hours, minutes, seconds).c_str(), nullptr);

	

}

bool PFDAuxGauge::preKill() {
	nvgDeleteInternal(nvgContext);
	return true;
}
