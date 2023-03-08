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
#include "SimEnums.h"
#include "SimConnectData.h"
#include "LVarsGetter.h"
#include "AircraftSpeedLimit.h"
#include "FlapsSpeedLimit.h"
#include "GearsSpeedLimit.h"
#include "algorithm"
#include "IRSState.h"
#include "IRSSwitchState.h"
#include "LVars.h"
#include "NavRadioEnums.h"
#include "fmt/core.h"

namespace Aircraft = SimConnectData::Aircraft;
namespace Autopilot = SimConnectData::Autopilot;
namespace Barometer = SimConnectData::Barometer;

namespace Misc = SimConnectData::Misc;

namespace Simplane {
	namespace comFrequencies {
		auto activeFrequency1() -> double;
		auto activeFrequency2() -> double;
		auto activeFrequency3() -> double;
		auto standbyFrequency1() -> double;
		auto standbyFrequency2() -> double;
		auto standbyFrequency3() -> double;
		auto transmit1() -> bool;
		auto transmit2() -> bool;
		auto transmit3() -> bool;
		auto active_com_id() -> int;
	}

	namespace transponder {
		auto code() -> double;
	}

	namespace aircraft {
		namespace info {
			auto tailID() -> char*;
			auto flightNumber() -> char*;
		}

		namespace state {
			auto isGearOnGround() -> bool;
			auto isGrounded() -> bool;
			auto gearPosition() -> double;
			auto bank() -> double;
			auto pitch() -> double;
			auto indicatedAltitude() -> double;
			auto indicatedAirspeed() -> double;
			auto verticalSpeed() -> double;
			auto altitudeAboveGround() -> double;
			auto flapsHandleIndex() -> double;
			auto latitude() -> double;
			auto longitude() -> double;
			auto headingTrue() -> double;
			auto headingMagnetic() -> double;
			auto stallSpeed() -> double;
			auto stallProtectionMinSpeed() -> double;
			auto stallProtectionMaxSpeed() -> double;
			auto maxSpeed() -> double;
			auto flapsSpeedLimit(double flapsHandleIndex) -> double;
			auto weight() -> double;
			auto maxWeight() -> double;
			auto maxGrossWeight() -> double;
		}
	}

	namespace autopilot {
		namespace state {
			auto isMasterActive() -> bool;
			auto isFLCHActive() -> bool;
			auto isGPSDriven() -> bool;
		}

		namespace flightDirector {
			auto isFlightDirectorActive() -> bool;
			auto isFlightDirector1Active() -> bool;
			auto isFlightDirector2Active() -> bool;
			auto bank() -> double;
			auto pitch() -> double;
		}

		namespace approach {
			auto approachHold() -> bool;
			auto approachActive() -> bool;
			auto approachCaptured() -> bool;
			auto approachArm() -> bool;
			auto approachIsLocalizer() -> bool;
			auto approachType() -> SimApproachType;
			auto approachLoaded() -> bool;
		}

		namespace glideSlope {
			auto glideSlopeHold() -> bool;
			auto glideSlopeActive() -> bool;
			auto glideSlopeArm() -> bool;
		}

		namespace navigation {
			auto backCourseHold() -> bool;
			auto radioNavSource() -> int;
			/*
			 * Deprecated - START
			 */
			auto glideSlopeError(int index) -> double;
			auto glideSlopeError(NavEquipmentIndex index) -> double;
			auto gsi(int index) -> double;
			auto gsi(NavEquipmentIndex index) -> double;
			auto cdi(int index) -> double;
			auto cdi(NavEquipmentIndex index) -> double;
			auto hasNav(int index) -> bool;
			auto hasNav(NavEquipmentIndex index) -> bool;
			auto hasLocalizer(int index) -> bool;
			auto hasLocalizer(NavEquipmentIndex index) -> bool;
			auto hasDme(int index) -> bool;
			auto hasDme(NavEquipmentIndex index) -> bool;
			auto dme(int index) -> double;
			auto dme(NavEquipmentIndex index) -> double;
			auto hasGlideSlope(int index) -> bool;
			auto hasGlideSlope(NavEquipmentIndex index) -> bool;
			auto localizer(int index) -> double;
			auto localizer(NavEquipmentIndex index) -> double;
			auto frequency(int index, bool MHz) -> double;
			auto frequency(NavEquipmentIndex index, bool MHz) -> double;
			auto standbyFrequency(int index, bool MHz) -> double;
			auto standbyFrequency(NavEquipmentIndex index, bool MHz) -> double;
			auto obs(int index) -> double;
			auto obs(NavEquipmentIndex index) -> double;
			auto radial(int index) -> double;
			auto radial(NavEquipmentIndex index) -> double;
			auto name(int index) -> char*;
			auto name(NavEquipmentIndex index) -> char*;
			auto ident(int index) -> char*;
			auto ident(NavEquipmentIndex index) -> char*;
			/*
			 * Deprecated - END
			 */
		}

		namespace throttle {
			auto areThrottlesArmed() -> bool;
			auto isLeftEngineThrottleArmed() -> bool;
			auto isRightEngineThrottleArmed() -> bool;
			auto areThrottlesActive() -> bool;
			auto isLeftEngineThrottleActive() -> bool;
			auto isRightEngineThrottleActive() -> bool;
			auto leftEngineThrottleMode() -> double;
			auto rightEngineThrottleMode() -> double;
			auto leftEngineThrottlePosition() -> double;
			auto rightEngineThrottlePosition() -> double;
		}

		namespace altitude {
			auto altitudeLock() -> bool;
			auto altitudeLockVar() -> double;
			auto altitudeLockVar1() -> double;
			auto altitudeLockVar2() -> double;
			auto altitudeLockVar3() -> double;
			auto altitudeSlotIndex() -> double;
		}

		namespace verticalSpeed {
			auto verticalSpeedHold() -> bool;
			auto verticalSpeedHoldVar() -> double;
			auto verticalSpeedHoldVar1() -> double;
			auto verticalSpeedHoldVar2() -> double;
			auto verticalSpeedHoldVar3() -> double;
			auto verticalSpeedSlotIndex() -> double;
		}

		namespace airspeed {
			auto airspeedHold() -> bool;
			auto airspeedHoldVar() -> double;
			auto airspeedHoldVar1() -> double;
			auto airspeedHoldVar2() -> double;
			auto airspeedHoldVar3() -> double;
			auto airspeedSlotIndex() -> double;
			auto machHold() -> bool;
			auto machHoldVar() -> double;
			auto machHoldVar1() -> double;
			auto machHoldVar2() -> double;
			auto machHoldVar3() -> double;
		}

		namespace heading {
			auto headingLock() -> bool;
			auto headingLockVar() -> double;
			auto headingLockVar1() -> double;
			auto headingLockVar2() -> double;
			auto headingLockVar3() -> double;
		}

