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
#include "fmt/core.h"

namespace GPSTools {
	inline void search(char* ident) {
		double numberOfIcaos;
		double numberOfIcaos2;
		double numberOfIcaos3;
		int numberOfIcaosInt;
		int numberOfIcaosInt2;
		int numberOfIcaosInt3;
		PCSTRINGZ stringOfIcaosInt;
		bool startCursor = execute_calculator_code("'V' (&gt;C:fs9gps:IcaoSearchStartCursor, string)", nullptr, nullptr, nullptr);
		bool search = execute_calculator_code("(C:fs9gps:IcaoSearchMatchedIcaosNumber, number)", &numberOfIcaos, &numberOfIcaosInt, nullptr);
		fmt::print(stderr, "NUMBER OF ICAOS: {}, {}; {}", numberOfIcaos, numberOfIcaosInt, search);

		//bool search2 = execute_calculator_code("(C:fs9gps:IcaoSearchMatchedIcao)", &numberOfIcaos2, &numberOfIcaosInt2, nullptr);
		//fmt::print(stderr, "NUMBER OF ICAOS2: {}, {}; {}", numberOfIcaos2, numberOfIcaosInt2, search2);

		//bool search3 = execute_calculator_code("(C:fs9gps:IcaoSearchCurrentIcao)", &numberOfIcaos3, &numberOfIcaosInt3, &stringOfIcaosInt);
		//fmt::print(stderr, "NUMBER OF ICAOS3: {}, {}, {}; {}", numberOfIcaos2, stringOfIcaosInt, numberOfIcaosInt2, search3);
	}

	inline void set(char* ident) {
		//bool startCursor = execute_calculator_code("'V' (&gt;C:fs9gps:IcaoSearchStartCursor)", nullptr, nullptr, nullptr);
		//fmt::print(stderr, "START CURSOR: {}", startCursor);
		//std::string toSearch = fmt::format("'{}' (>C:fs9gps:IcaoSearchEnterChar, string)", "LKPR");
		//bool enterChar = execute_calculator_code("L (>C:fs9gps:IcaoSearchEnterChar)", nullptr, nullptr, nullptr);
		//fmt::print(stderr, "ENTER CHAR: {}", enterChar);
	}
}
