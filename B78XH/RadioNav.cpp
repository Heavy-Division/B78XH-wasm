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


#include "RadioNav.h"

#include <string>

#include "NavRadioEnums.h"
#include "Simplane.h"
#include "KEvents.h"

auto RadioNav::getBeacon(NavEquipmentIndex index, bool onlyValid) -> NavBeacon& {
	return this->getEquipment(index, onlyValid);
}

auto RadioNav::getBestBeacon(UseNavSource useNavSource, NavEquipmentIndex main,
                             NavEquipmentIndex backup) -> NavBeacon& {
	const auto navSource = static_cast<NavSource>(Simplane::autopilot::navigation::radioNavSource());
	const auto mainNavSource = convertNavTypeToNavSource(main);
	const auto backupNavSource = convertNavTypeToNavSource(backup);

	if (navSource != NavSource::AUTO && useNavSource != UseNavSource::NO) {
		if (navSource == mainNavSource) {
			auto beacon = this->getRawEquipment(main);
			if (useNavSource == UseNavSource::YES || beacon.isValid()) {
				return beacon;
			}
		}
		if (navSource == backupNavSource) {
			auto beacon = this->getRawEquipment(backup);
			if (useNavSource == UseNavSource::YES || beacon.isValid()) {
				return beacon;
			}
		}
	}

	auto beacon = this->getRawEquipment(main);
	if (beacon.isValid()) {
		return beacon;
	}

	beacon = this->getRawEquipment(backup);
	if (beacon.isValid()) {
		return beacon;
	}

	return this->getRawEquipment(NavEquipmentIndex::UNKNOWN);
}

auto RadioNav::getBestILSBeacon(UseNavSource useNavSource) -> NavBeacon& {
	return this->getBestBeacon(useNavSource, NavEquipmentIndex::ILS1, NavEquipmentIndex::ILS2);
}

auto RadioNav::getBestVORBeacon(UseNavSource useNavSource) -> NavBeacon& {
	return this->getBestBeacon(useNavSource, NavEquipmentIndex::VOR1, NavEquipmentIndex::VOR2);
}

auto RadioNav::getEquipment(NavEquipmentIndex index, bool onlyValid) -> NavBeacon& {
	NavBeacon& beacon = this->getRawEquipment(index);
	if (onlyValid) {
		if (beacon.isValid()) {
			return beacon;
		}
		this->unknownBeacon.reset();
		return this->unknownBeacon;
	}
	return beacon;
}

auto RadioNav::getRawEquipment(NavEquipmentIndex index) -> NavBeacon& {
	switch (index) {
		case NavEquipmentIndex::VOR1: {
			return this->vorBeacon1;
		}
		case NavEquipmentIndex::VOR2: {
			return this->vorBeacon2;
		}
		case NavEquipmentIndex::ILS1: {
			return this->ilsBeacon1;
		}
		case NavEquipmentIndex::ILS2: {
			return this->ilsBeacon2;
		}
		case NavEquipmentIndex::UNKNOWN:
		default: {
			this->unknownBeacon.reset();
			return this->unknownBeacon;
		}
	}
}

auto RadioNav::convertNavTypeToNavSource(NavEquipmentIndex navType) -> NavSource {
	switch (navType) {
		case NavEquipmentIndex::UNKNOWN: {
			return NavSource::AUTO;
		}
		case NavEquipmentIndex::VOR1: {
			return NavSource::VOR1;
		}
		case NavEquipmentIndex::VOR2: {
			return NavSource::VOR2;
		}
		case NavEquipmentIndex::ILS1: {
			return NavSource::ILS1;
		}
		case NavEquipmentIndex::ILS2: {
			return NavSource::ILS2;
		}
		default: {
			return NavSource::AUTO;
		}
	}
}

auto RadioNav::swapBeaconFrequencies(NavEquipmentIndex navType) -> void {
	const auto kEvent = fmt::format("NAV{}_RADIO_SWAP", static_cast<int>(navType));
	KEvents::execute(kEvent, 1, "Bool");
}

auto RadioNav::setBeaconFrequency(NavEquipmentIndex navType, double frequency, bool Hz) -> void {
	const auto kEvent = fmt::format("NAV{}_RADIO_SET_HZ", static_cast<int>(navType));
	const auto fixedFrequency = (Hz ? frequency : frequency * 1000000);
	KEvents::execute(kEvent, fixedFrequency, "Hz");
}

auto RadioNav::setBeaconStandbyFrequency(NavEquipmentIndex navType, double frequency, bool Hz) -> void {
	const auto kEvent = fmt::format("NAV{}_STBY_SET_HZ", static_cast<int>(navType));
	const auto fixedFrequency = (Hz ? frequency : frequency * 1000000);
	KEvents::execute(kEvent, fixedFrequency, "Hz");
}

auto RadioNav::setBeaconOBS(NavEquipmentIndex navType, double obs) -> void {
	const auto kEvent = fmt::format("VOR{}_SET", static_cast<int>(navType));
	KEvents::execute(kEvent, obs);
}

auto RadioNav::tuneClosestILS() -> void {
	const auto kEvent = fmt::format("NAV1_CLOSE_FREQ_SET");
	KEvents::execute(kEvent, 1, "Bool");
}

auto RadioNav::tuneClosestILS2() -> void {
	const auto kEvent = fmt::format("NAV1_CLOSE_FREQ_SET");
	KEvents::execute(kEvent, 0, "Bool");
}