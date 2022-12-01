#include "SecondGenerationControl.h"
#include <iostream>
#include <ostream>

#include "FirstGenerationControl.h"
#include "ThirdGenerationControl.h"
#include "Tools/Tools.h"
#include "SimConnectData.h"

void SecondGenerationControl::prepareControls() {
	BaseControl::prepareControls();
	this->addControl(std::make_unique<ThirdGenerationControl>());


	this->onValidate.push_back([this]() {
		bool result = (SimConnectData::Misc::time.zuluTime - 5 < this->lastZuluTime);
		if (!result) {
			this->lastZuluTime = SimConnectData::Misc::time.zuluTime;
		}
		return result;
	});


}

void SecondGenerationControl::render(sGaugeDrawData* data) {
	BaseControl::render(data);
	nvgFillColor(this->getContext(), nvgRGB((std::rand() % (255 + 1)), (std::rand() % (255 + 1)), (std::rand() % (255 + 1))));
	//nvgFillColor(this->getContext(), Tools::Colors::red);
	nvgBeginPath(this->getContext());
	{
		nvgRect(this->getContext(), 100, 100, 100, 100);
	}
	nvgFill(this->getContext());
}
