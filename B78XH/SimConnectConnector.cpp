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


#include "SimConnectConnector.h"

#include "Tools\Console.h"
#include "GaugesInvalidateFlags.h"
#include "SimConnectClientEvents.h"
#include "EventDispatchers.h"
#include "MFDPanelResolver.h"

auto SimConnectConnector::connect(const char* name) -> bool {
	Console::info("B78XH WASM: SimConnect connecting...");
	this->connectionResult = SimConnect_Open(&simConnectHandle, name, nullptr, 0, 0, 0);
	if (this->connectionResult == S_OK) {
		Console::info("B78XH WASM: SimConnect client \"{}\" connected", name);
	}

	this->prepareEvents();
	this->prepareDataDefinitions();
	this->prepareRequests();
	return true;
}

auto SimConnectConnector::prepareEvents() -> void {
	this->mapEvent(ClientEvents::B78XH_CONTROL_IDS_TCP_1, "B78XH.CONTROL_IDS_TCP_1", FALSE);
	this->mapEvent(ClientEvents::B78XH_CONTROL_IDS_TCP_2, "B78XH.CONTROL_IDS_TCP_2", FALSE);
	this->mapEvent(ClientEvents::B78XH_CONTROL_IDS_TCP_3, "B78XH.CONTROL_IDS_TCP_3", FALSE);

	this->mapEvent(ClientEvents::B78XH_BUTTON_CLOCK_PUSH, "B78XH.BUTTON_CLOCK_PUSH", FALSE);

	this->mapEvent(ClientEvents::B78XH_CONTROL_IDS_MFD_1, "B78XH.CONTROL_IDS_MFD_1", FALSE);
	this->mapEvent(ClientEvents::B78XH_CONTROL_IDS_MFD_2, "B78XH.CONTROL_IDS_MFD_2", FALSE);
	this->mapEvent(ClientEvents::B78XH_CONTROL_IDS_MFD_3, "B78XH.CONTROL_IDS_MFD_3", FALSE);

	this->mapEvent(ClientEvents::B78XH_CONTROL_IDS_MFD_SIDE_1, "B78XH.CONTROL_IDS_MFD_SIDE_1", FALSE);
	this->mapEvent(ClientEvents::B78XH_CONTROL_IDS_MFD_SIDE_2, "B78XH.CONTROL_IDS_MFD_SIDE_2", FALSE);

	this->mapEvent(ClientEvents::B78XH_CONTROL_IDS_CDU_1, "B78XH.CONTROL_IDS_CDU_1", FALSE);
	this->mapEvent(ClientEvents::B78XH_CONTROL_IDS_CDU_2, "B78XH.CONTROL_IDS_CDU_2", FALSE);


}

auto SimConnectConnector::mapEvent(const SIMCONNECT_NOTIFICATION_GROUP_ID groupId, const ClientEvents eventId,
                                   const char* eventName = "", const BOOL maskable = FALSE) -> void {
	const auto clientEvent = static_cast<SIMCONNECT_CLIENT_EVENT_ID>(eventId);

	SimConnect_MapClientEventToSimEvent(simConnectHandle, clientEvent, eventName);
	SimConnect_AddClientEventToNotificationGroup(simConnectHandle, groupId, clientEvent, maskable);

	SimConnect_SetNotificationGroupPriority(simConnectHandle, groupId, SIMCONNECT_GROUP_PRIORITY_HIGHEST_MASKABLE);
}

auto SimConnectConnector::mapEvent(const ClientEvents eventId, const char* eventName = "",
                                   const BOOL maskable = FALSE) -> void {
	this->mapEvent(0, eventId, eventName, maskable);
}

