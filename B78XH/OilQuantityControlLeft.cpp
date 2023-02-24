#include "OilQuantityControlLeft.h"

// TODO: Oil consumption model

void ::OilQuantityControlLeft::render() {
	EICASBaseControl::render();
	this->setBoxStyle();
	this->minmax = MIN;
	drawDataBox(35, 27, 0, 20.0f);
}

void ::OilQuantityControlLeft::setupControl() {
	EICASBaseControl::setupControl();
	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_1::oilQty();
		return true;
	});


	this->fuel_valve_connection = LEFT;
	this->advisory_threshold = 10.;
	this->render_on_start = true;
}
