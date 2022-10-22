#pragma once
#include "FuelCompensatorSensor.h"
#include "FuelHeightSensor.h"
#include "FuelHeightTemperatureSensor.h"

class CenterFuelSensorGroupA
{
    private:
        FuelHeightSensor fhs1;
        FuelHeightSensor fhs2;
        FuelHeightTemperatureSensor fhts;
        FuelCompensatorSensor fcs;
};

