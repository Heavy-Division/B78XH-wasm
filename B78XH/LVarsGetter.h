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

namespace LVarsGetter {
	inline auto isMachModeActive = []()-> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("XMLVAR_AirSpeedIsInMach"),
		                                                        get_units_enum("bool")));
	};

	inline auto isSpeedInterventionActive = []()-> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("AP_SPEED_INTERVENTION_ACTIVE"),
		                                                        get_units_enum("bool")));
	};

	inline auto isHeadingHoldActive = []()-> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("AP_HEADING_HOLD_ACTIVE"),
		                                                        get_units_enum("bool")));
	};

	inline auto isSpeedActive = []()-> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("AP_SPD_ACTIVE"),
		                                                        get_units_enum("bool")));
	};

	inline auto isFLCHActive = []()-> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("AP_FLCH_ACTIVE"),
		                                                        get_units_enum("bool")));
	};

	inline auto isVNAVActive = []()-> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("AP_VNAV_ACTIVE"),
		                                                        get_units_enum("bool")));
	};

	inline auto isVNAVArmed = []()-> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("AP_VNAV_ARMED"),
		                                                        get_units_enum("bool")));
	};

	inline auto isLNAVActive = []()-> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("AP_LNAV_ACTIVE"),
		                                                        get_units_enum("bool")));
	};

	inline auto isLNAVArmed = []()-> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("AP_LNAV_ARMED"),
		                                                        get_units_enum("bool")));
	};

	inline auto isAltitudeHoldActive = []()-> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("AP_ALT_HOLD_ACTIVE"),
		                                                        get_units_enum("bool")));
	};

	inline auto isFPAModeActive = []()-> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("XMLVAR_FPA_MODE_ACTIVE"),
		                                                        get_units_enum("bool")));
	};

	inline auto isTRKModeActive = []()-> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("XMLVAR_TRK_MODE_ACTIVE"),
		                                                        get_units_enum("bool")));
	};

	inline auto isTRKFPAModeActive = []()-> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("XMLVAR_TRK_FPA_MODE_ACTIVE"),
		                                                        get_units_enum("bool")));
	};

	inline auto airlinerCruiseAltitude = []()-> double {
		return get_named_variable_typed_value(register_named_variable("AIRLINER_CRUISE_ALTITUDE"),
		                                      get_units_enum("Number"));
	};

	inline auto stallSpeed = []() -> double {
		return get_named_variable_typed_value(register_named_variable("B78XH_L_TRANSFER_PROTOCOL_STALL_SPEED"),
		                                      get_units_enum("Number"));
	};

	inline auto stallProtectionMinSpeed = []() -> double {
		return get_named_variable_typed_value(register_named_variable("B78XH_L_TRANSFER_PROTOCOL_STALL_PROTECTION_MIN_SPEED"),
				                               get_units_enum("Number"));
	};

	inline auto stallProtectionMaxSpeed = []() -> double {
		return get_named_variable_typed_value(register_named_variable("B78XH_L_TRANSFER_PROTOCOL_STALL_PROTECTION_MAX_SPEED"),
				                               get_units_enum("Number"));
	};

	inline auto v1Speed = []() -> double {
		return get_named_variable_typed_value(register_named_variable("AIRLINER_V1_SPEED"), get_units_enum("Knots"));
	};

	inline auto v2Speed = []() -> double {
		return get_named_variable_typed_value(register_named_variable("AIRLINER_V2_SPEED"), get_units_enum("Knots"));
	};

	inline auto vRSpeed = []() -> double {
		return get_named_variable_typed_value(register_named_variable("AIRLINER_VR_SPEED"), get_units_enum("Knots"));
	};

	inline auto vREFSpeed = []() -> double {
		return get_named_variable_typed_value(register_named_variable("AIRLINER_VREF_SPEED"), get_units_enum("Knots"));
	};

	inline auto approachFlaps = []() -> double {
		return get_named_variable_typed_value(register_named_variable("AIRLINER_APPROACH_FLAPS"),
		                                      get_units_enum("Number"));
	};

	inline auto flightPhase = []() -> double {
		return get_named_variable_typed_value(register_named_variable("AIRLINER_FLIGHT_PHASE"),
		                                      get_units_enum("Number"));
	};

	inline auto isBaroInHPA = []() -> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("XMLVAR_Baro_Selector_HPA_1"),
		                                                        get_units_enum("Bool")));
	};

	inline auto isBaroForcedToSTD = []() -> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("XMLVAR_Baro1_forcedToSTD"),
		                                                        get_units_enum("Bool")));
	};

	inline auto isMinimumSelectorBaro = []() -> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("XMLVAR_Mins_Selector_Baro"),
		                                                        get_units_enum("Bool")));
	};

	inline auto radionavSource = []() -> double {
		return get_named_variable_typed_value(register_named_variable("RADIONAV_SOURCE"), get_units_enum("Number"));
	};

	inline auto isIRSInited = []() -> bool {
		return static_cast<bool>(get_named_variable_typed_value(register_named_variable("B78XH_IS_IRS_INITED"),
		                                                        get_units_enum("Number")));
	};

	inline auto irsRState = []() -> double {
		return get_named_variable_typed_value(register_named_variable("B78XH_IRS_R_STATE"), get_units_enum("Number"));
	};

	inline auto irsLState = []() -> double {
		return get_named_variable_typed_value(register_named_variable("B78XH_IRS_L_STATE"), get_units_enum("Number"));
	};

	inline auto irsRSwitchState = []() -> double {
		return get_named_variable_typed_value(register_named_variable("B78XH_IRS_R_SWITCH_STATE"),
		                                      get_units_enum("Number"));
	};

	inline auto irsLSwitchState = []() -> double {
		return get_named_variable_typed_value(register_named_variable("B78XH_IRS_L_SWITCH_STATE"),
		                                      get_units_enum("Number"));
	};

}

