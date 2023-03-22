#include "OilTempControlRight.h"

void OilTempControlRight::render() {
	EICASBaseControl::render();

	drawDataBox(45, 27, 0, 20.0f);
	drawLineGauge(-10, 10, 75, TOP);

}

void OilTempControlRight::setupControl() {
	EICASBaseControl::setupControl();


	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_2::oilTemperature();
		return true;
	});


	this->fuel_valve_connection = RIGHT;
	this->max = 225.;
	this->advisory_threshold = 200.;
	this->warning_threshold = 210.;

}
