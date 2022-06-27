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


#include "TuningControlPanelINOPPage.h"

void TuningControlPanelINOPPage::loadData() {

}

void TuningControlPanelINOPPage::render(NVGcontext* context,
                                        float windowWidth,
                                        float windowHeight,
                                        float devicePixelRatio) {
	nvgBeginFrame(context, windowWidth, windowHeight, devicePixelRatio);
	{
		nvgFillColor(context, nvgRGB(0, 0, 0));
		nvgBeginPath(context);
		nvgRect(context, 0, 0, windowWidth, windowHeight);
		nvgFill(context);

		//nvgFontSize(context, 30.0f);
		nvgFontSize(context, 25.0f);
		nvgFontFace(context, "heavy-fmc");
		nvgFillColor(context, nvgRGBA(255, 255, 255, 255));
		renderTitle(context);
		renderInop(context);
	}
	nvgEndFrame(context);
}

TuningControlPanelINOPPage::TuningControlPanelINOPPage(const char* title) {
	(*this).title = title;
}

void TuningControlPanelINOPPage::renderInop(NVGcontext* context) {
	nvgTextAlign(context, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
	nvgText(context, 170.0f, 65.0f, "- INOP -", nullptr);
}

void TuningControlPanelINOPPage::renderTitle(NVGcontext* context) {
	nvgTextAlign(context, NVG_ALIGN_CENTER | NVG_ALIGN_BASELINE);
	nvgText(context, 170.0f, 28.0f, title, nullptr);
}
