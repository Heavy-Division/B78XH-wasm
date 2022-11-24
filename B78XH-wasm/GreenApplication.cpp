#include "GreenApplication.h"

#include "Tools.h"

auto GreenApplication::render(sGaugeDrawData* data) -> void {
	if (this->nvgContext == nullptr) {
		return;
	}
	nvgFillColor(this->nvgContext, Tools::Colors::black);
	nvgBeginPath(this->nvgContext);
	nvgRect(this->nvgContext, 0, 0, this->width, this->height);
	nvgFill(this->nvgContext);
	nvgFontSize(this->nvgContext, 90.0f);
	nvgFontFace(this->nvgContext, "dseg7");
	nvgFillColor(this->nvgContext, Tools::Colors::green);
	nvgFill(this->nvgContext);
	const int x = 0 + rand() % (500 + 1);
	const int y = 0 + rand() % (500 + 1);
	this->setMargin(x, y);
}
