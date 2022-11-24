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
#include "PFDAltitudeIndicator.h"
#include "PFDFlightDirector.h"
#include "PFDILSIndicator.h"
#include "PFDRadioAltitudeIndicator.h"
#include "MSFS/Render/nanovg.h"

class PFDPfdGauge: public BaseGauge {
	public:
		bool preInstall() override;
		bool postInstall(FsContext context) override;
		void registerVariables();
		bool preDraw(sGaugeDrawData* data) override;
		void test();
		void renderMainBackground();
		void renderAttitude();
		void renderPitch();
		void renderTriangle();
		void renderDashes();
		void renderDash(int angle, int length);
		void renderCursor();
		void renderSlipSkid();
		bool preDraw(FsContext context, sGaugeDrawData* data) override;
		bool preKill() override;
		static double deltaTime;
	private:
		FsContext fsContext = 0;
		NVGcontext* nvgContext = 0;
		float devicePixelRatio = 0;
		float windowWidth = 0;
		float windowHeight = 0;

		int slipSkidVariableId = 0;
		int slipSkidUnitsId = 0;
		int baseFont = 0;
		int heavyFont = 0;

		double pitchPosition = 0;
		double centerPosition = 0;
		PFDRadioAltitudeIndicator radioAltitudeIndicator;
		PFDFlightDirector flightDirector;
		PFDILSIndicator ilsIndicator;
		PFDAltitudeIndicator altitudeIndicator;
};
