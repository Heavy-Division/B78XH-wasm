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


#include "HelloWorldApplication.h"

using Colors = Tools::Colors;

void HelloWorldApplication::render(sGaugeDrawData* data) {
	if (this->nvgContext == nullptr) {
		return;
	}
	nvgFillColor(this->nvgContext, this->textColor);
	nvgFontSize(this->nvgContext, 90.0f);
	nvgFontFace(this->nvgContext, "heavy-fmc");
	nvgTextAlign(this->nvgContext, NVG_ALIGN_TOP | NVG_ALIGN_LEFT);
	nvgBeginPath(this->nvgContext);
	{
		nvgText(this->nvgContext, 10, 10, "Hello World!!!", nullptr);
	}
	nvgFill(this->nvgContext);
}

auto HelloWorldApplication::setColor(NVGcolor color) -> void {
	this->textColor = color;
}
