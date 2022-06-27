

#include <MSFS\MSFS.h>
#include "MSFS\MSFS_Render.h"
#include <MSFS\Legacy\gauges.h>

#include "PFDAuxGauge.h"


#ifdef _MSC_VER
#define snprintf _snprintf_s
#elif !defined(__MINGW32__)
#include <iconv.h>
#endif

PFDAuxGauge g_AUXGauge;

// ------------------------
// Callbacks
extern "C" {
	MSFS_CALLBACK bool pfd_aux_gauge_callback(FsContext ctx, int service_id, void* pData) {
		switch(service_id) {
			case PANEL_SERVICE_PRE_INSTALL: {
				//sGaugeInstallData* p_install_data = (sGaugeInstallData*)pData;
				return g_AUXGauge.preInstall();
			}
			break;
			case PANEL_SERVICE_POST_INSTALL: {
				return g_AUXGauge.postInstall(ctx);
			}
			break;
			case PANEL_SERVICE_PRE_DRAW: {
				return g_AUXGauge.preDraw(ctx, static_cast<sGaugeDrawData*>(pData));
			}
			break;
			case PANEL_SERVICE_PRE_KILL: {
				return g_AUXGauge.preKill();
			}
			break;
		}
		return false;
	}
}
