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