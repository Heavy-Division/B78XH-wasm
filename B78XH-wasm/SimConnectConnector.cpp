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


#include "fmt/core.h"
#include "SimConnectConnector.h"
#include "GaugesInvalidateFlags.h"

bool SimConnectConnector::connect(const char* name) {
	fmt::print("B78XH WASM: SimConnect connecting...");
	fflush(stdout);
	this->connectionResult = SimConnect_Open(&simConnectHandle, name, nullptr, 0, 0, 0);
	if(this->connectionResult == S_OK) {
		fmt::print("B78XH WASM : SimConnect client \"{}\" connected", name);
		fflush(stdout);
	}

	this->prepareDataDefinitions();
	this->prepareRequests();
	return true;
}

void SimConnectConnector::prepareDataDefinitions() {
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
	                                                        "ATTITUDE INDICATOR BANK DEGREES", "Degree");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AIRCRAFT_STATE,
	                                                        "ATTITUDE INDICATOR PITCH DEGREES", "Degree");

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
	
	/*
	 * Autopilot - State
	 */
	
	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_STATE,
	                                                        "AUTOPILOT MASTER", "Bool");

	this->connectionResult = SimConnect_AddToDataDefinition(simConnectHandle, DEFINITION_AUTOPILOT_STATE,
	                                                        "AUTOPILOT FLIGHT LEVEL CHANGE", "bool");
															

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
}

void SimConnectConnector::prepareClientDataDefinitions() {

}

void SimConnectConnector::prepareRequests() {
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

	this->connectionResult = SimConnect_RequestDataOnSimObject(simConnectHandle, REQUEST_AUTOPILOT_THROTTLE,
	                                                           DEFINITION_AUTOPILOT_THROTTLE, SIMCONNECT_OBJECT_ID_USER,
	                                                           SIMCONNECT_PERIOD_SIM_FRAME,
	                                                           SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);
}


void SimConnectConnector::requestDispatchMessages() {
	DWORD cbData;
	SIMCONNECT_RECV* pData;
	while(SUCCEEDED(SimConnect_GetNextDispatch(simConnectHandle, &pData, &cbData))) {
		this->processDispatchMessage(pData, &cbData);
	}
}

void SimConnectConnector::processDispatchMessage(SIMCONNECT_RECV* pData, DWORD* cbData) {
	switch(pData->dwID) {
		case SIMCONNECT_RECV_ID_OPEN:
			fmt::print("B78XH WASM: SimConnect connection established");
			fflush(stdout);
			break;

		case SIMCONNECT_RECV_ID_QUIT:
			fmt::print("B78XH WASM: Received SimConnect connection quit message");
			fflush(stdout);
			disconnect();
			break;

		case SIMCONNECT_RECV_ID_SIMOBJECT_DATA: {
			// process data
			SIMCONNECT_RECV_SIMOBJECT_DATA* pObjData = static_cast<SIMCONNECT_RECV_SIMOBJECT_DATA*>(pData);
			switch(pObjData->dwRequestID) {
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
					break;
				}

				case REQUEST_MISC_TIME: {
					SimConnectData::Misc::time = (*reinterpret_cast<SimConnectData::Misc::Time*>(&pObjData->dwData));
					break;
				}
				default:
					break;
			}
		}
		break;
		case SIMCONNECT_RECV_ID_EXCEPTION: {
			SIMCONNECT_RECV_EXCEPTION* except = (SIMCONNECT_RECV_EXCEPTION*)pData;
			fmt::print(stderr, "EXCEPTION SIMCONNECT ID {}", except->dwException);
		}
			break;
		case SIMCONNECT_RECV_ID_EVENT:
		case SIMCONNECT_RECV_ID_CLIENT_DATA: default:
			break;
	}
}

HRESULT SimConnectConnector::setDataOnSimObject(DATA_DEFINE_ID DefineID,
                                                SIMCONNECT_OBJECT_ID ObjectID,
                                                SIMCONNECT_DATA_SET_FLAG Flags,
                                                DWORD ArrayCount,
                                                DWORD cbUnitSize,
                                                void* pDataSet) {

	return SimConnect_SetDataOnSimObject(simConnectHandle, DefineID, ObjectID, Flags, ArrayCount, cbUnitSize, pDataSet);
}

void SimConnectConnector::disconnect() {
	fmt::print("B78XH WASM: SimConnect disconnecting...");
	fflush(stdout);
	SimConnect_Close(simConnectHandle);
	fmt::print("B78XH WASM: SimConnect disconnected...");
	fflush(stdout);
}
