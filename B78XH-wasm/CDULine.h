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
#include "CDULineAlign.h"
#include "CDULineType.h"
#include <string>
#include <vector>

enum class CDULineNumber {
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX
};


class CDULine {
	public:
		CDULine(CDULineNumber lineNumber = CDULineNumber::ONE, std::vector<std::vector<std::string>> content = {});
		CDULine(CDULineNumber lineNumber = CDULineNumber::ONE, std::string content = "");
		void setContent(std::string content);

		std::vector<int> r = {};
		std::vector<int> g = {};
		std::vector<int> b = {};
		std::vector<bool> settable = {};
		float x = 0;
		float y = 0;

		void setContent(std::string content) const;
		void setContent(std::vector<std::vector<std::string>> content, bool settable = false);
		void reset();
		double getOffset();
		CDULineType getLineType() const;
		std::string getBasicContent();
		std::vector<std::string> getComplexContent();

	protected:
		inline static constexpr double baseYOffset = 78;
		inline static constexpr double yOffsetFactor = 61;
		CDULineNumber lineNumber;
		CDULineType type = CDULineType::BASIC;
		CDULineAlign align = CDULineAlign::LEFT;

		std::string basicContent = "";
		std::vector<std::string> complexContent = {};

		void reverseContent();
};
