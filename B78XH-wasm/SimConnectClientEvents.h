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

enum class ClientEvents {
	/*
	 * Control IDs 
	 */
	B78XH_CONTROL_IDS_TCP_1,
	B78XH_CONTROL_IDS_TCP_2,
	B78XH_CONTROL_IDS_TCP_3,

	/*
	 * Others
	 */
	B78XH_BUTTON_CLOCK_PUSH,
	B78XH_BUTTON_MTRS_PUSH,
	B78XH_BUTTON_FPV_PUSH,
};