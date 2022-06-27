#include <MSFS\MSFS.h>
#include "MSFS\MSFS_Render.h"
#include "MSFS\Render\nanovg.h"
#include <MSFS\Legacy\gauges.h>
#include "MCPVSpeedGauge.h"

#ifdef _MSC_VER
#define snprintf _snprintf_s
#elif !defined(__MINGW32__)
#include <iconv.h>
#endif

MCPVSpeedGauge g_MCPVSpeedGauge;

// ------------------------
// Callbacks
extern "C" {
	MSFS_CALLBACK bool mcp_vspeed_gauge_callback(FsContext ctx, int service_id, void* pData) {
		switch(service_id) {
			case PANEL_SERVICE_PRE_INSTALL: {
				g_MCPVSpeedGauge.preInstall();
				return true;
			}
			break;
			case PANEL_SERVICE_POST_INSTALL: {
				g_MCPVSpeedGauge.postInstall(ctx);
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_DRAW: {
				g_MCPVSpeedGauge.preDraw((sGaugeDrawData*)pData);
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_KILL: {
				g_MCPVSpeedGauge.preKill();
				return true;
			}
			break;
		}
		return false;
	}
}
