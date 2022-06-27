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

#include "PEDESTALTuningControlPanelGauge.h"

#ifdef _MSC_VER
#define snprintf _snprintf_s
#elif !defined(__MINGW32__)
#include <iconv.h>
#endif

PEDESTALTuningControlPanelGauge g_PEDESTALTuningControlPanelGauges[3] = {
	PEDESTALTuningControlPanelGauge(0),
	PEDESTALTuningControlPanelGauge(1),
	PEDESTALTuningControlPanelGauge(2)
};

// ------------------------
// Callbacks
extern "C" {
	bool pedestal_tuning_control_panel_gauge_callback(FsContext ctx, int service_id, void* pData, int id) {
		switch(service_id) {
			case PANEL_SERVICE_PRE_INSTALL: {
				return g_PEDESTALTuningControlPanelGauges[id].preInstall();
			}
			break;
			case PANEL_SERVICE_POST_INSTALL: {
				return g_PEDESTALTuningControlPanelGauges[id].postInstall(ctx);
			}
			break;
			case PANEL_SERVICE_PRE_DRAW: {
				return g_PEDESTALTuningControlPanelGauges[id].preDraw(static_cast<sGaugeDrawData*>(pData));
			}
			break;
			case PANEL_SERVICE_PRE_KILL: {
				return g_PEDESTALTuningControlPanelGauges[id].preKill();
			}
			break;
		}
		return false;
	}

	MSFS_CALLBACK bool pedestal_tuning_control_panel_1_gauge_callback(FsContext ctx, int service_id, void* pData) {
		return pedestal_tuning_control_panel_gauge_callback(ctx, service_id, pData, 0);
	}

	MSFS_CALLBACK bool pedestal_tuning_control_panel_2_gauge_callback(FsContext ctx, int service_id, void* pData) {
		return pedestal_tuning_control_panel_gauge_callback(ctx, service_id, pData, 1);
	}

	MSFS_CALLBACK bool pedestal_tuning_control_panel_3_gauge_callback(FsContext ctx, int service_id, void* pData) {
		return pedestal_tuning_control_panel_gauge_callback(ctx, service_id, pData, 2);
	}
}
