#include "EngineN1GaugeControlLeft.h"
#include "HelloWorldApplication.h"
#include "Simplane.h"
#include "fmt/core.h"
#include "Tools/Console.h"

void EngineN1GaugeControlLeft::render() {
	EICASGauge::render();
	drawCircle(data);
	drawArc(data, 105);
	drawDataBox(CircularDataBox::width, CircularDataBox::height, data, 1, LEFT);

}

void EngineN1GaugeControlLeft::setupControl() {
	EICASGauge::setupControl();

	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_1::n1_rpm();

		this->advisory_threshold = 90;
		this->warning_threshold = 100;

		return true;
	});

	
}
