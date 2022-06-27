#include <MSFS/MSFS.h>
#include "SimConnectConnector.h"

// ------------------------
// Callbacks
extern "C" {
	MSFS_CALLBACK bool tool_simconnect_handling_gauge_callback(FsContext ctx, int service_id, void* pData) {
		switch(service_id) {
			case PANEL_SERVICE_PRE_INSTALL: {
				return true;
			}
			break;
			case PANEL_SERVICE_POST_INSTALL: {
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_DRAW: {
				connector.requestDispatchMessages();
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_KILL: {
				return true;
			}
			break;
		}
		return false;
	}
}
