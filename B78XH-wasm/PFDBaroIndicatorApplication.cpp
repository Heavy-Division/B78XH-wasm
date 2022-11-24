#include "PFDBaroIndicatorApplication.h"

#include "Tools.h"
#include "Simplane.h"
#include <cmath>

using Colors = Tools::Colors;

void PFDBaroIndicatorApplication::render(sGaugeDrawData* data) {
	if (Simplane::barometer::setting::forcedToSTD()) {
		drawSTD();
	} else {
		const bool hpa = Simplane::barometer::setting::isBaroInHPA();
		drawValue(hpa);
		drawUnits(hpa);
	}
}

auto PFDBaroIndicatorApplication::drawValue(bool isBaroInHPA) const -> void {
	double value = (isBaroInHPA
		? Simplane::barometer::setting::kohlsmanMB()
		: Simplane::barometer::setting::kohlsmanHG());
	std::string valueToRender;
	if (isBaroInHPA) {
		value = roundf(static_cast<float>(value));
		valueToRender = std::to_string(static_cast<int>(value));
	}
	else {
		value = round(static_cast<float>(value * 100)) / 100.0;
		valueToRender = fmt::format("{:.2f}", value);
	}

	nvgFillColor(this->nvgContext, Colors::green);
	nvgTextAlign(this->nvgContext, NVG_ALIGN_LEFT);
	nvgFontSize(this->nvgContext, 25.0f);
	nvgFontFace(this->nvgContext, "roboto");
	nvgBeginPath(this->nvgContext);
	{
		nvgText(this->nvgContext, 0, 0, valueToRender.c_str(), nullptr);
	}
	nvgFill(this->nvgContext);
}

auto PFDBaroIndicatorApplication::drawUnits(bool isBaroInHPA) const -> void {
	nvgFillColor(this->nvgContext, Colors::green);
	nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT);
	nvgFontSize(this->nvgContext, 25.0f);
	nvgFontFace(this->nvgContext, "roboto");
	nvgBeginPath(this->nvgContext);
	{
		nvgText(this->nvgContext, 80, 0, (isBaroInHPA ? "HPA" : "IN"), nullptr);
	}
	nvgFill(this->nvgContext);
}

auto PFDBaroIndicatorApplication::drawSTD() const -> void {
	nvgFillColor(this->nvgContext, Colors::green);
	nvgTextAlign(this->nvgContext, NVG_ALIGN_CENTER);
	nvgFontSize(this->nvgContext, 35.0f);
	nvgBeginPath(this->nvgContext);
	{
		nvgText(this->nvgContext, 40, 5, "STD", nullptr);
	}
	nvgFill(this->nvgContext);
}