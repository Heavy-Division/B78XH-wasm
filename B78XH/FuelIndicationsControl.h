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

	double grossWt;
	double totalFuelWt;
	double staticAirTemp;
	double fuelTemp = 0; // TODO: Fuel temp data model

	auto expandedMode() -> bool;
	auto setDisplayMode() -> void;
	auto drawFuelDataBox(double x, double y, double w, double h, bool outline) -> void;
	auto getUnitsType() -> AircraftUnitsType;
	auto drawBaseIndicator() -> void;
	auto drawStandardIndicator() -> void;
	auto drawExpandedIndicator() -> void;
	auto drawLabel(double x, double y, float fontSize, std::string title) -> void;
	auto drawData(double x, double y, float fontSize, double data, bool temperatureData) -> void;
};
