#pragma once

#include "units.h"

class BatteryRepository {
protected:

    virtual auto getPower() -> units::power::watt_t;
   
public:
    virtual ~BatteryRepository() = default;
    // placeholder classes:
    struct ElectricalStateWriter {};
    struct ElectricalElementIdentifier {};

    virtual auto getOutputPotential() -> units::voltage::volt_t;
    virtual auto getInputPotential() -> units::voltage::volt_t;
    virtual auto isDischarging() -> bool;
    virtual auto getCurrent() -> units::current::ampere_t;
    

    auto full() -> double;
    auto half() -> double;
    auto empty() -> double;

    units::voltage::volt_t input_potential;
    units::voltage::volt_t output_potential;
    units::current::ampere_t current;
};
