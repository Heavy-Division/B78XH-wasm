#include "EngineN1GaugeControl.h"
#include "HelloWorldApplication.h"
#include "Simplane.h"
#include "fmt/core.h"
#include "Tools/Console.h"

void EngineN1GaugeControl::render() {
	Control::render();

	std::string throttle1_pos = fmt::format("{:.1f}", Simplane::autopilot::throttle::leftEngineThrottlePosition());
	
	nvgFillColor(this->getContext(), Colors::greenPure);
	nvgFontFace(this->getContext(), "heavy-fmc");
	nvgFontSize(this->getContext(), 19.0f);
	nvgTextAlign(this->getContext(), NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
	nvgBeginPath(this->getContext());
	{
		nvgText(this->getContext(), 770, 27, throttle1_pos.c_str(), nullptr);
	}
	
	std::string eng1_n1_rpm = fmt::format("{:.1f}", Simplane::aircraft::systems::powerplant::engine_1::n1_rpm());
	nvgFillColor(this->getContext(), Colors::white);
	nvgStrokeColor(this->getContext(), Colors::white);
	nvgStrokeWidth(this->getContext(), 2.5f);
	nvgFontSize(this->getContext(),23.0f);
	nvgTextAlign(this->getContext(), NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
	nvgBeginPath(this->getContext());
	{
		nvgText(this->getContext(), 760, 53, eng1_n1_rpm.c_str(), nullptr);
		nvgRect(this->getContext(), 750, 47, 65, 29);
		nvgStroke(this->getContext());
	}
	
	
	
	double angle = (3.8 / 100) * Simplane::aircraft::systems::powerplant::engine_1::n1_rpm();
	
	
	nvgFillColor(this->getContext(), Colors::cduButtonGray);
	
	nvgBeginPath(this->getContext());
	{
		nvgMoveTo(this->getContext(), 750, 85);
		nvgArc(this->getContext(), 750, 85, 60, 0, angle, NVG_CW);
		nvgStroke(this->getContext());
	}
	nvgFill(this->getContext());
	
	Console::log("{}", Simplane::aircraft::systems::powerplant::engine_1::n1_rpm());
	Console::log("{}", Simplane::autopilot::throttle::leftEngineThrottlePosition());

}

void EngineN1GaugeControl::setupControls() {
	Control::setupControls();
}