		namespace altitude {
			auto indicated() -> double;
		}
	}

	namespace equipment::irs {

		namespace l {
			inline auto isAligned() -> bool {
				return static_cast<IRSState>(LVars::get(LVars::B78XH_IRS_L_STATE).getValue()) == IRSState::ALIGNED;
			}

			inline auto state() -> IRSState {
				return static_cast<IRSState>(LVars::get(LVars::B78XH_IRS_L_STATE).getValue());
			}

			inline auto switchState() -> IRSSwitchState {
				return static_cast<IRSSwitchState>(LVars::get(LVars::B78XH_IRS_L_SWITCH_STATE).getValue());
			}
		}

		namespace r {
			inline auto isAligned() -> bool {
				return static_cast<IRSState>(LVars::get(LVars::B78XH_IRS_R_STATE).getValue()) == IRSState::ALIGNED;
			}

			inline auto state() -> IRSState {
				return static_cast<IRSState>(LVars::get(LVars::B78XH_IRS_R_STATE).getValue());
			}

			inline auto switchState() -> IRSSwitchState {
				return static_cast<IRSSwitchState>(LVars::get(LVars::B78XH_IRS_R_SWITCH_STATE).getValue());
			}
		}

		inline auto isInited() -> bool {
			return LVars::get(LVars::B78XH_IS_IRS_INITED).isValue();
		}

		inline auto setIsInited(bool value) -> void {
			LVarsGetter::setIsIRSInited(value);
		}

		inline auto isAligned() -> bool {
			return l::isAligned() || r::isAligned();
		}

		inline auto forceAlign() {
			LVarsGetter::setIrsLState(IRSState::ALIGNED);
			LVarsGetter::setIrsRState(IRSState::ALIGNED);
			LVarsGetter::setIrsLSwitchState(IRSSwitchState::ON);
			LVarsGetter::setIrsRSwitchState(IRSSwitchState::ON);
			setIsInited(true);

		}
	}

	namespace equipment::radioNav {
		namespace unit1 {
			auto glideSlopeError() -> double;
			auto gsi() -> double;
			auto cdi() -> double;
			auto hasNav() -> bool;
			auto hasLocalizer() -> bool;
			auto hasDme() -> bool;
			auto dme() -> double;
			auto hasGlideSlope() -> bool;
			auto localizer() -> double;
			auto frequency(bool MHz = true) -> double;
			auto standbyFrequency(bool MHz = true) -> double;
			auto obs() -> double;
			auto radial() -> double;
			auto name() -> char*;
			auto ident() -> char*;
		}

		namespace unit2 {
			auto glideSlopeError() -> double;
			auto gsi() -> double;
			auto cdi() -> double;
			auto hasNav() -> bool;
			auto hasLocalizer() -> bool;
			auto hasDme() -> bool;
			auto dme() -> double;
			auto hasGlideSlope() -> bool;
			auto localizer() -> double;
			auto frequency(bool MHz = true) -> double;
			auto standbyFrequency(bool MHz = true) -> double;
			auto obs() -> double;
			auto radial() -> double;
			auto name() -> char*;
			auto ident() -> char*;
		}

		namespace unit3 {
			auto glideSlopeError() -> double;
			auto gsi() -> double;
			auto cdi() -> double;
			auto hasNav() -> bool;
			auto hasLocalizer() -> bool;
			auto hasDme() -> bool;
			auto dme() -> double;
			auto hasGlideSlope() -> bool;
			auto localizer() -> double;
			auto frequency(bool MHz = true) -> double;
			auto standbyFrequency(bool MHz = true) -> double;
			auto obs() -> double;
			auto radial() -> double;
			auto name() -> char*;
			auto ident() -> char*;
		}

		namespace unit4 {
			auto glideSlopeError() -> double;
			auto gsi() -> double;
			auto cdi() -> double;
			auto hasNav() -> bool;
			auto hasLocalizer() -> bool;
			auto hasDme() -> bool;
			auto dme() -> double;
			auto hasGlideSlope() -> bool;
			auto localizer() -> double;
			auto frequency(bool MHz = true) -> double;
			auto standbyFrequency(bool MHz = true) -> double;
			auto obs() -> double;
			auto radial() -> double;
			auto name() -> char*;
			auto ident() -> char*;
		}
	}

	namespace barometer::setting {
		auto kohlsmanHG() -> double;
		auto kohlsmanMB() -> double;
		auto forcedToSTD() -> bool;
		auto isBaroInHPA() -> bool;
		auto decisionHeight() -> double;
		auto decisionAltitudeMSL() -> double;
	}

	namespace misc::time {
		auto absoluteTime() -> double;
		auto zuluTime() -> double;
		auto localMonthOfYear() -> double;
		auto localDayOfMonth() -> double;
		auto localYear() -> double;
	}

	namespace flight {
		auto flightPhase() -> double;
	}

	namespace instruments {
		namespace cdu {
			auto v1() -> double;
			auto v2() -> double;
			auto vR() -> double;
			auto vREF() -> double;
			auto approachFlaps() -> double;
		}

		namespace fmc = cdu;
	}

	namespace environment {
		namespace temperature {
			auto trueAirTemp() -> double;
			auto staticAirTemp() -> double;
		}
	}

	namespace aircraft::systems {
		namespace powerplant {
			namespace engine_1 {
				auto n1_rpm() -> double;
				auto n2_rpm() -> double;
				auto n1_commanded() -> double;
				auto egt() -> double;
				auto fuelFlowPPH() -> double;
				auto hasCombustion() -> bool;
				auto oilPressure() -> double;
				auto oilTemperature() -> double;
				auto oilQty() -> double;
				auto vibration() -> double;
			};

			namespace engine_2 {
				auto n1_rpm() -> double;
				auto n2_rpm() -> double;
				auto n1_commanded() -> double;
				auto egt() -> double;
				auto fuelFlowPPH() -> double;
				auto hasCombustion() -> bool;
				auto oilPressure() -> double;
				auto oilTemperature() -> double;
				auto oilQty() -> double;
				auto vibration() -> double;
			}
		}

		namespace fuel {
			namespace valves {
				auto eng1_cutoff() -> bool;
				auto eng2_cutoff() -> bool;
			}

			auto total_lbs() -> double;
			
		}
	}
}

inline auto Simplane::comFrequencies::activeFrequency1() -> double {
	return SimConnectData::comFrequencies.activeFrequency1;
}

inline auto Simplane::comFrequencies::activeFrequency2() -> double {
	return SimConnectData::comFrequencies.activeFrequency2;
}

inline auto Simplane::comFrequencies::activeFrequency3() -> double {
	return SimConnectData::comFrequencies.activeFrequency3;
}

