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


#pragma once

class Timer {
	public:
		Timer(double target_value, bool auto_start = false)
			: targetValue(target_value),
			  autoStart(auto_start) {
		}

		auto start() -> void;
		auto restart() -> void;
		auto stop() -> void;
		auto stop(bool force) -> void;
		auto reset() -> void;
		auto update(double value) -> void;
		auto value() const -> double;
		auto finished() const -> bool;
		auto started() const -> bool;
	private:
		double targetValue;
		double internalValue = 0;
		bool isStarted = false;
		bool isFinished = false;
		bool autoStart = false;
};
