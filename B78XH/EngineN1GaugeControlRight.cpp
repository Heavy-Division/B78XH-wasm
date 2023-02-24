#include "EngineN1GaugeControlRight.h"
#include "HelloWorldApplication.h"
#include "Simplane.h"
#include "Tools/Console.h"

void EngineN1GaugeControlRight::render() {
	EICASCircularControl::render();
	drawCircle();
	drawArc(105, true);
	drawDataBox(CircularDataBox::width, CircularDataBox::height, 1, CircularDataBox::fontSize);

}

void EngineN1GaugeControlRight::setupControl() {
	EICASCircularControl::setupControl();

	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = Simplane::aircraft::systems::powerplant::engine_2::n1_rpm();

		this->commanded_data = Simplane::aircraft::systems::powerplant::engine_2::n1_commanded();

		this->fuel_valve_connection = RIGHT;
		this->gauge_type = PRIMARY;
		this->advisory_threshold = 90;
		this->warning_threshold = 100;
		//TODO: Verify accuracy
		this->render_cutoff = 20;

		return true;
	});
}
