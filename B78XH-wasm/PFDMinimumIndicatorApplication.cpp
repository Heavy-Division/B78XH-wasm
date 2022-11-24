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
