#pragma once
#include "Operable.h"
class FuelHeightTemperatureSensor : public Operable
{
	public:
		auto getFuelHeight() -> double;
		auto getFuelTemperature() -> double;
};

