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


#include "PFDFMAApplication.h"

#include "LVars.h"
#include "Simplane.h"
#include "Tools/Tools.h"

using Colors = Tools::Colors;

void PFDFMAApplication::render(sGaugeDrawData* data) {
	drawBackground();
	drawTexts();
}

void PFDFMAApplication::drawBackground() {
	nvgFillColor(this->nvgContext, nvgRGBA(0, 0, 0, 100));

	nvgBeginPath(this->nvgContext);
	{
		nvgRect(this->nvgContext, 0, 0, 376, 42);
	}
	nvgFill(this->nvgContext);

	constexpr double separatorHorizontalOffset = 376.0 / 3 - 1.5;
	nvgFillColor(this->nvgContext, Colors::white);
	nvgBeginPath(this->nvgContext);
	{
		nvgRect(this->nvgContext, separatorHorizontalOffset, 0, 3, 42);
		nvgRect(this->nvgContext, separatorHorizontalOffset * 2, 0, 3, 42);
	}
	nvgFill(this->nvgContext);
}

void PFDFMAApplication::drawTexts() {
	constexpr double textPositionFactor = 376.0 / 6;

	nvgFillColor(this->nvgContext, Colors::green);
	nvgTextAlign(this->nvgContext, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
	nvgFontFace(this->nvgContext, "heavy-fmc");
	nvgFontSize(this->nvgContext, 24.0f);
	nvgTextLetterSpacing(this->nvgContext, -3.0f);
	nvgBeginPath(this->nvgContext);
	{
		nvgText(this->nvgContext, textPositionFactor, 14, resolveActiveThrustMode(), nullptr);
		nvgText(this->nvgContext, (textPositionFactor * 3), 14, resolveActiveRollMode(), nullptr);
		nvgText(this->nvgContext, (textPositionFactor * 5), 14, resolveActivePitchMode(), nullptr);
	}
	nvgFill(this->nvgContext);

	nvgFillColor(this->nvgContext, Colors::white);
	nvgFontSize(this->nvgContext, 18.0f);
	nvgBeginPath(this->nvgContext);
	{
		nvgText(this->nvgContext, textPositionFactor, 35, "", nullptr);
		nvgText(this->nvgContext, textPositionFactor * 3, 35, resolveArmedRollMode(), nullptr);
		nvgText(this->nvgContext, textPositionFactor * 5, 35, resolveArmedPitchMode(), nullptr);
	}
	nvgFill(this->nvgContext);
}

const char* PFDFMAApplication::resolveActiveThrustMode() {
	namespace Autopilot = Simplane::autopilot;
	namespace Aircraft = Simplane::aircraft;

	if (!Autopilot::throttle::areThrottlesArmed()) {
		return ThrottleMode::NONE;
	}
	
	if (!LVars::get(LVars::AP_SPD_ACTIVE).isValue()) {
		return ThrottleMode::NONE;
	}

	if (static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::TOGA) {
		return ThrottleMode::THR_REF;
	}

	if (Aircraft::state::indicatedAirspeed() < 65) {
		return ThrottleMode::NONE;
	}

	if (static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::IDLE) {
		return ThrottleMode::IDLE;
	}

	if (Autopilot::state::isFLCHActive() && Autopilot::throttle::leftEngineThrottlePosition() < 30) {
		return ThrottleMode::IDLE;
	}

	if (Autopilot::state::isFLCHActive() && Aircraft::state::verticalSpeed() > 100) {
		return ThrottleMode::THR_REF;
	}

	if (static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::HOLD) {
		return ThrottleMode::HOLD;
	}

	if (LVars::get(LVars::AP_FLCH_ACTIVE).isValue()) {
		return ThrottleMode::THR_REF;
	}

	if (LVars::get(LVars::AP_SPD_ACTIVE).isValue()) {
		return ThrottleMode::SPD;
	}

	if (static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::CLIMB) {
		return ThrottleMode::THR_REF;
	}

	if (LVars::get(LVars::AP_SPEED_INTERVENTION_ACTIVE).isValue()) {
		return ThrottleMode::SPD;
	}

	if ((Autopilot::throttle::isLeftEngineThrottleArmed() || Autopilot::throttle::isRightEngineThrottleArmed()) &&
		Autopilot::throttle::areThrottlesActive()) {
		return ThrottleMode::THR;
	}

	return ThrottleMode::THR_REF;
}

const char* PFDFMAApplication::resolveActiveRollMode() {
	namespace Autopilot = Simplane::autopilot;

	const bool approachHold = Autopilot::approach::approachHold();
	const bool approachActive = Autopilot::approach::approachActive();

	if (approachHold && approachActive) {
		return (Autopilot::approach::approachType() == SimApproachType::APPROACH_TYPE_RNAV ? RollMode::FAC : RollMode::LOC);
	}

	/*
	 * Missing ROLLOUT
	 */

	if (static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::TOGA) {
		return RollMode::TOGA;
	}

	if (LVars::get(LVars::AP_LNAV_ACTIVE).isValue()) {
		return RollMode::LNAV;
	}

	if (Autopilot::state::isMasterActive() || Autopilot::flightDirector::isFlightDirector1Active() ||
		Autopilot::flightDirector::isFlightDirector2Active()) {
		if (LVars::get(LVars::AP_LNAV_ARMED).isValue() && static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) ==
			SimThrottleMode::HOLD) {
			return RollMode::TOGA;
		}
	}

	if (Autopilot::heading::headingLock()) {
		return (LVars::get(LVars::AP_HEADING_HOLD_ACTIVE).isValue() ? RollMode::HDG_HOLD : RollMode::HDG_SEL);
	}

	if (Autopilot::state::isMasterActive()) {
		if (Autopilot::heading::headingLock()) {
			if (LVars::get(LVars::AP_HEADING_HOLD_ACTIVE).isValue()) {
				return (LVars::get(LVars::XMLVAR_TRK_MODE_ACTIVE).isValue() ? RollMode::TRK_HOLD : RollMode::HDG_HOLD);
			}
			return (LVars::get(LVars::XMLVAR_TRK_MODE_ACTIVE).isValue() ? RollMode::TRK_SEL : RollMode::HDG_SEL);
		}
	}

	if (Autopilot::flightDirector::isFlightDirector1Active() && Simplane::aircraft::state::altitudeAboveGround() < 10) {
		return RollMode::TOGA;
	}

	return RollMode::NONE;
}

