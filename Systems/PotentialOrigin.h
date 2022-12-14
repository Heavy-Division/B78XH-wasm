#pragma once

#include "units.h"
class PotentialOrigin {
private:
	double startingPower;
	double oil_level;


protected:

	auto getName() -> void;
	
	units::voltage::volt_t ac_potential;
	units::frequency::Hz frequency;
	units::power::watt_t load;
	units::voltage::volt_t dc_potential;
	units::voltage::volt_t neg_dc_potential;

};

