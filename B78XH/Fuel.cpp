#include "Fuel.h"

double Fuel::getTemperature() {
    return this->temperature.getValue();
}

void Fuel::dump() {}


void Fuel::setTemperature(double value) {
    this->temperature.set(value);
}