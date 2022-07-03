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
#include <string>

#include "MSFS/Render/nanovg.h"

namespace Tools {
	class Colors {
		public:
			inline static const NVGcolor red = nvgRGB(255, 0, 0);
			inline static const NVGcolor green = nvgRGB(0, 255, 0);
			inline static const NVGcolor blue = nvgRGB(0, 0, 255);
			inline static const NVGcolor black = nvgRGB(0, 0, 0);
			inline static const NVGcolor white = nvgRGB(255, 255, 255);
			inline static const NVGcolor magenta = nvgRGB(255, 0, 255);
			inline static const NVGcolor cyan = nvgRGB(54, 201, 210);
			inline static const NVGcolor cduButtonGray = nvgRGB(106, 107, 120);
			inline static const NVGcolor cduButtonBorderTopGray = nvgRGB(185, 175, 196);
			inline static const NVGcolor cduButtonBorderRightGray = nvgRGB(35, 34, 36);
			inline static const NVGcolor cduButtonBorderBottomGray = nvgRGB(26, 25, 28);
			inline static const NVGcolor cduButtonBorderLeftGray = nvgRGB(196, 176, 200);
	};

	/*
	 * TODO: Move to different namespace
	 */
	class Frequencies {
		public:
			enum type {
				VHF
			};

			enum state {
				ACTIVE,
				STANDBY
			};

			enum vhf_index {
				ONE = 1,
				TWO = 2,
				THREE = 3
			};

			static void setVHFFrequency(vhf_index index, state state, FLOAT64 value);
			static void setVHFActiveFrequency(vhf_index index, FLOAT64 value);
			static void setVHFStandbyFrequency(vhf_index index, FLOAT64 value);
			static void swapVHFFrequencies(vhf_index index);
			static bool isVHFFrequencyValid(FLOAT64 MHz);
			static bool isHz833Compliant(FLOAT64 MHz);
			static bool isHz25Compliant(FLOAT64 MHz);
			static bool isHz50Compliant(FLOAT64 MHz);
	};

	/*
	 * TODO: Move to different namespace
	 */
	class Transponder {
		public:
			static bool isXPDRCompliant(std::string value);
			static void setCode(std::string value);
			static void ident();
	};
}
