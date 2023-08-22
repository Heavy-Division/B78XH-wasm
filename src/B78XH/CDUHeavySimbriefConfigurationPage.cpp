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


#include "CDUHeavySimbriefConfigurationPage.h"
#include "B78XHConfiguration.h"

using std::string;
using std::vector;

auto CDUHeavySimbriefConfigurationPage::preparePage() -> void {
	/*
	 * Left side
	 */
	this->LTP1({ "ROUTE ONLY", "" });
	this->LTP2({ "WITH SID", "" });
	this->LTP3({ "WITH STAR", "" });
	this->LTP4({ "IMPORT STRATEGY", "" });

	this->LL1(this->getRouteOnlyLine());
	this->LL2(this->getWithSIDLine());
	this->LL3(this->getWithSTARLine());
	this->LL4(this->getImportStrategyLine());

	/*
	 * Right side
	 */

	this->RTP1({ "USERNAME", "" });
	this->RTP2({ "USERID", "" });

	this->RLP1(this->getUsernameLine());
	this->RLP2(this->getUseridLine());
}


auto CDUHeavySimbriefConfigurationPage::getRouteOnlyLine() -> vector<vector<string>> {
	const auto routeOnly = B78XHConfiguration::simbrief::routeOnly();

	this->lsk1Event = [routeOnly]()->void {
		B78XHConfiguration::simbrief::setRouteOnly(!routeOnly);
	};

	if(routeOnly) {
		return { {"YES", "cgreen"}, {"←→", ""}, {"NO", ""} };
	}

	return { {"YES", ""}, {"←→", ""}, {"NO", "cgreen"}};
}

auto CDUHeavySimbriefConfigurationPage::getWithSIDLine() -> vector<vector<string>> {
	const auto withSID = B78XHConfiguration::simbrief::withSid();

	this->lsk2Event = [withSID]()->void {
		B78XHConfiguration::simbrief::setWithSid(!withSID);
	};

	if (withSID) {
		return { {"YES", "cgreen"}, {"←→", ""}, {"NO", ""} };
	}

	return { {"YES", ""}, {"←→", ""}, {"NO", "cgreen"} };
}

auto CDUHeavySimbriefConfigurationPage::getWithSTARLine() -> vector<vector<string>> {
	const auto withSTAR = B78XHConfiguration::simbrief::withStar();

	this->lsk3Event = [withSTAR]()->void {
		B78XHConfiguration::simbrief::setWithStar(!withSTAR);
	};
	if (withSTAR) {
		return { {"YES", "cgreen"}, {"←→", ""}, {"NO", ""} };
	}

	return { {"YES", ""}, {"←→", ""}, {"NO", "cgreen"} };
}

auto CDUHeavySimbriefConfigurationPage::getImportStrategyLine() -> vector<vector<string>> {
	const auto strategy = B78XHConfiguration::simbrief::strategy();

	this->lsk4Event = [strategy]()->void {
		B78XHConfiguration::simbrief::setStrategy((strategy == SimbriefImportStrategyType::SB ? SimbriefImportStrategyType::INGAME : SimbriefImportStrategyType::SB));
	};

	if (strategy == SimbriefImportStrategyType::INGAME) {
		return { {"INGAME", "cgreen"}, {"←→", ""}, {"SB", ""} };
	}

	return { {"INGAME", ""}, {"←→", ""}, {"SB", "cgreen"} };
}

auto CDUHeavySimbriefConfigurationPage::getUsernameLine() -> vector<string> {
	const auto username = B78XHConfiguration::simbrief::username();
	if(username.empty()) {
		return { "-----", "" };
	}
	return { username, "" };
}

auto CDUHeavySimbriefConfigurationPage::getUseridLine() -> vector<string> {
	const auto userid = B78XHConfiguration::simbrief::userid();
	if (userid == -1) {
		return { "-----", "" };
	}
	return { std::to_string(userid), "" };
}