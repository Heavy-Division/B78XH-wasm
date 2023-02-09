#include "SimConnectAirportPreloader.h"

#include "FacilityDataStructs.h"
#include "Tools/Console.h"

auto SimConnectAirportPreloader::requestDispatchMessages() -> void {
	if (airportCache == nullptr) {
		if (!NavDataCache::airportsPreloadQueue.empty()) {
			NavDataCache::airportsPreloadQueue.begin();
		}
	}

	if (airportCache == nullptr) {
	}

	if (!NavDataCache::airportsPreloadQueue.empty()) {
		const auto firstAirport = NavDataCache::airportsPreloadQueue.begin();

		if (NavDataCache::airports.find(firstAirport->first) != NavDataCache::airports.end()) {
			NavDataCache::airportsPreloadQueue.erase(firstAirport);
		}
		else {
			/*
			 * If routeCache is empty (we are not preloading any route at this time). Create new routeCache and make a request for reference waypoint (start preloading new route)
			 * If routeCache is not empty (We already preloading some route) -> skip (only one route can be preloading)
			 */
			if (airportCache == nullptr && NavDataCache::airports.find(firstAirport->first) == NavDataCache::airports.end()) {
				airportCache = std::make_unique<Airport>(firstAirport->first);
				callAirportRequest(const_cast<char*>(firstAirport->first.c_str()));
			}
		}
	}

	DWORD cbData;
	SIMCONNECT_RECV* pData;
	while (SUCCEEDED(SimConnect_GetNextDispatch(simConnectHandle, &pData, &cbData))) {
		processDispatchMessage(pData, &cbData);
	}
}

auto SimConnectAirportPreloader::getAirport(char* icao) -> void {
	Console::error("REQUESTING: {}", icao);
	NavDataCache::airportsPreloadQueue.emplace(icao, icao);
	Console::error("COUNT AIRPORTS QUEUE SIZE: {}", NavDataCache::airportsPreloadQueue.size());
}

auto SimConnectAirportPreloader::callAirportRequest(char* icao) -> void {
	this->connectionResult = SimConnect_RequestFacilityData_EX1(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            static_cast<SIMCONNECT_DATA_REQUEST_ID>(AIRPORT_PRELOAD_FACILITY_DATA_REQUEST_ID::START), icao);
}

auto SimConnectAirportPreloader::connect(const char* name) -> bool {
	Console::info("B78XH WASM: SimConnect connecting...");
	this->connectionResult = SimConnect_Open(&simConnectHandle, name, nullptr, 0, 0, 0);
	if (this->connectionResult == S_OK) {
		Console::info("B78XH WASM: SimConnect client \"{}\" connected", name);
	}
	prepareDataDefinitions();

	return true;
}

auto SimConnectAirportPreloader::disconnect() -> void {
	Console::info("B78XH WASM: SimConnect disconnecting...");
	SimConnect_Close(getHandle());
	Console::info("B78XH WASM: SimConnect disconnected...");
}

auto SimConnectAirportPreloader::getHandle() -> unsigned long long {
	return this->simConnectHandle;
}

auto SimConnectAirportPreloader::processDispatchMessage(SIMCONNECT_RECV* pData, DWORD* cbData) -> void {
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
					airportCache->update((*airport));
					//airportCache = std::make_unique<Airport>(airport->name, airport->latitude, airport->longitude, airport->altitude);
					//NavDataCache::airports.emplace(airport->name, std::make_unique<Airport>(airport->name, airport->latitude, airport->longitude, airport->altitude));
					break;
				}

				case SIMCONNECT_FACILITY_DATA_RUNWAY: {
					auto runway = reinterpret_cast<RunwayStruct*>(&pFacilityData->Data);
					Console::error("RUNWAY PRIMARY NUMBER: {}", runway->primaryNumber);
					Console::error("RUNWAY SECONDARY NUMBER: {}", runway->secondaryNumber);
					break;
				}

				case SIMCONNECT_FACILITY_DATA_WAYPOINT: {
					break;
				}

				case SIMCONNECT_FACILITY_DATA_ROUTE: {
					break;
				}
			}
		}
		break;
		case SIMCONNECT_RECV_ID_FACILITY_DATA_END: {
			NavDataCache::airports.emplace(airportCache->getIcao(), std::move(airportCache));


			Console::cerror("NUMBER OF PRELOADED ROUTES: {}", NavDataCache::airports.size());
			for (std::pair<const string, std::unique_ptr<Airport>>& airport : NavDataCache::airports) {
				Console::cerror("AirportName: {}", airport.second->getName());
				Console::cerror("AirportIcao: {}", airport.second->getIcao());
				Console::cerror("-------------- Fixes -------------- ");
				Console::cerror("----------------------------------- ");
				/*
				for (RouteWaypoint second : airport.second) {
					Console::cerror("ICAO: {}; REGION: {}; TYPE: {}", second.icao, second.region, second.type);
				}
				*/
				Console::cerror("----------------------------------- ");
			}
		}
		break;

		case SIMCONNECT_RECV_ID_FACILITY_MINIMAL_LIST: {
			break;
		}

		case SIMCONNECT_RECV_ID_EXCEPTION: {
			SIMCONNECT_RECV_EXCEPTION* pException = (SIMCONNECT_RECV_EXCEPTION*)pData;
			if (pException->dwException == 1) {
			}

			NavDataCache::airportsPreloadQueue.erase(airportCache->getIcao());
			airportCache = nullptr;

			Console::error("SIMCONNECT EXCEPTION: {}", pException->dwException);
			break;
		}
		case SIMCONNECT_RECV_ID_NULL: {
			Console::error("NULL");
			break;
		}
		case SIMCONNECT_RECV_ID_OPEN: {
			Console::error("OPEN");
			break;
		}
		case SIMCONNECT_RECV_ID_QUIT: {
			Console::error("QUIT");
			break;
		}
	
	}
}

auto SimConnectAirportPreloader::prepareDataDefinitions() -> void {
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            "OPEN AIRPORT");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            "LATITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            "LONGITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            "ALTITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT), "NAME");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            "N_RUNWAYS");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            "OPEN RUNWAY");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            "LATITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            "LONGITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            "ALTITUDE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            "HEADING");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            "LENGTH");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT), "WIDTH");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            "PRIMARY_NUMBER");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            "SECONDARY_NUMBER");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            "CLOSE RUNWAY");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            "CLOSE AIRPORT");
};
