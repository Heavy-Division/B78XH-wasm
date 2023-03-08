#include "FuelIndicationsControl.h"

#include "Tools/Console.h"


void FuelIndicationsControl::render() {
	EICASBaseControl::render();

	if(this->expandedMode()) {
		drawExpandedIndicator();
		return;
	}

	drawStandardIndicator();

	Console::log("{}", Simplane::environment::temperature::staticAirTemp());
}

void FuelIndicationsControl::setupControl() {
	EICASBaseControl::setupControl();

}

auto FuelIndicationsControl::setDisplayMode() -> void {}


auto FuelIndicationsControl::getUnitsType() -> AircraftUnitsType {
	return AircraftUnitsType::METRIC;
}


auto FuelIndicationsControl::drawStandardIndicator() -> void {
	nvgFillColor(getContext(), Tools::Colors::darkGray);
	nvgStrokeColor(getContext(), Tools::Colors::white);
	nvgStrokeWidth(getContext(), 2.5f);

	nvgBeginPath(getContext());
	{
		nvgRect(getContext(), 400, 925, 300, 125);
		nvgStroke(getContext());
		nvgFill(getContext());
	}

	drawBaseIndicator();

}
auto FuelIndicationsControl::drawExpandedIndicator() -> void {

	nvgFillColor(getContext(), Tools::Colors::darkGray);
	nvgStrokeColor(getContext(), Tools::Colors::white);
	nvgStrokeWidth(getContext(), 2.5f);

	nvgBeginPath(getContext());
	{
		nvgRect(getContext(), 400, 850, 300, 200);
		nvgStroke(getContext());
		nvgFill(getContext());
	}

	// Fuel qty
	drawFuelDataBox(480, 860, 150, 40, true);

	drawBaseIndicator();


	nvgFontFace(getContext(), "heavy-fmc");
	nvgFontSize(getContext(), 15.0f);
	nvgFillColor(getContext(), Tools::Colors::white);
	if (getUnitsType() == AircraftUnitsType::METRIC) {
		nvgText(getContext(), 525, 965, "KGS", nullptr);
	}
	nvgText(getContext(), 555, 965, "X", nullptr);
	nvgText(getContext(), 530, 980, "1000", nullptr);

}

auto FuelIndicationsControl::drawBaseIndicator() -> void {
	double grossWt = Simplane::aircraft::state::weight() / 1000;
	double totalWt = Simplane::aircraft::systems::fuel::total_lbs() / 1000;
	double sat = Simplane::environment::temperature::staticAirTemp();
	double fuelTemp = 0; // TODO: Fuel temp data LVar

	// gross wt
	drawLabel(421, 935, 20.0f, "GROSS WT");
	drawFuelDataBox(425, 960, 75, 30, false);
	drawData(430, 965, 15.0f, grossWt, false);

	// total fuel
	drawLabel(585, 935, 18.0f, "TOTAL FUEL");
	drawFuelDataBox(600, 955, 75, 32, false);
	drawData(605, 960, 15.0f, totalWt, false);

	// SAT
	drawLabel(410, 1018, 20.0f, "SAT");
	drawFuelDataBox(450, 1010, 55, 30, false);
	drawData(455, 1020, 15.0f, sat, true);

	// Fuel Temp
	drawLabel(565, 1005, 15.0f, "FUEL");
	drawLabel(565, 1025, 15.0f, "TEMP");
	drawFuelDataBox(615, 1010, 55, 30, false);
	drawData(620, 1015, 15.0f, fuelTemp, true);


	// labels

}


auto FuelIndicationsControl::drawFuelDataBox(double x, double y, double w, double h, bool outline) -> void {

	nvgStrokeColor(getContext(), Tools::Colors::lightBlue);
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

auto FuelIndicationsControl::drawLabel(double x, double y, float fontSize, std::string title) -> void {
	nvgFillColor(getContext(), Tools::Colors::lightBlue);
	nvgFontFace(getContext(), "heavy-fmc");
	nvgTextAlign(getContext(), NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
	nvgFontSize(getContext(), fontSize);

	nvgBeginPath(getContext());
	{
		nvgText(getContext(), x, y, title.c_str(), nullptr);
		nvgFill(getContext());
	}
}

auto FuelIndicationsControl::expandedMode() -> bool {
	return false;
}

auto FuelIndicationsControl::drawData(double x, double y, float fontSize, double data, bool temperatureData) -> void {
	nvgFillColor(getContext(), Tools::Colors::white);
	nvgFontFace(getContext(), "heavy-fmc");
	nvgFontSize(getContext(), fontSize);
	nvgTextAlign(getContext(), NVG_ALIGN_LEFT | NVG_ALIGN_TOP);

	std::string data_string;

	if(temperatureData) {
		data_string = Tools::formatToFixed(data, 0);
	} else {
		data_string = Tools::formatToFixed(data, 1);
	}

	auto tempSign = [data]() -> std::string {
		if (data >= 0) {
			return "+";
		};

		return "";
	};

	if (temperatureData) {
		data_string.insert(0, tempSign());
		data_string.push_back('c');
	}

	nvgBeginPath(getContext());
	{
		nvgText(getContext(), x, y,  data_string.c_str(), nullptr);
		nvgFill(getContext());
	}
}
