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
		);

		auto render(sGaugeDrawData* data) -> void;
		auto setContext(FsContext context) -> void;
		auto preInstall() -> void;
		auto postInstall(FsContext context) -> void;
		auto preUpdate() -> void;
		auto preDraw(sGaugeDrawData* data) -> void;
		auto preKill() -> void;
	private:
		NVGcontext*& nvgContext;
		CDUMouseMoveResolver& mouseMoveResolver;
		CDUMouseClickResolver& mouseClickResolver;
		CDUPageRenderer pageRenderer;

		/*
		 * CDU Controls
		 */

		std::string CDUControlIdVariable;
		ID CDUControlIdVariableID;
		double controlSwitchIdVariableValue = -1;

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

		auto setupMainKeysEvents() -> void;
		auto handleControlId(double controlId) -> void;
		auto handlePageSwitching(CDUPageType pageId) -> void;
		auto handleCDUEvents(CDUEvent eventId) -> void;
};
