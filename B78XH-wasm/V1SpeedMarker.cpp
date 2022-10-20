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


#include "V1SpeedMarker.h"
#include "Simplane.h";


auto V1SpeedMarker::draw(NVGcontext* context, double target, double indicatedAirspeed) -> void {
	if (isPassed) {
		return;
	}
	/*
	 * Remove V1 after takeoff
	 */
	if (Simplane::aircraft::state::altitudeAboveGround() > 30) {
		isPassed = true;
	}
	SpeedMarker::draw(context, target, indicatedAirspeed);
}
