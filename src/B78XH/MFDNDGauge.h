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


#pragma once
#include "BaseGauge.h"

class MFDNDGauge : public BaseGauge {
public:
	bool preInstall() override;
	bool postInstall(FsContext context) override;
	bool preDraw(sGaugeDrawData* data) override;
	bool preDraw(FsContext context, sGaugeDrawData* data) override;
	bool preKill() override;
	void testRender(sGaugeDrawData* data);
	std::vector<double> latLongToXY(double lat, double lon);

private:
	FsContext fsContext = 0;
	NVGcontext* nvgContext = nullptr;
	float devicePixelRatio = 0;
	float windowWidth = 0;
	float windowHeight = 0;

	int baseFont = 0;
	int heavyFont = 0;

	double ratio = 1;
	double nmWidth = 50;
	double ftWidth = 0;
	double angularHeight = 0;
	double angularWidth = 0;
	double angularWidthNorth = 0;
	double angularWidthSouth = 0;
	double topRightLat = 0;
	double topRightLong = 0;
	double bottomLeftLat = 0;
	double bottomLeftLong = 0;

	double cosPlaneDirection = 0;
	double sinPlaneDirection = 0;

	/*
	 * HardCoded LKPR RW 24 
	 */

	double centerLat = 50.115175;
	double centerLong = 14.270752;

	/*
	 * HardCoded PR402 from BALTU4A
	 */

	double pr402Lat = 50.038278;
	double pr402Long = 14.015472;

	/*
	 * HardCoded PR405 from BALTU4A
	 */

	double pr405Lat = 50.199389;
	double pr405Long = 13.842194;

	void calculateCoordinates();
};
