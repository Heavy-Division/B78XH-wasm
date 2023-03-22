#include "EngineVibrationControlLeft.h"


// TODO: Simconnect is not clear if Vibration is N1 or N2, one of them will need to be simulated LVAR.

void EngineVibrationControlLeft::render() {
	LowerEICASControl::render();
	this->setBoxStyle();
	
	drawDataBox(35, 27, 1, 20.0f);
	drawLineGauge(40, 0, 50, NONE);
}

void EngineVibrationControlLeft::setupControl() {
	LowerEICASControl::setupControl();
	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_1::vibration();
		return true;
	});

	this->max = 5.0;
	this->minmax = MAX;
	this->fuel_valve_connection = LEFT;
	this->advisory_threshold = 1.5;
	this->warning_threshold = 1500;
}
