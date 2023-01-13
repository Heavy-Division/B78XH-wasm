#include "SystemsMenuBarApplication.h"
#include "Tools/Tools.h"

void SystemsMenuBarApplication::drawBackground() {
	nvgFillColor(this->nvgContext, nvgRGBA(255, 255, 255, 100));
	nvgStrokeWidth(this->nvgContext, 1.0f);
	nvgStrokeColor(this->nvgContext, Tools::Colors::black);
	nvgBeginPath(this->nvgContext);
	nvgRect(this->nvgContext, 0, 0, 80, 465);
	nvgClosePath(this->nvgContext);
	nvgFill(this->nvgContext);
	nvgStroke(this->nvgContext);
}
