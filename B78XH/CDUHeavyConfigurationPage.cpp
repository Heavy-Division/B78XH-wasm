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


#include "CDUHeavyConfigurationPage.h"
#include "B78XHConfiguration.h"

using std::string;
using std::vector;

auto CDUHeavyConfigurationPage::preparePage() -> void {
	this->RTP1({ "SIMBRIEF", "" });
	this->RLP1(this->getSimbriefLine());

	this->RTP2({ "FP SYNC STRATEGY", "" });
	this->RL2(this->getFlightPlanSyncStrategyLine());

	this->RTP3({ "UNITS", "" });
	this->RL3(this->getUnitsLine());
}

auto CDUHeavyConfigurationPage::getSimbriefLine() -> vector<string> {
	const auto isSimbriefFilled = !B78XHConfiguration::simbrief::username().empty() || B78XHConfiguration::simbrief::userid() != -1;
	this->rsk1Event = [this]() {
		this->switchPage(CDUPageType::HEAVY_SIMBRIEF_CONFIGURATION);
	};
	if(isSimbriefFilled) {
		return  { "FILLED", "cgreen" };
	}
	return { "NOT FILLED", "" };
}

auto CDUHeavyConfigurationPage::getFlightPlanSyncStrategyLine() -> vector<vector<string>> {
	const auto strategy = B78XHConfiguration::general::flightPlanSyncStrategy();
	this->rsk2Event = [strategy]()-> void {
		B78XHConfiguration::general::setFlightPlanSyncStrategy((strategy == FPSyncStrategyType::NONE ? FPSyncStrategyType::ONEWAY : FPSyncStrategyType::NONE));
	};

	if(strategy == FPSyncStrategyType::NONE) {
		return { {"NONE", "cgreen"}, {"←→", ""},{"ONEWAY", ""} };
	}

	return { {"NONE", ""}, {"←→", ""},{"ONEWAY", "cgreen"}};
}

auto CDUHeavyConfigurationPage::getUnitsLine() -> vector<vector<string>> {
	const auto units = B78XHConfiguration::general::units();
	this->rsk3Event = [units]()-> void {
		B78XHConfiguration::general::setUnits((units == AircraftUnitsType::IMPERIAL ? AircraftUnitsType::METRIC : AircraftUnitsType::IMPERIAL));
	};

	if (units == AircraftUnitsType::IMPERIAL) {
		return { {"IMPERIAL", "cgreen"}, {"←→", ""},{"METRIC", ""} };
	}

	return { {"IMPERIAL", ""}, {"←→", ""}, {"METRIC", "cgreen"}};
}
