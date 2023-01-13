#include "SimConnectPreload.h"

#include <string>

#include "FacilityDataStructs.h"
#include "NavDataCache.h"
#include "Tools/Console.h"

enum class PRELOAD_FACILITY_DATA_DEFINE_ID {
	AIRPORT,
	WAYPOINT,
	WAYPOINT_MINIMAL
};

enum class PRELOAD_FACILITY_DATA_REQUEST_ID {
	START = 1000,
	WAYPOINT_REQUEST = 2000,
	ROUTE_PRE_LOAD = 10000
};

auto SimConnectPreload::connect(const char* name) -> bool {
	Console::info("B78XH WASM: SimConnect connecting...");
	this->connectionResult = SimConnect_Open(&simConnectHandle, name, nullptr, 0, 0, 0);
	if (this->connectionResult == S_OK) {
		Console::info("B78XH WASM: SimConnect client \"{}\" connected", name);
	}

	prepareDataDefinitions();
	return true;
}

auto SimConnectPreload::disconnect() -> void {
	Console::info("B78XH WASM: SimConnect disconnecting...");
	SimConnect_Close(getHandle());
	Console::info("B78XH WASM: SimConnect disconnected...");
}

auto SimConnectPreload::getHandle() -> unsigned long long {
	return this->simConnectHandle;
}

