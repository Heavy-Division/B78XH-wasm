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
#include "CDUMouseMoveResolver.h"
#include "CDURenderer.h"
#include "MSFS/Render/nanovg.h"


class MFDCduGauge : public BaseGauge {
	public:
	bool preInstall() override;
	bool postInstall(FsContext context) override;
	bool preUpdate();
	bool preDraw(sGaugeDrawData* data) override;
	bool preDraw(FsContext context, sGaugeDrawData* data) override;
	bool preKill() override;
	CDUMouseMoveResolver& getMouseMoveResolver();
	CDUMouseClickResolver& getMouseClickResolver();

	private:
		FsContext fsContext = 0;
		NVGcontext* nvgContext = nullptr;
		CDUMouseMoveResolver mouseMoveResolver = CDUMouseMoveResolver();
		CDUMouseClickResolver mouseClickResolver = CDUMouseClickResolver();
		CDURenderer renderer = CDURenderer(nvgContext, mouseMoveResolver, mouseClickResolver);

		float devicePixelRatio = 0;
		float windowWidth = 0;
		float windowHeight = 0;

		int baseFont = 0;
		int heavyFont = 0;
};
