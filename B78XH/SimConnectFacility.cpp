#include "SimConnectFacility.h"
#include <SimConnect.h>
#include "Tools/Console.h"
#include <unordered_map>;
#include <string>
#include <list>

#include "FacilityDataStructs.h"
#include "NavDataCache.h"
#include "RouteReference.h"

using std::string;

//std::unordered_map<string, string> waypointsRequests{};

//std::unordered_map<string, std::list<string>> routes;

enum FACILITY_DATA_DEFINE_ID {
	AIRPORT,
	WAYPOINT,
	WAYPOINT_MINIMAL
};

enum FACILITY_DATA_REQUEST_ID {
	START = 1000,
	WAYPOINT_REQUEST = 2000,
	ROUTE_PRE_LOAD = 10000
};


auto SimConnectFacility::connect(const char* name) -> bool {
	Console::info("B78XH WASM: SimConnect connecting...");
	this->connectionResult = SimConnect_Open(&simConnectHandle, name, nullptr, 0, 0, 0);
	if (this->connectionResult == S_OK) {
		Console::info("B78XH WASM: SimConnect client \"{}\" connected", name);
	}
	prepareDataDefinitions();

	preload->connect("PRELOAD");

	return true;
}

auto SimConnectFacility::disconnect() -> void {
	Console::info("B78XH WASM: SimConnect disconnecting...");
	SimConnect_Close(getHandle());
	Console::info("B78XH WASM: SimConnect disconnected...");
	preload->disconnect();
}

auto SimConnectFacility::getHandle() -> unsigned long long {
	return this->simConnectHandle;
}

auto SimConnectFacility::processDispatchMessage(SIMCONNECT_RECV* pData, DWORD* cbData) -> void {
	switch (pData->dwID) {
		case SIMCONNECT_RECV_ID_FACILITY_DATA: {
			auto pFacilityData = reinterpret_cast<SIMCONNECT_RECV_FACILITY_DATA*>(pData);

			switch (pFacilityData->Type) {
				case SIMCONNECT_FACILITY_DATA_AIRPORT: {
					auto airport = reinterpret_cast<AirportStruct*>(&pFacilityData->Data);
					//const std::string a = airport->name;
					//const Airport b = Airport(airport->name, airport->latitude, airport->longitude, airport->altitude);
					Console::error("{}", airport->name);
					Console::error("Number Of Runways {}", airport->numberOfRunways);
					NavDataCache::airports.emplace(airport->name, Airport(airport->name, airport->latitude, airport->longitude, airport->altitude));
					break;
				}

				case SIMCONNECT_FACILITY_DATA_RUNWAY: {
					auto runway = reinterpret_cast<RunwayStruct*>(&pFacilityData->Data);
					Console::error("RUNWAY PRIMARY NUMBER: {}", runway->primaryNumber);
					Console::error("RUNWAY SECONDARY NUMBER: {}", runway->secondaryNumber);
					break;
				}

				case SIMCONNECT_FACILITY_DATA_WAYPOINT: {
					Console::error("REQUESTING WAYPOINT");
					if (pFacilityData->UserRequestId == WAYPOINT_REQUEST) {
						auto waypoint = reinterpret_cast<WaypointStruct*>(&pFacilityData->Data);
						Console::error("WAYPOINT ICAO: {}", waypoint->icao);
						Console::error("NUMBER OF ROUTES: {}", waypoint->numberOFRoutes);
						auto finalWaypoint = Waypoint(waypoint->icao, waypoint->region, waypoint->latitude, waypoint->longitude, waypoint->altitude);
						NavDataCache::waypoints.emplace(waypoint->icao, finalWaypoint);
					}
					
					break;
				}

				case SIMCONNECT_FACILITY_DATA_ROUTE: {
					Console::error("USER REQUEST: {}", pFacilityData->UserRequestId);
					Console::error("PARENT: {}", pFacilityData->ParentUniqueRequestId);
					auto route = reinterpret_cast<RouteStruct*>(&pFacilityData->Data);
					//Console::error("ROUTE NAME: {}", route->name);
					//Console::error("PREV ICAO: {}", route->previousIcao);
					//Console::error("PREV REGION: {}", route->previousRegion);
					//Console::error("NEXT ICAO: {}", route->nextIcao);
					//Console::error("NEXT REGION: {}", route->nextRegion);


					/*
					 * If the route is not already loaded -> add the route to preload queue
					 */
					if (pFacilityData->UserRequestId == WAYPOINT_REQUEST && NavDataCache::routes.find(route->name) == NavDataCache::routes.end()) {
						if(static_cast<string>(route->previousIcao) != "") {
							NavDataCache::routesPreloadQueue.emplace(std::pair<string, RouteReference>(route->name, RouteReference(route->previousIcao, route->previousRegion, route->previousType, route->name, false)));
						} else {
							NavDataCache::routesPreloadQueue.emplace(std::pair<string, RouteReference>(route->name, RouteReference(route->nextIcao, route->nextRegion, route->nextType, route->name, false)));
						}
					}
					break;
				}
			}
		}
		break;
		case SIMCONNECT_RECV_ID_FACILITY_DATA_END: {
			Console::info("B78XH WASM: Facility data end...");

			auto pFacilityData = reinterpret_cast<SIMCONNECT_RECV_FACILITY_DATA_END*>(pData);
		}
		break;

		case SIMCONNECT_RECV_ID_FACILITY_MINIMAL_LIST: {
			Console::error("NON UNIQUE");
			auto msg = reinterpret_cast<SIMCONNECT_RECV_FACILITY_MINIMAL_LIST*>(pData);
			for (unsigned i = 0; i < msg->dwArraySize; ++i)
			{
				SIMCONNECT_FACILITY_MINIMAL& fm = msg->rgData[i];

				fprintf(stdout, "ICAO => Type: %c, Ident: %s, Region: %s, Airport: %s => Lat: %lf, Lat: %lf, Alt: %lf\n", fm.icao.Type, fm.icao.Ident, fm.icao.Region, fm.icao.Airport, fm.lla.Latitude, fm.lla.Longitude, fm.lla.Altitude);
			}
			break;
		}

		case SIMCONNECT_RECV_ID_EXCEPTION: {
			SIMCONNECT_RECV_EXCEPTION* pException = (SIMCONNECT_RECV_EXCEPTION*)pData;
			Console::error("SIMCONNECT EXCEPTION: {}", pException->dwException);
			break;
		}
	}
}

