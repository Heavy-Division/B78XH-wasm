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
#include <unordered_map>
#include <map>
#include "LVar.h"

class LVars {
	public:
		enum LVarsName {
			/*
			 * BOOLEAN
			 */
			XMLVAR_AirSpeedIsInMach,
			AP_SPEED_INTERVENTION_ACTIVE,
			AP_HEADING_HOLD_ACTIVE,
			AP_SPD_ACTIVE,
			AP_FLCH_ACTIVE,
			AP_VNAV_ACTIVE,
			AP_VNAV_ARMED,
			AP_LNAV_ACTIVE,
			AP_LNAV_ARMED,
			AP_VS_ACTIVE,
			AP_ALT_HOLD_ACTIVE,
			XMLVAR_FPA_MODE_ACTIVE,
			XMLVAR_TRK_MODE_ACTIVE,
			XMLVAR_TRK_FPA_MODE_ACTIVE,

			/*
			 * NUMBERS
			 */

			AIRLINER_CRUISE_ALTITUDE,
			B78XH_L_TRANSFER_PROTOCOL_STALL_SPEED,
			B78XH_L_TRANSFER_PROTOCOL_STALL_PROTECTION_MIN_SPEED,
			B78XH_L_TRANSFER_PROTOCOL_STALL_PROTECTION_MAX_SPEED,
			XMLVAR_APU_StarterKnob_Pos,

			/*
			 * KNOTS
			 */

			AIRLINER_V1_SPEED,
			AIRLINER_V2_SPEED,
			AIRLINER_VR_SPEED,
			AIRLINER_VREF_SPEED,

			/*
			 * NUMBERS
			 */
			AIRLINER_APPROACH_FLAPS,
			AIRLINER_FLIGHT_PHASE,

			/*
			 * BOOLEANS
			 */

			XMLVAR_Baro_Selector_HPA_1,
			XMLVAR_Baro1_forcedToSTD,
			XMLVAR_Mins_Selector_Baro,

			/*
			 * NUMBERS
			 */

			RADIONAV_SOURCE,
			B78XH_IS_IRS_INITED,
			B78XH_IRS_R_STATE,
			B78XH_IRS_L_STATE,
			B78XH_IRS_R_SWITCH_STATE,
			B78XH_IRS_L_SWITCH_STATE


		};

		static auto update() -> void;
		static auto get(LVarsName name) -> LVar&;
		static auto get(PSTRINGZ name) -> LVar;
	private:
		inline static std::unordered_map<LVarsName, LVar> data = {
			{XMLVAR_AirSpeedIsInMach, LVar("XMLVAR_AirSpeedIsInMach", "bool")},
			{AP_SPEED_INTERVENTION_ACTIVE, LVar("AP_SPEED_INTERVENTION_ACTIVE", "bool")},
			{AP_HEADING_HOLD_ACTIVE, LVar("AP_HEADING_HOLD_ACTIVE", "bool")},
			{AP_SPD_ACTIVE, LVar("AP_SPD_ACTIVE", "bool")},
			{AP_FLCH_ACTIVE, LVar("AP_FLCH_ACTIVE", "bool")},
			{AP_VNAV_ACTIVE, LVar("AP_VNAV_ACTIVE", "bool")},
			{AP_VNAV_ARMED, LVar("AP_VNAV_ARMED", "bool")},
			{AP_LNAV_ACTIVE, LVar("AP_LNAV_ACTIVE", "bool")},
			{AP_LNAV_ARMED, LVar("AP_LNAV_ARMED", "bool")},
			{AP_VS_ACTIVE, LVar("AP_VS_ACTIVE", "bool")},
			{AP_ALT_HOLD_ACTIVE, LVar("AP_ALT_HOLD_ACTIVE", "bool")},
			{XMLVAR_FPA_MODE_ACTIVE, LVar("XMLVAR_FPA_MODE_ACTIVE", "bool")},
			{XMLVAR_TRK_MODE_ACTIVE, LVar("XMLVAR_TRK_MODE_ACTIVE", "bool")},
			{XMLVAR_TRK_FPA_MODE_ACTIVE, LVar("XMLVAR_TRK_FPA_MODE_ACTIVE", "bool")},
			{AIRLINER_CRUISE_ALTITUDE, LVar("AIRLINER_CRUISE_ALTITUDE", "Number")},
			{B78XH_L_TRANSFER_PROTOCOL_STALL_SPEED, LVar("B78XH_L_TRANSFER_PROTOCOL_STALL_SPEED", "Number")},
			{
				B78XH_L_TRANSFER_PROTOCOL_STALL_PROTECTION_MIN_SPEED,
				LVar("B78XH_L_TRANSFER_PROTOCOL_STALL_PROTECTION_MIN_SPEED", "Number")
			},
			{
				B78XH_L_TRANSFER_PROTOCOL_STALL_PROTECTION_MAX_SPEED,
				LVar("B78XH_L_TRANSFER_PROTOCOL_STALL_PROTECTION_MAX_SPEED", "Number")
			},
			{AIRLINER_V1_SPEED, LVar("AIRLINER_V1_SPEED", "Knots")},
			{AIRLINER_V2_SPEED, LVar("AIRLINER_V2_SPEED", "Knots")},
			{AIRLINER_VR_SPEED, LVar("AIRLINER_VR_SPEED", "Knots")},
			{AIRLINER_VREF_SPEED, LVar("AIRLINER_VREF_SPEED", "Knots")},
			{AIRLINER_APPROACH_FLAPS, LVar("AIRLINER_APPROACH_FLAPS", "Number")},
			{AIRLINER_FLIGHT_PHASE, LVar("AIRLINER_FLIGHT_PHASE", "Number")},
			{XMLVAR_Baro_Selector_HPA_1, LVar("XMLVAR_Baro_Selector_HPA_1", "bool")},
			{XMLVAR_Baro1_forcedToSTD, LVar("XMLVAR_Baro1_forcedToSTD", "bool")},
			{XMLVAR_Mins_Selector_Baro, LVar("XMLVAR_Mins_Selector_Baro", "bool")},
			{RADIONAV_SOURCE, LVar("RADIONAV_SOURCE", "Number")},
			{B78XH_IS_IRS_INITED, LVar("B78XH_IS_IRS_INITED", "Number")},
			{B78XH_IRS_R_STATE, LVar("B78XH_IRS_R_STATE", "Number")},
			{B78XH_IRS_L_STATE, LVar("B78XH_IRS_L_STATE", "Number")},
			{B78XH_IRS_R_SWITCH_STATE, LVar("B78XH_IRS_R_SWITCH_STATE", "Number")},
			{B78XH_IRS_L_SWITCH_STATE, LVar("B78XH_IRS_L_SWITCH_STATE", "Number")},
			{XMLVAR_APU_StarterKnob_Pos, LVar("XMLVAR_APU_StarterKnob_Pos", "Number")}
		};
};
