#include "BatteryRepository.h"

using namespace units::voltage;
using namespace units::current;
using namespace units::power;
using namespace units::literals;

auto BatteryRepository::isDischarging() -> bool {
    return false;
}

auto BatteryRepository::getCurrent() -> units::current::ampere_t {
    return this->current;
}

auto BatteryRepository::getOutputPotential() -> units::voltage::volt_t {
    return this->output_potential;
}

auto BatteryRepository::getInputPotential() -> units::voltage::volt_t {
    return this->input_potential;
}

auto BatteryRepository::getPower() -> units::power::watt_t {
    return this->output_potential * this->current;
}