inline auto Simplane::comFrequencies::standbyFrequency1() -> double {
	return SimConnectData::comFrequencies.standbyFrequency1;
}

inline auto Simplane::comFrequencies::standbyFrequency2() -> double {
	return SimConnectData::comFrequencies.standbyFrequency2;
}

inline auto Simplane::comFrequencies::standbyFrequency3() -> double {
	return SimConnectData::comFrequencies.standbyFrequency3;
}

inline auto Simplane::comFrequencies::transmit1() -> bool {
	return static_cast<bool>(SimConnectData::comFrequencies.transmit1);
}

inline auto Simplane::comFrequencies::transmit2() -> bool {
	return static_cast<bool>(SimConnectData::comFrequencies.transmit2);
}

inline auto Simplane::comFrequencies::transmit3() -> bool {
	return static_cast<bool>(SimConnectData::comFrequencies.transmit3);
}

inline auto Simplane::comFrequencies::active_com_id() -> int {
	if (transmit1()) {
		return 1;
	}
	if (transmit2()) {
		return 2;
	}
	if (transmit3()) {
		return 3;
	}

	return 0;
}

inline auto Simplane::transponder::code() -> double {
	return SimConnectData::transponder.code;
}

inline auto Simplane::aircraft::info::tailID() -> char* {
	return Aircraft::info.tailID;
}

inline auto Simplane::aircraft::info::flightNumber() -> char* {
	return Aircraft::info.flightNumber;
}

inline auto Simplane::aircraft::state::isGearOnGround() -> bool {
	return static_cast<bool>(Aircraft::state.isGearOnGround);
}

inline auto Simplane::aircraft::state::isGrounded() -> bool {
	return Aircraft::state.altitudeAboveGround < 10;
}

inline auto Simplane::aircraft::state::gearPosition() -> double {
	return Aircraft::state.gearPosition;
}

inline auto Simplane::aircraft::state::bank() -> double {
	return Aircraft::state.bank;
}

inline auto Simplane::aircraft::state::pitch() -> double {
	return Aircraft::state.pitch;
}

inline auto Simplane::aircraft::state::indicatedAltitude() -> double {
	return Aircraft::state.indicatedAltitude;
}

inline auto Simplane::aircraft::state::indicatedAirspeed() -> double {
	return Aircraft::state.indicatedAirspeed;
}

inline auto Simplane::aircraft::state::verticalSpeed() -> double {
	return Aircraft::state.verticalSpeed;
}

inline auto Simplane::aircraft::state::altitudeAboveGround() -> double {
	return Aircraft::state.altitudeAboveGround;
}

inline auto Simplane::aircraft::state::flapsHandleIndex() -> double {
	return Aircraft::state.flapsHandleIndex;
}

inline auto Simplane::aircraft::state::latitude() -> double {
	return Aircraft::state.latitude;
}

inline auto Simplane::aircraft::state::longitude() -> double {
	return Aircraft::state.longitude;
}

inline auto Simplane::aircraft::state::headingTrue() -> double {
	return Aircraft::state.headingTrue;
}

inline auto Simplane::aircraft::state::headingMagnetic() -> double {
	return Aircraft::state.headingMagnetic;
}

inline auto Simplane::aircraft::state::stallSpeed() -> double {
	return LVarsGetter::stallSpeed();
}

inline auto Simplane::aircraft::state::stallProtectionMinSpeed() -> double {
	return LVarsGetter::stallProtectionMinSpeed();
}

inline auto Simplane::aircraft::state::stallProtectionMaxSpeed() -> double {
	return LVarsGetter::stallProtectionMaxSpeed();
}

inline auto Simplane::aircraft::state::maxSpeed() -> double {
	const auto flapsHandleIndex = state::flapsHandleIndex();
	double maxSpeed = flapsSpeedLimit(flapsHandleIndex);

	if (gearPosition() == 0) {
		return maxSpeed;
	}

	return std::min<int>(maxSpeed, GearsSpeedLimit::down);
}

inline auto Simplane::aircraft::state::flapsSpeedLimit(double flapsHandleIndex) -> double {
	double maxSpeed;
	switch (static_cast<int>(flapsHandleIndex)) {
		case 0: {
			maxSpeed = FlapsSpeedLimit::Flaps0;
		}
		break;
		case 1: {
			maxSpeed = FlapsSpeedLimit::Flaps1;
		}
		break;
		case 2: {
			maxSpeed = FlapsSpeedLimit::Flaps2;
		}
		break;
		case 3: {
			maxSpeed = FlapsSpeedLimit::Flaps3;
		}
		break;
		case 4: {
			maxSpeed = FlapsSpeedLimit::Flaps4;
		}
		break;
		case 5: {
			maxSpeed = FlapsSpeedLimit::Flaps5;
		}
		break;
		case 6: {
			maxSpeed = FlapsSpeedLimit::Flaps6;
		}
		break;
		case 7: {
			maxSpeed = FlapsSpeedLimit::Flaps7;
		}
		break;
		case 8: {
			maxSpeed = FlapsSpeedLimit::Flaps8;
		}
		break;
		case 9: {
			maxSpeed = FlapsSpeedLimit::Flaps9;
		}
		break;
		default: {
			maxSpeed = AircraftSpeedLimit::Vno;
		}
	}
	return maxSpeed;
}

inline auto Simplane::aircraft::state::weight() -> double {
	return Aircraft::state.weight;
}

inline auto Simplane::aircraft::state::maxWeight() -> double {
	return Aircraft::state.maxWeight;
}

inline auto Simplane::aircraft::state::maxGrossWeight() -> double {
	return maxWeight();
}

inline auto Simplane::autopilot::state::isMasterActive() -> bool {
	return static_cast<bool>(Autopilot::state.master);
}

inline auto Simplane::autopilot::state::isFLCHActive() -> bool {
	return static_cast<bool>(Autopilot::state.isFLCHActive);
}

inline auto Simplane::autopilot::state::isGPSDriven() -> bool {
	return static_cast<bool>(Autopilot::state.isGPSDriven);
}

inline auto Simplane::autopilot::flightDirector::isFlightDirectorActive() -> bool {
	return static_cast<bool>(Autopilot::flightDirector.isFlightDirectorActive);
}

inline auto Simplane::autopilot::flightDirector::isFlightDirector1Active() -> bool {
	return static_cast<bool>(Autopilot::flightDirector.isFlightDirector1Active);
}

inline auto Simplane::autopilot::flightDirector::isFlightDirector2Active() -> bool {
	return static_cast<bool>(Autopilot::flightDirector.isFlightDirector2Active);
}

inline auto Simplane::autopilot::flightDirector::bank() -> double {
	return Autopilot::flightDirector.bank;
}

inline auto Simplane::autopilot::flightDirector::pitch() -> double {
	return Autopilot::flightDirector.pitch;
}

