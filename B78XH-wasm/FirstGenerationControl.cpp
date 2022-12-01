#include "FirstGenerationControl.h"
#include "SecondGenerationControl.h"
#include "ThirdGenerationControl.h"
#include "Tools/Tools.h"

void FirstGenerationControl::prepareControls() {
	BaseControl::prepareControls();
	this->addControl(std::make_unique<SecondGenerationControl>());
}

void FirstGenerationControl::render(sGaugeDrawData* data) {
	BaseControl::render(data);

	nvgFillColor(this->getContext(), nvgRGB((std::rand() % (255 + 1)), (std::rand() % (255 + 1)), (std::rand() % (255 + 1))));
	nvgBeginPath(this->getContext());
	{
		nvgRect(this->getContext(), 0, 0, 100, 100);
	}
	nvgFill(this->getContext());
}