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

enum DATA_DEFINE_ID {
	DEFINITION_VHF,
	DEFINITION_TRANSPONDER_CODE,
	DEFINITION_AIRCRAFT_INFO,
	DEFINITION_AIRCRAFT_STATE,
	DEFINITION_AUTOPILOT_STATE,
	DEFINITION_AUTOPILOT_FLIGHT_DIRECTOR,
	DEFINITION_AUTOPILOT_APPROACH,
	DEFINITION_AUTOPILOT_GLIDESLOPE,
	DEFINITION_AUTOPILOT_NAVIGATION,
	DEFINITION_AUTOPILOT_THROTTLE,
	DEFINITION_AUTOPILOT_ALTITUDE,
	DEFINITION_AUTOPILOT_VERTICAL_SPEED,
	DEFINITION_AUTOPILOT_AIRSPEED,
	DEFINITION_AUTOPILOT_HEADING,
	DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	DEFINITION_BAROMETER_SETTING,
	DEFINITION_MISC_TIME,
	DEFINITION_CLOSE,
	DEFINITION_TEMPERATURE,
	DEFINITION_ENGINE,
	DEFINITION_FUEL,
	DEFINITION_ALTITUDE,
	DEFINITION_FLIGHT_SURFACES
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
	REQUEST_AUTOPILOT_NAVIGATION,
	REQUEST_AUTOPILOT_THROTTLE,
	REQUEST_AUTOPILOT_ALTITUDE,
	REQUEST_AUTOPILOT_VERTICAL_SPEED,
	REQUEST_AUTOPILOT_AIRSPEED,
	REQUEST_AUTOPILOT_HEADING,
	REQUEST_EQUIPMENT_RADIONAV_UNIT1,
	REQUEST_EQUIPMENT_RADIONAV_UNIT2,
	REQUEST_EQUIPMENT_RADIONAV_UNIT3,
	REQUEST_EQUIPMENT_RADIONAV_UNIT4,
	REQUEST_BAROMETER_SETTING,
	REQUEST_MISC_TIME,
	REQUEST_CLOSE,
	REQUEST_TEMPERATURE,
	REQUEST_ENGINE,
	REQUEST_FUEL,
	REQUEST_ALTITUDE,
	REQUEST_FLIGHT_SURFACES
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
			double gearPosition;
			double isGearMotorOn;
			double bank;
			double pitch;
			double groundSpeed;
			double indicatedAltitude;
			double indicatedAirspeed;
			double verticalSpeed;
			double altitudeAboveGround;
			double flapsHandleIndex;
			double latitude;
			double longitude;
			double headingTrue;
			double headingMagnetic;
			double headingMagneticGround;
			double weight;
			double maxWeight;

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
			double isGPSDriven;
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
			double approachHold;
			double approachActive;
			double approachCaptured;
			double approachArm;
			double approachIsLocalizer;
			double approachType;
			double approachIsLoaded;
		};

		inline Approach approach;

		struct GlideSlope {
			double glideSlopeHold;
			double glideSlopeActive;
			double glideSlopeArm;
		};

		inline GlideSlope glideSlope;

		struct Navigation {
			double backCourseHold;
		};

		inline Navigation navigation;

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
			double verticalSpeedHold;
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

	namespace Equipment::RadioNav {
		struct Unit1 {
			double gsi;
			double glideSlopeError;
			double cdi;
			double hasLocalizer;
			double hasNav;
			double hasDme;
			double dme;
			double hasGlideSlope;
			double obs;
			double radial;
			double activeFrequency;
			double standbyFrequency;
			double localizer;
			char name[256];
			char ident[256];
		};

		inline Unit1 unit1;

		struct Unit2 {
			double gsi;
			double glideSlopeError;
			double cdi;
			double hasLocalizer;
			double hasNav;
			double hasDme;
			double dme;
			double hasGlideSlope;
			double obs;
			double radial;
			double activeFrequency;
			double standbyFrequency;
			double localizer;
			char name[256];
			char ident[256];
		};

		inline Unit2 unit2;

		struct Unit3 {
			double gsi;
			double glideSlopeError;
			double cdi;
			double hasLocalizer;
			double hasNav;
			double hasDme;
			double dme;
			double hasGlideSlope;
			double obs;
			double radial;
			double activeFrequency;
			double standbyFrequency;
			double localizer;
			char name[256];
			char ident[256];
		};

		inline Unit3 unit3;

		struct Unit4 {
			double gsi;
			double glideSlopeError;
			double cdi;
			double hasLocalizer;
			double hasNav;
			double hasDme;
			double dme;
			double hasGlideSlope;
			double obs;
			double radial;
			double activeFrequency;
			double standbyFrequency;
			double localizer;
			char name[256];
			char ident[256];
		};

		inline Unit4 unit4;
	}

	namespace Barometer {
		struct Setting {
			double kohlsmanHG;
			double kohlsmanMB;
			double decisionHeight;
			double decisionAltitudeMSL;
		};

		inline Setting setting;
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

	namespace environment {
		struct Temperature {
			double totalAirTemperature;
			double staticAirTemperature;
		};

		inline Temperature temperature;
	}

	namespace Aircraft::systems {
		namespace powerplant {
			struct Engine {
				double engine1_n1;
				double engine1_n2;
				double engine2_n1;
				double engine2_n2;
				double engine1_commandedn1;
				double engine2_commandedn1;
				double engine1_egt;
				double engine2_egt;
				double engine1_fuel_flow_pph;
				double engine2_fuel_flow_pph;
				double engine1_combustion;
				double engine2_combustion;
				double engine1_oil_pressure;
				double engine2_oil_pressure;
				double engine1_oil_temp;
				double engine2_oil_temp;
				double engine1_oil_qty;
				double engine2_oil_qty;
				double engine1_vibration;
				double engine2_vibration;
			};

			inline Engine engine;
		}

		namespace fuel {
			struct Fuel {
				double cutoff_eng1;
				double cutoff_eng2;
				double total_lbs;
			};

			inline Fuel fuel;
		}

	}

	namespace Aircraft::position {
		struct Altitude {
			double indicated_altitude;
		};

		inline Altitude altitude;
	}

	namespace Aircraft::flight_surfaces {
		struct FlightSurfaces {
			double trailing_edge_flaps_left_percent;
		};

		inline FlightSurfaces flight_surfaces;
	}

}



struct TestAirport {
	double latitude;
	double longitude;
	double altitude;
	double magVar;
	char name[32];
	double towerLatitude;
	double towerLongitude;
	double towerAltitude;
	int runways;
	int frequencies;
	int helipads;
	int departures;
	int arrivals;
	int taxiParkings;
	int taxiPaths;
	int taxiNames;
	int jetways;
};
