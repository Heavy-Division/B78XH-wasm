#include "EngineN1GaugeControlRight.h"
#include "HelloWorldApplication.h"
#include "Simplane.h"
#include "fmt/core.h"
#include "Tools/Console.h"

void EngineN1GaugeControlRight::render() {
	EICASGauge::render();
	drawCircle(data);
	drawArc(data, 105);
	drawDataBox(CircularDataBox::width, CircularDataBox::height, data, 1, LEFT);

}

void EngineN1GaugeControlRight::setupControl() {
	EICASGauge::setupControl();

	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_2::n1_rpm();

		this->advisory_threshold = 90;
		this->warning_threshold = 100;

		return true;
	});
}
