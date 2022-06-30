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
#include "LVars.h"

namespace Aircraft = SimConnectData::Aircraft;
namespace Autopilot = SimConnectData::Autopilot;
namespace Misc = SimConnectData::Misc;

namespace Simplane {
	namespace comFrequencies {
		double activeFrequency1();
		double activeFrequency2();
		double activeFrequency3();
		double standbyFrequency1();
		double standbyFrequency2();
		double standbyFrequency3();
		bool transmit1();
		bool transmit2();
		bool transmit3();
		int activeCOMId();
	}

	namespace transponder {
		double code();
	}

	namespace aircraft {
		namespace info {
			char* tailID();
			char* flightNumber();
		}
		namespace state {
			bool isGearOnGround();
			double bank();
			double pitch();
			double indicatedAltitude();
			double indicatedAirspeed();
			double verticalSpeed();
			double altitudeAboveGround();
			double flapsHandleIndex();
		}
	}

	namespace autopilot {
		namespace state {
			bool isMasterActive();
			bool isFLCHActive();
		}

		namespace flightDirector {
			bool isFlightDirectorActive();
			bool isFlightDirector1Active();
			bool isFlightDirector2Active();
			double bank();
			double pitch();
		}

		namespace approach {
			bool approachHold();
			bool approachActive();
			bool approachCaptured();
			bool approachArm();
			bool approachIsLocalizer();
			double approachType();
		}

		namespace glideSlope {
			bool glideSlopeHold();
			bool glideSlopeActive();
			bool glideSlopeArm();
		}

		namespace throttle{
			bool areThrottlesArmed();
			bool isLeftEngineThrottleArmed();
			bool isRightEngineThrottleArmed();
			bool areThrottlesActive();
			bool isLeftEngineThrottleActive();
			bool isRightEngineThrottleActive();
			double leftEngineThrottleMode();
			double rightEngineThrottleMode();
			double leftEngineThrottlePosition();
			double rightEngineThrottlePosition();
		}

		namespace altitude {
			bool altitudeLock();
			double altitudeLockVar();
			double altitudeLockVar1();
			double altitudeLockVar2();
			double altitudeLockVar3();
			double altitudeSlotIndex();
		}

		namespace verticalSpeed {
			bool verticaSpeedlHold();
			double verticalSpeedHoldVar();
			double verticalSpeedHoldVar1();
			double verticalSpeedHoldVar2();
			double verticalSpeedHoldVar3();
			double verticalSpeedSlotIndex();
		}

		namespace airspeed {
			bool airspeedHold();
			double airspeedHoldVar();
			double airspeedHoldVar1();
			double airspeedHoldVar2();
			double airspeedHoldVar3();
			double airspeedSlotIndex();
			bool machHold();
			double machHoldVar();
			double machHoldVar1();
			double machHoldVar2();
			double machHoldVar3();
		}

		namespace heading {
			bool headingLock();
			double headingLockVar();
			double headingLockVar1();
			double headingLockVar2();
			double headingLockVar3();
		}
	}

	namespace misc {
		namespace time {
			double absoluteTime();
			double zuluTime();
			double localMonthOfYear();
			double localDayOfMonth();
			double localYear();
		}
	}
}

inline double Simplane::comFrequencies::activeFrequency1() {
	return SimConnectData::comFrequencies.activeFrequency1;
}

inline double Simplane::comFrequencies::activeFrequency2() {
	return SimConnectData::comFrequencies.activeFrequency2;
}

inline double Simplane::comFrequencies::activeFrequency3() {
	return SimConnectData::comFrequencies.activeFrequency3;
}

inline double Simplane::comFrequencies::standbyFrequency1() {
	return SimConnectData::comFrequencies.standbyFrequency1;
}

inline double Simplane::comFrequencies::standbyFrequency2() {
	return SimConnectData::comFrequencies.standbyFrequency2;
}

inline double Simplane::comFrequencies::standbyFrequency3() {
	return SimConnectData::comFrequencies.standbyFrequency3;
}

inline bool Simplane::comFrequencies::transmit1() {
	return static_cast<bool>(SimConnectData::comFrequencies.transmit1);
}

inline bool Simplane::comFrequencies::transmit2() {
	return static_cast<bool>(SimConnectData::comFrequencies.transmit2);
}

inline bool Simplane::comFrequencies::transmit3() {
	return static_cast<bool>(SimConnectData::comFrequencies.transmit3);
}

