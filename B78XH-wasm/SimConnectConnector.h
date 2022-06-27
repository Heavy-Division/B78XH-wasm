#pragma once
#include "SimConnectData.h"
#include <SimConnect.h>


class SimConnectConnector {
	private:
		HANDLE simConnectHandle = 0;
		HRESULT connectionResult = 0;

	public:
		SimConnectConnector() = default;
		~SimConnectConnector() = default;
		bool connect(const char* name);
		void disconnect();
		void requestDispatchMessages();
		void processDispatchMessage(SIMCONNECT_RECV* pData, DWORD* cbData);
		void prepareDataDefinitions();
		void prepareClientDataDefinitions();
		void prepareRequests();
		HRESULT setDataOnSimObject(DATA_DEFINE_ID DefineID,
		                           SIMCONNECT_OBJECT_ID ObjectID,
		                           SIMCONNECT_DATA_SET_FLAG Flags,
		                           DWORD ArrayCount,
		                           DWORD cbUnitSize,
		                           void* pDataSet);
};

inline SimConnectConnector connector;