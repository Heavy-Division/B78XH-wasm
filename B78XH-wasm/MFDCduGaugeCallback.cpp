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

#include "CDUMouseMoveResolver.h"
#include "MFDCduGauge.h"


#ifdef _MSC_VER
#define snprintf _snprintf_s
#elif !defined(__MINGW32__)
#include <iconv.h>
#endif

MFDCduGauge g_CDUGauge;

// ------------------------
// Callbacks
extern "C" {
	MSFS_CALLBACK bool mfd_cdu_gauge_callback(FsContext ctx, int service_id, void* pData) {
		switch(service_id) {
			case PANEL_SERVICE_PRE_INSTALL: {
				return g_CDUGauge.preInstall();
			}
			break;
			case PANEL_SERVICE_POST_INSTALL: {
				return g_CDUGauge.postInstall(ctx);
			}
			break;
			case PANEL_SERVICE_PRE_DRAW: {
				return g_CDUGauge.preDraw(static_cast<sGaugeDrawData*>(pData));
			}
			break;
			case PANEL_SERVICE_PRE_KILL: {
				return g_CDUGauge.preKill();
			}
			break;
		}
		return false;
	}

	MSFS_CALLBACK void mfd_cdu_mouse_callback(float fX, float fY, unsigned int iFlags) {
		switch(iFlags) {
			case MOUSE_MOVE: {
				g_CDUGauge.getMouseMoveResolver().positionX = fX;
				g_CDUGauge.getMouseMoveResolver().positionY = fY;
			}
			break;
			case MOUSE_LEFTDRAG: {
			}
			break;
			case MOUSE_RIGHTDRAG: {

			}
			break;
			case MOUSE_MIDDLEDRAG: {

			}
			break;
			case MOUSE_LEFTRELEASE: {
				g_CDUGauge.getMouseClickResolver().positionX = fX;
				g_CDUGauge.getMouseClickResolver().positionY = fY;
			}
			break;
			case MOUSE_RIGHTRELEASE: {

			}
			break;
			case MOUSE_MIDDLERELEASE: {

			}
			break;
			case MOUSE_LEFTSINGLE: {

			}
			break;
			case MOUSE_RIGHTSINGLE: {

			}
			break;
			case MOUSE_MIDDLESINGLE: {

			}
			break;
			case MOUSE_LEFTDOUBLE: {

			}
			break;
			case MOUSE_RIGHTDOUBLE: {

			}
			break;
			case MOUSE_MIDDLEDOUBLE: {

			}
			break;
			case MOUSE_WHEEL_UP: {

			}
			break;
			case MOUSE_WHEEL_DOWN: {

			}
			break;
			default:
				break;
		}

		/*
		 *
		 *  MOUSE_MOVE: the mouse cursor has moved.
			MOUSE_LEFTDRAG: left button down.
			MOUSE_RIGHTDRAG: right button down.
			MOUSE_MIDDLEDRAG: middle button down.
			MOUSE_LEFTRELEASE: left button up.
			MOUSE_RIGHTRELEASE: right button up.
			MOUSE_MIDDLERELEASE: middle button up.
			MOUSE_LEFTSINGLE: left button click (sent after a down/up sequence).
			MOUSE_RIGHTSINGLE: right button click (sent after a down/up sequence).
			MOUSE_MIDDLESINGLE: middle button click (sent after a down/up sequence).
			MOUSE_LEFTDOUBLE: left button click (sent after two consecutive clicks).
			MOUSE_MIDDLEDOUBLE: middle button click (sent after two consecutive clicks).
			MOUSE_WHEEL_UP: wheel moved up.
			MOUSE_WHEEL_DOWN: wheel moved down.
		 */
	}
}
