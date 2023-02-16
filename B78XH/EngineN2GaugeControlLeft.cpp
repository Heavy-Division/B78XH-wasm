#include "EngineN2GaugeControlLeft.h"

void EngineN2GaugeControlLeft::render() {
	EICASGauge::render();

	drawCircle(data);
	drawArc(data, 105);
	drawDataBox(65, 29, data, LEFT);

}

void EngineN2GaugeControlLeft::setupControl() {
	EICASGauge::setupControl();
	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_1::n2_rpm();

		this->advisory_threshold = 90;
		this->warning_threshold = 100;

		return true;
	});
}