inline auto Simplane::autopilot::approach::approachHold() -> bool {
	return static_cast<bool>(Autopilot::approach.approachHold);
}

inline auto Simplane::autopilot::approach::approachActive() -> bool {
	return static_cast<bool>(Autopilot::approach.approachActive);
}

inline auto Simplane::autopilot::approach::approachCaptured() -> bool {
	return static_cast<bool>(Autopilot::approach.approachCaptured);
}

inline auto Simplane::autopilot::approach::approachArm() -> bool {
	if (static_cast<bool>(Autopilot::approach.approachArm)) {
		return true;
	}

	if (static_cast<bool>(Autopilot::approach.approachActive) && (static_cast<bool>(Autopilot::state.isGPSDriven) || !
		static_cast<bool>(Autopilot::approach.approachCaptured))) {
		return true;
	}
	return false;
}

inline auto Simplane::autopilot::approach::approachIsLocalizer() -> bool {
	return static_cast<bool>(Autopilot::approach.approachIsLocalizer);
}

inline auto Simplane::autopilot::approach::approachType() -> SimApproachType {
	return static_cast<SimApproachType>(Autopilot::approach.approachType);
}

inline auto Simplane::autopilot::approach::approachLoaded() -> bool {
	return static_cast<bool>(Autopilot::approach.approachIsLoaded);
}

inline auto Simplane::autopilot::glideSlope::glideSlopeHold() -> bool {
	return static_cast<bool>(Autopilot::glideSlope.glideSlopeHold);
}

inline auto Simplane::autopilot::glideSlope::glideSlopeActive() -> bool {
	return static_cast<bool>(Autopilot::glideSlope.glideSlopeActive);
}

inline auto Simplane::autopilot::glideSlope::glideSlopeArm() -> bool {
	return static_cast<bool>(Autopilot::glideSlope.glideSlopeArm);
}

inline auto Simplane::autopilot::navigation::backCourseHold() -> bool {
	return static_cast<bool>(Autopilot::navigation.backCourseHold);
}

inline auto Simplane::autopilot::navigation::radioNavSource() -> int {
	return static_cast<int>(aircraft_varget(get_aircraft_var_enum("RADIONAV_SOURCE"), get_units_enum("Number"), 0));
}

inline auto Simplane::autopilot::navigation::glideSlopeError(int index) -> double {
	switch (index) {
		case 1:
			return SimConnectData::Equipment::RadioNav::unit1.glideSlopeError;
		case 2:
			return SimConnectData::Equipment::RadioNav::unit2.glideSlopeError;
		case 3:
			return SimConnectData::Equipment::RadioNav::unit3.glideSlopeError;
		case 4:
			return SimConnectData::Equipment::RadioNav::unit4.glideSlopeError;
		default:
			return 0.0;
	}
}

inline auto Simplane::autopilot::navigation::glideSlopeError(NavEquipmentIndex index) -> double {
	return glideSlopeError(static_cast<int>(index));
}

inline auto Simplane::autopilot::navigation::gsi(int index) -> double {
	switch (index) {
		case 1:
			return SimConnectData::Equipment::RadioNav::unit1.gsi;
		case 2:
			return SimConnectData::Equipment::RadioNav::unit2.gsi;
		case 3:
			return SimConnectData::Equipment::RadioNav::unit3.gsi;
		case 4:
			return SimConnectData::Equipment::RadioNav::unit4.gsi;
		default:
			return 0.0;
	}
}

inline auto Simplane::autopilot::navigation::gsi(NavEquipmentIndex index) -> double {
	return gsi(static_cast<int>(index));
}

inline auto Simplane::autopilot::navigation::cdi(int index) -> double {
	switch (index) {
		case 1:
			return SimConnectData::Equipment::RadioNav::unit1.cdi;
		case 2:
			return SimConnectData::Equipment::RadioNav::unit2.cdi;
		case 3:
			return SimConnectData::Equipment::RadioNav::unit3.cdi;
		case 4:
			return SimConnectData::Equipment::RadioNav::unit4.cdi;
		default:
			return 0.0;
	}
}

inline auto Simplane::autopilot::navigation::cdi(NavEquipmentIndex index) -> double {
	return cdi(static_cast<int>(index));
}

inline auto Simplane::autopilot::navigation::hasNav(int index) -> bool {
	switch (index) {
		case 1:
			return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit1.hasNav);
		case 2:
			return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit2.hasNav);
		case 3:
			return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit3.hasNav);
		case 4:
			return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit4.hasNav);
		default:
			return false;
	}
}

inline auto Simplane::autopilot::navigation::hasNav(NavEquipmentIndex index) -> bool {
	return hasNav(static_cast<int>(index));
}

inline auto Simplane::autopilot::navigation::hasLocalizer(int index) -> bool {
	switch (index) {
		case 1:
			return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit1.hasLocalizer);
		case 2:
			return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit2.hasLocalizer);
		case 3:
			return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit3.hasLocalizer);
		case 4:
			return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit4.hasLocalizer);
		default:
			return false;
	}
}

inline auto Simplane::autopilot::navigation::hasLocalizer(NavEquipmentIndex index) -> bool {
	return hasLocalizer(static_cast<int>(index));
}

inline auto Simplane::autopilot::navigation::hasDme(int index) -> bool {
	switch (index) {
		case 1:
			return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit1.hasDme);
		case 2:
			return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit2.hasDme);
		case 3:
			return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit3.hasDme);
		case 4:
			return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit4.hasDme);
		default:
			return false;
	}
}

inline auto Simplane::autopilot::navigation::hasDme(NavEquipmentIndex index) -> bool {
	return hasDme(static_cast<int>(index));
}

inline auto Simplane::autopilot::navigation::dme(int index) -> double {
	switch (index) {
		case 1:
			return SimConnectData::Equipment::RadioNav::unit1.dme;
		case 2:
			return SimConnectData::Equipment::RadioNav::unit2.dme;
		case 3:
			return SimConnectData::Equipment::RadioNav::unit3.dme;
		case 4:
			return SimConnectData::Equipment::RadioNav::unit4.dme;
		default:
			return 0.0;
	}
}

inline auto Simplane::autopilot::navigation::dme(NavEquipmentIndex index) -> double {
	return dme(static_cast<int>(index));
}

inline auto Simplane::autopilot::navigation::hasGlideSlope(int index) -> bool {
	switch (index) {
		case 1:
			return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit1.hasGlideSlope);
		case 2:
			return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit2.hasGlideSlope);
		case 3:
			return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit3.hasGlideSlope);
		case 4:
			return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit4.hasGlideSlope);
		default:
			return false;
	}
}

inline auto Simplane::autopilot::navigation::hasGlideSlope(NavEquipmentIndex index) -> bool {
	return hasGlideSlope(static_cast<int>(index));
}

