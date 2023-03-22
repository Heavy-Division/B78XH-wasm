#include "OilPressControlLeft.h"

void OilPressControlLeft::render() {
	EICASCircularControl::render();
	drawDataBox(45, 27, 0, 20.0f);
	drawLineGauge(50, 20, 75, BOTTOM);

}

void OilPressControlLeft ::setupControl() {
	EICASCircularControl::setupControl();

	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_1::oilPressure();
		return true;
	});
	

	// TODO: Check these values
	this->max = 160.;
	this->fuel_valve_connection = LEFT;
	this->advisory_threshold = 100.;
	this->warning_threshold = 110.;
}
