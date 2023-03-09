#pragma once
#include "Control.h"
#include "Simplane.h"
#include "Tools/Tools.h"

class GearPositionControl : public Control {
public:
	explicit GearPositionControl(const string& name)
		: Control(name) {}

	auto render() -> void override;



protected:
	auto setupControl() -> void override;

private:

	bool isGearDown;
	bool isGearInTransit;

	auto drawGearIndicator() -> void;
};
