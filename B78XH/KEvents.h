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
#include <string>

class KEvents {
	public:
		static auto execute(std::string name, std::string value) -> void;
		static auto execute(std::string name, int value) -> void;
		static auto execute(std::string name, float value) -> void;
		static auto execute(std::string name, long value) -> void;
		static auto execute(std::string name, double value) -> void;

		static auto trigger(std::string name, std::string value) -> void;
		static auto trigger(std::string name, int value) -> void;
		static auto trigger(std::string name, float value) -> void;
		static auto trigger(std::string name, long value) -> void;
		static auto trigger(std::string name, double value) -> void;


		static auto execute(std::string name, std::string value, std::string unit) -> void;
		static auto execute(std::string name, int value, std::string unit) -> void;
		static auto execute(std::string name, float value, std::string unit) -> void;
		static auto execute(std::string name, long value, std::string unit) -> void;
		static auto execute(std::string name, double value, std::string unit) -> void;

		static auto trigger(std::string name, std::string value, std::string unit) -> void;
		static auto trigger(std::string name, int value, std::string unit) -> void;
		static auto trigger(std::string name, float value, std::string unit) -> void;
		static auto trigger(std::string name, long value, std::string unit) -> void;
		static auto trigger(std::string name, double value, std::string unit) -> void;
	private:
		static auto executeEvent(std::string name, std::string value) -> void;
		static auto executeEvent(std::string name, std::string value, std::string unit) -> void;

};
