#pragma once
#include <MSFS/MSFS_WindowsTypes.h>
#include <SimConnect.h>

class SimConnectFacility {
	public:
		SimConnectFacility() = default;
		~SimConnectFacility() = default;
		auto requestDispatchMessages() -> void;
		auto getAirport(char* icao) -> void;
		auto getWaypoint(char* icao) -> void;
		auto connect(const char* name) -> bool;
		auto disconnect() -> void;
	protected:
		auto getHandle() -> unsigned long long;
		auto processDispatchMessage(SIMCONNECT_RECV* pData, DWORD* cbData) -> void;
		auto prepareDataDefinitions() -> void;



	private:
		unsigned long long simConnectHandle = 0;
		long connectionResult = 0;
};

inline SimConnectFacility facilityConnector;