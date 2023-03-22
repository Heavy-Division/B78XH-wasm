#include "OilPressControlRight.h"

using Tools::Colors;

void OilPressControlRight::render() {
	EICASCircularControl::render();
	drawDataBox(45, 27, 0, 20.0f);
	drawLineGauge(-10, 20, 75, BOTTOM);

}

void OilPressControlRight::setupControl() {
	EICASCircularControl::setupControl();
	
	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_2::oilPressure();
		return true;
	});

	this->fuel_valve_connection = RIGHT;
	this->max = 160.;
	// TODO: Check these values
	this->advisory_threshold = 100.;
	this->warning_threshold = 110.;
	
}
