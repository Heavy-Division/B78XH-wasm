#include "Testgauge.h"
#include "Tools/Console.h"


void TestGauge::render() {
	EICASGauge::render();
	drawCircle(300, 300);
	// TODO : Make n1 calibration data model 
	drawHeader(310, 260, 21.0f, Simplane::aircraft::systems::powerplant::engine_1::n1_commanded());
	// drawDataBox(320, 300, 65, 29);
}

void TestGauge::setupControl() {
	EICASGauge::setupControl();
	// Console::log("{}", this->data);
	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		advisory_threshold = 40;
		warn_threshold = 50;
		data = Simplane::aircraft::systems::powerplant::engine_1::n1_rpm();
		return true;
	});
}
