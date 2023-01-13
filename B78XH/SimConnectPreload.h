#pragma once
#include <MSFS/MSFS_WindowsTypes.h>
#include <SimConnect.h>
#include <string>
#include <unordered_map>
#include <list>

#include "FacilityDataStructs.h"

using std::string;

class SimConnectPreload {
	public:
		SimConnectPreload() = default;
		~SimConnectPreload() = default;
		auto requestDispatchMessages() -> void;
		auto getAirport(char* icao) -> void;
		auto getWaypoint(char* icao) -> void;
		auto getRoute(string route, string icao, string region, char type) -> void;
		auto connect(const char* name) -> bool;
		auto disconnect() -> void;

	protected:
		auto getHandle() -> unsigned long long;
		auto processDispatchMessage(SIMCONNECT_RECV* pData, DWORD* cbData) -> void;
		auto prepareDataDefinitions() -> void;

	private:
		unsigned long long simConnectHandle = 0;
		long connectionResult = 0;
		std::unordered_map<string, std::list<RouteWaypoint>> routeCache;
};
