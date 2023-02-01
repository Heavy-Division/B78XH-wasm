#pragma once

#include "Control.h"
#include "Simplane.h"

class EngineVibrationControl : public Control {
public:
	explicit EngineVibrationControl(const string& name)
		: Control(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;

private:
	double eng1_vib;
	double eng2_vib = Simplane::aircraft::systems::powerplant::engine_2::vibration();

	double gauge_height;
	double max_vib;
	double gauge_constant;
	double vib_gauge_1;
	double vib_gauge_2;
};