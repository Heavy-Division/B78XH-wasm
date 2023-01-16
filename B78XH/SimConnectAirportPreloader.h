#pragma once
#include <MSFS/MSFS_WindowsTypes.h>
#include <SimConnect.h>
#include <string>
#include "NavDataCache.h"

using std::string;

enum class AIRPORT_PRELOAD_FACILITY_DATA_DEFINE_ID {
	AIRPORT
};

enum class AIRPORT_PRELOAD_FACILITY_DATA_REQUEST_ID {
	START = 1000
};

class SimConnectAirportPreloader {
	public:
		SimConnectAirportPreloader() = default;
		~SimConnectAirportPreloader() = default;
		auto requestDispatchMessages() -> void;
		auto getAirport(char* icao) -> void;
		auto callAirportRequest(char* icao) -> void;
		auto connect(const char* name) -> bool;
		auto disconnect() -> void;

	protected:
		auto getHandle() -> unsigned long long;
		auto processDispatchMessage(SIMCONNECT_RECV* pData, DWORD* cbData) -> void;
		auto prepareDataDefinitions() -> void;

	private:
		unsigned long long simConnectHandle = 0;
		long connectionResult = 0;
		/*
		 * TODO: Use smart pointers???
		 */
		std::unique_ptr<Airport> airportCache;
};

inline SimConnectAirportPreloader facilityConnector;