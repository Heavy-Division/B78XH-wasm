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

class PFDAuxApplication: public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;
	protected:
		void renderMainBackground() const;
		void renderBackground() const;
		void renderMainBorders() const;
		void renderBorders() const;
		void renderAnalogClock();
		void renderAnalogClockBody() const;
		void renderAnalogClockMarkers();
		void renderTexts() const;
		void drawAnalogClockMarker(int angle, bool isBold = false) const;
		void drawAnalogClockHands(int hours, int minutes, double seconds) const;
		void renderChronoDigital();
		void renderBottomSection();
	private:
		double chronoTime = 0;
		double flightStartTime = 0;
};
