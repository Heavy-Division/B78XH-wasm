#include "MainBattery.h"
#include "Simplane.h"

using namespace units::current;
using namespace units::voltage;
using namespace units::power;

auto MainBattery::getOutputPotential() -> volt_t {
	this->output_potential = static_cast<volt_t>(Simplane::systems::electrical::battery::main_battery::getPotential());
	return this->output_potential;
}

auto MainBattery::getInputPotential() -> volt_t {
	this->input_potential = static_cast<volt_t>(0.);
	return this->input_potential;
}

auto MainBattery::getCurrent() -> ampere_t {
	this->current = ampere_t(0.);
	return this->current;
}

auto MainBattery::getPower() -> watt_t {
	return this->output_potential * this->current; 
}

bool MainBattery::isDischarging() {
	// if (this->current > ampere_t(0.)) {
	// 	return true;
	// }

	return false;
};