auto SimConnectConnector::prepareDataDefinitions() -> void {
	/*
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "OPEN AIRPORT");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "LATITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "LONGITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "ALTITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "MAGVAR");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "NAME");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "TOWER_LATITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "TOWER_LONGITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "TOWER_ALTITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "N_RUNWAYS");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "N_FREQUENCIES");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "N_HELIPADS");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "N_APPROACHS");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "N_DEPARTURES");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "N_ARRIVALS");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "N_TAXI_PARKINGS");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "N_TAXI_PATHS");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "N_TAXI_NAMES");
	this->connectionResult = SimConnect_AddToFacilityDefinition(simConnectHandle, FACILITY_DATA_DEF_AIRPORT, "N_JETWAYS");
	*/

	/**
	 * VHF
	 */
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_VHF, "COM ACTIVE FREQUENCY:1",
	                                                        "MHz");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_VHF, "COM ACTIVE FREQUENCY:2",
	                                                        "MHz");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_VHF, "COM ACTIVE FREQUENCY:3",
	                                                        "MHz");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_VHF, "COM STANDBY FREQUENCY:1",
	                                                        "MHz");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_VHF, "COM STANDBY FREQUENCY:2",
	                                                        "MHz");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_VHF, "COM STANDBY FREQUENCY:3",
	                                                        "MHz");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_VHF, "COM TRANSMIT:1", "Bool");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_VHF, "COM TRANSMIT:2", "Bool");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_VHF, "COM TRANSMIT:3", "Bool");

	/**
	 * Transponder
	 */
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_TRANSPONDER_CODE,
	                                                        "TRANSPONDER CODE:1", "number");

	/**
	 * Aircraft -> Info
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_INFO, "ATC ID", "",
	                                                        SIMCONNECT_DATATYPE_STRING256);

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_INFO,
	                                                        "ATC FLIGHT NUMBER", "", SIMCONNECT_DATATYPE_STRING256);

	/**
	 * Aircraft -> State
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "GEAR IS ON GROUND", "Boolean");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "GEAR POSITION", "Percent");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "ATTITUDE INDICATOR BANK DEGREES", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "ATTITUDE INDICATOR PITCH DEGREES", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "GPS GROUND SPEED", "knots");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "INDICATED ALTITUDE", "foot");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "AIRSPEED INDICATED", "knots");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "VERTICAL SPEED", "feet per minute");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "PLANE ALT ABOVE GROUND MINUS CG", "feet");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "FLAPS HANDLE INDEX", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "PLANE LATITUDE", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "PLANE LONGITUDE", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "PLANE HEADING DEGREES TRUE", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "PLANE HEADING DEGREES MAGNETIC", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "GPS GROUND MAGNETIC TRACK", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "TOTAL WEIGHT", "Pounds");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "MAX GROSS WEIGHT", "Pounds");

	/*
	 * Autopilot - State
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_STATE,
	                                                        "AUTOPILOT MASTER", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_STATE,
	                                                        "AUTOPILOT FLIGHT LEVEL CHANGE", "bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_STATE,
	                                                        "GPS DRIVES NAV1", "bool");


	/*
	 * Autopilot - Flight Director
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_FLIGHT_DIRECTOR,
	                                                        "AUTOPILOT FLIGHT DIRECTOR ACTIVE", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_FLIGHT_DIRECTOR,
	                                                        "AUTOPILOT FLIGHT DIRECTOR ACTIVE:1", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_FLIGHT_DIRECTOR,
	                                                        "AUTOPILOT FLIGHT DIRECTOR ACTIVE:2", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_FLIGHT_DIRECTOR,
	                                                        "AUTOPILOT FLIGHT DIRECTOR BANK", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_FLIGHT_DIRECTOR,
	                                                        "AUTOPILOT FLIGHT DIRECTOR PITCH", "Degree");

	/*
	 * Autopilot - Approach
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_APPROACH,
	                                                        "AUTOPILOT APPROACH HOLD", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_APPROACH,
	                                                        "AUTOPILOT APPROACH ACTIVE", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_APPROACH,
	                                                        "AUTOPILOT APPROACH CAPTURED", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_APPROACH,
	                                                        "AUTOPILOT APPROACH ARM", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_APPROACH,
	                                                        "AUTOPILOT APPROACH IS LOCALIZER", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_APPROACH,
	                                                        "GPS APPROACH APPROACH TYPE", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_APPROACH,
	                                                        "GPS IS APPROACH LOADED", "Bool");

	/*
	 * Autopilot - GlideSlope
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_GLIDESLOPE,
	                                                        "AUTOPILOT GLIDESLOPE HOLD", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_GLIDESLOPE,
	                                                        "AUTOPILOT GLIDESLOPE ACTIVE", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_GLIDESLOPE,
	                                                        "AUTOPILOT GLIDESLOPE ARM", "Bool");

	/*
	 * Autopilot - Navigation
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_NAVIGATION,
	                                                        "AUTOPILOT BACKCOURSE HOLD", "Bool");

	/*
	 * Autopilot - Throttle
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_THROTTLE,
	                                                        "AUTOPILOT THROTTLE ARM", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_THROTTLE,
	                                                        "AUTOPILOT THROTTLE ARM:1", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_THROTTLE,
	                                                        "AUTOPILOT THROTTLE ARM:2", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_THROTTLE,
	                                                        "AUTOPILOT MANAGED THROTTLE ACTIVE", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_THROTTLE,
	                                                        "AUTOPILOT MANAGED THROTTLE ACTIVE:1", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_THROTTLE,
	                                                        "AUTOPILOT MANAGED THROTTLE ACTIVE:2", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_THROTTLE,
	                                                        "GENERAL ENG THROTTLE MANAGED MODE:1", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_THROTTLE,
	                                                        "GENERAL ENG THROTTLE MANAGED MODE:2", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_THROTTLE,
	                                                        "GENERAL ENG THROTTLE LEVER POSITION:1", "Percent");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_THROTTLE,
	                                                        "GENERAL ENG THROTTLE LEVER POSITION:2", "Percent");

	/*
	 * 				struct Throttle {
			bool areThrottlesArmed;
			bool isLeftEngineThrottleArmed;
			bool isRightEngineThrottleArmed;
			bool areThrottlesActive;
			bool isLeftEngineThrottleActive;
			bool isRightEngineThrottleActive;
			FLOAT64 leftEngineThrottleMode;
			FLOAT64 rightEngineThrottleMode;
			FLOAT64 leftEngineThrottlePosition;
			FLOAT64 rightEngineThrottlePosition;
		};
	 */
	/*
	 * Autopilot - Altitude
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_ALTITUDE,
	                                                        "AUTOPILOT ALTITUDE LOCK", "Bool");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_ALTITUDE,
	                                                        "AUTOPILOT ALTITUDE LOCK VAR", "foot",
	                                                        SIMCONNECT_DATATYPE_FLOAT64);
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_ALTITUDE,
	                                                        "AUTOPILOT ALTITUDE LOCK VAR:1", "foot",
	                                                        SIMCONNECT_DATATYPE_FLOAT64);
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_ALTITUDE,
	                                                        "AUTOPILOT ALTITUDE LOCK VAR:2", "foot",
	                                                        SIMCONNECT_DATATYPE_FLOAT64);
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_ALTITUDE,
	                                                        "AUTOPILOT ALTITUDE LOCK VAR:3", "foot",
	                                                        SIMCONNECT_DATATYPE_FLOAT64);
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_ALTITUDE,
	                                                        "AUTOPILOT ALTITUDE SLOT INDEX", "Number");

	/*
	 * Autopilot - Vertical Speed
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_VERTICAL_SPEED,
	                                                        "AUTOPILOT VERTICAL HOLD", "Bool");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_VERTICAL_SPEED,
	                                                        "AUTOPILOT VERTICAL HOLD VAR", "feet/minute");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_VERTICAL_SPEED,
	                                                        "AUTOPILOT VERTICAL HOLD VAR:1", "feet/minute");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_VERTICAL_SPEED,
	                                                        "AUTOPILOT VERTICAL HOLD VAR:2", "feet/minute");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_VERTICAL_SPEED,
	                                                        "AUTOPILOT VERTICAL HOLD VAR:3", "feet/minute");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_VERTICAL_SPEED,
	                                                        "AUTOPILOT VS SLOT INDEX", "Number");

	/*
	 * Autopilot - Airspeed
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_AIRSPEED,
	                                                        "AUTOPILOT AIRSPEED HOLD", "Bool");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_AIRSPEED,
	                                                        "AUTOPILOT AIRSPEED HOLD VAR", "Knots");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_AIRSPEED,
	                                                        "AUTOPILOT AIRSPEED HOLD VAR:1", "Knots");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_AIRSPEED,
	                                                        "AUTOPILOT AIRSPEED HOLD VAR:2", "Knots");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_AIRSPEED,
	                                                        "AUTOPILOT AIRSPEED HOLD VAR:3", "Knots");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_AIRSPEED,
	                                                        "AUTOPILOT SPEED SLOT INDEX", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_AIRSPEED,
	                                                        "AUTOPILOT MACH HOLD", "Boolean");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_AIRSPEED,
	                                                        "AUTOPILOT MACH HOLD VAR", "Number");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_AIRSPEED,
	                                                        "AUTOPILOT MACH HOLD VAR:1", "Number");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_AIRSPEED,
	                                                        "AUTOPILOT MACH HOLD VAR:2", "Number");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_AIRSPEED,
	                                                        "AUTOPILOT MACH HOLD VAR:3", "Number");

	/*
	 * Autopilot - Heading
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_HEADING,
	                                                        "AUTOPILOT HEADING LOCK", "Bool");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_HEADING,
	                                                        "AUTOPILOT HEADING LOCK DIR", "Degrees");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_HEADING,
	                                                        "AUTOPILOT HEADING LOCK DIR:1", "Degrees");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_HEADING,
	                                                        "AUTOPILOT HEADING LOCK DIR:2", "Degrees");
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_HEADING,
	                                                        "AUTOPILOT HEADING LOCK DIR:3", "Degrees");

	/*
	 * Equipment - RadioNav - Unit1
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	                                                        "NAV GSI:1", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	                                                        "NAV GLIDE SLOPE ERROR:1", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	                                                        "NAV CDI:1", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	                                                        "NAV HAS LOCALIZER:1", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	                                                        "NAV HAS NAV:1", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	                                                        "NAV HAS DME:1", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	                                                        "NAV DME:1", "Nautical miles");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	                                                        "NAV HAS GLIDE SLOPE:1", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	                                                        "NAV OBS:1", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	                                                        "NAV RADIAL:1", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	                                                        "NAV ACTIVE FREQUENCY:1", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	                                                        "NAV STANDBY FREQUENCY:1", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	                                                        "NAV LOCALIZER:1", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	                                                        "NAV NAME:1", "", SIMCONNECT_DATATYPE_STRING256);

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	                                                        "NAV IDENT:1", "", SIMCONNECT_DATATYPE_STRING256);

	/*
	 * Equipment - RadioNav - Unit2
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	                                                        "NAV GSI:2", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	                                                        "NAV GLIDE SLOPE ERROR:2", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	                                                        "NAV CDI:2", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	                                                        "NAV HAS LOCALIZER:2", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	                                                        "NAV HAS NAV:2", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	                                                        "NAV HAS DME:2", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	                                                        "NAV DME:2", "Nautical miles");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	                                                        "NAV HAS GLIDE SLOPE:2", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	                                                        "NAV OBS:2", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	                                                        "NAV RADIAL:2", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	                                                        "NAV ACTIVE FREQUENCY:2", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	                                                        "NAV STANDBY FREQUENCY:2", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	                                                        "NAV LOCALIZER:2", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	                                                        "NAV NAME:2", "", SIMCONNECT_DATATYPE_STRING256);

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	                                                        "NAV IDENT:2", "", SIMCONNECT_DATATYPE_STRING256);

	/*
	 * Equipment - RadioNav - Unit3
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	                                                        "NAV GSI:3", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	                                                        "NAV GLIDE SLOPE ERROR:3", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	                                                        "NAV CDI:3", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	                                                        "NAV HAS LOCALIZER:3", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	                                                        "NAV HAS NAV:3", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	                                                        "NAV HAS DME:3", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	                                                        "NAV DME:3", "Nautical miles");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	                                                        "NAV HAS GLIDE SLOPE:3", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	                                                        "NAV OBS:3", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	                                                        "NAV RADIAL:3", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	                                                        "NAV ACTIVE FREQUENCY:3", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	                                                        "NAV STANDBY FREQUENCY:3", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	                                                        "NAV LOCALIZER:3", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	                                                        "NAV NAME:3", "", SIMCONNECT_DATATYPE_STRING256);

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	                                                        "NAV IDENT:3", "", SIMCONNECT_DATATYPE_STRING256);

	/*
	 * Equipment - RadioNav - Unit3
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	                                                        "NAV GSI:4", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	                                                        "NAV GLIDE SLOPE ERROR:4", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	                                                        "NAV CDI:4", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	                                                        "NAV HAS LOCALIZER:4", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	                                                        "NAV HAS NAV:4", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	                                                        "NAV HAS DME:4", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	                                                        "NAV DME:4", "Nautical miles");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	                                                        "NAV HAS GLIDE SLOPE:4", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	                                                        "NAV OBS:4", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	                                                        "NAV RADIAL:4", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	                                                        "NAV ACTIVE FREQUENCY:4", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	                                                        "NAV STANDBY FREQUENCY:4", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	                                                        "NAV LOCALIZER:4", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	                                                        "NAV NAME:4", "", SIMCONNECT_DATATYPE_STRING256);

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	                                                        "NAV IDENT:4", "", SIMCONNECT_DATATYPE_STRING256);

	/*
	 * Barometer - Setting
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_BAROMETER_SETTING,
	                                                        "KOHLSMAN SETTING HG", "inHg");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_BAROMETER_SETTING,
	                                                        "KOHLSMAN SETTING MB", "Millibars");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_BAROMETER_SETTING,
	                                                        "DECISION HEIGHT", "Feet");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_BAROMETER_SETTING,
	                                                        "DECISION ALTITUDE MSL", "Feet");

	/*
	 * Misc
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_MISC_TIME, "ABSOLUTE TIME",
	                                                        "Seconds", SIMCONNECT_DATATYPE_FLOAT64, 1);

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_MISC_TIME, "ZULU TIME",
	                                                        "Seconds", SIMCONNECT_DATATYPE_FLOAT64, 1);

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_MISC_TIME,
	                                                        "LOCAL MONTH OF YEAR", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_MISC_TIME,
	                                                        "LOCAL DAY OF MONTH", "Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_MISC_TIME, "LOCAL YEAR",
	                                                        "Number");


	/*
	 * Environment
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_TEMPERATURE, "TOTAL AIR TEMPERATURE",
															"Celsius");

	/*
	 *  Systems - Powerplant
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "TURB ENG N1:1",
		"Percent");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "TURB ENG N2:1",
		"Percent");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "TURB ENG N1:2",
		"Percent");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "TURB ENG N2:2",
		"Percent");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "TURB ENG THROTTLE COMMANDED N1:1",
		"Percent");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "TURB ENG THROTTLE COMMANDED N1:2",
		"Percent");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "ENG EXHAUST GAS TEMPERATURE:1",
		"Celsius");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "ENG EXHAUST GAS TEMPERATURE:2",
		"Celsius");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "ENG FUEL FLOW PPH:1",
		"Pounds per hour");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "ENG FUEL FLOW PPH:2",
		"Pounds per hour");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "GENERAL ENG COMBUSTION:1",
		"Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "GENERAL ENG COMBUSTION:2",
		"Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "ENG OIL PRESSURE:1",
		"Psi");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "ENG OIL PRESSURE:2",
		"Psi");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "ENG OIL TEMPERATURE:1",
		"Celsius");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "ENG OIL TEMPERATURE:2",
		"Celsius");

	// TODO: These values don't seem right
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "ENG OIL QUANTITY:1",
		"Percent scaler 16k");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "ENG OIL QUANTITY:2",
		"Percent scaler 16k");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "TURB ENG VIBRATION:2",
		"Number");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ENGINE, "TURB ENG VIBRATION:2",
		"Number");

	/*
	 *  Systems - Fuel
	 */

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_FUEL, "FUELSYSTEM VALVE SWITCH:1",
		"Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_FUEL, "FUELSYSTEM VALVE SWITCH:2",
		"Bool");


	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_ALTITUDE, "INDICATED ALTITUDE:1",
		"Feet");

	
}

