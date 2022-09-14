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
#include "CDUButton.h"

class CDUMainKeyButton: public CDUButton {
	public:
		CDUMainKeyButton(NVGcontext*& context,
		                 CDUMouseMoveResolver& mouseMoveResolver,
		                 CDUMouseClickResolver& mouseClickResolver,
		                 double x,
		                 double y,
		                 char* title = nullptr,
		                 char* title2 = nullptr
		) : CDUButton(context, mouseMoveResolver, mouseClickResolver, x, y, 72, 48, title, title2) {
			this->borderWidth = 3;
		}

		void draw() override;
};
