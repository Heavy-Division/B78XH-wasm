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


#include "IRU.h"

auto IRU::getAlignState() -> Alignable::AlignState& {
	return Alignable::getAlignState();
}

auto IRU::getTimeToAlign() -> double {
	return Alignable::getTimeToAlign();
}

auto IRU::setTimeToAlign(double time) -> void {
	Alignable::setTimeToAlign(time);
}

auto IRU::isAligned() -> bool {
	return Alignable::isAligned();
}

auto IRU::isAligning() -> bool {
	return Alignable::isAligning();
}

auto IRU::setAlignState(AlignState state) -> void {
	if (state == OFF || state == ALIGNED) {
		this->setTimeToAlign(-1);
	}

	Alignable::setAlignState(state);
}

auto IRU::update(double deltaTime) -> void {
	if (this->getAlignState() == ALIGNED || this->getAlignState() == OFF) {
		return;
	}
	const double timeToAlign = this->getTimeToAlign() - deltaTime;
	if (timeToAlign > 0) {
		this->setTimeToAlign(timeToAlign);
	}
	else {
		this->setTimeToAlign(-1);
		this->setAlignState(ALIGNED);
	}
}
