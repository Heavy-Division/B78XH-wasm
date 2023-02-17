#include "EngineN2GaugeControlRight.h"

void EngineN2GaugeControlRight::render() {
	EICASGauge::render();


	drawCircle(data);
	drawArc(data, 105);
	drawDataBox(CircularDataBox::width, CircularDataBox::height, data, 1, RIGHT);
}

void EngineN2GaugeControlRight::setupControl() {
	EICASGauge::setupControl();
	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_2::n2_rpm();

		this->advisory_threshold = 90;
		this->warning_threshold = 100;

		return true;
	});
}
