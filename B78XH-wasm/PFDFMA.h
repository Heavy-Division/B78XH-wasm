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
#include "MSFS/Render/nanovg.h"

class PFDFMA {
	public:
		static void draw(NVGcontext* context, float windowWidth, float windowHeight);
	private:
		struct ThrottleMode {
			static constexpr auto HOLD = "HOLD";
			static constexpr auto IDLE = "IDLE";
			static constexpr auto SPD = "SPD";
			static constexpr auto THR = "THR";
			static constexpr auto THR_REF = "THR REF";
			static constexpr auto NONE = "";
		};

		struct PitchMode {
			static constexpr auto ALT = "ALT";
			static constexpr auto FLARE = "FLARE";
			static constexpr auto FLCH_SPD = "FLCH SPD";
			static constexpr auto FPA = "FPA";
			static constexpr auto GS = "G/S";
			static constexpr auto GP = "G/P";
			static constexpr auto TOGA = "TO/GA";
			static constexpr auto VNAV_PTH = "VNAV PTH";
			static constexpr auto VNAV_SPD = "VNAV SPD";
			static constexpr auto VNAV_ALT = "VNAV ALT";
			static constexpr auto VNAV = "VNAV";
			static constexpr auto VS = "V/S";
			static constexpr auto NONE = "";
		};

		struct RollMode {
			static constexpr auto B_CRS = "B/CRS";
			static constexpr auto FAC = "FAC";
			static constexpr auto HDG_HOLD = "HDG HOLD";
			static constexpr auto HDG_SEL = "HDG SEL";
			static constexpr auto HUD_TOGA = "HUD TO/GA";
			static constexpr auto LNAV = "LNAV";
			static constexpr auto LOC = "LOC";
			static constexpr auto ROLLOUT = "ROLLOUT";
			static constexpr auto TOGA = "TO/GA";
			static constexpr auto TRK_SEL = "TRK SEL";
			static constexpr auto TRK_HOLD = "TRK HOLD";
			static constexpr auto ATT = "ATT";
			static constexpr auto NONE = "";
		};

		static void drawBackground(NVGcontext* context, float windowWidth, float windowHeight);
		static void drawTexts(NVGcontext* context, float windowWidth, float windowHeight);
		static const char* resolveActiveThrustMode();
		static const char* resolveActiveRollMode();
		static const char* resolveArmedRollMode();
		static const char* resolveActivePitchMode();
		static const char* resolveArmedPitchMode();
};