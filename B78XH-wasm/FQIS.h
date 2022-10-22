// fuel quantity indicating system

#pragma once
#include "FQDCSide.h"
#include "FQDCCenter.h"

class FQIS
{
	public:
		auto getCenterTankFuelWeight() -> double;
		auto getLeftTankFuelWeight() -> double;
		auto getRightTankFuelWeight() -> double;
	private:
		FQDCSide fqdcLeft;
		FQDCCenter fqdcCenter;
		FQDCSide fqdcRight;
};

