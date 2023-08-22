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
#include "AircraftUnitsType.h"
#include "FPSyncStrategyType.h"
#include "IRSAlignTimeType.h"
#include "OnOffState.h"
#include "SimbriefImportStrategyType.h"
#include "SimpleINI/SimpleIni.h"

namespace B78XHConfiguration {
	const struct version {
		static auto major() -> int;
		static auto minor() -> int;
	};

	const struct general {
		static auto units() -> AircraftUnitsType;
		static auto setUnits(AircraftUnitsType units) -> void;
		static auto flightPlanSyncStrategy() -> FPSyncStrategyType;
		static auto setFlightPlanSyncStrategy(FPSyncStrategyType strategy) -> void;
	};

	const struct irs {
		static auto alignTimeType() -> IRSAlignTimeType;
		static auto setAlignTimeType(IRSAlignTimeType value) -> void;
	};

	const struct simbrief {
		static auto username() -> std::string;
		static auto setUsername(std::string username) -> void;
		static auto userid() -> int;
		static auto setUserid(int userid) -> void;
		static auto routeOnly() -> bool;
		static auto setRouteOnly(bool state) -> void;
		static auto withSid() -> bool;
		static auto setWithSid(bool state) -> void;
		static auto withStar() -> bool;
		static auto setWithStar(bool state) -> void;
		static auto strategy() -> SimbriefImportStrategyType;
		static auto setStrategy(SimbriefImportStrategyType strategy) -> void;
	};

	inline class Configuration {
		private:
			CSimpleIniA ini;
		public:
			auto load() -> SI_Error;
			auto save() const -> SI_Error;
			auto loadDefaultConfiguration() -> SI_Error;
			auto getValue(const char* section, const char* key, const char* defaultValue = nullptr,
			              bool* hasMultiple = nullptr) const -> const char*;
			friend version;
			friend general;
			friend irs;
			friend simbrief;
	} data;

}