const char* PFDFMAApplication::resolveArmedRollMode() {
	namespace Autopilot = Simplane::autopilot;

	if (Autopilot::approach::approachHold() && Autopilot::approach::approachArm()) {
		return (Autopilot::approach::approachType() == SimApproachType::APPROACH_TYPE_RNAV ? RollMode::FAC : RollMode::LOC);
	}

	if (LVars::get(LVars::AP_LNAV_ARMED).isValue() && !LVars::get(LVars::AP_LNAV_ACTIVE).isValue()) {
		return RollMode::LNAV;
	}

	/*
	 * Missing Rollout
	 */

	return RollMode::NONE;
}

const char* PFDFMAApplication::resolveActivePitchMode() {
	namespace Autopilot = Simplane::autopilot;
	namespace Aircraft = Simplane::aircraft;

	const bool approachHold = Autopilot::approach::approachHold();
	const bool approachActive = Autopilot::approach::approachActive();
	const bool glideSlopeHold = Autopilot::glideSlope::glideSlopeHold();
	const bool glideSlopeActive = Autopilot::glideSlope::glideSlopeActive();

	if (approachHold && approachActive && glideSlopeHold && glideSlopeActive) {
		return (Autopilot::approach::approachType() == SimApproachType::APPROACH_TYPE_RNAV ? PitchMode::GP : PitchMode::GS);
	}

	if (static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::TOGA) {
		return PitchMode::TOGA;
	}

	if (LVars::get(LVars::AP_VNAV_ACTIVE).isValue()) {
		if (Autopilot::altitude::altitudeLock()) {
			const double indicatedAltitude = Aircraft::state::indicatedAltitude();
			const double cruiseAltitude = LVars::get(LVars::AIRLINER_CRUISE_ALTITUDE).getValue();
			if (indicatedAltitude > cruiseAltitude + 100) {
				return PitchMode::VNAV_ALT;
			}
			return PitchMode::VNAV_PTH;
		}
		return PitchMode::VNAV_SPD;
	}

	if (static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::HOLD &&
		LVars::get(LVars::AP_VNAV_ARMED).isValue()) {
		return PitchMode::TOGA;
	}

	if (LVars::get(LVars::AP_FLCH_ACTIVE).isValue()) {
		return PitchMode::FLCH_SPD;
	}

	if (LVars::get(LVars::AP_ALT_HOLD_ACTIVE).isValue()) {
		return PitchMode::ALT;
	}

	/**
	 * Missing FLARE
	 */

	if (Autopilot::state::isMasterActive()) {
		if (Autopilot::verticalSpeed::verticalSpeedHold()) {
			return (LVars::get(LVars::XMLVAR_TRK_FPA_MODE_ACTIVE).isValue() ? PitchMode::FPA : PitchMode::VS);
		}

		if (Autopilot::altitude::altitudeLock()) {
			return PitchMode::ALT;
		}
	}

	if (Autopilot::flightDirector::isFlightDirector1Active() && Aircraft::state::altitudeAboveGround() < 10) {
		return PitchMode::TOGA;
	}

	return PitchMode::NONE;
}

const char* PFDFMAApplication::resolveArmedPitchMode() {
	namespace Autopilot = Simplane::autopilot;

	const bool approachHold = Autopilot::approach::approachHold();
	const bool approachActive = Autopilot::approach::approachActive();
	const bool glideSlopeHold = Autopilot::glideSlope::glideSlopeHold();
	const bool glideSlopeActive = Autopilot::glideSlope::glideSlopeActive();

	if (approachHold && glideSlopeHold && !(approachActive && glideSlopeActive)) {
		if (Autopilot::approach::approachType() == SimApproachType::APPROACH_TYPE_RNAV) {
			return PitchMode::GP;
		}
		else {
			return PitchMode::GS;
		}
	}

	if (LVars::get(LVars::AP_VNAV_ARMED).isValue() && !LVars::get(LVars::AP_VNAV_ACTIVE).isValue()) {
		return PitchMode::VNAV;
	}

	return PitchMode::NONE;
}