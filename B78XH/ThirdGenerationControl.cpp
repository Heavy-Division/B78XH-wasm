#include "ThirdGenerationControl.h"

#include "SimConnectData.h"
#include "Tools/Tools.h"

void ThirdGenerationControl::render(sGaugeDrawData* data) {
	BaseControl::render(data);
	nvgFillColor(this->getContext(), nvgRGB((std::rand() % (255 + 1)), (std::rand() % (255 + 1)), (std::rand() % (255 + 1))));
	nvgBeginPath(this->getContext());
	{
		nvgRect(this->getContext(), 200, 200, 100, 100);
	}
	nvgFill(this->getContext());
}

void ThirdGenerationControl::prepareControls() {
	BaseControl::prepareControls();
	this->onValidate.push_back([this]() {
		bool result = (SimConnectData::Misc::time.zuluTime - 10 < this->lastZuluTime);
	if (!result) {
		this->lastZuluTime = SimConnectData::Misc::time.zuluTime;
	}
	return result;
		});
}
