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


#include "RedApplication.h"

#include "Console.h"
#include "Tools.h"

auto RedApplication::render(sGaugeDrawData* data) -> void {
	if(this->nvgContext == nullptr) {
		return;
	}
	nvgFillColor(this->nvgContext, Tools::Colors::red);
	nvgBeginPath(this->nvgContext);
	nvgRect(this->nvgContext, 0, 0, 200, 200);
	nvgFill(this->nvgContext);
	nvgFontSize(this->nvgContext, 90.0f);
	nvgFontFace(this->nvgContext, "dseg7");
	nvgFillColor(this->nvgContext, Tools::Colors::white);
	nvgFill(this->nvgContext);
}
