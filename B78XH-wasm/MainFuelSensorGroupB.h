#pragma once
#include "FuelDensitySensor.h"
#include "FuelHeightSensor.h"
#include "FuelHeightTemperatureSensor.h"

class MainFuelSensorGroupB
{
    private:
        FuelHeightSensor fhs1;
        FuelHeightSensor fhs2;
        FuelHeightSensor fhs3;
        FuelHeightSensor fhs4;
        FuelHeightSensor fhs5;
        FuelHeightSensor fhs6;
        FuelHeightSensor fhs7;
        FuelHeightSensor centerFhs;
        FuelDensitySensor fds;
};

