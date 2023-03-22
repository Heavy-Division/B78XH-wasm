#include "OilQuantityControlRight.h"

void OilQuantityControlRight::render() {
	EICASBaseControl::render();
	this->setBoxStyle();
	this->minmax = MIN;
	drawDataBox(35, 27, 0, 20.0f);
	
}

void OilQuantityControlRight::setupControl() {
	EICASBaseControl::setupControl();

	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_2::oilQty();
		return true;
	});

	
	
	this->fuel_valve_connection = RIGHT;
	this->advisory_threshold = 10.;
	this->render_on_start = true;
}
