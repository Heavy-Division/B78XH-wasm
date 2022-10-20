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


#include "PFDMinimumIndicator.h"

#include <string>

#include "Simplane.h"
#include "Tools.h"

using Colors = Tools::Colors;

void PFDMinimumIndicator::draw(NVGcontext* context) {
	const bool isReferenceBaro = LVarsGetter::isMinimumSelectorBaro();
	const double value = (isReferenceBaro ? Simplane::barometer::setting::decisionAltitudeMSL() : Simplane::barometer::setting::decisionHeight());
	nvgSave(context);
	{
		nvgFontFace(context, "roboto");
		nvgFontSize(context, 24.0f);
		nvgFillColor(context, Colors::green);
		nvgTextAlign(context, NVG_ALIGN_LEFT);
		nvgBeginPath(context);
		{
			nvgText(context, 0, 0, (isReferenceBaro ? "BARO" : "RADIO"), nullptr);
			nvgText(context, 0, 10, std::to_string(static_cast<int>(value)).c_str(), nullptr);
		}
		nvgFill(context);
	}
	nvgRestore(context);
}
