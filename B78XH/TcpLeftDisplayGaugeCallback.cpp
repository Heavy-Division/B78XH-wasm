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


//#include <MSFS\MSFS.h>
#include <MSFS/MSFS_Render.h>
#include <MSFS/Legacy/gauges.h>

#include "Displays.h"

#ifdef _MSC_VER
#define snprintf _snprintf_s
#elif !defined(__MINGW32__)
#include <iconv.h>
#endif
// ------------------------
// Callbacks
extern "C" {
	__attribute__((visibility("default"))) bool tcp_left_display_gauge_callback(FsContext ctx, int service_id, void* pData) {
		switch (service_id) {
			case PANEL_SERVICE_PRE_INSTALL: {
				Displays::tcpLeftDisplay->preInstall(static_cast<BaseControl::GaugeInstallData*>(pData));
				return true;
			}
			break;
			case PANEL_SERVICE_POST_INSTALL: {
<<<<<<< HEAD
				//Console::log("POST_INSTALL");

=======
>>>>>>> 676f8f55237bfa904b213521f19a258ae6977e7d
				NVGparams params;
				params.userPtr = ctx;
				params.edgeAntiAlias = true;
				Displays::tcpLeftDisplay->postInstall(nvgCreateInternal(&params));

				return true;
			}
			break;
			case PANEL_SERVICE_PRE_UPDATE: {
				Displays::tcpLeftDisplay->preUpdate();
				return true;
			}
			break;
			case PANEL_SERVICE_POST_UPDATE: {
				Displays::tcpLeftDisplay->postUpdate();
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_DRAW: {
				Displays::tcpLeftDisplay->preDraw(static_cast<BaseControl::GaugeDrawData*>(pData));
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_KILL: {
				Displays::tcpLeftDisplay->preKill();
				return true;
			}
			case PANEL_SERVICE_POST_KILL: {
				Displays::tcpLeftDisplay->postKill();
			}
			break;
		}
		return false;
	}
}
