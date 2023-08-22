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


#include "V2SpeedMarker.h"
#include "Simplane.h"

auto V2SpeedMarker::draw(NVGcontext* context, double target, double indicatedAirspeed) -> void {
	this->draw(context, target, indicatedAirspeed, 0);
}

auto V2SpeedMarker::draw(NVGcontext* context, double target, double indicatedAirspeed, double deltaTime) -> void {
	if (isPassed) {
		return;
	}

	/*
	 * Remove V2 when VREF has been selected
	 */

	if (Simplane::instruments::cdu::vREF() != 0) {
		isPassed = true;
	}

	/*
	 * Remove V2 when flap retraction begins
	 */
	if (Simplane::aircraft::state::altitudeAboveGround() < 30) {
		this->takeoffFlaps = Simplane::aircraft::state::flapsHandleIndex();
	}

	if ((takeoffFlaps == 0 || takeoffFlaps > Simplane::aircraft::state::flapsHandleIndex()) &&
		Simplane::aircraft::state::altitudeAboveGround() > 30) {
		isPassed = true;
	}

	/*
	 * Remove V2 10 minutes after takeoff without flap lever movement
	 */

	if (!Simplane::aircraft::state::isGearOnGround()) {
		this->takeoffTimeDelta += deltaTime;
	}
	else {
		this->takeoffTimeDelta = 0;
	}

	if (this->takeoffTimeDelta > 600) {
		isPassed = true;
		this->takeoffTimeDelta = 0;
	}
	SpeedMarker::draw(context, target, indicatedAirspeed);
}
