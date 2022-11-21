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

#include "SimConnectConnector.h"
#include "SimpleINI/SimpleIni.h"
#include "B78XHConfiguration.h"
CSimpleIniA ini;

// ------------------------
// Callbacks
extern "C" {
	auto EventHandler(ID32 event, UINT32 evdata, PVOID userdata) -> void {
		if (event == 66978 || event == 66981 || event == 66984 || event == 65762 || event == 65763 || event == 65764) {
			return;
		}
		//Console::error("EVENT {}", event);
	}

	MSFS_CALLBACK auto tool_simconnect_handling_gauge_callback(FsContext ctx, int service_id, void* pData) -> bool {
		switch (service_id) {
			case PANEL_SERVICE_PRE_INSTALL: {
				//NavData::prepareWaypoints();
				return true;
			}
			break;
			case PANEL_SERVICE_POST_INSTALL: {
				//register_key_event_handler_EX1((GAUGE_KEY_EVENT_HANDLER_EX1)EventHandler, NULL);
				B78XHConfiguration::data.load();
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_DRAW: {
				connector.requestDispatchMessages();
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_KILL: {
				B78XHConfiguration::data.save();
				//unregister_key_event_handler_EX1((GAUGE_KEY_EVENT_HANDLER_EX1)EventHandler, NULL);
				return true;
			}
			break;
		}
		return false;
	}
}
