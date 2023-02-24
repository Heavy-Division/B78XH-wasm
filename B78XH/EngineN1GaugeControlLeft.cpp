#include "EngineN1GaugeControlLeft.h"
#include "HelloWorldApplication.h"
#include "Simplane.h"
#include "fmt/core.h"
#include "Tools/Console.h"

void EngineN1GaugeControlLeft::render() {
	EICASCircularControl::render();
	drawCircle();
	drawArc(105, true);
	drawDataBox(CircularDataBox::width, CircularDataBox::height, 1, CircularDataBox::fontSize);

}

void EngineN1GaugeControlLeft::setupControl() {
	EICASCircularControl::setupControl();

	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_1::n1_rpm();

		this->commanded_data = Simplane::aircraft::systems::powerplant::engine_1::n1_commanded();

		this->fuel_valve_connection = LEFT;
		this->gauge_type = PRIMARY;
		this->advisory_threshold = 90;
		this->warning_threshold = 100;
		//TODO: Verify accuracy
		this->render_cutoff = 20;

		return true;
	});

	
}
