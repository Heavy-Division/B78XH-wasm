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
#include <string>
#include "NavRadioEnums.h"
#include "Simplane.h"

class NavBeacon {
	public:
		NavBeacon(NavEquipmentType type, NavEquipmentIndex index): id(index), type(type) {

		};

		auto getId() const -> NavEquipmentIndex {
			return this->id;
		}

		auto getType() const -> NavEquipmentType {
			return this->type;
		}

		auto getName() -> std::string {
			return this->name = Simplane::autopilot::navigation::name(this->id);
		}

		auto getIdent() -> std::string {
			return this->ident = Simplane::autopilot::navigation::ident(this->id);
		}

		auto getFrequency() -> double {
			return this->frequency = Simplane::autopilot::navigation::frequency(this->id, true);
		}

		auto getCourse() -> double {
			if (this->type == NavEquipmentType::ILS) {
				this->course = Simplane::autopilot::navigation::localizer(this->id);
			}

			if (this->type == NavEquipmentType::VOR) {
				this->course = Simplane::autopilot::navigation::obs(this->id);
				if (Simplane::autopilot::navigation::backCourseHold()) {
					this->course += 180;
				}
			}

			return this->course;
		}

		auto getRadial() -> double {
			return this->radial = Simplane::autopilot::navigation::radial(this->id);
		}

		auto getCDI() -> double {
			return this->cdi = Simplane::autopilot::navigation::cdi(this->id);
		}

		auto getGlideSlopeError() -> double {
			return this->glideSlopeError = Simplane::autopilot::navigation::glideSlopeError(this->id);
		}

		auto getGSI() -> double {
			return this->gsi = Simplane::autopilot::navigation::gsi(this->id);
		}

		auto getOBS() -> double {
			return this->obs = Simplane::autopilot::navigation::obs(this->id);
		}

		auto getDME() -> double {
			return this->dme = Simplane::autopilot::navigation::dme(this->id);
		}

		auto hasLocalizer() -> bool {
			return this->hasBeaconLocalizer = Simplane::autopilot::navigation::hasLocalizer(this->id);
		}

		auto hasGlideSlope() -> bool {
			return this->hasBeaconGlideSlope = Simplane::autopilot::navigation::hasGlideSlope(this->id);
		}

		auto hasNav() -> bool {
			return this->hasBeaconNav = Simplane::autopilot::navigation::hasNav(this->id);
		}

		auto hasDME() -> bool {
			return this->hasBeaconDME = Simplane::autopilot::navigation::hasDme(this->id);
		}

		auto isValid() -> bool {
			switch (this->type) {
				case NavEquipmentType::VOR: {
					return this->hasNav() && !this->hasLocalizer();
				}
				case NavEquipmentType::ILS: {
					return this->hasLocalizer();
				}
				case NavEquipmentType::UNKNOWN:
				default:
					return false;
			}
		}

		auto reset() -> void {
			this->name = "";
			this->ident = "";
			this->frequency = 0;
			this->course = 0;
			this->radial = 0;
			this->cdi = 0;
			this->gsi = 0;
			this->glideSlopeError = 0;
			this->obs = 0;
			this->dme = 0;
			this->hasBeaconLocalizer = false;
			this->hasBeaconGlideSlope = false;
			this->hasBeaconNav = false;
			this->hasBeaconDME = false;
		};

		auto update() -> void {
			this->name = this->getName();
			this->ident = this->getIdent();
			this->frequency = this->getFrequency();
			this->course = this->getCourse();
			this->radial = this->getRadial();
			this->cdi = this->getCDI();
			this->gsi = this->getGSI();
			this->glideSlopeError = this->getGlideSlopeError();
			this->obs = this->getOBS();
			this->dme = this->getDME();
			this->hasBeaconGlideSlope = this->hasGlideSlope();
			this->hasBeaconLocalizer = this->hasLocalizer();
			this->hasBeaconNav = this->hasNav();
			this->hasBeaconDME = this->hasDME();
		}

	protected:
		NavEquipmentIndex id = NavEquipmentIndex::UNKNOWN;
		NavEquipmentType type = NavEquipmentType::UNKNOWN;
		std::string name = "";
		std::string ident = "";
		double frequency = 0;
		double course = 0;
		double radial = 0;
		double cdi = 0;
		double gsi = 0;
		double glideSlopeError = 0;
		double obs = 0;
		double dme = 0;
		bool hasBeaconLocalizer = false;
		bool hasBeaconGlideSlope = false;
		bool hasBeaconNav = false;
		bool hasBeaconDME = false;
};
