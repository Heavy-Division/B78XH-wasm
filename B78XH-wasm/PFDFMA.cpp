#include "PFDFMA.h"
#include "Simplane.h"

void PFDFMA::draw(NVGcontext* context, float windowWidth, float windowHeight) {
	drawBackground(context, windowWidth, windowHeight);
	drawTexts(context, windowWidth, windowHeight);
}

void PFDFMA::drawBackground(NVGcontext* context, float windowWidth, float windowHeight) {
	nvgFillColor(context, nvgRGBA(0, 0, 0, 100));

	nvgBeginPath(context);
	{
		//nvgRect(context, -188, -21, 376, 42);
		nvgRect(context, 0, 0, 376, 42);
	}
	nvgFill(context);

	constexpr double separatorHorizontalOffset = 376.0 / 3 - 1.5;
	nvgFillColor(context, nvgRGB(255, 255, 255));
	nvgBeginPath(context);
	{
		nvgRect(context,  separatorHorizontalOffset, 0, 3, 42);
		nvgRect(context,  separatorHorizontalOffset * 2, 0, 3, 42);
	}
	nvgFill(context);
}

void PFDFMA::drawTexts(NVGcontext* context, float windowWidth, float windowHeight) {
	constexpr double textPositionFactor = 376.0 / 6;

	nvgFillColor(context, nvgRGB(0, 255, 0));
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

	nvgFillColor(context, nvgRGB(255, 255, 255));
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

	if(!LVars::isSpeedActive()) {
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

	if(LVars::isFLCHActive()) {
		return ThrottleMode::THR_REF;
	}

	if(LVars::isSpeedActive()) {
		return ThrottleMode::SPD;
	}

	if(static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::CLIMB) {
		return ThrottleMode::THR_REF;
	}

	if(LVars::isSpeedInterventionActive()) {
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
		return (Autopilot::approach::approachType() == 10 ? RollMode::FAC : RollMode::LOC);
	}

	if(static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::TOGA) {
		return RollMode::TOGA;
	}

	if(LVars::isLNAVActive()) {
		return RollMode::LNAV;
	}

	if(Autopilot::state::isMasterActive() || Autopilot::flightDirector::isFlightDirector1Active() ||
		Autopilot::flightDirector::isFlightDirector2Active()) {
		if(LVars::isLNAVArmed() && static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) ==
			SimThrottleMode::HOLD) {
			return RollMode::TOGA;
		}
	}

	if(Autopilot::heading::headingLock()) {
		return (LVars::isHeadingHoldActive() ? RollMode::HDG_HOLD : RollMode::HDG_SEL);
	}

	if(Autopilot::state::isMasterActive()) {
		if(Autopilot::heading::headingLock()) {
			if(LVars::isHeadingHoldActive()) {
				return (LVars::isTRKModeActive() ? RollMode::TRK_HOLD : RollMode::HDG_HOLD);
			} else {
				return (LVars::isTRKModeActive() ? RollMode::TRK_SEL : RollMode::HDG_SEL);
			}
		}
	}

	return RollMode::NONE;
}

const char* PFDFMA::resolveArmedRollMode() {
	namespace Autopilot = Simplane::autopilot;

	if(Autopilot::approach::approachHold() && Autopilot::approach::approachArm()) {
		return (Autopilot::approach::approachType() == 10 ? RollMode::FAC : RollMode::LOC);
	}

	if(LVars::isLNAVArmed() && !LVars::isLNAVActive()) {
		return RollMode::LNAV;
	}

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
		if(Autopilot::approach::approachType() == 10) {
			return PitchMode::GP;
		} else {
			return PitchMode::GS;
		}
	}

	if(static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::TOGA) {
		return PitchMode::TOGA;
	}

	if(LVars::isVNAVActive()) {
		if(Autopilot::altitude::altitudeLock()) {
			const double indicatedAltitude = Aircraft::state::indicatedAltitude();
			const double cruiseAltitude = LVars::airlinerCruiseAltitude();
			if(indicatedAltitude > cruiseAltitude + 100) {
				return PitchMode::VNAV_ALT;
			}
			return PitchMode::VNAV_PTH;
		}
		return PitchMode::VNAV_SPD;
	}

	if(static_cast<SimThrottleMode>(Autopilot::throttle::leftEngineThrottleMode()) == SimThrottleMode::HOLD &&
		LVars::isVNAVArmed()) {
		return PitchMode::TOGA;
	}

	if(LVars::isFLCHActive()) {
		return PitchMode::FLCH_SPD;
	}

	if(LVars::isAltitudeHoldActive()) {
		return PitchMode::ALT;
	}

	if(Autopilot::state::isMasterActive()) {
		if(Autopilot::altitude::altitudeLock()) {
			return PitchMode::ALT;
		}

		if(Autopilot::verticalSpeed::verticaSpeedlHold()) {
			if(LVars::isFPAModeActive()) {
				return PitchMode::FPA;
			} else {
				return PitchMode::VS;
			}
		}
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
		if(Autopilot::approach::approachType() == 10) {
			return PitchMode::GP;
		} else {
			return PitchMode::GS;
		}
	}

	if(LVars::isVNAVArmed() && !LVars::isVNAVActive()) {
		return PitchMode::VNAV;
	}

	return PitchMode::NONE;
}
