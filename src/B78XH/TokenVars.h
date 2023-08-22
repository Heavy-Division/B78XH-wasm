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
#include <MSFS/Legacy/gauges.h>

class TokenVars {
	public:
		static double getNavFrequency() {
			const auto unit = get_units_enum("Number");
			const auto var = get_aircraft_var_enum("NAV FREQUENCY");
			return aircraft_varget(var, unit, 0);
		}

		static STRING test() {
			const auto unit = get_units_enum("string");
			const auto var = get_aircraft_var_enum("NAV IDENT");

			//fmt::print(stderr, "DIRECT0: ", aircraft_varget(var, unit, 0));
			//fmt::print(stderr, "DIRECT1: ", aircraft_varget(var, unit, 1));
			//fmt::print(stderr, "DIRECT2: ", aircraft_varget(var, unit, 2));
			//fmt::print(stderr, "DIRECT3: {}", aircraft_varget(var, get_units_enum("string"), 3));
			//fmt::print(stderr, "DIRECT4: ", aircraft_varget(var, unit, 4));
			return aircraft_varget(var, unit, 3);
		}
};
