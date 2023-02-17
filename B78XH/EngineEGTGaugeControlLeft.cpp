#include "Tools/Console.h"
#include "EngineEGTGaugeControlLeft.h"
#include <cmath>
#include "fmt/core.h"
#include "Simplane.h"
#include "Tools/Tools.h"
#include "EICASGauge.h"

using Tools::Colors;


void EngineEGTGaugeControlLeft::render() {
	EICASGauge::render();

	drawCircle(data);
	drawArc(data, 1000);
	drawDataBox(CircularDataBox::width, CircularDataBox::height, data, 0, LEFT);

}

void EngineEGTGaugeControlLeft::setupControl() {
	EICASGauge::setupControl();
	addOnBeforeRender([this](BaseControl& base_control) -> bool {

		this->data = Simplane::aircraft::systems::powerplant::engine_1::egt();

		this->advisory_threshold = 450;
		this->warning_threshold = 500;

		return true;
	});

}