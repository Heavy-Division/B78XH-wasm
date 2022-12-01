#include "GreenControl.h"

#include "Tools/Tools.h"

void GreenControl::render(sGaugeDrawData* data) {
	Control::render(data);
	nvgFillColor(this->getContext(), Tools::Colors::green);
	nvgBeginPath(this->getContext());
	{
		nvgRect(this->getContext(), 0, 0, 200, 200);
	}
	nvgFill(this->getContext());
}
