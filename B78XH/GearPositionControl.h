#pragma once
#include "Control.h"
#include "Simplane.h"
#include "Tools/Tools.h"
#include "Timer.h"

class GearPositionControl : public Control {
public:
	explicit GearPositionControl(const string& name)
		: Control(name) {}

	auto render() -> void override;



protected:
	auto setupControl() -> void override;

private:

	sGaugeDrawData* data;
	Timer timer = Timer(10);
	bool isGearDown;
	bool isGearInTransit;
	bool lastGearPosition;

	auto drawGearIndicator() -> void;
	bool shouldStartTimer();
};