auto SimConnectPreload::processDispatchMessage(SIMCONNECT_RECV* pData, DWORD* cbData) -> void {
	switch (pData->dwID) {
		case SIMCONNECT_RECV_ID_FACILITY_DATA: {
			auto pFacilityData = reinterpret_cast<SIMCONNECT_RECV_FACILITY_DATA*>(pData);

			switch (pFacilityData->Type) {
				case SIMCONNECT_FACILITY_DATA_AIRPORT: {
					//Console::error("!!!!!!!!!!!!!!!!HAVE THE AIRPORT!!!!!!!!!!!!!!!!!!");
					break;
				}

				case SIMCONNECT_FACILITY_DATA_RUNWAY: {
					break;
				}

				case SIMCONNECT_FACILITY_DATA_WAYPOINT: {
					Console::error("GETTING WAYPOINT MINIMAL");
					break;
				}

				case SIMCONNECT_FACILITY_DATA_ROUTE: {
					auto route = reinterpret_cast<RouteStruct*>(&pFacilityData->Data);
					auto iterator = routeCache.find(route->name);

					for (std::pair<const string, std::list<RouteWaypoint>> route_cache : routeCache) {
						Console::cerror("ROUTE CACHE: {};", route_cache.first);
					}
					Console::cerror("ROUTE: {}", route->name);

					if (iterator != routeCache.end()) {
						Console::cerror("CONDITION1");
						if (iterator->second.front().icao != "|START|") {
							Console::cerror("CONDITION2");
							string previous = route->previousIcao;
							if (previous == "") {
								Console::cerror("CONDITION3");
								iterator->second.emplace_front(RouteWaypoint{ "|START|", "", 0 });
								getRoute("", iterator->second.back().icao, iterator->second.back().region, iterator->second.back().type);
							}
							else {
								Console::cerror("CONDITION4");
								iterator->second.emplace_front(RouteWaypoint{ previous, route->previousRegion, (char)route->previousType });
								getRoute("asd", iterator->second.front().icao, route->previousRegion, route->previousType);
							}
						}
						else {
							Console::cerror("CONDITION5");
							if (iterator->second.back().icao != "|END|") {
								Console::cerror("CONDITION6");
								string next = route->nextIcao;
								if (next == "") {
									Console::cerror("CONDITION7");
									auto const icao = iterator->second.back();
									iterator->second.emplace_back(RouteWaypoint{"|END|", "", 0});
									Console::cerror("CONDITION9");
									NavDataCache::routes.emplace(std::pair<string, std::list<RouteWaypoint>>(iterator->first, iterator->second));
									NavDataCache::routesPreloadQueue.erase(iterator->first);
									routeCache.clear();
								}
								else {
									Console::cerror("CONDITION8");
									iterator->second.emplace_back(RouteWaypoint{ route->nextIcao, route->nextRegion, (char)route->nextType });
									getRoute("", iterator->second.back().icao, route->nextRegion, route->nextType);
								}
							}
							else {
								Console::cerror("CONDITION9");
								NavDataCache::routes.emplace(std::pair<string, std::list<RouteWaypoint>>(iterator->first, iterator->second));
								NavDataCache::routesPreloadQueue.erase(iterator->first);
								routeCache.clear();
							}
						}
					} else {
						Console::cerror("CONDITION10");
					}
					Console::error("GETTING ROUTE");
					break;
				}
			}
		}
		break;
		case SIMCONNECT_RECV_ID_FACILITY_DATA_END: {
			Console::info("B78XH WASM: Facility data end...");
			Console::cerror("NUMBER OF PRELOADED ROUTES: {}", NavDataCache::routes.size());
			for (std::pair<const string, std::list<RouteWaypoint>> route : NavDataCache::routes) {
				Console::cerror("RouteName: {}", route.first);
				Console::cerror("RouteSize: {}", route.second.size());
				Console::cerror("-------------- Fixes -------------- ");
				Console::cerror("----------------------------------- ");
				for (RouteWaypoint second : route.second) {
					Console::cerror("ICAO: {}; REGION: {}; TYPE: {}", second.icao, second.region, second.type);
				}
				Console::cerror("----------------------------------- ");
			}
			auto pFacilityData = reinterpret_cast<SIMCONNECT_RECV_FACILITY_DATA_END*>(pData);

		}
		break;

		case SIMCONNECT_RECV_ID_FACILITY_MINIMAL_LIST: {
			Console::error("NON UNIQUE");
			auto msg = reinterpret_cast<SIMCONNECT_RECV_FACILITY_MINIMAL_LIST*>(pData);
			for (unsigned i = 0; i < msg->dwArraySize; ++i) {
				SIMCONNECT_FACILITY_MINIMAL& fm = msg->rgData[i];

				fprintf(stdout, "ICAO => Type: %c, Ident: %s, Region: %s, Airport: %s => Lat: %lf, Lat: %lf, Alt: %lf\n", fm.icao.Type, fm.icao.Ident, fm.icao.Region,
				        fm.icao.Airport, fm.lla.Latitude, fm.lla.Longitude, fm.lla.Altitude);
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

auto SimConnectPreload::requestDispatchMessages() -> void {
	if (!NavDataCache::routesPreloadQueue.empty()) {
		Console::cerror("NOT EMPTY");
		const auto firstRoute = NavDataCache::routesPreloadQueue.begin();

		if (routeCache.empty() && !NavDataCache::routesPreloadQueue.empty()) {
			Console::cerror("C1");
			routeCache.emplace(std::pair<string, std::list<RouteWaypoint>>(firstRoute->first, {}));
			getRoute(firstRoute->first, firstRoute->second.getReferenceWaypoint(), firstRoute->second.getRegion(), firstRoute->second.getType());
		}

		//Console::cerror("SEARCHING: {}", firstRoute->first);
		//if (routeCache.find(firstRoute->first) != routeCache.end()) {
			//Console::cerror("C2");
			//routeCache.clear();
		//}
	}


	unsigned long cbData;
	SIMCONNECT_RECV* pData;
	while (SUCCEEDED(SimConnect_GetNextDispatch(simConnectHandle, &pData, &cbData))) {
		processDispatchMessage(pData, &cbData);
	}
}

auto SimConnectPreload::prepareDataDefinitions() -> void {
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), (SIMCONNECT_DATA_DEFINITION_ID)PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL, "OPEN WAYPOINT");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), (SIMCONNECT_DATA_DEFINITION_ID)PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL, "ICAO");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), (SIMCONNECT_DATA_DEFINITION_ID)PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL, "REGION");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), (SIMCONNECT_DATA_DEFINITION_ID)PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL, "OPEN ROUTE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), (SIMCONNECT_DATA_DEFINITION_ID)PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL, "NAME");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), (SIMCONNECT_DATA_DEFINITION_ID)PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL, "NEXT_ICAO");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), (SIMCONNECT_DATA_DEFINITION_ID)PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL, "PREV_ICAO");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), (SIMCONNECT_DATA_DEFINITION_ID)PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL, "NEXT_REGION");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), (SIMCONNECT_DATA_DEFINITION_ID)PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL, "PREV_REGION");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), (SIMCONNECT_DATA_DEFINITION_ID)PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL, "NEXT_TYPE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), (SIMCONNECT_DATA_DEFINITION_ID)PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL, "PREV_TYPE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), (SIMCONNECT_DATA_DEFINITION_ID)PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL, "CLOSE ROUTE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), (SIMCONNECT_DATA_DEFINITION_ID)PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL, "CLOSE WAYPOINT");
}

auto SimConnectPreload::getAirport(char* icao) -> void {
	this->connectionResult = SimConnect_RequestFacilityData_EX1(getHandle(), (SIMCONNECT_DATA_DEFINITION_ID)PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT,
	                                                            (SIMCONNECT_DATA_REQUEST_ID)PRELOAD_FACILITY_DATA_REQUEST_ID::START, icao);
}

auto SimConnectPreload::getRoute(string route, string icao, string region, char type) -> void {
	Console::cerror("getRoute: {}", route);
	Console::cerror("getRoute ICAO: {}", icao);
	Console::cerror("getRoute Region: {}", region);
	this->connectionResult = SimConnect_RequestFacilityData_EX1(getHandle(), (SIMCONNECT_DATA_DEFINITION_ID)PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL,
	                                                            (SIMCONNECT_DATA_REQUEST_ID)PRELOAD_FACILITY_DATA_REQUEST_ID::START, icao.c_str(),region.c_str(), type);
}
