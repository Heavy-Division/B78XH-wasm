#include "GearPositionControl.h"

#include "Tools/Console.h"

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
	//
	// Log(Simplane::aircraft::state::gearPosition());
	// Log(shouldStartTimer());
	drawGearIndicator();
	// if (!this->isGearInTransit && !this->isGearDown) {
	// 	// if (this->shouldStartTimer()) {
	// 	this->timer.start();
	// 	// }
	//
	// 	this->timer.update(data->dt);
	// 	if (!this->timer.finished() && this->timer.started()) {
	// 		nvgText(getContext(), 1, -30, "UP", nullptr);
	// 	}
	// 	else {
	// 		this->timer.restart();
	// 		this->timer.stop();
	// 	}
	//
	// 	this->lastGearPosition = Simplane::aircraft::state::gearPosition();
	// }
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
		if (this->isGearDown && !this->isGearInTransit) {
			return Tools::Colors::greenPure;
		}

		return Tools::Colors::white;
	};
	double rectX = -25;
	double rectY = -55;
	nvgStrokeWidth(getContext(), 3.5f);
	nvgStrokeColor(getContext(), strokeColor());

	nvgFontSize(getContext(), 19.5f);
	nvgFontFace(getContext(), "heavy-fmc");
	nvgFillColor(getContext(), Tools::Colors::greenPure);

	nvgBeginPath(getContext());
	{
		if (this->isGearDown && !this->isGearInTransit) {
			nvgText(getContext(), 1, -32, "DOWN", nullptr);
			nvgFill(getContext());
		}
		else if (this->isGearInTransit) {
			nvgMoveTo(getContext(), rectX + 15, rectY);
			nvgLineTo(getContext(), rectX, rectY + 15);

			nvgMoveTo(getContext(), rectX + 27, rectY);
			nvgLineTo(getContext(), rectX, rectY + 26);

			nvgMoveTo(getContext(), rectX + 39, rectY);
			nvgLineTo(getContext(), rectX + 10.75, rectY + 29);

			nvgMoveTo(getContext(), rectX + 51, rectY);
			nvgLineTo(getContext(), rectX + 24, rectY + 29);

			nvgMoveTo(getContext(), rectX + 52.5, rectY + 11.5);
			nvgLineTo(getContext(), rectX + 38, rectY + 27.5);
		}
		nvgRect(getContext(), rectX, rectY, 52, 29);
		nvgStroke(getContext());

	}
}

bool GearPositionControl::shouldStartTimer() {

	return this->lastGearPosition && !isGearDown;
}
