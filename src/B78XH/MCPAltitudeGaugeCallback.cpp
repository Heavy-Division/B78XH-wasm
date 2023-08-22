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


#include <MSFS\MSFS.h>
#include "MSFS\MSFS_Render.h"
#include <MSFS\Legacy\gauges.h>

#include "MCPAltitudeGauge.h"


#ifdef _MSC_VER
#define snprintf _snprintf_s
#elif !defined(__MINGW32__)
#include <iconv.h>
#endif

extern MCPAltitudeGauge g_MCPAltitudeGauge;


/*
const auto workAround = "B78XH_WASM_TRANSFER_DATA";
const auto workAroundVariable = check_named_variable(workAround);
const auto position = "B78XH_WASM_REQUEST_DATA_POSITION";
const auto positionVariable = check_named_variable(position);
std::string transfer;

const auto displayedAltitudeLockValueUnit = get_units_enum("STRING");
const auto displayedAltitudeLockValue = get_aircraft_var_enum("DROPPABLE OBJECTS TYPE");
*/



// ------------------------
// Callbacks
extern "C" {
	MSFS_CALLBACK bool mcp_altitude_gauge_callback(FsContext ctx, int service_id, void* pData) {
		switch(service_id) {
			case PANEL_SERVICE_PRE_INSTALL: {
				return g_MCPAltitudeGauge.preInstall();
			}
			break;
			case PANEL_SERVICE_POST_INSTALL: {
				return g_MCPAltitudeGauge.postInstall(ctx);
			}
			break;
			case PANEL_SERVICE_PRE_DRAW: {
				return g_MCPAltitudeGauge.preDraw(static_cast<sGaugeDrawData*>(pData));
			}
			break;
			case PANEL_SERVICE_PRE_KILL: {
				return g_MCPAltitudeGauge.preKill();
			}
			break;
		}
		return false;
	}
}
