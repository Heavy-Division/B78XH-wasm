#pragma once
#include "Operable.h"
class FuelCompensatorSensor : public Operable
{
	public:
		auto getFuelDensity() -> double;
};

