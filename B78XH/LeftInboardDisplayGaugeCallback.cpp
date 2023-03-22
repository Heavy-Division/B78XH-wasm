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


#ifdef _MSC_VER
#define snprintf _snprintf_s
#elif !defined(__MINGW32__)
#include <iconv.h>
#endif

// ------------------------
// Callbacks
extern "C" {
	MSFS_CALLBACK bool left_inboard_display_gauge_callback(FsContext ctx, int service_id, void* pData) {
		switch (service_id) {
			case PANEL_SERVICE_PRE_INSTALL: {
				Displays::leftInboardDisplay->preInstall(static_cast<BaseControl::GaugeInstallData*>(pData));
				return true;
			}
			break;
			case PANEL_SERVICE_POST_INSTALL: {
				NVGparams params;
				params.userPtr = ctx;
				params.edgeAntiAlias = true;
				Displays::leftInboardDisplay->postInstall(nvgCreateInternal(&params));

				return true;
			}
			break;
			case PANEL_SERVICE_PRE_UPDATE: {
				Displays::leftInboardDisplay->preUpdate();
				return true;
			}
			break;
			case PANEL_SERVICE_POST_UPDATE: {
				Displays::leftInboardDisplay->postUpdate();
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_DRAW: {
				Displays::leftInboardDisplay->preDraw(static_cast<BaseControl::GaugeDrawData*>(pData));
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_KILL: {
				Displays::leftInboardDisplay->preKill();
				return true;
			}
			case PANEL_SERVICE_POST_KILL: {
				Displays::leftInboardDisplay->postKill();
			}
			break;
		}
		return false;
	}

	MSFS_CALLBACK void left_inboard_display_mouse_callback(float fX, float fY, unsigned int iFlags) {
		switch (iFlags) {
			case MOUSE_MOVE: {
				//Displays::leftInboardDisplay->getMouseMoveResolver().setRelativePosition(fX, fY);
				Displays::leftInboardDisplay->queueMouseMove(fX, fY);

				break;
			}
			case MOUSE_LEFTRELEASE: {
				Displays::leftInboardDisplay->queueMouseClick(fX, fY);
				break;
			}
			default: {
				break;
			}
		}
	}
}