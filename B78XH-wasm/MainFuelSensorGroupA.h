#pragma once
#include "FuelCompensatorSensor.h"
#include "FuelHeightSensor.h"
#include "FuelHeightTemperatureSensor.h"

class MainFuelSensorGroupA 
{
    private:
        FuelHeightSensor fhs1;
        FuelHeightSensor fhs2;
        FuelHeightSensor fhs3;
        FuelHeightSensor fhs4;
        FuelHeightSensor fhs5;
        FuelHeightSensor fhs6;
        FuelHeightTemperatureSensor fhts;
        FuelHeightSensor centerFhs;
        FuelCompensatorSensor fcs;
};

