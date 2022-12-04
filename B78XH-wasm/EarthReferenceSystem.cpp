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


#include "EarthReferenceSystem.h"

auto EarthReferenceSystem::setLeftIRSSwitchPosition(bool position) -> void {
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

auto EarthReferenceSystem::setRightIRSSwitchPosition(bool position) -> void {
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

auto EarthReferenceSystem::getLeftIRS() -> IRS& {
	return this->getIRS(LEFT);
}

auto EarthReferenceSystem::getRightIRS() -> IRS& {
	return this->getIRS(RIGHT);
}

auto EarthReferenceSystem::getIRS(IRSPosition position) -> IRS& {
	switch (position) {
		case LEFT: {
			return this->leftIRS;
		}
		case RIGHT: {
			return this->rightIRS;
		}
	}
}

auto EarthReferenceSystem::update(double deltaTime) -> void {
	if (!this->getLeftIRS().isAligned()) {
		this->getLeftIRS().update(deltaTime);
	}

	if (!this->getRightIRS().isAligned()) {
		this->getRightIRS().update(deltaTime);
	}
}
