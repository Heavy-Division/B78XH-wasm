#include "FQIS.h"

auto FQIS::getCenterTankFuelWeight() -> double {
	// TODO: return actual fuel weight
	// simple impl based on default simvars: get fuel level in each tank * fuel density. or even simpler just get fuel weight simvars
	// advanced custom impl: calculate fuel level from height sensors, fuel density from density sensors, and use that to calculate
	return 0;
}

auto FQIS::getLeftTankFuelWeight() -> double {
	// TODO: return actual fuel weight
	return 0;
}

auto FQIS::getRightTankFuelWeight() -> double {
	// TODO: return actual fuel weight
	return 0;
}
