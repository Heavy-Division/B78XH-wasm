#pragma once
#include "EICASBaseControl.h"
#include "Tools/Tools.h"

class GearPositionControl : public EICASBaseControl {
public:
	explicit GearPositionControl(const string& name)
		: EICASBaseControl(name) {}

	auto render() -> void override;
};
