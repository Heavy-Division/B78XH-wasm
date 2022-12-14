#pragma once

#include <unordered_map>
#include "units.h"
#include "Potential.h"

class PotentialCollection {
protected:
    // placeholder classes
    struct ElectricalElementIdentifier {};
    struct Power {};
    struct PotentialOrigin {};

    // Potential in this map needs to implement shared ptr like Rc<RefCell<Potential>>
    std::unordered_map<ElectricalElementIdentifier, Potential> items;
    std::unordered_map<PotentialOrigin, units::power::watt_t> consumption_per_origin;

};