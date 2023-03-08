#pragma once
#include <unordered_map>
#include "CrewAlertMessageName.h"
#include "CrewAlertMessage.h"

class CrewAlertMessages {
public:
	inline static std::unordered_map<CrewAlertMessageName, CrewAlertMessage> messages = {
		{APU_COOLDOWN, CrewAlertMessage("APU COOLDOWN", MEMO, false)},
		{ENG_AUTOSTART_L, CrewAlertMessage("ENG AUTOSTART L", WARNING, false)},
		{ENG_AUTOSTART_R, CrewAlertMessage("ENG AUTOSTART R", ADVISORY, false)},
		{ENG_CORE_ANTI_ICE_L, CrewAlertMessage("ENG CORE ANTI ICE L", CAUTION, false)},
		{APU_LIMIT, CrewAlertMessage("APU LIMIT", CAUTION, false)},
		{APU_RUNNING, CrewAlertMessage("APU RUNNING", WARNING, false)},
		{ENG_EEC_MODE_L, CrewAlertMessage("ENG EEC MODE L", ADVISORY, false)},
		{ENG_CORE_ANTI_ICE_R, CrewAlertMessage("ENG CORE ANTI ICE R",CAUTION, false)},
		{APU_SHUTDOWN, CrewAlertMessage("APU SHUTDOWN", MEMO, false)},
		{ENG_EEC_MODE_R, CrewAlertMessage("•ENG EEC MODE R", COMM, false)},
		{ENG_OIL_PRESS_R, CrewAlertMessage("ENG OIL PRESS R", ADVISORY, false)},
		{ENG_FAIL_L, CrewAlertMessage("ENG FAIL L", WARNING, true)},
		{ENG_FAIL_R, CrewAlertMessage("ENG FAIL R", WARNING, true)},
		{ENG_FUEL_VALVE_L, CrewAlertMessage("ENG FUEL VALVE L",MEMO, false)},
		{ENG_OIL_TEMP_L, CrewAlertMessage("ENG OIL TEMP L", ADVISORY, false)},
		{ENG_SEC_AIR_VLV_R, CrewAlertMessage("•ENG SEC AIR VLV R", COMM, false)},
	};
};