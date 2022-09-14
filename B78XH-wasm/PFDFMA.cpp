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


#include "PFDFMA.h"
#include "Simplane.h"
#include "Tools.h"

using Colors = Tools::Colors;

void PFDFMA::draw(NVGcontext* context) {
	drawBackground(context);
	drawTexts(context);
}

void PFDFMA::drawBackground(NVGcontext* context) {
	nvgFillColor(context, nvgRGBA(0, 0, 0, 100));

	nvgBeginPath(context);
	{
		nvgRect(context, 0, 0, 376, 42);
	}
	nvgFill(context);

	constexpr double separatorHorizontalOffset = 376.0 / 3 - 1.5;
	nvgFillColor(context, Colors::white);
	nvgBeginPath(context);
	{
		nvgRect(context,  separatorHorizontalOffset, 0, 3, 42);
		nvgRect(context,  separatorHorizontalOffset * 2, 0, 3, 42);
	}
	nvgFill(context);
}

void PFDFMA::drawTexts(NVGcontext* context) {
	constexpr double textPositionFactor = 376.0 / 6;

	nvgFillColor(context, Colors::green);
	nvgTextAlign(context, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
	nvgFontFace(context, "heavy-fmc");
	nvgFontSize(context, 24.0f);
	nvgTextLetterSpacing(context, -3.0f);
	nvgBeginPath(context);
	{
		nvgText(context, textPositionFactor, 14, resolveActiveThrustMode(), nullptr);
		nvgText(context, (textPositionFactor * 3), 14, resolveActiveRollMode(), nullptr);
		nvgText(context, (textPositionFactor * 5), 14, resolveActivePitchMode(), nullptr);
	}
	nvgFill(context);

	nvgFillColor(context, Colors::white);
	nvgFontSize(context, 18.0f);
	nvgBeginPath(context);
	{
		nvgText(context, textPositionFactor, 35, "", nullptr);
		nvgText(context, textPositionFactor * 3, 35, resolveArmedRollMode(), nullptr);
		nvgText(context, textPositionFactor * 5, 35, resolveArmedPitchMode(), nullptr);
	}
	nvgFill(context);
}

const char* PFDFMA::resolveActiveThrustMode() {
	namespace Autopilot = Simplane::autopilot;
	namespace Aircraft = Simplane::aircraft;

	if(!Autopilot::throttle::areThrottlesArmed()) {
		return ThrottleMode::NONE;
	}

	if(!LVarsGetter::isSpeedActive()) {
		return ThrottleMode::NONE;
	}

	if(static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::TOGA) {
		return ThrottleMode::THR_REF;
	}

	if(Aircraft::state::indicatedAirspeed() < 65) {
		return ThrottleMode::NONE;
	}

	if(static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::IDLE) {
		return ThrottleMode::IDLE;
	}

	if(Autopilot::state::isFLCHActive() && Autopilot::throttle::leftEngineThrottlePosition() < 30) {
		return ThrottleMode::IDLE;
	}

	if(Autopilot::state::isFLCHActive() && Aircraft::state::verticalSpeed() > 100) {
		return ThrottleMode::THR_REF;
	}

	if(static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::HOLD) {
		return ThrottleMode::HOLD;
	}

	if(LVarsGetter::isFLCHActive()) {
		return ThrottleMode::THR_REF;
	}

	if(LVarsGetter::isSpeedActive()) {
		return ThrottleMode::SPD;
	}

	if(static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::CLIMB) {
		return ThrottleMode::THR_REF;
	}

	if(LVarsGetter::isSpeedInterventionActive()) {
		return ThrottleMode::SPD;
	}

	if((Autopilot::throttle::isLeftEngineThrottleArmed() || Autopilot::throttle::isRightEngineThrottleArmed()) &&
		Autopilot::throttle::areThrottlesActive()) {
		return ThrottleMode::THR;
	}

	return ThrottleMode::THR_REF;
}

const char* PFDFMA::resolveActiveRollMode() {
	namespace Autopilot = Simplane::autopilot;

	const bool approachHold = Autopilot::approach::approachHold();
	const bool approachActive = Autopilot::approach::approachActive();

	if(approachHold && approachActive) {
		return (Autopilot::approach::approachType() == SimApproachType::APPROACH_TYPE_RNAV ? RollMode::FAC : RollMode::LOC);
	}

	/*
	 * Missing ROLLOUT
	 */

	if(static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::TOGA) {
		return RollMode::TOGA;
	}

	if(LVarsGetter::isLNAVActive()) {
		return RollMode::LNAV;
	}

	if(Autopilot::state::isMasterActive() || Autopilot::flightDirector::isFlightDirector1Active() ||
		Autopilot::flightDirector::isFlightDirector2Active()) {
		if(LVarsGetter::isLNAVArmed() && static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) ==
			SimThrottleMode::HOLD) {
			return RollMode::TOGA;
		}
	}

	if(Autopilot::heading::headingLock()) {
		return (LVarsGetter::isHeadingHoldActive() ? RollMode::HDG_HOLD : RollMode::HDG_SEL);
	}

	if(Autopilot::state::isMasterActive()) {
		if(Autopilot::heading::headingLock()) {
			if(LVarsGetter::isHeadingHoldActive()) {
				return (LVarsGetter::isTRKModeActive() ? RollMode::TRK_HOLD : RollMode::HDG_HOLD);
			}
			return (LVarsGetter::isTRKModeActive() ? RollMode::TRK_SEL : RollMode::HDG_SEL);
		}
	}

	if(Autopilot::flightDirector::isFlightDirector1Active() && Simplane::aircraft::state::altitudeAboveGround() < 10) {
		return RollMode::TOGA;
	}

	return RollMode::NONE;
}

