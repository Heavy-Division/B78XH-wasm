#include "SimConnectFacility.h"
#include <SimConnect.h>
#include "Tools/Console.h"
#include <unordered_map>;
#include <string>

using std::string;

struct AirportStruct {
	double latitude;
	double longitude;
	double altitude;
	char name[32];
	int numberOfRunways;
};

struct RunwayStruct {
	double latitude;
	double longitude;
	double altitude;
	float heading;
	float length;
	float width;
	int primaryNumber;
	int secondaryNumber;
};

struct WaypointStruct {
	double latitude;
	double longitude;
	double altitude;
	int numberOFRoutes;
	char icao[8];
	char region[8];
};

struct RouteStruct {
	char name[32];
	char nextIcao[8];
	char previousIcao[8];
	char nextRegion[8];
	char previousRegion[8];
};

class Airport {
	public:
		Airport(std::string name, const double latitude, const double longitude, const double altitude)
			: name(name),
			  latitude(latitude),
			  longitude(longitude),
			  altitude(altitude) {
		}

	private:
		std::string name;
		double latitude;
		double longitude;
		double altitude;
};

class Waypoint {
	public:
		Waypoint(std::string name);
};


std::unordered_map<string, Airport> airportsCache{};
std::unordered_map<string, string> waypointsCache{};
std::unordered_map<string, string> waypointsRequests{};

enum FACILITY_DATA_DEFINE_ID {
	AIRPORT,
	WAYPOINT
};

enum FACILITY_DATA_REQUEST_ID {
	START = 1000
};


auto SimConnectFacility::connect(const char* name) -> bool {
	Console::info("B78XH WASM: SimConnect connecting...");
	this->connectionResult = SimConnect_Open(&simConnectHandle, name, nullptr, 0, 0, 0);
	if (this->connectionResult == S_OK) {
		Console::info("B78XH WASM: SimConnect client \"{}\" connected", name);
	}

	prepareDataDefinitions();
	return true;
}

auto SimConnectFacility::disconnect() -> void {
	Console::info("B78XH WASM: SimConnect disconnecting...");
	SimConnect_Close(getHandle());
	Console::info("B78XH WASM: SimConnect disconnected...");
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
					airportsCache.emplace(airport->name, Airport(airport->name, airport->latitude, airport->longitude, airport->altitude));
					break;
				}

				case SIMCONNECT_FACILITY_DATA_RUNWAY: {
					auto runway = reinterpret_cast<RunwayStruct*>(&pFacilityData->Data);
					Console::error("RUNWAY PRIMARY NUMBER: {}", runway->primaryNumber);
					Console::error("RUNWAY SECONDARY NUMBER: {}", runway->secondaryNumber);
					break;
				}

				case SIMCONNECT_FACILITY_DATA_WAYPOINT: {
					auto waypoint = reinterpret_cast<WaypointStruct*>(&pFacilityData->Data);
					Console::error("WAYPOINT ICAO: {}", waypoint->icao);
					Console::error("NUMBER OF ROUTES: {}", waypoint->numberOFRoutes);

					waypointsCache.emplace(waypoint->icao, waypoint->icao);
					
					break;
				}

				case SIMCONNECT_FACILITY_DATA_ROUTE: {
					auto route = reinterpret_cast<RouteStruct*>(&pFacilityData->Data);
					Console::error("ROUTE NAME: {}", route->name);
					Console::error("PREV ICAO: {}", route->previousIcao);
					Console::error("PREV REGION: {}", route->previousRegion);
					Console::error("NEXT ICAO: {}", route->nextIcao);
					Console::error("NEXT REGION: {}", route->nextRegion);

					if(route->previousIcao != "") {
						waypointsRequests.emplace(route->previousIcao, route->previousRegion);
					}

					if (route->nextIcao != "") {
						waypointsRequests.emplace(route->nextIcao, route->nextRegion);
					}
					break;
				}
			}
		}
		break;
		case SIMCONNECT_RECV_ID_FACILITY_DATA_END: {
			auto pFacilityData = reinterpret_cast<SIMCONNECT_RECV_FACILITY_DATA_END*>(pData);
			for(auto waypoint : waypointsRequests) {
				/* TODO: move */
				auto icao = waypoint.first.c_str();
				auto region = waypoint.second.c_str();
				waypointsRequests.erase(waypoint.first);
				this->connectionResult = SimConnect_RequestFacilityData_EX1(getHandle(), WAYPOINT, START, icao, region);
			}
			Console::info("B78XH WASM: Facility data end...");
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
	}
}

auto SimConnectFacility::requestDispatchMessages() -> void {
	DWORD cbData;
	SIMCONNECT_RECV* pData;
	while (SUCCEEDED(SimConnect_GetNextDispatch(simConnectHandle, &pData, &cbData))) {
		processDispatchMessage(pData, &cbData);
	}
}

auto SimConnectFacility::prepareDataDefinitions() -> void {
	/*
	 * 	double latitude;
	double longitude;
	double altitude;
	char name[32];
	 */

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

	/*
	 * 	double latitude;
	double longitude;
	double altitude;
	double heading;
	double length;
	double width;
	int number;
	 */
}

auto SimConnectFacility::getAirport(char* icao) -> void {
	this->connectionResult = SimConnect_RequestFacilityData_EX1(getHandle(), AIRPORT, START, icao);
}

auto SimConnectFacility::getWaypoint(char* icao) -> void {
	this->connectionResult = SimConnect_RequestFacilityData_EX1(getHandle(), WAYPOINT, START, icao);
}
