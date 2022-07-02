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
#include "CDUCenterLine.h"
#include "CDULeftLine.h"
#include "CDULine.h"
#include "CDURightLine.h"
#include "MSFS/Render/nanovg.h"

class CDUPageRenderer {
	public:
		CDUPageRenderer(NVGcontext*& context) : context(context) {
			
		}

		void render();

	protected:
		void drawBackground();
		void drawLine(CDULine line);
		void drawLine(CDURightLine line);
		void drawLine(CDUCenterLine line);
		void drawLine(CDULeftLine line);
		void drawBasicLine(CDULeftLine line);
		void drawBasicLine(CDUCenterLine line);
		void drawBasicLine(CDURightLine line);
		void drawComplexLine(CDULeftLine line);
		void drawComplexLine(CDUCenterLine line);
		void drawComplexLine(CDURightLine line);
		void drawLines();

	private:
		NVGcontext*& context;
};
