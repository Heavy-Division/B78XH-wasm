#pragma once
#include "Operable.h"
class FuelDensitySensor : public Operable
{
	public:
		auto getFuelDensity() -> double;
};

