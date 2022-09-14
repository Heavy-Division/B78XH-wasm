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


#include "SpeedMarker.h"

#include <string>
#include "Tools.h"

using Colors = Tools::Colors;

auto SpeedMarker::draw(NVGcontext* context, double target, double indicatedAirspeed) -> void {

	if (target == 0 || this->isPassed) {
		return;
	}

	const double delta = indicatedAirspeed - target;

	constexpr double baseOffset = (465.0 / 2);
	constexpr double pixelPerKnot = 3.875;
	const double deltaPixels = pixelPerKnot * delta;
	double offset = baseOffset + (deltaPixels);

	nvgScissor(context, -10, 0, 150, 465);
	{
		nvgSave(context);
		{
			nvgStrokeColor(context, Colors::green);
			nvgStrokeWidth(context, 2.0f);
			nvgTranslate(context, 70, offset);
			{
				nvgBeginPath(context);
				{
					nvgMoveTo(context, (this->isMain ? -5 : 0), 0);
					nvgLineTo(context, 14, 0);
				}
			}

			nvgStroke(context);
		}
		nvgRestore(context);


		nvgSave(context);
		{
			nvgFillColor(context, Colors::green);
			nvgTextAlign(context, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
			nvgTextLetterSpacing(context, -2.0f);

			bool renderSecondLine = false;
			if (offset < 19.375 && this->isMain) {
				offset = 19.375;
				renderSecondLine = true;
			}

			nvgTranslate(context, 70, offset);
			{
				nvgBeginPath(context);
				{
					nvgText(context, (this->isMain ? 15 : (this->enableSafeArea ? 32 : 15)), 0, this->title.c_str(),
					        nullptr);
					if (renderSecondLine) {
						nvgText(context, 15, 14, std::to_string(static_cast<int>(target)).c_str(), nullptr);
					}
				}
			}
			nvgFill(context);
		}
		nvgRestore(context);
	}
	nvgResetScissor(context);
}
