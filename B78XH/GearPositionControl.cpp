#include "GearPositionControl.h"


void GearPositionControl::render() {
	Control::render();
	nvgFontFace(getContext(), "heavy-fmc");
	nvgFontSize(getContext(), 18.0f);
	nvgTextAlign(getContext(), NVG_ALIGN_CENTER);
	nvgFillColor(getContext(), Tools::Colors::lightBlue);
	nvgBeginPath(getContext());
	{
		nvgText(getContext(), 0, 0, "GEAR", nullptr);
		nvgFill(getContext());
	}

	drawGearIndicator();
}

void GearPositionControl::setupControl() {
	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->isGearDown = static_cast<bool>(Simplane::aircraft::state::gearPosition());
		this->isGearInTransit = Simplane::aircraft::state::isGearMotorOn();

		return true;

		});


}

auto GearPositionControl::drawGearIndicator() -> void {

	auto strokeColor = [this]() -> NVGcolor {
		if (this->isGearDown) {
			return Tools::Colors::greenPure;
		}

		return Tools::Colors::white;
	};

	nvgStrokeWidth(getContext(), 3.5f);
	nvgStrokeColor(getContext(), strokeColor());

	nvgFontSize(getContext(), 22.0f);
	nvgFontFace(getContext(), "heavy-fmc");
	nvgFillColor(getContext(), Tools::Colors::greenPure);

	nvgBeginPath(getContext());
	{
		if (this->isGearDown) {
			nvgText(getContext(), -3, -38, "DOWN", nullptr);
			nvgFill(getContext());
		}
		nvgRect(getContext(), -43, -70, 68, 29);
		nvgStroke(getContext());
	}


}
