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


#include "CDURoutePage.h"
#include "CDULine.h"

CDURoutePage::CDURoutePage(NVGcontext*& context): CDUPage(context) {
}

void CDURoutePage::preparePage() {
	this->LTP1({ "ORIGIN", "" });
	this->LTP2({ "RUNWAY", "" });
	this->LTP3({ "ROUTE", "" });
	this->LTP4({ "ROUTE", "" });
	this->LTP5({ "ROUTE -------", "" });

	this->LLP1({ "□□□□", "settable" });
	this->LLP2({ "-----", "settable" });
	this->LLP3({ "<REQUEST", "" });
	this->LLP4({ "<REPORT", "" });
	this->LLP5({ "<PRINT", "" });
	this->LLP6({ "<RTE2", "" });

	this->RTP1({ "DEST", "" });
	this->RTP2({ "FLT NO", "" });
	this->RTP3({ "CO ROUTE", "" });

	this->RLP1({ "□□□□", "settable" });
	this->RLP2({ "□□□□", "settable" });
	this->RLP3({ "--------", "settable" });
	this->RLP4({ "RTE COPY>", "" });
	this->RLP5({ "ALTN>", "" });
	this->RLP6({ "PERF INIT>", "" });
}