inline auto Simplane::autopilot::navigation::frequency(int index, bool MHz = false) -> double {
	switch (index) {
		case 1:
			return SimConnectData::Equipment::RadioNav::unit1.activeFrequency / (MHz ? 1000000 : 1);
		case 2:
			return SimConnectData::Equipment::RadioNav::unit2.activeFrequency / (MHz ? 1000000 : 1);
		case 3:
			return SimConnectData::Equipment::RadioNav::unit3.activeFrequency / (MHz ? 1000000 : 1);
		case 4:
			return SimConnectData::Equipment::RadioNav::unit4.activeFrequency / (MHz ? 1000000 : 1);
		default:
			return 0.0;
	}
}

inline auto Simplane::autopilot::navigation::frequency(NavEquipmentIndex index, bool MHz) -> double {
	return frequency(static_cast<int>(index), MHz);
}

inline auto Simplane::autopilot::navigation::standbyFrequency(int index, bool MHz) -> double {
	switch (index) {
		case 1:
			return SimConnectData::Equipment::RadioNav::unit1.standbyFrequency / (MHz ? 1000000 : 1);
		case 2:
			return SimConnectData::Equipment::RadioNav::unit2.standbyFrequency / (MHz ? 1000000 : 1);
		case 3:
			return SimConnectData::Equipment::RadioNav::unit3.standbyFrequency / (MHz ? 1000000 : 1);
		case 4:
			return SimConnectData::Equipment::RadioNav::unit4.standbyFrequency / (MHz ? 1000000 : 1);
		default:
			return 0.0;
	}
}

inline auto Simplane::autopilot::navigation::standbyFrequency(NavEquipmentIndex index, bool MHz) -> double {
	return standbyFrequency(static_cast<int>(index), MHz);
}

inline auto Simplane::autopilot::navigation::obs(int index) -> double {
	switch (index) {
		case 1:
			return SimConnectData::Equipment::RadioNav::unit1.obs;
		case 2:
			return SimConnectData::Equipment::RadioNav::unit2.obs;
		case 3:
			return SimConnectData::Equipment::RadioNav::unit3.obs;
		case 4:
			return SimConnectData::Equipment::RadioNav::unit4.obs;
		default:
			return 0.0;
	}
}

inline auto Simplane::autopilot::navigation::obs(NavEquipmentIndex index) -> double {
	return obs(static_cast<int>(index));
}

inline auto Simplane::autopilot::navigation::radial(int index) -> double {
	switch (index) {
		case 1:
			return SimConnectData::Equipment::RadioNav::unit1.radial;
		case 2:
			return SimConnectData::Equipment::RadioNav::unit2.radial;
		case 3:
			return SimConnectData::Equipment::RadioNav::unit3.radial;
		case 4:
			return SimConnectData::Equipment::RadioNav::unit4.radial;
		default:
			return 0.0;
	}
}

inline auto Simplane::autopilot::navigation::radial(NavEquipmentIndex index) -> double {
	return radial(static_cast<int>(index));
}

inline auto Simplane::autopilot::navigation::name(int index) -> char* {
	switch (index) {
		case 1:
			return SimConnectData::Equipment::RadioNav::unit1.name;
		case 2:
			return SimConnectData::Equipment::RadioNav::unit2.name;
		case 3:
			return SimConnectData::Equipment::RadioNav::unit3.name;
		case 4:
			return SimConnectData::Equipment::RadioNav::unit4.name;
		default:
			return SimConnectData::Equipment::RadioNav::unit1.name;
	}
}

inline auto Simplane::autopilot::navigation::name(NavEquipmentIndex index) -> char* {
	return name(static_cast<int>(index));
}

inline auto Simplane::autopilot::navigation::ident(int index) -> char* {

	switch (index) {
		case 1:
			return SimConnectData::Equipment::RadioNav::unit1.ident;
		case 2:
			return SimConnectData::Equipment::RadioNav::unit2.ident;
		case 3:
			return SimConnectData::Equipment::RadioNav::unit3.ident;
		case 4:
			return SimConnectData::Equipment::RadioNav::unit4.ident;
		default:
			return SimConnectData::Equipment::RadioNav::unit1.ident;
	}
}

inline auto Simplane::autopilot::navigation::ident(NavEquipmentIndex index) -> char* {
	return ident(static_cast<int>(index));
}

inline auto Simplane::autopilot::navigation::localizer(int index) -> double {
	switch (index) {
		case 1:
			return SimConnectData::Equipment::RadioNav::unit1.localizer;
		case 2:
			return SimConnectData::Equipment::RadioNav::unit2.localizer;
		case 3:
			return SimConnectData::Equipment::RadioNav::unit3.localizer;
		case 4:
			return SimConnectData::Equipment::RadioNav::unit4.localizer;
		default:
			return 0.0;
	}
}

inline auto Simplane::autopilot::navigation::localizer(NavEquipmentIndex index) -> double {
	return localizer(static_cast<int>(index));
}

inline auto Simplane::autopilot::throttle::areThrottlesArmed() -> bool {
	return static_cast<bool>(Autopilot::throttle.areThrottlesArmed);
}

inline auto Simplane::autopilot::throttle::isLeftEngineThrottleArmed() -> bool {
	return static_cast<bool>(Autopilot::throttle.isLeftEngineThrottleArmed);
}

inline auto Simplane::autopilot::throttle::isRightEngineThrottleArmed() -> bool {
	return static_cast<bool>(Autopilot::throttle.isRightEngineThrottleArmed);
}

inline auto Simplane::autopilot::throttle::areThrottlesActive() -> bool {
	return static_cast<bool>(Autopilot::throttle.areThrottlesActive);
}

inline auto Simplane::autopilot::throttle::isLeftEngineThrottleActive() -> bool {
	return static_cast<bool>(Autopilot::throttle.isLeftEngineThrottleActive);
}

inline auto Simplane::autopilot::throttle::isRightEngineThrottleActive() -> bool {
	return static_cast<bool>(Autopilot::throttle.isRightEngineThrottleActive);
}

inline auto Simplane::autopilot::throttle::leftEngineThrottleMode() -> double {
	return Autopilot::throttle.leftEngineThrottleMode;
}

inline auto Simplane::autopilot::throttle::rightEngineThrottleMode() -> double {
	return Autopilot::throttle.rightEngineThrottleMode;
}

inline auto Simplane::autopilot::throttle::leftEngineThrottlePosition() -> double {
	return Autopilot::throttle.leftEngineThrottlePosition;
}

inline auto Simplane::autopilot::throttle::rightEngineThrottlePosition() -> double {
	return Autopilot::throttle.rightEngineThrottlePosition;
}

inline auto Simplane::autopilot::altitude::altitudeLock() -> bool {
	return static_cast<bool>(Autopilot::altitude.altitudeLock);
}

