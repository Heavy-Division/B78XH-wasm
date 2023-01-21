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
#include "SimConnectAirportPreloader.h"
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
				facilityConnector.connect("FACILITY");
				return true;
			}
			break;
			case PANEL_SERVICE_POST_INSTALL: {
				//register_key_event_handler_EX1((GAUGE_KEY_EVENT_HANDLER_EX1)EventHandler, NULL);
				B78XHConfiguration::data.load();
				//facilityConnector.getAirport("EDDF");

				//facilityConnector.getWaypoint("DONAD");

				/* Not unique*/
				//facilityConnector.getWaypoint("GUP");
				//facilityConnector.getWaypoint("FLINT");
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_UPDATE: {
				/*
				char cch1 = 97 + rand() % 26;
				char cch2 = 97 + rand() % 26;
				char cch3 = 97 + rand() % 26;
				char cch4 = 97 + rand() % 26;
				string a;
				a.push_back(cch1);
				string b;
				b.push_back(cch2);
				string c;
				c.push_back(cch3);
				string d;
				d.push_back(cch4);
				*/
				//facilityConnector.getAirport(const_cast<char*>((a + b + c + d).c_str()));
				//facilityConnector.getAirport("LKPR");
				return true;
			}
			break;
			case PANEL_SERVICE_POST_UPDATE: {
				facilityConnector.requestDispatchMessages();

				return true;
			}
			break;
			case PANEL_SERVICE_PRE_DRAW: {
				connector.requestDispatchMessages();
				facilityConnector.requestDispatchMessages();
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_KILL: {
				B78XHConfiguration::data.save();
				facilityConnector.disconnect();
				//unregister_key_event_handler_EX1((GAUGE_KEY_EVENT_HANDLER_EX1)EventHandler, NULL);
				return true;
			}
			break;
		}
		return false;
	}
}
