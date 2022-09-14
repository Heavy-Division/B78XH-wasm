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


#include "VRSpeedMarker.h"
#include "Simplane.h"

auto VRSpeedMarker::draw(NVGcontext* context, double target, double indicatedAirspeed) -> void {
	if (SpeedMarker::isPassed) {
		return;
	}
	/*
	 * Remove VR after takeoff
	 */
	if (Simplane::aircraft::state::altitudeAboveGround() > 30) {
		SpeedMarker::isPassed = true;
	}

	const double minV1SafeBorder = Simplane::instruments::cdu::v1() - 4;
	const double maxV1SafeBorder = Simplane::instruments::cdu::v1() + 4;
	const double minV2SafeBorder = Simplane::instruments::cdu::v2() - 4;
	const double maxV2SafeBorder = Simplane::instruments::cdu::v2() + 4;

	if ((target >= minV1SafeBorder && target <= maxV1SafeBorder) || (target >= minV2SafeBorder && target <=
		maxV2SafeBorder)) {
		SpeedMarker::title = "R";
		SpeedMarker::enableSafeArea = true;
	}
	else {
		SpeedMarker::title = "VR";
		SpeedMarker::enableSafeArea = false;
	}

	SpeedMarker::draw(context, target, indicatedAirspeed);
}
