#pragma once
#include "CenterFuelSensorGroupA.h"
#include "CenterFuelSensorGroupB.h"
class FQDCCenter
{
	public:
		// TODO: see FQDC side comments
		auto getSensorData() -> double;
	private:
		CenterFuelSensorGroupA sensorGroupA;
		CenterFuelSensorGroupB sensorGroupB;
};

