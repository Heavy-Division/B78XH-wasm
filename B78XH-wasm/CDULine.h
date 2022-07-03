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
#include "CDULineRenderingType.h"
#include <string>
#include <vector>

#include "CDULineType.h"
#include "Drawable.h"
#include "MSFS/Render/nanovg.h"

enum class CDULineNumber {
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX
};


class CDULine: public Drawable {
	public:
		std::vector<int> r = {};
		std::vector<int> g = {};
		std::vector<int> b = {};
		std::vector<bool> settable = {};
		float x = 0;
		float y = 0;

		void draw() override;
		void setContent(std::string content);
		void setContent(std::vector<std::vector<std::string>> content, bool settable = false);
		void reset();
		float getVerticalOffset();
		virtual void calculateHorizontalOffset();
		CDULineRenderingType getLineType() const;
		std::string getBasicContent();
		std::vector<std::string> getComplexContent();

	protected:
		CDULine(NVGcontext*& context, CDULineNumber lineNumber = CDULineNumber::ONE, std::vector<std::vector<std::string>> content = {});
		CDULine(NVGcontext*& context, CDULineNumber lineNumber = CDULineNumber::ONE, std::string content = "");

		float horizontalOffset = 0;
		inline static constexpr float titleVerticalOffset = -30;
		inline static constexpr float baseVerticalOffset = 78;
		inline static constexpr float yOffsetFactor = 61;
		float fontSize = 20.0f;
		CDULineNumber lineNumber;
		CDULineType lineType = CDULineType::LINE;
		CDULineRenderingType lineRenderingType = CDULineRenderingType::BASIC;
	
		CDULineAlign align = CDULineAlign::LEFT;
		NVGcontext*& context;

		std::string basicContent = "";
		std::vector<std::string> complexContent = {};

		void reverseContent();
		virtual void drawBasicLine();
		virtual void drawComplexLine();
};
