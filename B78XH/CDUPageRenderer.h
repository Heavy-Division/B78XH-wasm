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

#include <utility>

#include "CDUIdentPage.h"
#include "CDULineRenderer.h"
#include "CDUPage.h"
#include "CDUPageType.h"
#include "MSFS/Render/nanovg.h"

class CDUPageRenderer {
	public:
		CDUPageRenderer(NVGcontext*& context) : context(context) {

		}

		void switchPage(CDUPageType page);
		auto preparePage() -> void;
		void render();

		CDUPage* getCDUPage() const {
			return this->cduPage;
		}

	protected:
		void drawBackground();
		void drawLines();

	private:
		NVGcontext*& context;
		CDUPage* cduPage = new CDUIdentPage(context);
		CDULineRenderer lineRenderer = CDULineRenderer(context);

};
