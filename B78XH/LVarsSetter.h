#pragma once
#include <MSFS/Legacy/gauges.h>

#include "CDUEvent.h"
#include "CDUPageType.h"
#include "IRSState.h"
#include "IRSSwitchState.h"

namespace LVarsSetter {
	inline auto setIrsLSwitchState = [](IRSSwitchState state) -> void {
		set_named_variable_value(register_named_variable("B78XH_IRS_L_SWITCH_STATE"), static_cast<double>(state));
	};

	inline auto setIrsRSwitchState = [](IRSSwitchState state) -> void {
		set_named_variable_value(register_named_variable("B78XH_IRS_R_SWITCH_STATE"), static_cast<double>(state));
	};

	inline auto setIrsLState = [](IRSState state) -> void {
		set_named_variable_value(register_named_variable("B78XH_IRS_L_STATE"), static_cast<double>(state));
	};

	inline auto setIrsRState = [](IRSState state) -> void {
		set_named_variable_value(register_named_variable("B78XH_IRS_R_STATE"), static_cast<double>(state));
	};

	inline auto setIsIRSInited = [](bool value) -> void {
		set_named_variable_value(register_named_variable("B78XH_IS_IRS_INITED"), value);
	};

	inline auto setCDUControlId(CDUEvent eventId) -> void {
		set_named_variable_value(register_named_variable("CDU_CONTROL_ID"), static_cast<double>(eventId));
	}

	inline auto setCDUControlId(CDUPageType pageId) -> void {
		set_named_variable_value(register_named_variable("CDU_CONTROL_ID"), static_cast<double>(pageId));
	}

}