inline auto Simplane::autopilot::altitude::altitudeLockVar() -> double {
	return Autopilot::altitude.altitudeLockVar;
}

inline auto Simplane::autopilot::altitude::altitudeLockVar1() -> double {
	return Autopilot::altitude.altitudeLockVar1;
}

inline auto Simplane::autopilot::altitude::altitudeLockVar2() -> double {
	return Autopilot::altitude.altitudeLockVar2;
}

inline auto Simplane::autopilot::altitude::altitudeLockVar3() -> double {
	return Autopilot::altitude.altitudeLockVar3;
}

inline auto Simplane::autopilot::altitude::altitudeSlotIndex() -> double {
	return Autopilot::altitude.altitudeSlotIndex;
}

inline auto Simplane::autopilot::verticalSpeed::verticalSpeedHold() -> bool {
	return static_cast<bool>(Autopilot::verticalSpeed.verticalSpeedHold);
}

inline auto Simplane::autopilot::verticalSpeed::verticalSpeedHoldVar() -> double {
	return Autopilot::verticalSpeed.verticalSpeedHoldVar;
}

inline auto Simplane::autopilot::verticalSpeed::verticalSpeedHoldVar1() -> double {
	return Autopilot::verticalSpeed.verticalSpeedHoldVar1;
}

inline auto Simplane::autopilot::verticalSpeed::verticalSpeedHoldVar2() -> double {
	return Autopilot::verticalSpeed.verticalSpeedHoldVar2;
}

inline auto Simplane::autopilot::verticalSpeed::verticalSpeedHoldVar3() -> double {
	return Autopilot::verticalSpeed.verticalSpeedHoldVar3;
}

inline auto Simplane::autopilot::verticalSpeed::verticalSpeedSlotIndex() -> double {
	return Autopilot::verticalSpeed.verticalSpeedSlotIndex;
}

inline auto Simplane::autopilot::airspeed::airspeedHold() -> bool {
	return static_cast<bool>(Autopilot::airspeed.airspeedHold);
}

inline auto Simplane::autopilot::airspeed::airspeedHoldVar() -> double {
	return Autopilot::airspeed.airspeedHoldVar;
}

inline auto Simplane::autopilot::airspeed::airspeedHoldVar1() -> double {
	return Autopilot::airspeed.airspeedHoldVar1;
}

inline auto Simplane::autopilot::airspeed::airspeedHoldVar2() -> double {
	return Autopilot::airspeed.airspeedHoldVar2;
}

inline auto Simplane::autopilot::airspeed::airspeedHoldVar3() -> double {
	return Autopilot::airspeed.airspeedHoldVar3;
}

inline auto Simplane::autopilot::airspeed::airspeedSlotIndex() -> double {
	return Autopilot::airspeed.airspeedSlotIndex;
}

inline auto Simplane::autopilot::airspeed::machHold() -> bool {
	return static_cast<bool>(Autopilot::airspeed.machHold);
}

inline auto Simplane::autopilot::airspeed::machHoldVar() -> double {
	return Autopilot::airspeed.machHoldVar;
}

inline auto Simplane::autopilot::airspeed::machHoldVar1() -> double {
	return Autopilot::airspeed.machHoldVar1;
}

inline auto Simplane::autopilot::airspeed::machHoldVar2() -> double {
	return Autopilot::airspeed.machHoldVar2;
}

inline auto Simplane::autopilot::airspeed::machHoldVar3() -> double {
	return Autopilot::airspeed.machHoldVar3;
}

inline auto Simplane::autopilot::heading::headingLock() -> bool {
	return static_cast<bool>(Autopilot::heading.headingLock);
}

inline auto Simplane::autopilot::heading::headingLockVar() -> double {
	return Autopilot::heading.headingLockVar;
}

inline auto Simplane::autopilot::heading::headingLockVar1() -> double {
	return Autopilot::heading.headingLockVar1;
}

inline auto Simplane::autopilot::heading::headingLockVar2() -> double {
	return Autopilot::heading.headingLockVar2;
}

inline auto Simplane::autopilot::heading::headingLockVar3() -> double {
	return Autopilot::heading.headingLockVar3;
}

inline auto Simplane::barometer::setting::kohlsmanHG() -> double {
	return Barometer::setting.kohlsmanHG;
}

inline auto Simplane::barometer::setting::kohlsmanMB() -> double {
	return Barometer::setting.kohlsmanMB;
}

inline auto Simplane::barometer::setting::forcedToSTD() -> bool {
	return LVars::get(LVars::XMLVAR_Baro1_forcedToSTD).isValue();
}

inline auto Simplane::barometer::setting::isBaroInHPA() -> bool {
	return LVars::get(LVars::XMLVAR_Baro_Selector_HPA_1).isValue();
}

inline auto Simplane::barometer::setting::decisionHeight() -> double {
	return Barometer::setting.decisionHeight;
}

inline auto Simplane::barometer::setting::decisionAltitudeMSL() -> double {
	return Barometer::setting.decisionAltitudeMSL;
}

inline auto Simplane::misc::time::absoluteTime() -> double {
	return Misc::time.absoluteTime;
}

inline auto Simplane::misc::time::zuluTime() -> double {
	return Misc::time.zuluTime;
}

inline auto Simplane::misc::time::localMonthOfYear() -> double {
	return Misc::time.localMonthOfYear;
}

inline auto Simplane::misc::time::localDayOfMonth() -> double {
	return Misc::time.localDayOfMonth;
}

inline auto Simplane::misc::time::localYear() -> double {
	return Misc::time.localMonthOfYear;
}

inline auto Simplane::instruments::cdu::v1() -> double {
	return LVars::get(LVars::AIRLINER_V1_SPEED).getValue();
}

inline auto Simplane::instruments::cdu::v2() -> double {
	return LVars::get(LVars::AIRLINER_V2_SPEED).getValue();
}

inline auto Simplane::instruments::cdu::vR() -> double {
	return LVars::get(LVars::AIRLINER_VR_SPEED).getValue();
}

inline auto Simplane::instruments::cdu::vREF() -> double {
	return LVars::get(LVars::AIRLINER_VREF_SPEED).getValue();
}

inline auto Simplane::instruments::cdu::approachFlaps() -> double {
	return LVars::get(LVars::AIRLINER_APPROACH_FLAPS).getValue();
}

inline auto Simplane::flight::flightPhase() -> double {
	return LVars::get(LVars::AIRLINER_FLIGHT_PHASE).getValue();
}

inline auto Simplane::equipment::radioNav::unit1::glideSlopeError() -> double {
	return SimConnectData::Equipment::RadioNav::unit1.glideSlopeError;
}

inline auto Simplane::equipment::radioNav::unit1::gsi() -> double {
	return SimConnectData::Equipment::RadioNav::unit1.gsi;
}

