#include "FFControlLeft.h"
#include "Simplane.h"
#include "Tools/Console.h"
#include "Tools/Tools.h"

using Tools::Colors;

void FFControlLeft::render() {
	EICASCircularControl::render();

	drawDataBox(65, 29, 1, 25.0f);
	
}

void FFControlLeft::setupControl() {
	EICASCircularControl::setupControl();

	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_1::fuelFlowPPH() / 1000;
		return true;
	});
	

	this->fuel_valve_connection = LEFT;
	this->advisory_threshold = 10;
	this->warning_threshold = 29;
}
