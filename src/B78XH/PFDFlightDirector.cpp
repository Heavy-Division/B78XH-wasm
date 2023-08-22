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


#include "PFDFlightDirector.h"
#include "Simplane.h"
#include "Tools/Tools.h"
#include "fmt/core.h"

using Colors = Tools::Colors;

void PFDFlightDirector::draw(NVGcontext* context, double deltaTime) {
	PFDFlightDirector::drawHeading(context, deltaTime);
	PFDFlightDirector::drawPitch(context, deltaTime);
}

void PFDFlightDirector::drawHeading(NVGcontext* context, double deltaTime) {
	const double bank = Simplane::aircraft::state::bank();
	const double altitudeAboveGround = Simplane::aircraft::state::altitudeAboveGround();
	const double flightDirectorBank = (altitudeAboveGround > 0 && altitudeAboveGround < 10 ? 0 : Simplane::autopilot::flightDirector::bank());

	this->flightDirectorBank += (flightDirectorBank - this->flightDirectorBank) * std::min<double>(1, deltaTime);
	const double calculatedX = std::max<double>(-1, std::min<double>(1, (bank - this->flightDirectorBank) / 30)) * 75;

	nvgSave(context);
	{
		nvgTranslate(context, (calculatedX), 0);
		{
			nvgStrokeColor(context, Colors::magenta);
			nvgStrokeWidth(context, 4.0f);
			nvgBeginPath(context);
			{
				nvgMoveTo(context, 0, -95);
				nvgLineTo(context, 0, 95);
			}
			nvgStroke(context);
		}
	}
	nvgRestore(context);

}

void PFDFlightDirector::drawPitch(NVGcontext* context, double deltaTime) {
	const double pitch = Simplane::aircraft::state::pitch();
	const double altitudeAboveGround = Simplane::aircraft::state::altitudeAboveGround();
	const double flightDirectorPitch = (altitudeAboveGround > 0 && altitudeAboveGround < 10 ? -8 : Simplane::autopilot::flightDirector::pitch());
	const double pitchFactor = 6.91111111111;

	this->flightDirectorPitch += (flightDirectorPitch - this->flightDirectorPitch) * std::min<double>(1, deltaTime);
	const double pitchDiff = this->flightDirectorPitch - pitch;
	const double calculatedY = Tools::clamp((pitchDiff * pitchFactor), -100.0, 100.0);

	nvgSave(context);
	{
		nvgTranslate(context, 0, calculatedY);
		{
			nvgStrokeColor(context, Colors::magenta);
			nvgStrokeWidth(context, 4.0f);
			nvgBeginPath(context);
			{
				nvgMoveTo(context, -95, 0);
				nvgLineTo(context, 95, 0);
			}
			nvgStroke(context);
		}
		nvgResetTransform(context);
	}
	nvgRestore(context);
}
