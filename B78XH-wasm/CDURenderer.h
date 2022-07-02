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


#pragma once
#include "BaseGauge.h"
#include "CDUMainKeyButton.h"
#include "CDUMouseClickResolver.h"
#include "CDUMouseCursor.h"
#include "CDUMouseMoveResolver.h"
#include "CDUPageRenderer.h"
#include "CDUSelectKeyButton.h"

class CDURenderer {
	public:
		CDURenderer(NVGcontext*& nvg_context,
			CDUMouseMoveResolver& mouse_move_resolver,
			CDUMouseClickResolver& mouse_click_resolver
		) : nvgContext(nvg_context),
			mouseMoveResolver(mouse_move_resolver),
			mouseClickResolver(mouse_click_resolver),
			pageRenderer(CDUPageRenderer(nvg_context)),
		    mouseCursor(CDUMouseCursor(nvg_context, mouse_move_resolver)),
		    MKInitRef(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 11, 486, "INIT", "REF")),
		    MKRte(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 89, 486, "RTE")),
		    MKDepArr(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 167, 486, "DEP", "ARR")),
		    MKAltn(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 245, 486, "ALTN")),
		    MKVnav(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 323, 486, "VNAV")),

			MKFix(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 11, 538, "FIX")),
			MKLegs(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 89, 538, "LEGS")),
			MKHold(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 167, 538, "HOLD")),
			MKFmcComm(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 245, 538, "FMC", "COMM")),
			MKProg(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 323, 538, "PROG")),

			MKNavRad(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 11, 590, "NAV", "RAD")),
			MKOfst(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 89, 590, "OFST")),
			MKRta(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 167, 590, "RTA")),
			MKHeavy(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 245, 590, "HEAVY")),

		    LSK1(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 17, 86)),
		    LSK2(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 17, 147)),
		    LSK3(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 17, 208)),
		    LSK4(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 17, 269)),
		    LSK5(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 17, 330)),
		    LSK6(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 17, 391)),
		    RSK1(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 595, 86, true)),
		    RSK2(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 595, 147, true)),
		    RSK3(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 595, 208, true)),
		    RSK4(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 595, 269, true)),
		    RSK5(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 595, 330, true)),
		    RSK6(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 595, 391, true)) {
		}

		void render(sGaugeDrawData* data);
		void setContext(FsContext context);
		void kill();
	private:
		NVGcontext*& nvgContext;
		CDUMouseMoveResolver& mouseMoveResolver;
		CDUMouseClickResolver& mouseClickResolver;
		CDUPageRenderer pageRenderer;

		/**
		 * Mouse Cursor
		 */
		CDUMouseCursor mouseCursor;

		/*
		 * MAIN Keys
		 */
		CDUMainKeyButton MKInitRef;
		CDUMainKeyButton MKRte;
		CDUMainKeyButton MKDepArr;
		CDUMainKeyButton MKAltn;
		CDUMainKeyButton MKVnav;
		CDUMainKeyButton MKFix;
		CDUMainKeyButton MKLegs;
		CDUMainKeyButton MKHold;
		CDUMainKeyButton MKFmcComm;
		CDUMainKeyButton MKProg;
		CDUMainKeyButton MKNavRad;
		CDUMainKeyButton MKOfst;
		CDUMainKeyButton MKRta;
		CDUMainKeyButton MKHeavy;
		/*
		 * SELECT KEYS Keys
		 */
		CDUSelectKeyButton LSK1;
		CDUSelectKeyButton LSK2;
		CDUSelectKeyButton LSK3;
		CDUSelectKeyButton LSK4;
		CDUSelectKeyButton LSK5;
		CDUSelectKeyButton LSK6;
		CDUSelectKeyButton RSK1;
		CDUSelectKeyButton RSK2;
		CDUSelectKeyButton RSK3;
		CDUSelectKeyButton RSK4;
		CDUSelectKeyButton RSK5;
		CDUSelectKeyButton RSK6;
};
