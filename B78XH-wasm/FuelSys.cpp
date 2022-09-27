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
#include "FuelSystem.h"

auto FuelSystem::getCenterTankFuel() -> double {
    return centerTankFuel;
}

auto FuelSystem::getLeftTankFuel() -> double {
    return leftTankFuel;
}

auto FuelSystem::getRightTankFuel() -> double {
    return rightTankFuel;
}

// updating all the tank quantities etc might go here
auto FuelSystem::update(double deltaTime) -> void {
    // factors affecting: engine power, whether jettison nozzles on, etc
}
