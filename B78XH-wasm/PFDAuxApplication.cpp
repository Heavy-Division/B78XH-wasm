#include "PFDAuxApplication.h"
#include "Tools.h"
#include "Simplane.h"
#include <cmath>

using Colors = Tools::Colors;

void PFDAuxApplication::render(sGaugeDrawData* data) {
	this->chronoTime += data->dt;

	if (this->flightStartTime == 0) {
		this->flightStartTime = SimConnectData::Misc::time.absoluteTime;
	}


	this->renderMainBackground();
	this->renderBackground();
	this->renderMainBorders();
	this->renderBorders();
	this->renderAnalogClock();

	this->renderTexts();
	this->renderChronoDigital();
	this->renderBottomSection();
}

void PFDAuxApplication::renderMainBackground() const {
	nvgFillColor(nvgContext, Colors::black);
	nvgBeginPath(nvgContext);
	nvgRect(nvgContext, 0, 0, this->width, this->height);
	nvgFill(nvgContext);
	nvgClosePath(nvgContext);
}

void PFDAuxApplication::renderBackground() const {
	nvgFillColor(nvgContext, nvgRGB(49, 49, 51));
	nvgBeginPath(nvgContext);
	nvgRect(nvgContext, 0, 0, this->width, 250);
	nvgFill(nvgContext);
	nvgClosePath(nvgContext);
}

void PFDAuxApplication::renderMainBorders() const {
	nvgBeginPath(nvgContext);
	nvgMoveTo(nvgContext, this->width - 2, 0);
	nvgLineTo(nvgContext, this->width - 2, this->height);
	nvgStrokeColor(nvgContext, nvgRGB(78, 78, 80));
	nvgStrokeWidth(nvgContext, 4.0f);
	nvgStroke(nvgContext);
	nvgClosePath(nvgContext);
}

void PFDAuxApplication::renderBorders() const {
	nvgBeginPath(nvgContext);
	nvgMoveTo(nvgContext, 2, 0);
	nvgLineTo(nvgContext, 2, 250);
	nvgLineTo(nvgContext, this->width, 250);
	nvgMoveTo(nvgContext, 2, 200);
	nvgLineTo(nvgContext, this->width, 200);


	//nvgMoveTo(nvgContext, 0, 200);
	//nvgLineTo(nvgContext, this->windowWidth, 200);
	nvgStrokeColor(nvgContext, nvgRGB(78, 78, 80));
	nvgStrokeWidth(nvgContext, 4.0f);
	nvgStroke(nvgContext);
	nvgClosePath(nvgContext);
}

void PFDAuxApplication::renderAnalogClock() {
	this->renderAnalogClockBody();
	this->renderAnalogClockMarkers();

	this->drawAnalogClockHands(3, 30, this->chronoTime);
}

void PFDAuxApplication::renderAnalogClockBody() const {
	constexpr float centerX = 348;
	constexpr float centerY = 75;
	constexpr float radius = 67;
	nvgBeginPath(nvgContext);
	//nvgMoveTo(nvgContext, 100, 100);
	nvgArc(nvgContext, centerX, centerY, radius, 0, 2 * NVG_PI, NVG_CW);
	nvgFillColor(nvgContext, nvgRGB(30, 27, 28));
	nvgFill(nvgContext);
	nvgStrokeColor(nvgContext, Colors::white);
	nvgStrokeWidth(nvgContext, 4.0f);
	nvgStroke(nvgContext);
	nvgClosePath(nvgContext);
}

void PFDAuxApplication::renderAnalogClockMarkers() {
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

void PFDAuxApplication::renderTexts() const {
	constexpr float titleHorizontalOffset = 15.0f;
	constexpr float valueHorizontalOffset = 95.0f;
	constexpr int verticalOffsets[5] = { 25, 62, 99, 136, 175 };


	nvgResetTransform(this->nvgContext);
	nvgSave(this->nvgContext);
	nvgFontFace(this->nvgContext, "heavy-fmc");
	nvgFontSize(this->nvgContext, 18.0f);
	nvgTextAlign(this->nvgContext, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
	nvgFillColor(this->nvgContext, Colors::cyan);

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
	nvgFillColor(this->nvgContext, Colors::white);
	nvgFontSize(this->nvgContext, 35.0f);
	nvgText(this->nvgContext, valueHorizontalOffset, verticalOffsets[0], Simplane::aircraft::info::flightNumber(), nullptr);
	nvgFontSize(this->nvgContext, 23.0f);
	nvgText(this->nvgContext, valueHorizontalOffset, verticalOffsets[1], fmt::format("{:.3f}", Simplane::comFrequencies::activeFrequency1()).c_str(), nullptr);
	nvgText(this->nvgContext, valueHorizontalOffset, verticalOffsets[2], fmt::format("{}", static_cast<int>(Simplane::transponder::code())).c_str(), nullptr);
	nvgText(this->nvgContext, valueHorizontalOffset, verticalOffsets[3], "DH-GR", nullptr);
	nvgText(this->nvgContext, valueHorizontalOffset, verticalOffsets[4], Simplane::aircraft::info::tailID(), nullptr);
	nvgRestore(this->nvgContext);
}

void PFDAuxApplication::drawAnalogClockMarker(int angle, bool isBold) const {
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

void PFDAuxApplication::drawAnalogClockHands(int hours, int minutes, double seconds) const {
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
	nvgFillColor(nvgContext, Colors::white);
	nvgFill(nvgContext);
	nvgStrokeColor(nvgContext, Colors::white);
	nvgStrokeWidth(nvgContext, 1.0f);
	nvgStroke(nvgContext);
	nvgClosePath(nvgContext);


	nvgBeginPath(nvgContext);
	nvgArc(nvgContext, 0, 0, 4, 0, 2 * NVG_PI, NVG_CW);
	nvgFillColor(nvgContext, Colors::black);
	nvgFill(nvgContext);
	nvgStrokeWidth(nvgContext, 3.0f);
	nvgStroke(nvgContext);
	nvgClosePath(nvgContext);
}

void PFDAuxApplication::renderChronoDigital() {
	const int minutes = floor(this->chronoTime) / 60;
	const int seconds = floor(this->chronoTime) - (minutes * 60);
	nvgTextAlign(this->nvgContext, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
	nvgFillColor(this->nvgContext, Colors::white);
	nvgFontSize(this->nvgContext, 23.0f);
	nvgText(this->nvgContext, 348, 175.0f, fmt::format("{:02}:{:02}", minutes, seconds).c_str(), nullptr);
}

void PFDAuxApplication::renderBottomSection() {

	nvgFontFace(this->nvgContext, "heavy-fmc");
	nvgFontSize(this->nvgContext, 18.0f);
	nvgTextAlign(this->nvgContext, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
	nvgFillColor(this->nvgContext, Colors::cyan);
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

	nvgFillColor(this->nvgContext, Colors::white);
	nvgFontSize(this->nvgContext, 23.0f);
	nvgText(this->nvgContext, 348, 236.0f, fmt::format("{}", elapsedTime).c_str(), nullptr);

	/*
	 * Date
	 */
	const std::string months[12] = { "JAN", "FEB", "MAR", "APR", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
	const std::string year = std::to_string(SimConnectData::Misc::time.localYear).substr(2, 2);
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
