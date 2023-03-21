#pragma once

#include "LVars.h"

class Fuel {
public:

    void setTemperature(double value);
    double getTemperature();
private:

    LVar& temperature = LVars::get(LVars::FUEL_TEMP);

    void dump();
};


