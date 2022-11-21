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


#include "KEvents.h"

#include <string>
#include <string>
#include <MSFS/Legacy/gauges.h>
#include "fmt/core.h"

auto KEvents::execute(std::string name, std::string value) -> void {
	executeEvent(name, value);
}

auto KEvents::execute(std::string name, int value) -> void {
	executeEvent(name, std::to_string(value));
}

auto KEvents::execute(std::string name, float value) -> void {
	executeEvent(name, std::to_string(value));
}

auto KEvents::execute(std::string name, long value) -> void {
	executeEvent(name, std::to_string(value));
}

auto KEvents::execute(std::string name, double value) -> void {
	executeEvent(name, std::to_string(value));
}

auto KEvents::trigger(std::string name, std::string value) -> void {
	execute(name, value);
}

auto KEvents::trigger(std::string name, int value) -> void {
	execute(name, value);
}

auto KEvents::trigger(std::string name, float value) -> void {
	execute(name, value);
}

auto KEvents::trigger(std::string name, long value) -> void {
	execute(name, value);
}

auto KEvents::trigger(std::string name, double value) -> void {
	execute(name, value);
}

auto KEvents::execute(std::string name, std::string value, std::string unit) -> void {
	executeEvent(name, value, unit);
}

auto KEvents::execute(std::string name, int value, std::string unit) -> void {
	executeEvent(name, std::to_string(value), unit);
}

auto KEvents::execute(std::string name, float value, std::string unit) -> void {
	executeEvent(name, std::to_string(value), unit);
}

auto KEvents::execute(std::string name, long value, std::string unit) -> void {
	executeEvent(name, std::to_string(value), unit);
}

auto KEvents::execute(std::string name, double value, std::string unit) -> void {
	executeEvent(name, std::to_string(value), unit);
}

auto KEvents::trigger(std::string name, std::string value, std::string unit) -> void {
	execute(name, value, unit);
}

auto KEvents::trigger(std::string name, int value, std::string unit) -> void {
	execute(name, value, unit);
}

auto KEvents::trigger(std::string name, float value, std::string unit) -> void {
	execute(name, value, unit);
}

auto KEvents::trigger(std::string name, long value, std::string unit) -> void {
	execute(name, value, unit);
}

auto KEvents::trigger(std::string name, double value, std::string unit) -> void {
	execute(name, value, unit);
}

auto KEvents::executeEvent(std::string name, std::string value) -> void {
	const auto command = fmt::format("{} (>K:{})", value, name);
	execute_calculator_code(command.c_str(), nullptr, nullptr, nullptr);
}

auto KEvents::executeEvent(std::string name, std::string value, std::string unit) -> void {
	const auto command = fmt::format("{} (>K:{}, {})", value, name, unit);
	execute_calculator_code(command.c_str(), nullptr, nullptr, nullptr);
}
