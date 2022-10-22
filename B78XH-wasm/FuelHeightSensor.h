// fuel height sensor - supplies capacitance signal corresponding to fuel height at a specific location in the tank

#pragma once
#include "Operable.h"
class FuelHeightSensor final : public Operable
{
	public:
		auto getFuelHeight() -> double;
};

