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

namespace LVars {
	inline auto isMachModeActive = []()-> bool {
		return get_named_variable_typed_value(register_named_variable("XMLVAR_AirSpeedIsInMach"), get_units_enum("bool"));
	};

	inline auto isSpeedInterventionActive = []()-> bool {
		return get_named_variable_typed_value(register_named_variable("AP_SPEED_INTERVENTION_ACTIVE"), get_units_enum("bool"));
	};

	inline auto isHeadingHoldActive = []()-> bool {
		return get_named_variable_typed_value(register_named_variable("AP_HEADING_HOLD_ACTIVE"), get_units_enum("bool"));
	};

	inline auto isSpeedActive = []()-> bool {
		return get_named_variable_typed_value(register_named_variable("AP_SPD_ACTIVE"), get_units_enum("bool"));
	};

	inline auto isFLCHActive = []()-> bool {
		return get_named_variable_typed_value(register_named_variable("AP_FLCH_ACTIVE"), get_units_enum("bool"));
	};

	inline auto isVNAVActive = []()-> bool {
		return get_named_variable_typed_value(register_named_variable("AP_VNAV_ACTIVE"), get_units_enum("bool"));
	};

	inline auto isVNAVArmed = []()-> bool {
		return get_named_variable_typed_value(register_named_variable("AP_VNAV_ARMED"), get_units_enum("bool"));
	};

	inline auto isLNAVActive = []()-> bool {
		return get_named_variable_typed_value(register_named_variable("AP_LNAV_ACTIVE"), get_units_enum("bool"));
	};

	inline auto isLNAVArmed = []()-> bool {
		return get_named_variable_typed_value(register_named_variable("AP_LNAV_ARMED"), get_units_enum("bool"));
	};

	inline auto isAltitudeHoldActive = []()-> bool {
		return get_named_variable_typed_value(register_named_variable("AP_ALT_HOLD_ACTIVE"), get_units_enum("bool"));
	};

	inline auto isFPAModeActive = []()-> bool {
		return get_named_variable_typed_value(register_named_variable("XMLVAR_FPA_MODE_ACTIVE"), get_units_enum("bool"));
	};

	inline auto isTRKModeActive = []()-> bool {
		return get_named_variable_typed_value(register_named_variable("XMLVAR_TRK_MODE_ACTIVE"), get_units_enum("bool"));
	};

	inline auto isTRKFPAModeActive = []()-> bool {
		return get_named_variable_typed_value(register_named_variable("XMLVAR_TRK_FPA_MODE_ACTIVE"), get_units_enum("bool"));
	};

	inline auto airlinerCruiseAltitude = []()-> double {
		return get_named_variable_typed_value(register_named_variable("AIRLINER_CRUISE_ALTITUDE"), get_units_enum("Number"));
	};
}
