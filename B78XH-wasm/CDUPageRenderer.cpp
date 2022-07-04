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


#include "CDUPageRenderer.h"

#include "CDULine.h"

void CDUPageRenderer::render() {
	this->drawBackground();
	this->drawLines();
}

void CDUPageRenderer::drawBackground() {
	nvgFillColor(this->context, nvgRGB(0, 0, 0));
	nvgBeginPath(this->context);
	{
		nvgRect(this->context, 0, 0, 498, 398);
	}
	nvgClosePath(this->context);
	nvgFill(this->context);
}

void CDUPageRenderer::drawLines() {
	
	std::vector<CDULine> lines = this->cduPage->getLines();
	
	const auto numberOfLines = lines.size();

	for (int i = 0; i < numberOfLines; i++) {
		lines.at(i).draw();
	}
	
}
