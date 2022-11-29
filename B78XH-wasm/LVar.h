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

class LVar {
	public:
		LVar(PSTRINGZ id, PSTRINGZ unit);
		auto getValue() -> double;
		auto isValue() -> bool;
		auto update() -> void;
		auto set(double value) -> void;
		auto set(bool value) -> void;
		auto set(int value) -> void;
		auto set(float value) -> void;
	private:
		ID id;
		ENUM unit;
		double value;
};