inline int Simplane::comFrequencies::activeCOMId() {
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

inline double Simplane::transponder::code() {
	return SimConnectData::transponder.code;
}

inline char* Simplane::aircraft::info::tailID() {
	return Aircraft::info.tailID;
}

inline char* Simplane::aircraft::info::flightNumber() {
	return Aircraft::info.flightNumber;
}

inline bool Simplane::aircraft::state::isGearOnGround() {
	return static_cast<bool>(Aircraft::state.isGearOnGround);
}

inline double Simplane::aircraft::state::bank() {
	return Aircraft::state.bank;
}

inline double Simplane::aircraft::state::pitch() {
	return Aircraft::state.pitch;
}

inline double Simplane::aircraft::state::indicatedAltitude() {
	return Aircraft::state.indicatedAltitude;
}

inline double Simplane::aircraft::state::indicatedAirspeed() {
	return Aircraft::state.indicatedAirspeed;
}

inline double Simplane::aircraft::state::verticalSpeed() {
	return Aircraft::state.verticalSpeed;
}

inline double Simplane::aircraft::state::altitudeAboveGround() {
	return Aircraft::state.altitudeAboveGround;
}

inline double Simplane::aircraft::state::flapsHandleIndex() {
	return Aircraft::state.flapsHandleIndex;
}

inline bool Simplane::autopilot::state::isMasterActive() {
	return static_cast<bool>(Autopilot::state.master);
}

inline bool Simplane::autopilot::state::isFLCHActive() {
	return static_cast<bool>(Autopilot::state.isFLCHActive);
}

inline bool Simplane::autopilot::flightDirector::isFlightDirectorActive() {
	return static_cast<bool>(Autopilot::flightDirector.isFlightDirectorActive);
}

inline bool Simplane::autopilot::flightDirector::isFlightDirector1Active() {
	return static_cast<bool>(Autopilot::flightDirector.isFlightDirector1Active);
}

inline bool Simplane::autopilot::flightDirector::isFlightDirector2Active() {
	return static_cast<bool>(Autopilot::flightDirector.isFlightDirector2Active);
}

inline double Simplane::autopilot::flightDirector::bank() {
	return Autopilot::flightDirector.bank;
}

inline double Simplane::autopilot::flightDirector::pitch() {
	return Autopilot::flightDirector.pitch;
}

inline bool Simplane::autopilot::approach::approachHold() {
	return static_cast<bool>(Autopilot::approach.approachHold);
}

inline bool Simplane::autopilot::approach::approachActive() {
	return static_cast<bool>(Autopilot::approach.approachActive);
}

inline bool Simplane::autopilot::approach::approachCaptured() {
	return static_cast<bool>(Autopilot::approach.approachCaptured);
}

inline bool Simplane::autopilot::approach::approachArm() {
	return static_cast<bool>(Autopilot::approach.approachArm);
}

inline bool Simplane::autopilot::approach::approachIsLocalizer() {
	return static_cast<bool>(Autopilot::approach.approachIsLocalizer);
}

inline double Simplane::autopilot::approach::approachType() {
	return static_cast<bool>(Autopilot::approach.approachType);
}

inline bool Simplane::autopilot::glideSlope::glideSlopeHold() {
	return static_cast<bool>(Autopilot::glideSlope.glideSlopeHold);
}

inline bool Simplane::autopilot::glideSlope::glideSlopeActive() {
	return static_cast<bool>(Autopilot::glideSlope.glideSlopeActive);
}

inline bool Simplane::autopilot::glideSlope::glideSlopeArm() {
	return static_cast<bool>(Autopilot::glideSlope.glideSlopeArm);
}

inline bool Simplane::autopilot::throttle::areThrottlesArmed() {
	return static_cast<bool>(Autopilot::throttle.areThrottlesArmed);
}

inline bool Simplane::autopilot::throttle::isLeftEngineThrottleArmed() {
	return static_cast<bool>(Autopilot::throttle.isLeftEngineThrottleArmed);
}

inline bool Simplane::autopilot::throttle::isRightEngineThrottleArmed() {
	return static_cast<bool>(Autopilot::throttle.isRightEngineThrottleArmed);
}

inline bool Simplane::autopilot::throttle::areThrottlesActive() {
	return static_cast<bool>(Autopilot::throttle.areThrottlesActive);
}

inline bool Simplane::autopilot::throttle::isLeftEngineThrottleActive() {
	return static_cast<bool>(Autopilot::throttle.isLeftEngineThrottleActive);
}

inline bool Simplane::autopilot::throttle::isRightEngineThrottleActive() {
	return static_cast<bool>(Autopilot::throttle.isRightEngineThrottleActive);
}

inline double Simplane::autopilot::throttle::leftEngineThrottleMode() {
	return Autopilot::throttle.leftEngineThrottleMode;
}

inline double Simplane::autopilot::throttle::rightEngineThrottleMode() {
	return Autopilot::throttle.rightEngineThrottleMode;
}

inline double Simplane::autopilot::throttle::leftEngineThrottlePosition() {
	return Autopilot::throttle.leftEngineThrottlePosition;
}

inline double Simplane::autopilot::throttle::rightEngineThrottlePosition() {
	return Autopilot::throttle.rightEngineThrottlePosition;
}

inline bool Simplane::autopilot::altitude::altitudeLock() {
	return static_cast<bool>(Autopilot::altitude.altitudeLock);
}

inline double Simplane::autopilot::altitude::altitudeLockVar() {
	return Autopilot::altitude.altitudeLockVar;
}

inline double Simplane::autopilot::altitude::altitudeLockVar1() {
	return Autopilot::altitude.altitudeLockVar1;
}

inline double Simplane::autopilot::altitude::altitudeLockVar2() {
	return Autopilot::altitude.altitudeLockVar2;
}

inline double Simplane::autopilot::altitude::altitudeLockVar3() {
	return Autopilot::altitude.altitudeLockVar3;
}

inline double Simplane::autopilot::altitude::altitudeSlotIndex() {
	return Autopilot::altitude.altitudeSlotIndex;
}

inline bool Simplane::autopilot::verticalSpeed::verticaSpeedlHold() {
	return static_cast<bool>(Autopilot::verticalSpeed.verticaSpeedlHold);
}

inline double Simplane::autopilot::verticalSpeed::verticalSpeedHoldVar() {
	return Autopilot::verticalSpeed.verticalSpeedHoldVar;
}

inline double Simplane::autopilot::verticalSpeed::verticalSpeedHoldVar1() {
	return Autopilot::verticalSpeed.verticalSpeedHoldVar1;
}

inline double Simplane::autopilot::verticalSpeed::verticalSpeedHoldVar2() {
	return Autopilot::verticalSpeed.verticalSpeedHoldVar2;
}

inline double Simplane::autopilot::verticalSpeed::verticalSpeedHoldVar3() {
	return Autopilot::verticalSpeed.verticalSpeedHoldVar3;
}

inline double Simplane::autopilot::verticalSpeed::verticalSpeedSlotIndex() {
	return Autopilot::verticalSpeed.verticalSpeedSlotIndex;
}

inline bool Simplane::autopilot::airspeed::airspeedHold() {
	return static_cast<bool>(Autopilot::airspeed.airspeedHold);
}

inline double Simplane::autopilot::airspeed::airspeedHoldVar() {
	return Autopilot::airspeed.airspeedHoldVar;
}

inline double Simplane::autopilot::airspeed::airspeedHoldVar1() {
	return Autopilot::airspeed.airspeedHoldVar1;
}

inline double Simplane::autopilot::airspeed::airspeedHoldVar2() {
	return Autopilot::airspeed.airspeedHoldVar2;
}

inline double Simplane::autopilot::airspeed::airspeedHoldVar3() {
	return Autopilot::airspeed.airspeedHoldVar3;
}

inline double Simplane::autopilot::airspeed::airspeedSlotIndex() {
	return Autopilot::airspeed.airspeedSlotIndex;
}

inline bool Simplane::autopilot::airspeed::machHold() {
	return static_cast<bool>(Autopilot::airspeed.machHold);
}

inline double Simplane::autopilot::airspeed::machHoldVar() {
	return Autopilot::airspeed.machHoldVar;
}

inline double Simplane::autopilot::airspeed::machHoldVar1() {
	return Autopilot::airspeed.machHoldVar1;
}

inline double Simplane::autopilot::airspeed::machHoldVar2() {
	return Autopilot::airspeed.machHoldVar2;
}

inline double Simplane::autopilot::airspeed::machHoldVar3() {
	return Autopilot::airspeed.machHoldVar3;
}

inline bool Simplane::autopilot::heading::headingLock() {
	return static_cast<bool>(Autopilot::heading.headingLock);
}

inline double Simplane::autopilot::heading::headingLockVar() {
	return Autopilot::heading.headingLockVar;
}

inline double Simplane::autopilot::heading::headingLockVar1() {
	return Autopilot::heading.headingLockVar1;
}

inline double Simplane::autopilot::heading::headingLockVar2() {
	return Autopilot::heading.headingLockVar2;
}

inline double Simplane::autopilot::heading::headingLockVar3() {
	return Autopilot::heading.headingLockVar3;
}

inline double Simplane::misc::time::absoluteTime() {
	return Misc::time.absoluteTime;
}

inline double Simplane::misc::time::zuluTime() {
	return Misc::time.zuluTime;
}

inline double Simplane::misc::time::localMonthOfYear() {
	return Misc::time.localMonthOfYear;
}

inline double Simplane::misc::time::localDayOfMonth() {
	return Misc::time.localDayOfMonth;
}

inline double Simplane::misc::time::localYear() {
	return Misc::time.localMonthOfYear;
}