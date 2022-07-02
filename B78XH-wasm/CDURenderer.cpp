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


#include "CDURenderer.h"

void CDURenderer::render(sGaugeDrawData* data) {
	const auto devicePixelRatio = static_cast<float>(data->fbWidth) / static_cast<float>(data->winWidth);
	const auto windowWidth = static_cast<float>(data->winWidth);
	const auto windowHeight = static_cast<float>(data->winHeight);

	nvgBeginFrame(this->nvgContext, windowWidth, windowHeight, devicePixelRatio);
	{
		nvgFillColor(this->nvgContext, nvgRGB(97, 100, 127));
		nvgBeginPath(this->nvgContext);
		{
			nvgRect(this->nvgContext, 0, 0, windowWidth, windowHeight);

		}
		nvgFill(this->nvgContext);
		nvgSave(this->nvgContext);
		{
			nvgTranslate(this->nvgContext, windowWidth / 2 - 249, 34);
			{
				this->pageRenderer.render();
			}
			nvgResetTransform(this->nvgContext);
		}
		nvgRestore(this->nvgContext);
		
		this->MKInitRef.draw();
		this->MKRte.draw();
		this->MKDepArr.draw();
		this->MKAltn.draw();
		this->MKVnav.draw();
		this->MKFix.draw();
		this->MKLegs.draw();
		this->MKHold.draw();
		this->MKFmcComm.draw();
		this->MKProg.draw();
		this->MKNavRad.draw();
		this->MKOfst.draw();
		this->MKRta.draw();
		this->MKHeavy.draw();
		this->LSK1.draw();
		this->LSK2.draw();
		this->LSK3.draw();
		this->LSK4.draw();
		this->LSK5.draw();
		this->LSK6.draw();
		this->RSK1.draw();
		this->RSK2.draw();
		this->RSK3.draw();
		this->RSK4.draw();
		this->RSK5.draw();
		this->RSK6.draw();
		
		this->LSK1.event = []() {
			fmt::print(stderr, "LSK1 event triggered");
		};

		this->mouseCursor.draw();
	}
	nvgEndFrame(nvgContext);
}

void CDURenderer::setContext(FsContext context) {
	NVGparams params;
	params.userPtr = context;
	params.edgeAntiAlias = true;

	this->nvgContext = nvgCreateInternal(&params);
	nvgCreateFont(this->nvgContext, "heavy-fmc", "./data/Heavy787FMC.ttf");
}

void CDURenderer::kill() {
	nvgDeleteInternal(this->nvgContext);
}
