#include "OilTempControlLeft.h"
#include "Simplane.h"
#include "Tools/Console.h"
#include "Tools/Tools.h"

using Tools::Colors;

void OilTempControlLeft::render() {
	EICASBaseControl::render();

	drawDataBox(45, 27, 0, 20.0f);
	drawLineGauge(50, 10, 75, TOP);

	
}

void OilTempControlLeft::setupControl() {
	EICASBaseControl::setupControl();

	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_1::oilTemperature();
		return true;
	});

	this->max = 225.;
	this->fuel_valve_connection = LEFT;
	this->advisory_threshold = 200.;
	this->warning_threshold = 210.;
}