auto SimConnectConnector::prepareClientDataDefinitions() -> void {
}

auto SimConnectConnector::prepareRequests() -> void {
	//connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_VHF, "DROPPABLE OBJECTS TYPE:1", "", SIMCONNECT_DATATYPE_STRING256);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_VHF, DEFINITION_VHF,
	                                                           SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_VISUAL_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_TRANSPONDER_CODE,
	                                                           DEFINITION_TRANSPONDER_CODE, SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_VISUAL_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_AIRCRAFT_INFO,
	                                                           DEFINITION_AIRCRAFT_INFO, SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_VISUAL_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_AIRCRAFT_STATE,
	                                                           DEFINITION_AIRCRAFT_STATE, SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_SIM_FRAME);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_AUTOPILOT_STATE,
	                                                           DEFINITION_AUTOPILOT_STATE, SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_VISUAL_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_AUTOPILOT_FLIGHT_DIRECTOR,
	                                                           DEFINITION_AUTOPILOT_FLIGHT_DIRECTOR,
	                                                           SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_SIM_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_AUTOPILOT_ALTITUDE,
	                                                           DEFINITION_AUTOPILOT_ALTITUDE, SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_VISUAL_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_AUTOPILOT_VERTICAL_SPEED,
	                                                           DEFINITION_AUTOPILOT_VERTICAL_SPEED,
	                                                           SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_VISUAL_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_AUTOPILOT_AIRSPEED,
	                                                           DEFINITION_AUTOPILOT_AIRSPEED, SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_VISUAL_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_AUTOPILOT_HEADING,
	                                                           DEFINITION_AUTOPILOT_HEADING, SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_VISUAL_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_BAROMETER_SETTING,
	                                                           DEFINITION_BAROMETER_SETTING, SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_SIM_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_MISC_TIME,
	                                                           DEFINITION_MISC_TIME, SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_SIM_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_AUTOPILOT_APPROACH,
	                                                           DEFINITION_AUTOPILOT_APPROACH, SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_VISUAL_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_AUTOPILOT_GLIDESLOPE,
	                                                           DEFINITION_AUTOPILOT_GLIDESLOPE,
	                                                           SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_SIM_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_AUTOPILOT_NAVIGATION,
	                                                           DEFINITION_AUTOPILOT_NAVIGATION,
	                                                           SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_SIM_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_EQUIPMENT_RADIONAV_UNIT1,
	                                                           DEFINITION_EQUIPMENT_RADIONAV_UNIT1,
	                                                           SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_SIM_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_EQUIPMENT_RADIONAV_UNIT2,
	                                                           DEFINITION_EQUIPMENT_RADIONAV_UNIT2,
	                                                           SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_SIM_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_EQUIPMENT_RADIONAV_UNIT3,
	                                                           DEFINITION_EQUIPMENT_RADIONAV_UNIT3,
	                                                           SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_SIM_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_EQUIPMENT_RADIONAV_UNIT4,
	                                                           DEFINITION_EQUIPMENT_RADIONAV_UNIT4,
	                                                           SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_SIM_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_AUTOPILOT_THROTTLE,
	                                                           DEFINITION_AUTOPILOT_THROTTLE, SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_SIM_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_TEMPERATURE,
	                                                           DEFINITION_TEMPERATURE, SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_SIM_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_ENGINE,
	                                                           DEFINITION_ENGINE, SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_SIM_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	
	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_FUEL,
	                                                           DEFINITION_FUEL, SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_SIM_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_ALTITUDE,
	                                                           DEFINITION_ALTITUDE, SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_SIM_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);
}



