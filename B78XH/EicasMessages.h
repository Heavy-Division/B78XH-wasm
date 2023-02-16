#pragma once

namespace EICASMessages {
	
	namespace APU {
		enum Messages {
			APU_COOLDOWN,
			APU_LIMIT,
			APU_RUNNING,
			APU_SHUTDOWN
		};
		inline Messages messages;
	}

	namespace Engine {
		enum Messages {
			ENG_CONTROL_L,
			ENG_CONTROL_R,
			ENG_CORE_ANTI_ICE_L,
			ENG_CORE_ANTI_ICE_R,
			ENG_EEC_MODE_L,
			ENG_EEC_MODE_R,
			ENG_FAIL_L,
			ENG_FAIL_R,
			ENG_LIMIT_EXCEED_L,
			ENG_LIMIT_EXCEED_R,
			ENG_LIMIT_PROT_L,
			ENG_LIMIT_PROT_R,
			ENG_REV_AIR_GROUND,
			ENG_REV_COMMANDED_L,
			ENG_REV_COMMANDED_R,
			ENG_REV_LIMITED_L,
			ENG_REV_LIMITED_R,
			EMG_REVERSER_L,
			EMG_REVERSER_R,
			ENG_RPM_LIMITED_L,
			ENG_RPM_LIMITED_R,
			ENG_SEC_AIR_VLV_L,
			ENG_SEC_AIR_VLV_R,
			ENG_SHUTDOWN,
			ENG_SHUTDOWN_L,
			ENG_SHUTDOWN_R,
			ENG_SURGE_L,
			ENG_SURGE_R,
			ENG_THRUST_L,
			ENG_THRUST_R,
			ENG_THRUST_HIGH_L,
			ENG_THRUST_HIGH_R,
			ENG_TURB_DAMAGE_L,
			ENG_TURB_DAMAGE_R,
			THRUST_ASYM_PROT,
			ENG_AUTOSTART_L,
			ENG_AUTOSTART_R,
			ENG_START_CUTOUT_L,
			ENG_START_CUTOUT_R,
			ENG_STARTERS_L,
			ENG_STARTERS_R,

		};
		inline Messages messages;
	}

	namespace Fuel {
		enum Messages {
			ENG_FUEL_FILTER_L,
			ENG_FUEL_FILTER_R,
			ENG_FUEL_FILTER_LR,
			ENG_FUEL_VALVE_L,
			ENG_FUEL_VALVE_R,
		};

		inline Messages messages;
	}

	namespace Oil {
		enum Messages {
			ENG_OIL_PRESS_L,
			ENG_OIL_PRESS_R,
			ENG_OIL_TEMP_L,
			ENG_OIL_TEMP_R,
		};

		inline Messages messages;
	}
};