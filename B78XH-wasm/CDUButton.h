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
#include "CDUMouseClickResolver.h"
#include "CDUMouseMoveResolver.h"
#include "MSFS/Render/nanovg.h"
#include <functional>

#include "Drawable.h"
#include "Tools.h"

class CDUButton: public Drawable {
	public:
		CDUButton(NVGcontext*& context,
		          CDUMouseMoveResolver& mouseMoveResolver,
		          CDUMouseClickResolver& mouseClickResolver,
		          const double x,
		          const double y,
		          const double width,
		          const double height,
		          char* const title = nullptr,
		          char* const title2 = nullptr) : context(context),
		                                          mouseMoveResolver(mouseMoveResolver),
		                                          mouseClickResolver(mouseClickResolver),
		                                          x(x),
		                                          y(y),
		                                          width(width),
		                                          height(height),
		                                          title(title),
		                                          title2(title2) {
		}

		std::function<void()> event;
		
		void draw() override;
	protected:
		NVGcontext*& context;
		CDUMouseMoveResolver& mouseMoveResolver;
		CDUMouseClickResolver& mouseClickResolver;
		double x;
		double y;
		double width;
		double height;
		double borderWidth = 5;
		NVGalign titleAlign = NVG_ALIGN_CENTER;
		char* title;
		char* title2;
		float bounds[4] = {0, 0, 0, 0};

		void drawTitle(NVGcolor color = Tools::Colors::white);
		void drawButtonBorders();
		void drawBackBorders(NVGcolor color = Tools::Colors::black);
		void drawBackground() const;
		bool isInFocus();
		void shouldTriggerEvent();
		virtual void calculateBounds();
};
