#pragma once

#include "Systems/BatteryRepository.h"
#include "units.h"
#include "BatteryType.h"

class MainBattery : public BatteryRepository {
private:

    double rated_capacity = 65.;

protected:

public:
    
    BatteryType id = MAIN_BATT;
    auto getOutputPotential() -> units::voltage::volt_t override;
    auto getInputPotential() -> units::voltage::volt_t override;
    auto isDischarging() -> bool override;
    auto getCurrent() -> units::current::ampere_t override;
    auto getPower() -> units::power::watt_t override;
};