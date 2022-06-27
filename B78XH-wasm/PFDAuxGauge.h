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
#include "MSFS/Render/nanovg.h"

class PFDAuxGauge: public BaseGauge {
	public:
		bool preInstall() override;
		bool postInstall(FsContext context) override;
		bool preDraw(sGaugeDrawData* data) override;
		bool preDraw(FsContext context, sGaugeDrawData* data) override;
		void renderMainBackground();
		void renderBackground();
		void renderMainBorders();
		void renderBorders();
		void renderAnalogClock();
		void renderAnalogClockBody();
		void renderAnalogClockMarkers();
		void renderTexts();
		void drawAnalogClockMarker(int angle, bool isBold = false);
		void drawAnalogClockHands(int hours, int minutes, double seconds);
		void renderChronoDigital();
		void renderBottomSection();
		bool preKill() override;
	private:
		FsContext fsContext = 0;
		NVGcontext* nvgContext = 0;
		float devicePixelRatio = 0;
		float windowWidth = 0;
		float windowHeight = 0;
		double chronoTime = 0;
		double flightStartTime = 0;
		double upscaleRatio = 1;
		double throttleTimeCheck = 0;
};
