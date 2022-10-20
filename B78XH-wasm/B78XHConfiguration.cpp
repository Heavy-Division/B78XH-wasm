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


#include "B78XHConfiguration.h"

auto B78XHConfiguration::version::major() -> int {
	return static_cast<int>(data.ini.GetDoubleValue("VERSION", "major", 0));
}

auto B78XHConfiguration::version::minor() -> int {
	return static_cast<int>(data.ini.GetDoubleValue("VERSION", "minor", 0));
}

auto B78XHConfiguration::general::units() -> AircraftUnitsType {
	return static_cast<AircraftUnitsType>(data.ini.GetDoubleValue("GENERAL", "units",
	                                                              static_cast<double>(AircraftUnitsType::IMPERIAL)));
}

auto B78XHConfiguration::general::setUnits(AircraftUnitsType units) -> void {
	data.ini.SetDoubleValue("GENERAL", "units", static_cast<double>(units));
}

auto B78XHConfiguration::general::flightPlanSyncStrategy() -> FPSyncStrategyType {
	return static_cast<FPSyncStrategyType>(data.ini.GetDoubleValue("GENERAL", "fp_sync_strategy",
	                                                               static_cast<double>(FPSyncStrategyType::NONE)));
}

auto B78XHConfiguration::general::setFlightPlanSyncStrategy(FPSyncStrategyType strategy) -> void {
	data.ini.SetDoubleValue("GENERAL", "fp_sync_strategy", static_cast<double>(strategy));
}

auto B78XHConfiguration::irs::alignTimeType() -> IRSAlignTimeType {
	return static_cast<IRSAlignTimeType>(data.ini.GetDoubleValue("IRS", "align_time_type",
	                                                             static_cast<double>(IRSAlignTimeType::REAL)));
}

auto B78XHConfiguration::irs::setAlignTimeType(IRSAlignTimeType value) -> void {
	data.ini.SetDoubleValue("irs", "align_time_type", static_cast<double>(value));
}

auto B78XHConfiguration::simbrief::username() -> std::string {
	return data.ini.GetValue("SIMBRIEF", "username", "");
}

auto B78XHConfiguration::simbrief::setUsername(std::string username) -> void {
	data.ini.SetValue("SIMBRIEF", "username", username.c_str());
}

auto B78XHConfiguration::simbrief::userid() -> int {
	return static_cast<int>(data.ini.GetDoubleValue("SIMBRIEF", "userid", -1));
}

auto B78XHConfiguration::simbrief::setUserid(int userid) -> void {
	data.ini.SetDoubleValue("SIMBRIEF", "userid", userid);
}

auto B78XHConfiguration::simbrief::routeOnly() -> bool {
	return data.ini.GetBoolValue("SIMBRIEF", "route_only", false);
}

auto B78XHConfiguration::simbrief::setRouteOnly(bool state) -> void {
	data.ini.SetBoolValue("SIMBRIEF", "route_only", state);
}

auto B78XHConfiguration::simbrief::withSid() -> bool {
	return data.ini.GetBoolValue("SIMBRIEF", "sid", false);
}

auto B78XHConfiguration::simbrief::setWithSid(bool state) -> void {
	data.ini.SetBoolValue("SIMBRIEF", "sid", state);
}

auto B78XHConfiguration::simbrief::withStar() -> bool {
	return data.ini.GetBoolValue("SIMBRIEF", "star", false);
}

auto B78XHConfiguration::simbrief::setWithStar(bool state) -> void {
	data.ini.SetBoolValue("SIMBRIEF", "star", state);
}

auto B78XHConfiguration::simbrief::strategy() -> SimbriefImportStrategyType {
	return static_cast<SimbriefImportStrategyType>(data.ini.GetDoubleValue("SIMBRIEF", "strategy",
	                                                                       static_cast<double>(
		                                                                       SimbriefImportStrategyType::SB)));
}

auto B78XHConfiguration::simbrief::setStrategy(SimbriefImportStrategyType strategy) -> void {
	data.ini.SetDoubleValue("SIMBRIEF", "strategy", static_cast<double>(strategy));
}

auto B78XHConfiguration::Configuration::load() -> SI_Error {
	auto rc = ini.LoadFile("/work/configuration.cfg");

	if (rc < 0) {
		rc = loadDefaultConfiguration();
		if (rc < 0) {
			return rc;
		}
		rc = save();
	}
	return rc;
}

auto B78XHConfiguration::Configuration::save() const -> SI_Error {
	return ini.SaveFile("/work/configuration.cfg");
}

auto B78XHConfiguration::Configuration::loadDefaultConfiguration() -> SI_Error {
	return ini.LoadFile("./data/defaultConfiguration.cfg");
}

auto B78XHConfiguration::Configuration::getValue(const char* section, const char* key, const char* defaultValue,
                                                 bool* hasMultiple) const -> const char* {
	return ini.GetValue(section, key, defaultValue, hasMultiple);
}
