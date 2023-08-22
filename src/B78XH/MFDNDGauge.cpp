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


#include "MFDNDGauge.h"
#include <cmath>
#include "vector"
#include "Simplane.h"

bool MFDNDGauge::preInstall() {
	return true;
}

bool MFDNDGauge::postInstall(FsContext context) {
	NVGparams params;
	params.userPtr = context;
	params.edgeAntiAlias = true;

	this->nvgContext = nvgCreateInternal(&params);
	nvgCreateFont(this->nvgContext, "heavy-fmc", "./data/Heavy787FMC.ttf");
	return true;
}

bool MFDNDGauge::preDraw(sGaugeDrawData* data) {
	const auto devicePixelRatio = static_cast<float>(data->fbWidth) / static_cast<float>(data->winWidth);
	const auto windowWidth = static_cast<float>(data->winWidth);
	const auto windowHeight = static_cast<float>(data->winHeight);

	nvgBeginFrame(this->nvgContext, windowWidth, windowHeight, devicePixelRatio);
	{
		nvgFillColor(this->nvgContext, nvgRGB(97, 100, 127));
		nvgBeginPath(this->nvgContext);
		{
			nvgRect(this->nvgContext, 0, 0, windowWidth, windowHeight);
		}
		nvgFill(this->nvgContext);
		this->testRender(data);
	}
	nvgEndFrame(nvgContext);
	return true;
}

bool MFDNDGauge::preDraw(FsContext context, sGaugeDrawData* data) {
	return true;
}

bool MFDNDGauge::preKill() {
	nvgDeleteInternal(this->nvgContext);
	return true;
}

void MFDNDGauge::testRender(sGaugeDrawData* data) {

	//fmt::print(stderr, "LATIDUDE: {}", Simplane::aircraft::state::latitude());
	//fmt::print(stderr, "LONGITUDE: {}", Simplane::aircraft::state::longitude());

	this->centerLat = Simplane::aircraft::state::latitude();
	this->centerLong = Simplane::aircraft::state::longitude();

	const auto devicePixelRatio = static_cast<float>(data->fbWidth) / static_cast<float>(data->winWidth);
	const auto windowWidth = static_cast<float>(data->winWidth);
	const auto windowHeight = static_cast<float>(data->winHeight);

	const auto ndTranslateX = (windowWidth / 2) - 500;
	const auto ndTranslateY = (windowHeight / 2) - 500;

	this->calculateCoordinates();

	/*
	 * ND BACKGROUND 1000x1000 pixels 
	 */
	nvgFillColor(this->nvgContext, nvgRGB(0, 0, 0));
	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, ndTranslateX, ndTranslateY);
		{
			nvgBeginPath(this->nvgContext);
			{
				nvgRect(this->nvgContext, 0, 0, 1000, 1000);
			}
			nvgFill(this->nvgContext);
		}
		nvgResetTransform(this->nvgContext);
	}

	/*
	 * This is center point
	 */

	nvgFillColor(this->nvgContext, nvgRGB(255, 0, 0));
	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, ndTranslateX, ndTranslateY);
		{
			nvgBeginPath(this->nvgContext);
			{
				nvgRect(this->nvgContext, 495, 495, 10, 10);
			}
			nvgFill(this->nvgContext);
		}
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);

	std::vector<double> pr = this->latLongToXY(this->pr402Lat, this->pr402Long);

	//fmt::print(stderr, "X: {}", pr.at(0));
	//fmt::print(stderr, "Y: {}", pr.at(1));

	nvgFillColor(this->nvgContext, nvgRGB(0, 255, 0));

	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, ndTranslateX, ndTranslateY);
		{
			nvgBeginPath(this->nvgContext);
			{
				nvgRect(this->nvgContext, pr.at(0), pr.at(1), 10, 10);
			}
			nvgFill(this->nvgContext);
		}
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);


	std::vector<double> pr2 = this->latLongToXY(this->pr405Lat, this->pr405Long);

	//fmt::print(stderr, "X: {}", pr.at(0));
	//fmt::print(stderr, "Y: {}", pr.at(1));

	nvgFillColor(this->nvgContext, nvgRGB(0, 255, 0));

	nvgSave(this->nvgContext);
	{
		nvgTranslate(this->nvgContext, ndTranslateX, ndTranslateY);
		{
			nvgBeginPath(this->nvgContext);
			{
				nvgRect(this->nvgContext, pr2.at(0), pr2.at(1), 10, 10);
			}
			nvgFill(this->nvgContext);
		}
		nvgResetTransform(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}

std::vector<double> MFDNDGauge::latLongToXY(double lat, double lon) {
	std::vector<double> vector = {};
	if(this->centerLong > 90) {
		if(lon < -90) {
			lon += 360;
		}
	}

	if(this->centerLong < -90) {
		if(lon > 90) {
			lon -= 360;
		}
	}
	/*
	double x = (lon - this->centerLong) / this->angularWidthNorth * 1000;
	double y = -((lat - this->centerLat) / this->angularWidthSouth) * 1000;
	*/
	/*
	 * FIXED NORTH Implementation
	 */

	//vector.push_back(x + 500);
	//vector.push_back(y + 500);

	/*
	 * PLANE HEADING UP IMPLEMENTATION
	 */
	 /*
	vector.push_back(x * this->cosPlaneDirection - y * this->sinPlaneDirection + 500);
	vector.push_back(x * this->sinPlaneDirection + y * this->cosPlaneDirection + 500);
	*/

	const double xNorth = (lon - this->centerLong) / this->angularWidthNorth * 1000;
	const double xSouth = (lon - this->centerLong) / this->angularWidthSouth * 1000;
	const double delta = (lat - this->centerLat) / this->angularHeight;
	const double delta2 = delta + 0.5;

	const double x = xNorth * delta + xSouth * (1 - delta);
	const double y = -delta * 1000;

	vector.push_back(x * this->cosPlaneDirection - y * this->sinPlaneDirection + 500);
	vector.push_back(x * this->sinPlaneDirection + y * this->cosPlaneDirection + 500);



	return vector;
}

void MFDNDGauge::calculateCoordinates() {
	this->ftWidth = 6076.11549 * this->nmWidth;
	this->angularWidth = this->nmWidth / 60.0 / std::cos(nvgDegToRad(this->centerLat));
	this->angularHeight = this->nmWidth / 60.0;
	this->bottomLeftLat = this->centerLat - this->angularHeight * 0.5;
	this->bottomLeftLong = this->centerLong - this->angularHeight * 0.5;

	this->topRightLat = this->centerLat + this->angularHeight * 0.5;
	this->topRightLong = this->centerLong + this->angularHeight * 0.5;

	this->angularWidthNorth = this->nmWidth / 60.0 / std::cos(nvgDegToRad(this->topRightLat));
	this->angularWidthSouth = this->nmWidth / 60.0 / std::cos(nvgDegToRad(this->bottomLeftLat));

	double trueHeading = Simplane::aircraft::state::headingTrue();
	const float fixedHeading = 360 - fmod(trueHeading, 360);

	this->cosPlaneDirection = std::cos(nvgDegToRad(fixedHeading));
	this->sinPlaneDirection = std::sin(nvgDegToRad(fixedHeading));
}
