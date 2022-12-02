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


#include "CDUMouseCursor.h"

#include "Tools/Tools.h"

void CDUMouseCursor::draw() {
	if(this->context == nullptr) {
		return;
	}
	nvgSave(this->context);
	{
		nvgStrokeColor(context, Tools::Colors::magenta);
		nvgStrokeWidth(this->context, 2.0f);
		nvgTranslate(this->context, this->mouseMoveResolver.getX() - 15, this->mouseMoveResolver.getY() - 15);
		{
			nvgBeginPath(this->context);
			{
				nvgMoveTo(this->context, 10, 0);
				nvgLineTo(this->context, 10, 10);
				nvgLineTo(this->context, 0, 10);

				nvgMoveTo(this->context, 15, 0);
				nvgLineTo(this->context, 15, 10);
				nvgLineTo(this->context, 25, 10);

				nvgMoveTo(this->context, 0, 15);
				nvgLineTo(this->context, 10, 15);
				nvgLineTo(this->context, 10, 25);

				nvgMoveTo(this->context, 25, 15);
				nvgLineTo(this->context, 15, 15);
				nvgLineTo(this->context, 15, 25);
				nvgMoveTo(this->context, 10, 0);
			}
		}
		nvgClosePath(this->context);
		nvgStroke(this->context);
		nvgResetTransform(this->context);
	}
	nvgRestore(this->context);
}
