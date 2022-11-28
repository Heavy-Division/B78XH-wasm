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


#include "PFDMinimumIndicatorApplication.h"

#include "Simplane.h"
#include "Tools.h"

using Colors = Tools::Colors;

void PFDMinimumIndicatorApplication::render(sGaugeDrawData* data) {
	const bool isReferenceBaro = LVarsGetter::isMinimumSelectorBaro();
	const double value = (isReferenceBaro ? Simplane::barometer::setting::decisionAltitudeMSL() : Simplane::barometer::setting::decisionHeight());
	nvgSave(this->nvgContext);
	{
		nvgFontFace(this->nvgContext, "roboto");
		nvgFillColor(this->nvgContext, Colors::green);
		nvgTextAlign(this->nvgContext, NVG_ALIGN_CENTER);
		nvgBeginPath(this->nvgContext);
		{
			nvgFontSize(this->nvgContext, 24.0f);
			nvgText(this->nvgContext, 0, 0, (isReferenceBaro ? "BARO" : "RADIO"), nullptr);
			nvgFontSize(this->nvgContext, 30.0f);
			nvgText(this->nvgContext, 0, 25, std::to_string(static_cast<int>(value)).c_str(), nullptr);
		}
		nvgFill(this->nvgContext);
	}
	nvgRestore(this->nvgContext);
}
