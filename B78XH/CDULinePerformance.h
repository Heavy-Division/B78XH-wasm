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
#include <string>
#include <vector>

#include "CDULineAlign.h"
#include "CDULineType.h"

struct CDULinePerformance {
	CDULinePerformance(CDULineType type, CDULineAlign align, CDULineNumber number): lineType(type), lineAlign(align),
		lineNumber(number) {

	};

	/*
	 * Remove default values???
	 */
	CDULineType lineType = CDULineType::LINE;
	CDULineAlign lineAlign = CDULineAlign::LEFT;
	CDULineNumber lineNumber = CDULineNumber::ONE;
	std::vector<std::vector<std::string>> data = {};
	auto getData() -> std::vector<std::vector<std::string>>& {
		return this->data;
	};
};
