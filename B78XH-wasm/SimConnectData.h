#pragma once
#include <MSFS/Legacy/gauges.h>

enum DATA_DEFINE_ID {
	DEFINITION_VHF,
	DEFINITION_TRANSPONDER_CODE,
	DEFINITION_AIRCRAFT_INFO,
	DEFINITION_AIRCRAFT_STATE,
	DEFINITION_AUTOPILOT_STATE,
	DEFINITION_AUTOPILOT_FLIGHT_DIRECTOR,
	DEFINITION_AUTOPILOT_APPROACH,
	DEFINITION_AUTOPILOT_GLIDESLOPE,
	DEFINITION_AUTOPILOT_THROTTLE,
	DEFINITION_AUTOPILOT_ALTITUDE,
	DEFINITION_AUTOPILOT_VERTICAL_SPEED,
	DEFINITION_AUTOPILOT_AIRSPEED,
	DEFINITION_AUTOPILOT_HEADING,
	DEFINITION_MISC_TIME
};

enum DATA_REQUEST_ID {
	REQUEST_VHF,
	REQUEST_TRANSPONDER_CODE,
	REQUEST_AIRCRAFT_INFO,
	REQUEST_AIRCRAFT_STATE,
	REQUEST_AUTOPILOT_STATE,
	REQUEST_AUTOPILOT_FLIGHT_DIRECTOR,
	REQUEST_AUTOPILOT_APPROACH,
	REQUEST_AUTOPILOT_GLIDESLOPE,
	REQUEST_AUTOPILOT_THROTTLE,
	REQUEST_AUTOPILOT_ALTITUDE,
	REQUEST_AUTOPILOT_VERTICAL_SPEED,
	REQUEST_AUTOPILOT_AIRSPEED,
	REQUEST_AUTOPILOT_HEADING,
	REQUEST_MISC_TIME
};

namespace SimConnectData {

	struct ComFrequencies {
		FLOAT64 activeFrequency1;
		FLOAT64 activeFrequency2;
		FLOAT64 activeFrequency3;
		FLOAT64 standbyFrequency1;
		FLOAT64 standbyFrequency2;
		FLOAT64 standbyFrequency3;
		FLOAT64 transmit1;
		FLOAT64 transmit2;
		FLOAT64 transmit3;
	};

	inline ComFrequencies comFrequencies;

	struct Transponder {
		FLOAT64 code;
	};

	inline Transponder transponder;

	namespace Aircraft {
		/**
		 * Holds basic info about aircraft
		 */
		struct Info {
			char tailID[256];
			char flightNumber[256];
		};

		inline Info info;

		/**
		 * Holds STATE of aircraft (bank, pitch and so on)
		 */

		struct State {
			double isGearOnGround;
			double bank;
			double pitch;
			double indicatedAltitude;
			double indicatedAirspeed;
			double verticalSpeed;
			double altitudeAboveGround;
			double flapsHandleIndex;
			double stallSpeed;
			double crossSpeed;
			double crossSpeedFactor;

			/*
			 * Calculated
			 */
			//double maxSpeed;
			/*
			 * L:Vars
			 */
			//double flightPhase;
			//double v1Airspeed;
			//double vRAirspeed;
			//double v2Airspeed;
			//double vREFAirspeed;
			//double vXAirspeed;
		};

		inline State state;
	}

	namespace Autopilot {
		/**
		 * Holds state of AP (engaged modes and so on)
		 */
		struct State {
			/*
			 * TODO: RENAME to "active"/"autopilotActive"/"masterActive"/"masterAutopilotActive"/"isMasterActive"
			 */
			double master;
			double isFLCHActive;
		};

		inline State state;

		struct FlightDirector {
			double isFlightDirectorActive;
			double isFlightDirector1Active;
			double isFlightDirector2Active;
			double bank;
			double pitch;
		};

		inline FlightDirector flightDirector;

		struct Approach {
			bool approachHold;
			double approachActive;
			double approachCaptured;
			double approachArm;
			double approachIsLocalizer;
			double approachType;
		};

		inline Approach approach;

		struct GlideSlope {
			double glideSlopeHold;
			double glideSlopeActive;
			double glideSlopeArm;
		};

		inline GlideSlope glideSlope;

		/*
		 * LEFT ENGINE ID = 1
		 * RIGHT ENGINE ID = 2
		 */
		struct Throttle {
			double areThrottlesArmed;
			double isLeftEngineThrottleArmed;
			double isRightEngineThrottleArmed;
			double areThrottlesActive;
			double isLeftEngineThrottleActive;
			double isRightEngineThrottleActive;
			double leftEngineThrottleMode;
			double rightEngineThrottleMode;
			double leftEngineThrottlePosition;
			double rightEngineThrottlePosition;
		};

		inline Throttle throttle;

		struct Altitude {
			double altitudeLock;
			double altitudeLockVar;
			double altitudeLockVar1;
			double altitudeLockVar2;
			double altitudeLockVar3;
			double altitudeSlotIndex;
		};

		inline Altitude altitude;

		struct VerticalSpeed {
			double verticaSpeedlHold;
			double verticalSpeedHoldVar;
			double verticalSpeedHoldVar1;
			double verticalSpeedHoldVar2;
			double verticalSpeedHoldVar3;
			double verticalSpeedSlotIndex;
		};
		inline VerticalSpeed verticalSpeed;

		struct Airspeed {
			double airspeedHold;
			double airspeedHoldVar;
			double airspeedHoldVar1;
			double airspeedHoldVar2;
			double airspeedHoldVar3;
			double airspeedSlotIndex;
			double machHold;
			double machHoldVar;
			double machHoldVar1;
			double machHoldVar2;
			double machHoldVar3;
		};

		inline Airspeed airspeed;

		struct Heading {
			double headingLock;
			double headingLockVar;
			double headingLockVar1;
			double headingLockVar2;
			double headingLockVar3;
		};

		inline Heading heading;
	}

	namespace Misc {
		struct Time {
			double absoluteTime;
			double zuluTime;
			double localMonthOfYear;
			double localDayOfMonth;
			double localYear;
		};

		inline Time time;
	}

}
