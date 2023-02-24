#include "EngineEGTGaugeControlRight.h"

#include "Tools/Console.h"
#include "EngineEGTGaugeControlRight.h"
#include <cmath>
#include "fmt/core.h"
#include "Simplane.h"
#include "Tools/Tools.h"
#include "EICASCircularControl.h"

using Tools::Colors;


void EngineEGTGaugeControlRight::render() {
	EICASCircularControl::render();

	drawCircle();
	drawArc(1000, false);
	drawDataBox(CircularDataBox::width, CircularDataBox::height, 0, CircularDataBox::fontSize);

}

void EngineEGTGaugeControlRight::setupControl() {
	EICASCircularControl::setupControl();
	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = static_cast<int>(Simplane::aircraft::systems::powerplant::engine_2::egt());

		this->fuel_valve_connection = RIGHT;
		this->gauge_type = PRIMARY;
		this->advisory_threshold = 450;
		this->warning_threshold = 500;
		//TODO: Verify accuracy
		this->render_cutoff = 100;

		return true;
	});

}