auto SimConnectConnector::requestDispatchMessages() -> void {
	DWORD cbData;
	SIMCONNECT_RECV* pData;
	while (SUCCEEDED(SimConnect_GetNextDispatch(simConnectHandle, &pData, &cbData))) {
		this->processDispatchMessage(pData, &cbData);
	}
}

auto SimConnectConnector::processDispatchMessage(SIMCONNECT_RECV* pData, DWORD* cbData) -> void {
	switch (pData->dwID) {
		case SIMCONNECT_RECV_ID_SIMOBJECT_DATA: {
			// process data
			auto pObjData = static_cast<SIMCONNECT_RECV_SIMOBJECT_DATA*>(pData);
			switch (pObjData->dwRequestID) {
				case REQUEST_VHF: {
					SimConnectData::comFrequencies = (*reinterpret_cast<SimConnectData::ComFrequencies*>(&pObjData->
						dwData));
					GaugesInvalidateFlags.PEDESTALTuningControlGauge[0] = true;
					GaugesInvalidateFlags.PEDESTALTuningControlGauge[1] = true;
					GaugesInvalidateFlags.PEDESTALTuningControlGauge[2] = true;
					break;
				}
				case REQUEST_TRANSPONDER_CODE: {
					SimConnectData::transponder = (*reinterpret_cast<SimConnectData::Transponder*>(&pObjData->dwData));
					GaugesInvalidateFlags.PEDESTALTuningControlGauge[0] = true;
					GaugesInvalidateFlags.PEDESTALTuningControlGauge[1] = true;
					GaugesInvalidateFlags.PEDESTALTuningControlGauge[2] = true;
					break;
				}
				case REQUEST_AIRCRAFT_INFO: {
					SimConnectData::Aircraft::info = (*reinterpret_cast<SimConnectData::Aircraft::Info*>(&pObjData->
						dwData));
					break;
				}
				case REQUEST_AIRCRAFT_STATE: {
					SimConnectData::Aircraft::state = (*reinterpret_cast<SimConnectData::Aircraft::State*>(&pObjData->
						dwData));
					GaugesInvalidateFlags.MCPHeadingGaugeTrack = true;
					break;
				}
				case REQUEST_AUTOPILOT_STATE: {
					SimConnectData::Autopilot::state = (*reinterpret_cast<SimConnectData::Autopilot::State*>(&pObjData->
						dwData));
					break;
				}

				case REQUEST_AUTOPILOT_FLIGHT_DIRECTOR: {
					SimConnectData::Autopilot::flightDirector = (*reinterpret_cast<
						SimConnectData::Autopilot::FlightDirector*>(&pObjData->dwData));
					break;
				}
				case REQUEST_AUTOPILOT_APPROACH: {
					SimConnectData::Autopilot::approach = (*reinterpret_cast<SimConnectData::Autopilot::Approach*>(&
						pObjData->dwData));
					break;
				}
				case REQUEST_AUTOPILOT_GLIDESLOPE: {
					SimConnectData::Autopilot::glideSlope = (*reinterpret_cast<SimConnectData::Autopilot::GlideSlope*>(&
						pObjData->dwData));
					break;
				}
				case REQUEST_AUTOPILOT_NAVIGATION: {
					SimConnectData::Autopilot::navigation = (*reinterpret_cast<SimConnectData::Autopilot::Navigation*>(&
						pObjData->dwData));
					break;
				}
				case REQUEST_AUTOPILOT_THROTTLE: {
					SimConnectData::Autopilot::throttle = (*reinterpret_cast<SimConnectData::Autopilot::Throttle*>(&
						pObjData->dwData));
					break;
				}
				case REQUEST_AUTOPILOT_ALTITUDE: {
					SimConnectData::Autopilot::altitude = (*reinterpret_cast<SimConnectData::Autopilot::Altitude*>(&
						pObjData->dwData));
					GaugesInvalidateFlags.MCPAltitudeGauge = true;
					break;
				}

				case REQUEST_AUTOPILOT_VERTICAL_SPEED: {
					SimConnectData::Autopilot::verticalSpeed = (*reinterpret_cast<
						SimConnectData::Autopilot::VerticalSpeed*>(&pObjData->dwData));
					GaugesInvalidateFlags.MCPVSpeedGauge = true;
					break;
				}

				case REQUEST_AUTOPILOT_AIRSPEED: {
					SimConnectData::Autopilot::airspeed = (*reinterpret_cast<SimConnectData::Autopilot::Airspeed*>(&
						pObjData->dwData));
					break;
				}

				case REQUEST_AUTOPILOT_HEADING: {
					SimConnectData::Autopilot::heading = (*reinterpret_cast<SimConnectData::Autopilot::Heading*>(&
						pObjData->dwData));
					GaugesInvalidateFlags.MCPHeadingGaugeHeading = true;
					break;
				}

				case REQUEST_EQUIPMENT_RADIONAV_UNIT1: {
					SimConnectData::Equipment::RadioNav::unit1 = (*reinterpret_cast<
						SimConnectData::Equipment::RadioNav::Unit1*>(&
						pObjData->dwData));
					break;
				}

				case REQUEST_EQUIPMENT_RADIONAV_UNIT2: {
					SimConnectData::Equipment::RadioNav::unit2 = (*reinterpret_cast<
						SimConnectData::Equipment::RadioNav::Unit2*>(&
						pObjData->dwData));
					break;
				}

				case REQUEST_EQUIPMENT_RADIONAV_UNIT3: {
					SimConnectData::Equipment::RadioNav::unit3 = (*reinterpret_cast<
						SimConnectData::Equipment::RadioNav::Unit3*>(&
						pObjData->dwData));
					break;
				}

				case REQUEST_EQUIPMENT_RADIONAV_UNIT4: {
					SimConnectData::Equipment::RadioNav::unit4 = (*reinterpret_cast<
						SimConnectData::Equipment::RadioNav::Unit4*>(&
						pObjData->dwData));
					break;
				}

				case REQUEST_BAROMETER_SETTING: {
					SimConnectData::Barometer::setting = (*reinterpret_cast<SimConnectData::Barometer::Setting*>(&
						pObjData->dwData));
					break;
				}

				case REQUEST_MISC_TIME: {
					SimConnectData::Misc::time = (*reinterpret_cast<SimConnectData::Misc::Time*>(&pObjData->dwData));
					break;
				}

				case REQUEST_TEMPERATURE: {
					SimConnectData::environment::temperature = (*reinterpret_cast<SimConnectData::environment::Temperature*>(&pObjData->dwData));
					break;
				}

				case REQUEST_ENGINE: {
					SimConnectData::systems::powerplant::engine = (*reinterpret_cast<SimConnectData::systems::powerplant::Engine*>(&pObjData->dwData));
					break;
				}

				case REQUEST_FUEL: {
					SimConnectData::systems::fuel::switches = (*reinterpret_cast<SimConnectData::systems::fuel::Switches*>(&pObjData->dwData));
					break;
				}

				case REQUEST_ALTITUDE: {
					SimConnectData::Aircraft::position::altitude = (*reinterpret_cast<SimConnectData::Aircraft::position::Altitude*>(&pObjData->dwData));
					break;
				}

				default:
					break;
			}
			break;
		}
		/*
		case SIMCONNECT_RECV_ID_FACILITY_DATA: {
			fmt::print(stderr, "FACILITY EVENT");
			const auto data = static_cast<SIMCONNECT_RECV_FACILITY_DATA*>(pData);
			switch (data->dwType) {
				case SIMCONNECT_FACILITY_DATA_AIRPORT: {
					auto airport = (TestAirport*)&data->Data;
					fmt::print(stderr, "AIRPORT NAME: {}", airport->name);
					fmt::print(stderr, "AIRPORT LATITUDE: {}", airport->latitude);
					fmt::print(stderr, "AIRPORT LONGITUDE: {}", airport->longitude);
					delete airport;
				}
				default: ;
			}
		}
		break;
		*/
		case SIMCONNECT_RECV_ID_FACILITY_DATA_END: {
			break;
		}
		case SIMCONNECT_RECV_ID_OPEN:
			Console::info("B78XH WASM: SimConnect connection established");
			break;
		case SIMCONNECT_RECV_ID_QUIT:
			Console::info("B78XH WASM: Received SimConnect connection quit message");
			disconnect();
			break;
		case SIMCONNECT_RECV_ID_EXCEPTION: {
			auto except = static_cast<SIMCONNECT_RECV_EXCEPTION*>(pData);
			Console::error("(SimConnectConnector::processDispatchMessage) EXCEPTION SIMCONNECT ID {}",
			               except->dwException);
		}
		break;
		case SIMCONNECT_RECV_ID_EVENT: {
			this->handleCustomEvents(static_cast<SIMCONNECT_RECV_EVENT_EX1*>(pData));
		}
		case SIMCONNECT_RECV_ID_CLIENT_DATA:
		default:
			break;
	}
}

