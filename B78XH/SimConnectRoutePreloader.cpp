#include "SimConnectRoutePreloader.h"

#include <string>

#include "FacilityDataStructs.h"
#include "NavDataCache.h"
#include "Tools/Console.h"

enum class ROUTE_PRELOAD_FACILITY_DATA_DEFINE_ID {
	AIRPORT,
	WAYPOINT,
	WAYPOINT_MINIMAL
};

enum class ROUTE_PRELOAD_FACILITY_DATA_REQUEST_ID {
	START = 1000,
	WAYPOINT_REQUEST = 2000,
	ROUTE_PRE_LOAD = 10000
};

auto SimConnectRoutePreloader::connect(const char* name) -> bool {
	Console::info("B78XH WASM: SimConnect connecting...");
	this->connectionResult = SimConnect_Open(&simConnectHandle, name, nullptr, 0, 0, 0);
	if (this->connectionResult == S_OK) {
		Console::info("B78XH WASM: SimConnect client \"{}\" connected", name);
	}

	prepareDataDefinitions();
	return true;
}

auto SimConnectRoutePreloader::disconnect() -> void {
	Console::info("B78XH WASM: SimConnect disconnecting...");
	SimConnect_Close(getHandle());
	Console::info("B78XH WASM: SimConnect disconnected...");
}

auto SimConnectRoutePreloader::getHandle() -> unsigned long long {
	return this->simConnectHandle;
}