inline auto Simplane::equipment::radioNav::unit1::cdi() -> double {
	return SimConnectData::Equipment::RadioNav::unit1.cdi;
}

inline auto Simplane::equipment::radioNav::unit1::dme() -> double {
	return SimConnectData::Equipment::RadioNav::unit1.dme;
}

inline auto Simplane::equipment::radioNav::unit1::obs() -> double {
	return SimConnectData::Equipment::RadioNav::unit1.obs;
}

inline auto Simplane::equipment::radioNav::unit1::localizer() -> double {
	return SimConnectData::Equipment::RadioNav::unit1.localizer;
}

inline auto Simplane::equipment::radioNav::unit1::frequency(bool MHz) -> double {
	return SimConnectData::Equipment::RadioNav::unit1.activeFrequency / (MHz ? 1000000 : 1);
}

inline auto Simplane::equipment::radioNav::unit1::standbyFrequency(bool MHz) -> double {
	return SimConnectData::Equipment::RadioNav::unit1.standbyFrequency / (MHz ? 1000000 : 1);
}

inline auto Simplane::equipment::radioNav::unit1::radial() -> double {
	return SimConnectData::Equipment::RadioNav::unit1.radial;
}

inline auto Simplane::equipment::radioNav::unit1::hasNav() -> bool {
	return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit1.hasNav);
}

inline auto Simplane::equipment::radioNav::unit1::hasLocalizer() -> bool {
	return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit1.hasLocalizer);
}

inline auto Simplane::equipment::radioNav::unit1::hasDme() -> bool {
	return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit1.hasDme);
}

inline auto Simplane::equipment::radioNav::unit1::hasGlideSlope() -> bool {
	return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit1.hasGlideSlope);
}

inline auto Simplane::equipment::radioNav::unit1::name() -> char* {
	return SimConnectData::Equipment::RadioNav::unit1.name;
}

inline auto Simplane::equipment::radioNav::unit1::ident() -> char* {
	return SimConnectData::Equipment::RadioNav::unit1.ident;
}

inline auto Simplane::equipment::radioNav::unit2::glideSlopeError() -> double {
	return SimConnectData::Equipment::RadioNav::unit2.glideSlopeError;
}

inline auto Simplane::equipment::radioNav::unit2::gsi() -> double {
	return SimConnectData::Equipment::RadioNav::unit2.gsi;
}

inline auto Simplane::equipment::radioNav::unit2::cdi() -> double {
	return SimConnectData::Equipment::RadioNav::unit2.cdi;
}

inline auto Simplane::equipment::radioNav::unit2::dme() -> double {
	return SimConnectData::Equipment::RadioNav::unit2.dme;
}

inline auto Simplane::equipment::radioNav::unit2::obs() -> double {
	return SimConnectData::Equipment::RadioNav::unit2.obs;
}

inline auto Simplane::equipment::radioNav::unit2::localizer() -> double {
	return SimConnectData::Equipment::RadioNav::unit2.localizer;
}

inline auto Simplane::equipment::radioNav::unit2::frequency(bool MHz) -> double {
	return SimConnectData::Equipment::RadioNav::unit2.activeFrequency / (MHz ? 1000000 : 1);
}

inline auto Simplane::equipment::radioNav::unit2::standbyFrequency(bool MHz) -> double {
	return SimConnectData::Equipment::RadioNav::unit2.standbyFrequency / (MHz ? 1000000 : 1);
}

inline auto Simplane::equipment::radioNav::unit2::radial() -> double {
	return SimConnectData::Equipment::RadioNav::unit2.radial;
}

inline auto Simplane::equipment::radioNav::unit2::hasNav() -> bool {
	return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit2.hasNav);
}

inline auto Simplane::equipment::radioNav::unit2::hasLocalizer() -> bool {
	return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit2.hasLocalizer);
}

inline auto Simplane::equipment::radioNav::unit2::hasDme() -> bool {
	return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit2.hasDme);
}

inline auto Simplane::equipment::radioNav::unit2::hasGlideSlope() -> bool {
	return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit2.hasGlideSlope);
}

inline auto Simplane::equipment::radioNav::unit2::name() -> char* {
	return SimConnectData::Equipment::RadioNav::unit2.name;
}

inline auto Simplane::equipment::radioNav::unit2::ident() -> char* {
	return SimConnectData::Equipment::RadioNav::unit2.ident;
}

inline auto Simplane::equipment::radioNav::unit3::glideSlopeError() -> double {
	return SimConnectData::Equipment::RadioNav::unit3.glideSlopeError;
}

inline auto Simplane::equipment::radioNav::unit3::gsi() -> double {
	return SimConnectData::Equipment::RadioNav::unit3.gsi;
}

inline auto Simplane::equipment::radioNav::unit3::cdi() -> double {
	return SimConnectData::Equipment::RadioNav::unit3.cdi;
}

inline auto Simplane::equipment::radioNav::unit3::dme() -> double {
	return SimConnectData::Equipment::RadioNav::unit3.dme;
}

inline auto Simplane::equipment::radioNav::unit3::obs() -> double {
	return SimConnectData::Equipment::RadioNav::unit3.obs;
}

inline auto Simplane::equipment::radioNav::unit3::localizer() -> double {
	return SimConnectData::Equipment::RadioNav::unit3.localizer;
}

inline auto Simplane::equipment::radioNav::unit3::frequency(bool MHz) -> double {
	return SimConnectData::Equipment::RadioNav::unit3.activeFrequency / (MHz ? 1000000 : 1);
}

inline auto Simplane::equipment::radioNav::unit3::standbyFrequency(bool MHz) -> double {
	return SimConnectData::Equipment::RadioNav::unit3.standbyFrequency / (MHz ? 1000000 : 1);
}

inline auto Simplane::equipment::radioNav::unit3::radial() -> double {
	return SimConnectData::Equipment::RadioNav::unit3.radial;
}

inline auto Simplane::equipment::radioNav::unit3::hasNav() -> bool {
	return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit3.hasNav);
}

inline auto Simplane::equipment::radioNav::unit3::hasLocalizer() -> bool {
	return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit3.hasLocalizer);
}

inline auto Simplane::equipment::radioNav::unit3::hasDme() -> bool {
	return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit3.hasDme);
}

inline auto Simplane::equipment::radioNav::unit3::hasGlideSlope() -> bool {
	return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit3.hasGlideSlope);
}

inline auto Simplane::equipment::radioNav::unit3::name() -> char* {
	return SimConnectData::Equipment::RadioNav::unit3.name;
}

inline auto Simplane::equipment::radioNav::unit3::ident() -> char* {
	return SimConnectData::Equipment::RadioNav::unit3.ident;
}

