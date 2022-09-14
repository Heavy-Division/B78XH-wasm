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


#include "ERS.h"

auto ERS::setLeftIRSSwitchPosition(bool position) -> void {
	if (this->leftIRSSwitchPosition == position) {
		return;
	}

	if (position == false) {
		this->getLeftIRS().setAlignState(Alignable::OFF);
	}
	else {
		if (!this->getLeftIRS().isAligned()) {
			this->getLeftIRS().setAlignState(Alignable::ALIGNING);
		}
	}

	this->leftIRSSwitchPosition = position;
}

auto ERS::setRightIRSSwitchPosition(bool position) -> void {
	if (this->rightIRSSwitchPosition == position) {
		return;
	}

	if (position == false) {
		this->getRightIRS().setAlignState(Alignable::OFF);
	}
	else {
		if (!this->getRightIRS().isAligned()) {
			this->getRightIRS().setAlignState(Alignable::ALIGNING);
		}
	}
	this->rightIRSSwitchPosition = position;
}

auto ERS::getLeftIRS() -> IRS& {
	return this->getIRS(LEFT);
}

auto ERS::getRightIRS() -> IRS& {
	return this->getIRS(RIGHT);
}

auto ERS::getIRS(IRSPosition position) -> IRS& {
	switch (position) {
		case LEFT: {
			return this->leftIRS;
		}
		case RIGHT: {
			return this->rightIRS;
		}
	}
}

auto ERS::update(double deltaTime) -> void {
	if (!this->getLeftIRS().isAligned()) {
		this->getLeftIRS().update(deltaTime);
	}

	if (!this->getRightIRS().isAligned()) {
		this->getRightIRS().update(deltaTime);
	}
}
