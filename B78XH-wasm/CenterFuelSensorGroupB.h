#pragma once
#include "FuelCompensatorSensor.h"
#include "FuelHeightSensor.h"

class CenterFuelSensorGroupB
{
    private:
        FuelHeightSensor fhs1;
        FuelHeightSensor fhs2;
        FuelCompensatorSensor fcs;
};