inline auto Simplane::equipment::radioNav::unit4::glideSlopeError() -> double {
	return SimConnectData::Equipment::RadioNav::unit4.glideSlopeError;
}

inline auto Simplane::equipment::radioNav::unit4::gsi() -> double {
	return SimConnectData::Equipment::RadioNav::unit4.gsi;
}

inline auto Simplane::equipment::radioNav::unit4::cdi() -> double {
	return SimConnectData::Equipment::RadioNav::unit4.cdi;
}

inline auto Simplane::equipment::radioNav::unit4::dme() -> double {
	return SimConnectData::Equipment::RadioNav::unit4.dme;
}

inline auto Simplane::equipment::radioNav::unit4::obs() -> double {
	return SimConnectData::Equipment::RadioNav::unit4.obs;
}

inline auto Simplane::equipment::radioNav::unit4::localizer() -> double {
	return SimConnectData::Equipment::RadioNav::unit4.localizer;
}

inline auto Simplane::equipment::radioNav::unit4::frequency(bool MHz) -> double {
	return SimConnectData::Equipment::RadioNav::unit4.activeFrequency / (MHz ? 1000000 : 1);
}

inline auto Simplane::equipment::radioNav::unit4::standbyFrequency(bool MHz) -> double {
	return SimConnectData::Equipment::RadioNav::unit4.standbyFrequency / (MHz ? 1000000 : 1);
}

inline auto Simplane::equipment::radioNav::unit4::radial() -> double {
	return SimConnectData::Equipment::RadioNav::unit4.radial;
}

inline auto Simplane::equipment::radioNav::unit4::hasNav() -> bool {
	return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit4.hasNav);
}

inline auto Simplane::equipment::radioNav::unit4::hasLocalizer() -> bool {
	return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit4.hasLocalizer);
}

inline auto Simplane::equipment::radioNav::unit4::hasDme() -> bool {
	return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit4.hasDme);
}

inline auto Simplane::equipment::radioNav::unit4::hasGlideSlope() -> bool {
	return static_cast<bool>(SimConnectData::Equipment::RadioNav::unit4.hasGlideSlope);
}

inline auto Simplane::equipment::radioNav::unit4::name() -> char* {
	return SimConnectData::Equipment::RadioNav::unit4.name;
}

inline auto Simplane::equipment::radioNav::unit4::ident() -> char* {
	return SimConnectData::Equipment::RadioNav::unit4.ident;
}

inline auto Simplane::environment::temperature::trueAirTemp() -> double {
	return SimConnectData::environment::temperature.totalAirTemperature;
}

inline auto Simplane::aircraft::systems::powerplant::engine_1::n1_rpm() -> double {
	return SimConnectData::systems::powerplant::engine.engine1_n1;
}

inline auto Simplane::aircraft::systems::powerplant::engine_1::n2_rpm() -> double {
	return SimConnectData::systems::powerplant::engine.engine1_n2;
}

inline auto Simplane::aircraft::systems::powerplant::engine_2::n1_rpm() -> double {
	return SimConnectData::systems::powerplant::engine.engine2_n1;
}
inline auto Simplane::aircraft::systems::powerplant::engine_2::n2_rpm() -> double {
	return SimConnectData::systems::powerplant::engine.engine2_n2;
}

inline auto Simplane::aircraft::systems::powerplant::engine_1::n1_commanded() -> double {

	return SimConnectData::systems::powerplant::engine.engine1_commandedn1;
}

inline auto Simplane::aircraft::systems::powerplant::engine_2::n1_commanded() -> double {
	return 	SimConnectData::systems::powerplant::engine.engine2_commandedn1;
}

inline auto Simplane::aircraft::systems::powerplant::engine_1::egt() -> double {
	return  SimConnectData::systems::powerplant::engine.engine1_egt;
}

inline auto Simplane::aircraft::systems::powerplant::engine_2::egt() -> double {
	return SimConnectData::systems::powerplant::engine.engine2_egt;
}

inline auto Simplane::aircraft::systems::powerplant::engine_1::fuelFlowPPH() -> double {
	return SimConnectData::systems::powerplant::engine.engine1_fuel_flow_pph;
}

inline auto Simplane::aircraft::systems::powerplant::engine_2::fuelFlowPPH() -> double {
	return SimConnectData::systems::powerplant::engine.engine2_fuel_flow_pph;
}

inline auto Simplane::aircraft::systems::powerplant::engine_1::hasCombustion() -> bool {
	return static_cast<bool>(SimConnectData::systems::powerplant::engine.engine1_combustion);
}

inline auto Simplane::aircraft::systems::powerplant::engine_2::hasCombustion() -> bool {
	return static_cast<bool>(SimConnectData::systems::powerplant::engine.engine2_combustion);
}

inline auto Simplane::aircraft::systems::fuel::valves::eng1_cutoff() -> bool {
	return static_cast<bool>(SimConnectData::systems::fuel::fuel.cutoff_eng1);
}

inline auto Simplane::aircraft::systems::fuel::valves::eng2_cutoff() -> bool {
	return static_cast<bool>(SimConnectData::systems::fuel::fuel.cutoff_eng2);
}

inline auto Simplane::aircraft::systems::powerplant::engine_1::oilPressure() -> double {
	return SimConnectData::systems::powerplant::engine.engine1_oil_pressure;
}

inline auto Simplane::aircraft::systems::powerplant::engine_2::oilPressure() -> double {
	return SimConnectData::systems::powerplant::engine.engine2_oil_pressure;
}

inline auto Simplane::aircraft::systems::powerplant::engine_1::oilTemperature() -> double {
	return SimConnectData::systems::powerplant::engine.engine1_oil_temp;
}


inline auto Simplane::aircraft::systems::powerplant::engine_2::oilTemperature() -> double {
	return SimConnectData::systems::powerplant::engine.engine2_oil_temp;
}

inline auto Simplane::aircraft::systems::powerplant::engine_1::oilQty() -> double {
	return SimConnectData::systems::powerplant::engine.engine1_oil_qty * 0.001;
}

inline auto Simplane::aircraft::systems::powerplant::engine_2::oilQty() -> double {
	return SimConnectData::systems::powerplant::engine.engine2_oil_qty * 0.001;
}

inline auto Simplane::aircraft::systems::powerplant::engine_1::vibration() -> double {
	return SimConnectData::systems::powerplant::engine.engine1_vibration;
}

inline auto Simplane::aircraft::systems::powerplant::engine_2::vibration() -> double {
	return SimConnectData::systems::powerplant::engine.engine2_vibration;
}

inline auto Simplane::environment::temperature::staticAirTemp() -> double {
	return  SimConnectData::environment::temperature.staticAirTemperature;
}

inline auto Simplane::aircraft::systems::fuel::total_lbs() -> double {
	return SimConnectData::systems::fuel::fuel.total_lbs;
}