const char* PFDFMA::resolveArmedRollMode() {
	namespace Autopilot = Simplane::autopilot;

	if(Autopilot::approach::approachHold() && Autopilot::approach::approachArm()) {
		return (Autopilot::approach::approachType() == SimApproachType::APPROACH_TYPE_RNAV ? RollMode::FAC : RollMode::LOC);
	}

	if(LVarsGetter::isLNAVArmed() && !LVarsGetter::isLNAVActive()) {
		return RollMode::LNAV;
	}

	/*
	 * Missing Rollout
	 */

	return RollMode::NONE;
}

const char* PFDFMA::resolveActivePitchMode() {
	namespace Autopilot = Simplane::autopilot;
	namespace Aircraft = Simplane::aircraft;

	const bool approachHold = Autopilot::approach::approachHold();
	const bool approachActive = Autopilot::approach::approachActive();
	const bool glideSlopeHold = Autopilot::glideSlope::glideSlopeHold();
	const bool glideSlopeActive = Autopilot::glideSlope::glideSlopeActive();

	if(approachHold && approachActive && glideSlopeHold && glideSlopeActive) {
		return (Autopilot::approach::approachType() == SimApproachType::APPROACH_TYPE_RNAV ? PitchMode::GP : PitchMode::GS);
	}

	if(static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::TOGA) {
		return PitchMode::TOGA;
	}

	if(LVarsGetter::isVNAVActive()) {
		if(Autopilot::altitude::altitudeLock()) {
			const double indicatedAltitude = Aircraft::state::indicatedAltitude();
			const double cruiseAltitude = LVarsGetter::airlinerCruiseAltitude();
			if(indicatedAltitude > cruiseAltitude + 100) {
				return PitchMode::VNAV_ALT;
			}
			return PitchMode::VNAV_PTH;
		}
		return PitchMode::VNAV_SPD;
	}

	if(static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::HOLD &&
		LVarsGetter::isVNAVArmed()) {
		return PitchMode::TOGA;
	}

	if(LVarsGetter::isFLCHActive()) {
		return PitchMode::FLCH_SPD;
	}

	if(LVarsGetter::isAltitudeHoldActive()) {
		return PitchMode::ALT;
	}

	/**
	 * Missing FLARE
	 */

	if(Autopilot::state::isMasterActive()) {
		if(Autopilot::verticalSpeed::verticalSpeedHold()) {
			return (LVarsGetter::isFPAModeActive() ? PitchMode::FPA : PitchMode::VS);
		}

		if (Autopilot::altitude::altitudeLock()) {
			return PitchMode::ALT;
		}
	}

	if(Autopilot::flightDirector::isFlightDirector1Active() && Aircraft::state::altitudeAboveGround() < 10) {
		return PitchMode::TOGA;
	}

	return PitchMode::NONE;
}

const char* PFDFMA::resolveArmedPitchMode() {
	namespace Autopilot = Simplane::autopilot;

	const bool approachHold = Autopilot::approach::approachHold();
	const bool approachActive = Autopilot::approach::approachActive();
	const bool glideSlopeHold = Autopilot::glideSlope::glideSlopeHold();
	const bool glideSlopeActive = Autopilot::glideSlope::glideSlopeActive();

	if(approachHold && glideSlopeHold && !(approachActive && glideSlopeActive)) {
		if(Autopilot::approach::approachType() == SimApproachType::APPROACH_TYPE_RNAV) {
			return PitchMode::GP;
		} else {
			return PitchMode::GS;
		}
	}

	if(LVarsGetter::isVNAVArmed() && !LVarsGetter::isVNAVActive()) {
		return PitchMode::VNAV;
	}

	return PitchMode::NONE;
}
