#include "EngineVibrationControlRight.h"

void EngineVibrationControlRight::render() {
	LowerEICASControl::render();
	drawDataBox(35, 27, 1, 20.0f);
	drawLineGauge(-10, 0, 50, NONE);

}

void EngineVibrationControlRight::setupControl() {
	LowerEICASControl::setupControl();

	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_2::vibration();
		return true;
	});

	this->max = 5.0;
	this->fuel_valve_connection = RIGHT;
	this->advisory_threshold = 1000;
	this->warning_threshold = 1500;
}
