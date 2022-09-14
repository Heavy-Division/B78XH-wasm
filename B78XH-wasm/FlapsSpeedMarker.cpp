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


#include "FlapsSpeedMarker.h"
#include "Simplane.h"
#include "fmt/core.h"
#include "Tools.h"

auto FlapsSpeedMarker::draw(NVGcontext* context, double target, double indicatedAirspeed) -> void {
	SpeedMarker::draw(context, target, indicatedAirspeed);
}

auto FlapsSpeedMarker::draw(NVGcontext* context, double target, double indicatedAirspeed,
                            double flapsHandleIndex) -> void {
	isPassed = false;
	title = this->flapsLabel(flapsHandleIndex);
	this->draw(context, target - calculateSpeedBuffer(), indicatedAirspeed);
}

auto FlapsSpeedMarker::calculateSpeedBuffer() -> double {
	const double baseWeightRatio = Simplane::aircraft::state::weight() / Simplane::aircraft::state::maxWeight();
	const double altitudeRatio = Simplane::aircraft::state::indicatedAltitude() / 30000;
	const double weightRatio = 1 - Tools::clamp((baseWeightRatio - 0.65) / (1 - 0.65), 0.0, 1.0);
	return 50 * (weightRatio * 0.7 + altitudeRatio * 0.3);
}

auto FlapsSpeedMarker::flapsLabel(double flapsHandleIndex) -> std::string {
	switch (static_cast<int>(flapsHandleIndex)) {
		case 0: {
			return "UP";
		}
		case 1: {
			return "1";
		}
		case 2: {
			return "5";
		}
		case 3: {
			return "10";
		}
		case 4: {
			return "15";
		}
		case 5: {
			return "17";
		}
		case 6: {
			return "18";
		}
		case 7: {
			return "20";
		}
		case 8: {
			return "25";
		}
		case 9: {
			return "30";
		}
		default: {
			return "";
		}
	}
};
