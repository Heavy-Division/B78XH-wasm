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
