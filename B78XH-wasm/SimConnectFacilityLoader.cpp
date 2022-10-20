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


#include "SimConnectFacilityLoader.h"
#include "SimConnectConnector.h"
#include "fmt/core.h"

auto SimConnectFacilityLoader::getAirport() -> SimConnectAirport {
	/*
	const auto handle = connector.getHandle();
	HRESULT res = SimConnect_RequestFacilityData(handle, FACILITY_DATA_DEF_AIRPORT, 1000, "LFPG");
	if(res == S_OK) {
		fmt::print(stderr, "GET AIRPORT OK");
	} else {
		fmt::print(stderr, "GET AIRPORT FAIL");
	}
	*/
	//SimConnect_RequestFacilityData(handle, FACILITY_DATA_DEF_AIRPORT, 1000, "LKPR");
	return SimConnectAirport();
}
