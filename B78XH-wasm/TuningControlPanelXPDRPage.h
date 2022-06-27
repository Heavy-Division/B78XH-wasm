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
#include "TuningControlPanelBasePage.h"

class TuningControlPanelXPDRPage: public TuningControlPanelBasePage {
	public:
		TuningControlPanelXPDRPage(TuningControlPanelScratchpad* scratchpad);
		void render(NVGcontext* context, float windowWidth, float windowHeight, float devicePixelRatio) override;
		void handleEvent(TuningControlPanelControlPageEventsID eventId) override;
	private:
		void renderLines(NVGcontext* context);
		void renderTitle(NVGcontext* context);
		void renderRightColoredLines(NVGcontext* context, float offset);
		void renderRightLines(NVGcontext* context, std::string text, float offset, FsColor* color = nullptr);
		void renderLeftColoredLines(NVGcontext* context, float offset);
};
