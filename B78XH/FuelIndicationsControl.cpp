#include "FuelIndicationsControl.h"

void FuelIndicationsControl::render() {
	EICASBaseControl::render();

	nvgFillColor(getContext(), Tools::Colors::cduButtonGray);
	nvgStrokeColor(getContext(), Tools::Colors::white);
	nvgStrokeWidth(getContext(), 2.5f);

	nvgBeginPath(getContext());
	{
		nvgRect(getContext(), 400, 850, 300, 200);
		nvgStroke(getContext());
		nvgFill(getContext());
	}

	;
	
	// Fuel qty
	drawFuelDataBox(480, 860, 150, 40, true, "!", 20.0f);

	// Fuel qty label
	drawFuelDataBox(513, 850, 80, 30, false, "1", 13.0f);

	// gross wt
	drawFuelDataBox(417, 950, 75, 40, false, "1", 20.0f);

	// total fuel
	drawFuelDataBox(600, 940, 75, 50, false, "1", 20.0f);

	// SAT
	drawFuelDataBox(430, 1000, 65, 40, false, "1", 20.0f);

	// Fuel Temp
	drawFuelDataBox(615, 1000, 75, 40, false, "1", 20.0f);

	

}

void FuelIndicationsControl::setupControl() {
	EICASBaseControl::setupControl();
}

auto FuelIndicationsControl::setDisplayMode() -> void {}

auto FuelIndicationsControl::drawFuelDataBox(double x, double y, double w, double h, bool outline, std::string data, float fontSize) -> void {
	
	nvgStrokeColor(getContext(), Tools::Colors::cyan);


	nvgFillColor(getContext(), Tools::Colors::black);
	nvgBeginPath(getContext());
	{
		nvgRoundedRect(getContext(), x, y, w, h, 10.0f);
		nvgFill(getContext());
		if (outline) {
			nvgStroke(getContext());
		}
	}

	
}

auto FuelIndicationsControl::getUnitsType() -> AircraftUnitsType {
	return AircraftUnitsType::METRIC;
}
