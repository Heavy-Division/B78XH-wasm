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
#include "ILSBeacon.h"
#include "NavBeacon.h"
#include "NavRadioEnums.h"
#include "VORBeacon.h"

class RadioNav {
	public:
		/*
		 * Returns tuned beacon
		 * @param Index of NavEquipment
		 * @param Returns only valid beacons
		 * @return Reference to beacon tuned in equipment
		 */
		auto getBeacon(NavEquipmentIndex index, bool onlyValid = true) -> NavBeacon&;
		/*
		 * Returns best tuned ILS beacon
		 * @param Should prefer navSource
		 * @return Reference to beacon tuned in equipment
		 */
		auto getBestILSBeacon(UseNavSource useNavSource = UseNavSource::YES) -> NavBeacon&;
		/*
		 * Returns best tuned VOR beacon
		 * @param Should prefer navSource
		 * @return Reference to beacon tuned in equipment
		 */
		auto getBestVORBeacon(UseNavSource useNavSource = UseNavSource::YES) -> NavBeacon&;

		auto swapBeaconFrequencies(NavEquipmentIndex navType) -> void;
		auto setBeaconFrequency(NavEquipmentIndex navType, double frequency, bool Hz = false) -> void;
		auto setBeaconStandbyFrequency(NavEquipmentIndex navType, double frequency, bool Hz = false) -> void;

	private:
		NavBeacon unknownBeacon = NavBeacon(NavEquipmentType::UNKNOWN, NavEquipmentIndex::UNKNOWN);
		ILSBeacon ilsBeacon1 = ILSBeacon(NavEquipmentIndex::ILS1);
		ILSBeacon ilsBeacon2 = ILSBeacon(NavEquipmentIndex::ILS2);
		VORBeacon vorBeacon1 = VORBeacon(NavEquipmentIndex::VOR1);
		VORBeacon vorBeacon2 = VORBeacon(NavEquipmentIndex::VOR2);;
		/*
		 * Returns best beacon
		 * @param Should prefer Nav Source
		 * @param Index of main NavEquipment
		 * @param Index of backup NavEquipment
		 * @return Reference to best Nav beacon
		 */
		auto getBestBeacon(UseNavSource useNavSource, NavEquipmentIndex main, NavEquipmentIndex backup) -> NavBeacon&;
		/*
		 * Returns Nav beacon
		 * @param Index of NavEquipment
		 * @param Should return only valid beacon
		 * @return Reference to Nav beacon
		 */
		auto getEquipment(NavEquipmentIndex index, bool onlyValid = true) -> NavBeacon&;
		/*
		 * Returns Raw Nav beacon
		 * @param Index of NavEquipment
		 * @return Reference to Nav beacon
		 */
		auto getRawEquipment(NavEquipmentIndex index) -> NavBeacon&;
		/*
		 * Converts NavType to NavSource
		 * @param Index of NavEquipment
		 * @return NavSource
		 */
		static auto convertNavTypeToNavSource(NavEquipmentIndex navType) -> NavSource;
};
