#include "FFControlRight.h"

using Tools::Colors;

void FFControlRight::render() {
	EICASCircularControl::render();

	drawDataBox(65, 29, 1, 25.0f);

}

void FFControlRight::setupControl() {
	EICASCircularControl::setupControl();

	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_2::fuelFlowPPH() / 1000;
		return true;
	});

	this->fuel_valve_connection = LEFT;
	this->advisory_threshold = 10;
	this->warning_threshold = 20;
}
