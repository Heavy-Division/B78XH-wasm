#include "RedApplication.h"

#include "Console.h"
#include "Tools.h"

auto RedApplication::render(sGaugeDrawData* data) -> void {
	if(this->nvgContext == nullptr) {
		return;
	}
	nvgFillColor(this->nvgContext, Tools::Colors::red);
	nvgBeginPath(this->nvgContext);
	nvgRect(this->nvgContext, 0, 0, 200, 200);
	nvgFill(this->nvgContext);
	nvgFontSize(this->nvgContext, 90.0f);
	nvgFontFace(this->nvgContext, "dseg7");
	nvgFillColor(this->nvgContext, Tools::Colors::white);
	nvgFill(this->nvgContext);
}
