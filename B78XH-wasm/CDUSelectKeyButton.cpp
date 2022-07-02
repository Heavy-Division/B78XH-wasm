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


#include "CDUSelectKeyButton.h"

void CDUSelectKeyButton::draw() {
	if (this->context != nullptr) {
		if(this->event) {
			CDUButton::draw();
		} else {
			drawBackBorders(nvgRGB(54, 201, 210));
		}
		this->drawPointers();
	}
	this->shouldTriggerEvent();
	if(this->isInFocus()) {
		CDUSelectKeyButton::drawBorder();
	}
}

void CDUSelectKeyButton::calculateBounds() {
	if(this->rightSide) {
		this->bounds[0] = this->x - 200;
		this->bounds[1] = this->x + this->width;
		this->bounds[2] = this->y;
		this->bounds[3] = this->y + this->height;
	} else {
		this->bounds[0] = this->x;
		this->bounds[1] = this->x + this->width + 200;
		this->bounds[2] = this->y;
		this->bounds[3] = this->y + this->height;
	}
}

void CDUSelectKeyButton::drawBorder() {
	nvgStrokeColor(context, nvgRGB(213, 112, 255));
	nvgStrokeWidth(this->context, 5.0f);
	if(this->rightSide) {
		nvgBeginPath(this->context);
		{
			nvgMoveTo(this->context, this->x + this->width, this->y);
			nvgLineTo(this->context, this->x - 200, this->y);
			nvgLineTo(this->context, this->x - 200, this->y + this->height);
			nvgLineTo(this->context, this->x + this->width, this->y + this->height);
		}
		nvgClosePath(this->context);
	} else {
		nvgBeginPath(this->context);
		{
			nvgMoveTo(this->context, this->x, this->y);
			nvgLineTo(this->context, this->x + 200, this->y);
			nvgLineTo(this->context, this->x + 200, this->y + this->height);
			nvgLineTo(this->context, this->x, this->y + this->height);
		}
		nvgClosePath(this->context);
	}
	nvgStroke(this->context);
}

void CDUSelectKeyButton::drawPointers() {

	nvgStrokeWidth(this->context, 1.5f);
	if(this->event) {
		nvgFillColor(this->context, nvgRGB(255, 255, 255));
	} else {
		nvgFillColor(this->context, nvgRGB(54, 201, 210));
	}
	nvgStrokeColor(this->context, nvgRGB(0, 0, 0));

	nvgBeginPath(this->context);
	{
		if(this->rightSide) {
			nvgRoundedRect(this->context, this->x - 16 - 5, this->y + (this->height / 2) - 2, 16, 4, 2.0f);
		} else {
			nvgRoundedRect(this->context, this->x + this->width + 5, this->y + (this->height / 2) - 2, 16, 4, 2.0f);
		}
	}
	nvgClosePath(this->context);
	nvgFill(this->context);
	nvgStroke(this->context);
}
