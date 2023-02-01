#pragma once

#include "EICASGauge.h"
#include "Simplane.h"

using Tools::Colors;

class TestCircle : public EICASGauge {
public:
	TestCircle(const string& name)
		: EICASGauge(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;

private:
	
	double advisory_threshold = 450;
	double warn_threshold = 500;
	double data = Simplane::aircraft::systems::powerplant::engine_1::egt();
};

inline void TestCircle::render() {
	EICASGauge::render();
	
	drawCircle(500, 150);
}

inline void TestCircle::setupControl() {
	EICASGauge::setupControl();
	addOnBeforeRender([this](BaseControl& base_control) -> bool {
		this->data;
		return true;
		});
}
