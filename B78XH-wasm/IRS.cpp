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


#include "IRS.h"
#include "B78XHConfiguration.h"
#include <cmath>
#include "Simplane.h";
#include <chrono>

auto IRS::setTimeToAlign(double time) -> void {
	Alignable::setTimeToAlign(time);
	this->ahru.setTimeToAlign(time);
	this->iru.setTimeToAlign(time);
}

auto IRS::isAligned() -> bool {
	return this->ahru.isAligned() && this->iru.isAligned();
}

auto IRS::isAligning() -> bool {
	return this->ahru.isAligning() || this->iru.isAligning();
}

auto IRS::getTimeToAlign() -> double {
	return std::min<double>(this->iru.getTimeToAlign(), this->ahru.getTimeToAlign());
}

auto IRS::update(double deltaTime) -> void {
	this->ahru.update(deltaTime);
	this->iru.update(deltaTime);
}

auto IRS::setAlignState(AlignState state) -> void {
	if (this->getAlignState() != state) {
		if (state == ALIGNING) {
			const double timeToAlign = this->generateAlignTime();
			this->setTimeToAlign(timeToAlign);
		}
		Alignable::setAlignState(state);
		this->ahru.setAlignState(state);
		this->iru.setAlignState(state);
	}
}

auto IRS::generateAlignTime() -> double {
	const auto alignTypeType = B78XHConfiguration::irs::alignTimeType();
	double min = 0;
	double max = 0;

	switch (alignTypeType) {
		case IRSAlignTimeType::INSTANT: {
			min = 0;
			max = 0;
		}
		break;
		case IRSAlignTimeType::FAST: {
			min = 70;
			max = 110;
		}
		break;
		case IRSAlignTimeType::NORMAL: {
			min = 230;
			max = 270;
		}
		break;
		case IRSAlignTimeType::REAL: {
			const double timeConstant = 5.4;
			const double distanceConstant = 0.9;
			const double planeLatitudeAbsolute = std::abs(Simplane::aircraft::state::latitude());
			const double timeToAlign = std::floor((planeLatitudeAbsolute / distanceConstant) * timeConstant);
			min = timeToAlign + 360 - 20;
			max = timeToAlign + 360 + 20;
		}
		break;
		default: {
			min = 230;
			max = 270;
		}
	}

	return std::floor((rand() / static_cast<double>(RAND_MAX)) * (max - min + 1)) + min;
}
