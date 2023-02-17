#include "EngineEGTGaugeControlRight.h"

#include "Tools/Console.h"
#include "EngineEGTGaugeControlRight.h"
#include <cmath>
#include "fmt/core.h"
#include "Simplane.h"
#include "Tools/Tools.h"
#include "EICASGauge.h"

using Tools::Colors;


void EngineEGTGaugeControlRight::render() {
	EICASGauge::render();

	drawCircle(data);
	drawArc(data, 1000);
	drawDataBox(CircularDataBox::width, CircularDataBox::height, data, 0, RIGHT);

}

void EngineEGTGaugeControlRight::setupControl() {
	EICASGauge::setupControl();
	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data = static_cast<int>(Simplane::aircraft::systems::powerplant::engine_2::egt());

		this->advisory_threshold = 450;
		this->warning_threshold = 500;

		return true;
	});

}