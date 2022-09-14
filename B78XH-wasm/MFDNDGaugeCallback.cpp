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


#include <MSFS/MSFS.h>

#include "MFDNDGauge.h"
#include "Simplane.h"


MFDNDGauge g_MFDNDGauge;
// ------------------------
// Callbacks
extern "C" {
	MSFS_CALLBACK bool mfd_nd_gauge_callback(FsContext ctx, int service_id, void* pData) {
		switch(service_id) {
			case PANEL_SERVICE_PRE_INSTALL: {
				g_MFDNDGauge.preInstall();
				return true;
			}
			break;
			case PANEL_SERVICE_POST_INSTALL: {
				g_MFDNDGauge.postInstall(ctx);
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_DRAW: {
				g_MFDNDGauge.preDraw((sGaugeDrawData*)pData);
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_KILL: {
				g_MFDNDGauge.preKill();
				return true;
			}
			break;
		}
		return false;
	}
}
