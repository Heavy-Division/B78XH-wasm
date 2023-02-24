#include "EngineN2GaugeControlLeft.h"

void EngineN2GaugeControlLeft::render() {
	EICASCircularControl::render();

	drawCircle();
	drawArc(105, false);
	drawDataBox(CircularDataBox::width, CircularDataBox::height, 1, CircularDataBox::fontSize);

}

void EngineN2GaugeControlLeft::setupControl() {
	EICASCircularControl::setupControl();
	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_1::n2_rpm();

		this->render_on_start = true;
		this->fuel_valve_connection = LEFT;
		this->advisory_threshold = 90;
		this->warning_threshold = 100;

		return true;
	});
}
