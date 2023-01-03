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
#include "LVars.h"
#include "Tools/Console.h"
#include "KEvents.h"
#include "SimConnectData.h"
#include "MainBattery.h"
#include "Simplane.h"
#include "LVarsGetter.h"
#include "RPDS.h"

auto CCS::init() -> void {
}

auto CCS::prepare() -> void {
	this->updateLVars();
}

auto CCS::update(double deltaTime) -> void {
	this->updateERS(deltaTime);
	MainBattery battery;

	Console::log("{}", static_cast<double>(battery.getCurrent()));
	
}

auto CCS::reset() -> void {
}

auto CCS::updateLVars() -> void {
	LVars::update();
}

auto CCS::updateERS(double deltaTime) -> void {
	this->ers.setLeftIRSSwitchPosition(LVars::get(LVars::B78XH_IRS_L_SWITCH_STATE).isValue());
	this->ers.setRightIRSSwitchPosition(LVars::get(LVars::B78XH_IRS_R_SWITCH_STATE).isValue());
	this->ers.update(deltaTime);
}
