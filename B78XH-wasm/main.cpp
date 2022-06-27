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


#include <MSFS/MSFS.h>
#include "fmt/core.h"
#include "SimConnectConnector.h"

extern "C" MSFS_CALLBACK void module_init(void) {
	connector.connect("Global SimConnect connection");
	fmt::print("B78XH WASM: Module init");
	fflush(stdout);
}

extern "C" MSFS_CALLBACK void module_deinit(void) {
	connector.disconnect();
	fmt::print("B78XH WASM: Module deinit");
	fflush(stdout);
}