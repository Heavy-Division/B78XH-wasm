// fuel quantity data concentrators. there are 3 of them, one for each tank
// 

#pragma once
#include "MainFuelSensorGroupA.h"
#include "MainFuelSensorGroupB.h"
class FQDCSide
{
	public:
		// TODO: define functions for retrieval of data. The "main" sensor groups (left and right) also have a sensor for
		// the center tank, so it's not directly 1-to-1
		// for now this is double but eventually will be something more complex, probably a struct
		// can just get the corresponding (l/c/r) fuel tank to start with ig?
		auto getSensorData() -> double;
	private:
		MainFuelSensorGroupA sensorGroupA;
		MainFuelSensorGroupB sensorGroupB;
};