auto SimConnectRoutePreloader::processDispatchMessage(SIMCONNECT_RECV* pData, DWORD* cbData) -> void {
	switch (pData->dwID) {
		case SIMCONNECT_RECV_ID_FACILITY_DATA: {
			auto pFacilityData = reinterpret_cast<SIMCONNECT_RECV_FACILITY_DATA*>(pData);

			switch (pFacilityData->Type) {
				case SIMCONNECT_FACILITY_DATA_AIRPORT: {
					break;
				}

				case SIMCONNECT_FACILITY_DATA_RUNWAY: {
					break;
				}

				case SIMCONNECT_FACILITY_DATA_WAYPOINT: {
					/*
					 * We do not need any waypoint information... We only need routes.
					 */
					//Console::error("GETTING WAYPOINT MINIMAL");
					break;
				}

				case SIMCONNECT_FACILITY_DATA_ROUTE: {
					/*
					 * Waypoint route
					 */
					auto route = reinterpret_cast<RouteStruct*>(&pFacilityData->Data);
					/*
					 * Search the route name in route cache (Are we preloading route this name right now??)
					 */
					auto iterator = routeCache.find(route->name);
					/*
					for (std::pair<const string, std::list<RouteWaypoint>> route_cache : routeCache) {
						Console::cerror("ROUTE CACHE: {};", route_cache.first);
					}
					Console::cerror("ROUTE: {}", route->name);
					*/

					/*
					 * Is the route preloading now  -> the continue -> else skip
					 */
					if (iterator != routeCache.end()) {
						/*
						 * if front waypoint icao is not |START| -> try to preload waypoints in route backwards
						 * if front waypoint icao is |START| -> try to preload waypoints in route forward (we already loaded all waypoints from beginning of route to reference waypoint so we need to load waypoints from reference to end of route)
						 */
						if (iterator->second.front().icao != "|START|") {
							string previous = route->previousIcao;
							/*
							 * If the previous ICAO is empty -> insert |START| to front of route waypoints array and start preloading route forward from last preloaded waypoint in array
							 * (we are at the beginning of route)
							 *
							 * If the previous ICAO is not empty -> insert the previous ICAO to the array and make request for previous waypoint (routes of previous)
							 */
							if (previous == "") {
								iterator->second.emplace_front(RouteWaypoint{"|START|", "", 0});
								getRoute("", iterator->second.back().icao, iterator->second.back().region, iterator->second.back().type);
							}
							else {
								iterator->second.emplace_front(RouteWaypoint{previous, route->previousRegion, (char)route->previousType});
								getRoute("asd", iterator->second.front().icao, route->previousRegion, route->previousType);
							}
						}
						else {
							/*
							 * if back waypoint is |END| -> route is complete. Copy the preloaded route to NavDataCache, remove route from queue and clear routeCache (The code should never get to this condition)
							 * if back waypoint is not |END| -> try to preload route forward (from reference waypoint to the end of route)
							 */
							if (iterator->second.back().icao != "|END|") {
								string next = route->nextIcao;
								/*
								 * if next ICAO is empty -> We are in the end of route (Route is complete) -> Copy the preloaded route to NavDataCache, remove route from queue and clear routeCache
								 *
								 * if next ICAO is not empty -> insert next ICAO to the array and make request to next waypoint (routes of next waypoint)
								 */
								if (next == "") {
									auto const icao = iterator->second.back();
									//iterator->second.emplace_back(RouteWaypoint{"|END|", "", 0});
									/*
									 * Pop front waypoint "|START|" helper
									 */
									iterator->second.pop_front();
									NavDataCache::routes.emplace(std::pair<string, std::list<RouteWaypoint>>(iterator->first, iterator->second));
									NavDataCache::routesPreloadQueue.erase(iterator->first);
									routeCache.clear();
								}
								else {
									iterator->second.emplace_back(RouteWaypoint{route->nextIcao, route->nextRegion, (char)route->nextType});
									getRoute("", iterator->second.back().icao, route->nextRegion, route->nextType);
								}
							}
							else {
								/*
								 * This code should not be reachable because the route is closed inside the if branch.
								 * (The route is closed automatically if next icao is empty so there should not be next iteration on the same route)
								 */
								NavDataCache::routes.emplace(std::pair<string, std::list<RouteWaypoint>>(iterator->first, iterator->second));
								NavDataCache::routesPreloadQueue.erase(iterator->first);
								routeCache.clear();
							}
						}
					}
					break;
				}
			}
		}
		break;
		case SIMCONNECT_RECV_ID_FACILITY_DATA_END: {
			Console::info("B78XH WASM: Facility data end...");
			/*
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
			*/
			//auto pFacilityData = reinterpret_cast<SIMCONNECT_RECV_FACILITY_DATA_END*>(pData);
		}
		break;

		case SIMCONNECT_RECV_ID_FACILITY_MINIMAL_LIST: {
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

auto SimConnectRoutePreloader::requestDispatchMessages() -> void {
	/*
	 * Do we have any route to preload?
	 */
	if (!NavDataCache::routesPreloadQueue.empty()) {
		const auto firstRoute = NavDataCache::routesPreloadQueue.begin();

		if (NavDataCache::routes.find(firstRoute->first) != NavDataCache::routes.end()) {
			NavDataCache::routesPreloadQueue.erase(firstRoute);
		}
		else {
			/*
			 * If routeCache is empty (we are not preloading any route at this time). Create new routeCache and make a request for reference waypoint (start preloading new route)
			 * If routeCache is not empty (We already preloading some route) -> skip (only one route can be preloading)
			 */
			if (routeCache.empty() && NavDataCache::routes.find(firstRoute->first) == NavDataCache::routes.end()) {
				routeCache.emplace(std::pair<string, std::list<RouteWaypoint>>(firstRoute->first, {}));
				getRoute(firstRoute->first, firstRoute->second.getReferenceWaypoint(), firstRoute->second.getRegion(), firstRoute->second.getType());
			}
		}
	}


	unsigned long cbData;
	SIMCONNECT_RECV* pData;
	while (SUCCEEDED(SimConnect_GetNextDispatch(simConnectHandle, &pData, &cbData))) {
		processDispatchMessage(pData, &cbData);
	}
}

auto SimConnectRoutePreloader::prepareDataDefinitions() -> void {
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(ROUTE_PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL),
	                                                            "OPEN WAYPOINT");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(ROUTE_PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL),
	                                                            "OPEN ROUTE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(ROUTE_PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL),
	                                                            "NAME");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(ROUTE_PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL),
	                                                            "NEXT_ICAO");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(ROUTE_PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL),
	                                                            "PREV_ICAO");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(ROUTE_PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL),
	                                                            "NEXT_REGION");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(ROUTE_PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL),
	                                                            "PREV_REGION");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(ROUTE_PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL),
	                                                            "NEXT_TYPE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(ROUTE_PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL),
	                                                            "PREV_TYPE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(ROUTE_PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL),
	                                                            "CLOSE ROUTE");
	this->connectionResult = SimConnect_AddToFacilityDefinition(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(ROUTE_PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL),
	                                                            "CLOSE WAYPOINT");
}

auto SimConnectRoutePreloader::getAirport(char* icao) -> void {
	this->connectionResult = SimConnect_RequestFacilityData_EX1(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(ROUTE_PRELOAD_FACILITY_DATA_DEFINE_ID::AIRPORT),
	                                                            static_cast<SIMCONNECT_DATA_REQUEST_ID>(ROUTE_PRELOAD_FACILITY_DATA_REQUEST_ID::START), icao);
}

auto SimConnectRoutePreloader::getRoute(string route, string icao, string region, char type) -> void {
	this->connectionResult = SimConnect_RequestFacilityData_EX1(getHandle(), static_cast<SIMCONNECT_DATA_DEFINITION_ID>(ROUTE_PRELOAD_FACILITY_DATA_DEFINE_ID::WAYPOINT_MINIMAL),
	                                                            static_cast<SIMCONNECT_DATA_REQUEST_ID>(ROUTE_PRELOAD_FACILITY_DATA_REQUEST_ID::START), icao.c_str(),
	                                                            region.c_str(), type);
}
