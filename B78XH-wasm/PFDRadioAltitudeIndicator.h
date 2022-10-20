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
#include "Timer.h"
#include "MSFS/Render/nanovg.h"

class PFDRadioAltitudeIndicator {
	public:
		void draw(NVGcontext* context, double deltaTime);
	private:
		void drawBackground(NVGcontext* context, bool highlight);
		void drawValue(NVGcontext* context);
		bool shouldShowRadioAltitude() const;
		bool shouldHighlightRadioAltitude() const;
		bool shouldStartStartTimer() const;
		double passDelta = -1;
		double altitude = 0;
		double lastAltitude = 0;
		Timer deltaTimer = Timer(10);
};
