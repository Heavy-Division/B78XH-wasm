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


#include <cmath>
#include "CDUNavRadioPage.h"
#include "Systems.h"
#include "fmt/core.h"

using std::string;
using std::vector;

void CDUNavRadioPage::preparePage() {
	/*
	 * Left side
	 */
	this->LTP1({ "VOR L", "" });
	this->LTP2({ "CRS", "" });
	this->LTP3({ "ADF L", "" });
	this->LTP4({ "ILS-GLS", "" });

	this->LL1(this->getVorLLine());
	this->LL2({ {"0","settable"}, {" °", ""}});
	this->LLP3({"890.00","settable"});
	//this->LLP4({"[]/[ ]","settable"});
	this->LL4(this->getIlsLine());
	this->LLP6({"------","settable"});


	/*
	 * Center
	 */

	this->CTP6({ "PRESELECT", "" });

	/*
	 * Right side
	 */

	this->RTP1({ "VOR R", "" });
	this->RTP2({ "CRS", "" });
	this->RTP3({ "ADF R", "" });

	this->RL1(this->getVorRLine());
	this->RL2({ {"0","settable"}, {" °", ""} });
	this->RLP3({ "890.00","settable" });
	this->RLP6({ "------","settable" });
}

auto CDUNavRadioPage::getIlsLine() -> vector<vector<string>> {
	auto beacon = Systems::radioNav.getBeacon(NavEquipmentIndex::ILS1, false);

	/*
	 * PARK -> PARK
	 * A -> AUTO-TUNING
	 * M -> MANUAL
	 */

	std::string ilsMode = "";

	const auto frequency = beacon.getFrequency();
	const auto course = beacon.getCourse();
	std::string ilsValue = "PARK";

	if(frequency >= 108.0 && frequency <= 111.95) {
		ilsValue = fmt::format("{:.2f}/{}", frequency, std::round(course));
		ilsMode = " M";
	}
	return { {ilsValue, "settable"},  {ilsMode ,""}};
}

auto CDUNavRadioPage::getVorLine(NavEquipmentIndex index) -> vector<vector<string>> {
	auto beacon = Systems::radioNav.getBeacon(index, false);
	const auto frequency = beacon.getFrequency();
	if (frequency < 108.0 || frequency > 117.95) {
		return { {"-----", "settable"}};
	}

	const auto ident = (beacon.getIdent().empty() || !beacon.isValid()) ? "---" : beacon.getIdent();
	const auto fixedFrequency = fmt::format("{:.2f}", frequency);
	/*
	 * P -> PROCEDURE
	 * R -> ROUTE
	 * A -> AUTO-TUNING
	 * M -> MANUAL
	 */

	constexpr auto tuningMode = "M";

	if(index == NavEquipmentIndex::VOR1) {
		return { {fixedFrequency, "cgreen|settable"}, {tuningMode, "settable|ssmall"}, {ident, "cgreen|settable"} };
	}

	return {{ident, "cgreen|settable"}, {tuningMode, "settable|ssmall"} , {fixedFrequency, "cgreen|settable"} };
}

auto CDUNavRadioPage::getVorLLine() -> vector<vector<string>> {
	return this->getVorLine(NavEquipmentIndex::VOR1);
}

auto CDUNavRadioPage::getVorRLine() -> vector<vector<string>> {
	return this->getVorLine(NavEquipmentIndex::VOR2);
}