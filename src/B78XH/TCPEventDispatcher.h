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

#include <queue>

class TCPEventDispatcher {
	public:
		enum class EVENT_LIST {
			NONE,
			VFH = 1,
			HF = 2,
			SAT = 3,
			CAB = 4,
			GPWS = 5,
			WXR = 6,
			XPDR = 7,
			LSK1 = 8,
			LSK2 = 9,
			LSK3 = 10,
			LSK4 = 11,
			RSK1 = 12,
			RSK2 = 13,
			RSK3 = 14,
			RSK4 = 15,
			PREV = 28,
			NEXT = 29,
			OFF = 32,
			NAV = 30,
			MENU = 31,
			STBY_UP = 33,
			STBY_DOWN = 34,
			XFR =35,
			CLR =26,
			DOT = 27,
			ONE = 16,
			TWO = 17,
			THREE = 18,
			FOUR = 19,
			FIVE = 20,
			SIX = 21,
			SEVEN = 22,
			EIGHT = 23,
			NINE = 24,
			ZERO = 25
		};

		auto get() -> EVENT_LIST;
		auto front() -> EVENT_LIST;
		auto back() -> EVENT_LIST;
		auto push(EVENT_LIST event) -> void;
		auto pop() -> void;
		auto empty() -> bool;
		auto size() -> int;

	protected:
		std::queue<EVENT_LIST> queue{};
};
