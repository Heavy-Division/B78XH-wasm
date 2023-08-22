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
#include "Application.h"
#include "Timer.h"

class PFDRadioAltitudeIndicatorApplication : public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;

	private:
		void drawBackground(bool highlight);
		void drawValue();
		bool shouldShowRadioAltitude() const;
		bool shouldHighlightRadioAltitude() const;
		bool shouldStartStartTimer() const;

		double passDelta = -1;
		double altitude = 0;
		double lastAltitude = 0;
		Timer deltaTimer = Timer(10);
};
