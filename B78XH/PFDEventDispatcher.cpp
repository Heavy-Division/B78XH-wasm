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


#include "PFDEventDispatcher.h"

auto PFDEventDispatcher::get() -> EVENT_LIST {
	if (this->empty()) {
		return EVENT_LIST::NONE;
	}

	const auto eventToReturn = this->front();
	this->pop();
	return eventToReturn;
}

auto PFDEventDispatcher::front() -> EVENT_LIST {
	return this->queue.front();
}

auto PFDEventDispatcher::back() -> EVENT_LIST {
	return this->queue.back();
}

auto PFDEventDispatcher::push(EVENT_LIST event) -> void {
	this->queue.push(event);
}

auto PFDEventDispatcher::pop() -> void {
	if (!this->empty()) {
		this->queue.pop();
	}
}

auto PFDEventDispatcher::empty() -> bool {
	return this->queue.empty();
}

auto PFDEventDispatcher::size() -> int {
	return this->queue.size();
}
