#include <MSFS\MSFS.h>
#include "MSFS\MSFS_Render.h"
#include <MSFS\Legacy\gauges.h>

#include "PFDPfdGauge.h"


#ifdef _MSC_VER
#define snprintf _snprintf_s
#elif !defined(__MINGW32__)
#include <iconv.h>
#endif

PFDPfdGauge g_PFDGauge;

// ------------------------
// Callbacks
extern "C" {
	MSFS_CALLBACK bool pfd_pfd_gauge_callback(FsContext ctx, int service_id, void* pData) {
		switch(service_id) {
			case PANEL_SERVICE_PRE_INSTALL: {
				return g_PFDGauge.preInstall();
			}
			break;
			case PANEL_SERVICE_POST_INSTALL: {
				return g_PFDGauge.postInstall(ctx);
			}
			break;
			case PANEL_SERVICE_PRE_DRAW: {
				return g_PFDGauge.preDraw(static_cast<sGaugeDrawData*>(pData));
			}
			break;
			case PANEL_SERVICE_PRE_KILL: {
				return g_PFDGauge.preKill();
			}
			break;
		}
		return false;
	}
}
