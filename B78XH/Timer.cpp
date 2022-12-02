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


#include "Timer.h"

auto Timer::start() -> void {
	this->isStarted = true;
	this->isFinished = false;
}

auto Timer::restart() -> void {
	this->reset();
	this->isFinished = false;
}

auto Timer::stop() -> void {
	this->isStarted = false;
}

auto Timer::stop(bool force) -> void {
	this->autoStart = false;
	this->isStarted = false;
}

auto Timer::reset() -> void {
	this->internalValue = 0;
}

auto Timer::update(double value) -> void {
	if (this->isFinished) {
		return;
	}
	if (this->autoStart) {
		this->isStarted = true;
	}
	if (this->isStarted) {
		this->internalValue += value;
		this->isFinished = this->internalValue >= this->targetValue;
	}
}

auto Timer::value() const -> double {
	return this->internalValue;
}

auto Timer::finished() const -> bool {
	return this->isFinished;
}

auto Timer::started() const -> bool {
	return this->isStarted;
}
