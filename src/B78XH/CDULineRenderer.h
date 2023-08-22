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
#include "CDULine.h"
#include "CDULineType.h"
#include "MSFS/Render/nanovg.h"

class CDULineRenderer {
	public:
		CDULineRenderer(NVGcontext*& context);
		auto draw(CDULineType type, CDULineNumber lineNumber, CDULineAlign lineAlign, std::vector<std::vector<std::string>>& content) -> void;
		auto drawComplexLine() -> void;
		auto getVerticalOffset() -> float;

	private:
		NVGcontext*& context;
		CDULineNumber lineNumber = CDULineNumber::ONE;
		CDULineType lineType = CDULineType::LINE;
		CDULineAlign lineAlign = CDULineAlign::LEFT;
		float horizontalOffset = 0;
		float fontSize = 20.0f;
		inline static constexpr float titleVerticalOffset = -30;
		inline static constexpr float baseVerticalOffset = 78;
		inline static constexpr float yOffsetFactor = 61;
		std::vector<std::tuple<std::string, NVGcolor, bool, float>> complexContentData;
		std::string plainContentData = "";
		auto prepareContent(const std::vector<std::vector<std::string>>& content) -> void;
		auto clearData() -> void;
		auto calculateHorizontalOffset() -> void;
};
