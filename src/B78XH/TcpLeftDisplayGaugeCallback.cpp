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

#include "Displays.h"
#include "LifeCycle.h"


#ifdef _MSC_VER
#define snprintf _snprintf_s
#elif !defined(__MINGW32__)
#include <iconv.h>
#endif

// ------------------------
// Callbacks
extern "C" {
	MSFS_CALLBACK bool tcp_left_display_gauge_callback(FsContext ctx, int service_id, void* pData) {
		switch (service_id) {
			case PANEL_SERVICE_PRE_INSTALL: {
				Displays::masterControl.startup(static_cast<sGaugeInstallData*>(pData));
				return true;
			}
			break;
			case PANEL_SERVICE_POST_INSTALL: {
				Displays::masterControl.afterStartup(ctx);
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_UPDATE: {
				Displays::masterControl.beforeRender();
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_DRAW: {
				Displays::masterControl.render(static_cast<sGaugeDrawData*>(pData));
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_KILL: {
				Displays::masterControl.shutdown();
				return true;
			}
			break;
		}
		return false;
	}
}
