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


#include "CCS.h"
#include "fmt/core.h"

auto CCS::init() -> void {
}

auto CCS::prepare() -> void {
	this->updateLVars();
}

auto CCS::update(double deltaTime) -> void {
	this->updateERS(deltaTime);
}

auto CCS::reset() -> void {
}

auto CCS::updateLVars() -> void {
	this->lvars.update();
}

auto CCS::updateERS(double deltaTime) -> void {
	this->ers.setLeftIRSSwitchPosition(this->lvars.get(LVars::B78XH_IRS_L_SWITCH_STATE).isValue());
	this->ers.setRightIRSSwitchPosition(this->lvars.get(LVars::B78XH_IRS_R_SWITCH_STATE).isValue());
	this->ers.update(deltaTime);
}
