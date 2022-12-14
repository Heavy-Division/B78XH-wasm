#pragma once

#include <unordered_map>
#include "Potential.h"

class Electricity {
public:
    // placeholder classes:
    struct ElectricalElementIdentifier {};
    struct ElectricalBusType {};
    struct PotentialCollection {};

    ElectricalElementIdentifier next_identifier;
    std::unordered_map<ElectricalBusType, ElectricalElementIdentifier> buses;
    PotentialCollection potential;

    // Datatype "Potential" should incorporate some shared_ptr or RefCell method
    Potential none_potential;

};