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
#include "FlapsSpeedMarker.h"
#include "V1SpeedMarker.h"
#include "V2SpeedMarker.h"
#include "VRefSpeedMarker.h"
#include "VRSpeedMarker.h"

class PFDAirspeedIndicatorApplication: public Application {

	private:
		inline static V1SpeedMarker v1SpeedMarker = V1SpeedMarker("V1", false);
		inline static V2SpeedMarker v2SpeedMarker = V2SpeedMarker("V2", false);
		inline static VRSpeedMarker vRSpeedMarker = VRSpeedMarker("VR", false);
		inline static VRefSpeedMarker vRefSpeedMarker = VRefSpeedMarker("REF", false);
		inline static FlapsSpeedMarker currentFlapsMarker = FlapsSpeedMarker("", true);
		inline static FlapsSpeedMarker nextFlapsMarker = FlapsSpeedMarker("", true);
		void drawVSpeedMarkers(double v1, double v2, double vR, double deltaTime);
		void drawNOVSpeedMessage();
		void drawSpeedMarkers(double deltaTime);
		bool shouldDrawFlapsMarkers(double indicatedAltitude, double flightPhase);
		void drawOverSpeedStrips();
		void drawStallStrips();
		void drawProtStrip();
		void drawStrips();
		void drawBackground();
		void drawGraduations();
		void drawCursor();
		void drawTargetPointer();
	public:
		auto render(sGaugeDrawData* data) -> void override;
};