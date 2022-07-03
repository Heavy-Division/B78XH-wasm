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


#include "CDUCenterLine.h"

void CDUCenterLine::calculateHorizontalOffset() {
	nvgFontSize(this->context, this->fontSize);
	nvgTextAlign(this->context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
	float translateXBounds[4];
	nvgTextBounds(this->context, 0, 0, this->basicContent.c_str(), nullptr, translateXBounds);
	this->horizontalOffset = 249 + ((translateXBounds[2] - translateXBounds[0]) / 2);
}