auto SimConnectFacility::requestDispatchMessages() -> void {
	DWORD cbData;
	SIMCONNECT_RECV* pData;
	while (SUCCEEDED(SimConnect_GetNextDispatch(simConnectHandle, &pData, &cbData))) {
		processDispatchMessage(pData, &cbData);
	}
	/*
	Console::cerror("Size of routes states: {}", NavDataCache::routesPreloadQueue.size());
	for (std::pair<const string, RouteReference> routes_preload_state : NavDataCache::routesPreloadQueue) {
		Console::cerror("NAME: {}; REFERENCE: {}; PRELOADED: {}", routes_preload_state.first, routes_preload_state.second.getReferenceWaypoint(), routes_preload_state.second.isPreloaded());
	}
	*/

	preload->requestDispatchMessages();
}

auto SimConnectFacility::prepareDataDefinitions() -> void {
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "OPEN AIRPORT");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "LATITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "LONGITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "ALTITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "NAME");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "N_RUNWAYS");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "OPEN RUNWAY");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "LATITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "LONGITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "ALTITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "HEADING");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "LENGTH");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "WIDTH");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "PRIMARY_NUMBER");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "SECONDARY_NUMBER");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "CLOSE RUNWAY");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), AIRPORT, "CLOSE AIRPORT");


	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT, "OPEN WAYPOINT");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT, "LATITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT, "LONGITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT, "ALTITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT, "N_ROUTES");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT, "ICAO");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT, "REGION");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT, "OPEN ROUTE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT, "NAME");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT, "NEXT_ICAO");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT, "PREV_ICAO");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT, "NEXT_REGION");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT, "PREV_REGION");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT, "CLOSE ROUTE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT, "CLOSE WAYPOINT");

	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT_MINIMAL, "OPEN WAYPOINT");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT_MINIMAL, "ICAO");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT_MINIMAL, "REGION");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT_MINIMAL, "OPEN ROUTE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT_MINIMAL, "NAME");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT_MINIMAL, "NEXT_ICAO");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT_MINIMAL, "PREV_ICAO");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT_MINIMAL, "NEXT_REGION");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT_MINIMAL, "PREV_REGION");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT_MINIMAL, "CLOSE ROUTE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), WAYPOINT_MINIMAL, "CLOSE WAYPOINT");
}

auto SimConnectFacility::getAirport(char* icao) -> void {
	this->connectionResult = SimConnect_RequestFacilityData_EX1(getHandle(), AIRPORT, START, icao);
}

auto SimConnectFacility::getWaypoint(char* icao) -> void {
	this->connectionResult = SimConnect_RequestFacilityData_EX1(getHandle(), WAYPOINT, WAYPOINT_REQUEST, icao);
}