auto SimConnectConnector::handleCustomEvents(SIMCONNECT_RECV_EVENT_EX1* data) -> void {
	const auto eventId = static_cast<ClientEvents>(data->uEventID);
	const auto data0 = data->dwData0;
	switch (eventId) {
		case ClientEvents::B78XH_CONTROL_IDS_TCP_1: {
			EventDispatchers::tcpEventDispatcher[0].push(static_cast<TCPEventDispatcher::EVENT_LIST>(data0));
			break;
		};

		case ClientEvents::B78XH_CONTROL_IDS_TCP_2: {
			EventDispatchers::tcpEventDispatcher[1].push(static_cast<TCPEventDispatcher::EVENT_LIST>(data0));
			break;
		};

		case ClientEvents::B78XH_CONTROL_IDS_TCP_3: {
			EventDispatchers::tcpEventDispatcher[2].push(static_cast<TCPEventDispatcher::EVENT_LIST>(data0));
			break;
		};

		case ClientEvents::B78XH_BUTTON_CLOCK_PUSH: break;
		case ClientEvents::B78XH_BUTTON_MTRS_PUSH: break;
		case ClientEvents::B78XH_BUTTON_FPV_PUSH: break;
		case ClientEvents::B78XH_CONTROL_IDS_MFD_1: {
			Console::error("SIM: {}", static_cast<int>(static_cast<MFDPanelResolver::PANEL_EVENT_ID>(data0)));
			MFD::resolver.processSwitchEvent(MFDPanelResolver::MFD::ONE, static_cast<MFDPanelResolver::PANEL_EVENT_ID>(data0));
			break;
		}
		case ClientEvents::B78XH_CONTROL_IDS_MFD_2: {
			MFD::resolver.processSwitchEvent(MFDPanelResolver::MFD::TWO, static_cast<MFDPanelResolver::PANEL_EVENT_ID>(data0));
			Console::error("MFD EVENT");
			break;
		}
		case ClientEvents::B78XH_CONTROL_IDS_MFD_3: {
			MFD::resolver.processSwitchEvent(MFDPanelResolver::MFD::THREE, static_cast<MFDPanelResolver::PANEL_EVENT_ID>(data0));
			Console::error("MFD EVENT");
			break;
		}
		case ClientEvents::B78XH_CONTROL_IDS_MFD_SIDE_1: break;
		case ClientEvents::B78XH_CONTROL_IDS_MFD_SIDE_2: break;
		case ClientEvents::B78XH_CONTROL_IDS_CDU_1: {
			MFD::resolver.processScratchpadEvent(0, static_cast<CDUScratchpadControl::events>(data0));
			Console::error("CDU EVENT");
			break;
		}
		case ClientEvents::B78XH_CONTROL_IDS_CDU_2: {
			MFD::resolver.processScratchpadEvent(1, static_cast<CDUScratchpadControl::events>(data0));
			Console::error("CDU EVENT");
			break;
		}
		default: {
			Console::error("(SimConnectConnector::handleCustomEvents) Unknown client event");
			break;
		}
	}
}

auto SimConnectConnector::setDataOnSimObject(DATA_DEFINE_ID DefineID,
                                             SIMCONNECT_OBJECT_ID ObjectID,
                                             SIMCONNECT_DATA_SET_FLAG Flags,
                                             DWORD ArrayCount,
                                             DWORD cbUnitSize,
                                             void* pDataSet
		) -> HRESULT {
	return SimConnect_SetDataOnSimObject(simConnectHandle, DefineID, ObjectID, Flags, ArrayCount, cbUnitSize, pDataSet);
}

auto SimConnectConnector::disconnect() -> void {
	Console::info("B78XH WASM: SimConnect disconnecting...");
	SimConnect_Close(simConnectHandle);
	Console::info("B78XH WASM: SimConnect disconnected...");
}

auto SimConnectConnector::getHandle() -> HANDLE {
	return this->simConnectHandle;
}
