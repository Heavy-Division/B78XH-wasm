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


/// Fuel system notes
///
/// capacities and quantities are in gallons (volume) - since density can
/// actually vary, I presume volume capacity is the limiting factor. No matter
/// how much the fuel weighs, can only squeeze so much volume of fuel into the 
/// tanks. leaves open the possibility of simulating fuel density later. For now
/// density is fixed, default unit imperial (gallons/lbs)
///
/// All variants have the same fuel tanks apparently - same capacity!
/// So then I wondered why the -8 has lower range than a -9 since lighter 
/// plane + less fuel should mean more range
/// answer: https://www.quora.com/How-does-the-Boeing-787-9-manage-to-have-a-greater-range-than-the-787-8-even-though-fuel-capacity-is-almost-identical

#pragma once

#include "Updateable.h"

class FuelSystem final : public Updateable {
    // todo: expose fuel flow rates, other parameters, etc
    public:
        auto update(double deltaTime) -> void override;

        auto getLeftTankFuel() -> double;
        auto getRightTankFuel() -> double;
        auto getCenterTankFuel() -> double;
    private:
        static constexpr double LEFT_RIGHT_MAIN_TANK_CAPACITY_GALLONS = 5520;
        static constexpr double CENTER_TANK_CAPACITY_GALLONS = 22340;
        static constexpr double LEFT_RIGHT_SURGE_TANK_CAPACITY_GALLONS = 996.5;

        static constexpr double FUEL_DENSITY_LBS_PER_GALLON = 6.7;

        double leftTankFuel;
        double rightTankFuel;
        double centerTankFuel;

        // todo: better way to represent refuel speed. want 3 speeds instant, fast, and real like i've seen other mods. For now can use 0/1/2 or wtv
        bool refueling;
        int refuelSpeed;

        // are there default lvars for this? not sure
        bool leftJettisonNozzleOn;
        bool rightJettisonNozzleOn;
};