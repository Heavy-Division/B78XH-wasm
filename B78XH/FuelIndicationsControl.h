#pragma once
#include "EICASBaseControl.h"
#include "AircraftUnitsType.h"

class FuelIndicationsControl : public EICASBaseControl {
public:
	explicit FuelIndicationsControl(const string& name)
		: EICASBaseControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;

private:
	bool isDisplayModeAlternate = true;

	auto setDisplayMode() -> void;
	auto drawFuelDataBox(double x, double y, double w, double h, bool tempData, std::string data, float fontSize) -> void;

	auto getUnitsType() -> AircraftUnitsType;
};
