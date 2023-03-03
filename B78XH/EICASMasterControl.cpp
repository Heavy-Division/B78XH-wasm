#include "EICASMasterControl.h"
#include "EngineN1GaugeControlLeft.h"
#include "EngineN1GaugeControlRight.h"
#include "EngineEGTGaugeControlRight.h"
#include "EngineEGTGaugeControlLeft.h"
#include "EngineN2GaugeControlLeft.h"
#include "EngineN2GaugeControlRight.h"
#include "LineSeparatorControl.h"
#include "TATControl.h"
#include "ThrestReferenceModeControl.h"
#include "FFControlLeft.h"
#include  "FFControlRight.h"
#include "OilPressControlleft.h"
#include "OilPressControlRight.h"
#include "Tools/Tools.h"
#include "OilTempControlLeft.h"
#include "OilTempControlRight.h"
#include "OilQuantityControlLeft.h"
#include "OilQuantityControlRight.h"
#include "EngineVibrationControlLeft.h"
#include "EngineVibrationControlRight.h"
#include "FuelIndicationsControl.h"
#include "GearPositionControl.h"
#include "CrewAlertMessageControl.h"


void EICASMasterControl::prepareControls() {
	MFDBaseControl::prepareControls();

	add(std::make_unique<TATControl>("TATControl"));
	add(std::make_unique<ThrustReferenceModeControl>("ThrustReferenceModeControl"));

	add(std::make_unique<EngineN1GaugeControlLeft>("EngineN1GaugeControlLeft"));
	add(std::make_unique<EngineN1GaugeControlRight>("EngineN1GaugeControlRight"));

	add(std::make_unique<EngineEGTGaugeControlRight>("EngineEGTGaugeControlRight"));
	add(std::make_unique<EngineEGTGaugeControlLeft>("EngineEGTGaugeControlLeft"));

	add(std::make_unique<EngineN2GaugeControlLeft>("EngineN2GaugeControlLeft"));
	add(std::make_unique<EngineN2GaugeControlRight>("EngineN2GaugeControlRight"));

	add(std::make_unique<FFControlLeft>("FFControlLeft"));
	add(std::make_unique<FFControlRight>("FFControlRight"));

	add(std::make_unique<OilPressControlLeft>("OilPressControlLeft"));
	add(std::make_unique<OilPressControlRight>("OilPressControlRight"));

	add(std::make_unique<OilTempControlLeft>("OilTempControlLeft"));
	add(std::make_unique<OilTempControlRight>("OilTempControlRight"));

	add(std::make_unique<OilQuantityControlLeft>("OilQuantityControlLeft"));
	add(std::make_unique<OilQuantityControlRight>("OilQuantityControlRight"));

	add(std::make_unique<EngineVibrationControlLeft>("EngineVibrationControlLeft"));
	add(std::make_unique<EngineVibrationControlRight>("EngineVibrationControlRight"));

	add(std::make_unique<FuelIndicationsControl>("FuelIndicationsControl"));

	add(std::make_unique<GearPositionControl>("GearPositionControl"));

	// add(std::make_unique<CrewAlertMessageControl>("CrewAlertMessageDispatchControl"));
	add(std::make_unique<LineSeparatorControl>("LineSeparatorControl"));
}


void EICASMasterControl::setupControls() {
	MFDBaseControl::setupControls();

	double const x_offset = 180;

	double const x = 120;

	auto& n1_l = getControl("EngineN1GaugeControlLeft");
	n1_l->getRelativePosition().setPosition(x, 100, 0, 0);
	auto& n1_r = getControl("EngineN1GaugeControlRight");
	n1_r->getRelativePosition().setPosition(x + x_offset, 100, 0, 0);

	auto& egt_l = getControl("EngineEGTGaugeControlLeft");
	egt_l->getRelativePosition().setPosition(x, 225, 0, 0);
	auto& egt_r = getControl("EngineEGTGaugeControlRight");
	egt_r->getRelativePosition().setPosition(x + x_offset, 225, 0, 0);

	auto& n2_l = getControl("EngineN2GaugeControlLeft");
	n2_l->getRelativePosition().setPosition(x, 350, 0, 0);
	auto& n2_r = getControl("EngineN2GaugeControlRight");
	n2_r->getRelativePosition().setPosition(x + x_offset, 350, 0, 0);

	double const secondary_x = 85;
	double const secondary_x_offset = 195;

	auto& ff_l = getControl("FFControlLeft");
	ff_l->getRelativePosition().setPosition(secondary_x, 475, 0, 0);
	auto& ff_r = getControl("FFControlRight");
	ff_r->getRelativePosition().setPosition(secondary_x + secondary_x_offset, 475, 0, 0);

	auto& oilPress_l = getControl("OilPressControlLeft");
	oilPress_l->getRelativePosition().setPosition(secondary_x + 20, 560, 0, 0);
	auto& oilPress_r = getControl("OilPressControlRight");
	oilPress_r->getRelativePosition().setPosition(secondary_x + secondary_x_offset + 6, 560, 0, 0);

	auto& oilTemp_l = getControl("OilTempControlLeft");
	oilTemp_l->getRelativePosition().setPosition(secondary_x + 20, 730, 0, 0);
	auto& oilTemp_r = getControl("OilTempControlRight");
	oilTemp_r->getRelativePosition().setPosition(secondary_x + secondary_x_offset + 6, 730, 0, 0);

	auto& oilQty_l = getControl("OilQuantityControlLeft");
	oilQty_l->getRelativePosition().setPosition(secondary_x + 20, 800, 0, 0);
	auto& oilQty_r = getControl("OilQuantityControlRight");
	oilQty_r->getRelativePosition().setPosition(secondary_x + secondary_x_offset + 6, 800, 0, 0);

	auto& engVib_l = getControl("EngineVibrationControlLeft");
	engVib_l->getRelativePosition().setPosition(secondary_x + 30, 900, 0, 0);
	auto& engVib_r = getControl("EngineVibrationControlRight");
	engVib_r->getRelativePosition().setPosition(secondary_x + secondary_x_offset + 6, 900, 0, 0);
	
	auto& gearControl = getControl("GearPositionControl");
	gearControl->getRelativePosition().setPosition(550, 475, 0, 0);

}

void EICASMasterControl::setupControl() {
	MFDBaseControl::setupControl();

}


void EICASMasterControl::render() {
	MFDBaseControl::render();
	drawLabel(215, 100, "N1", "");
	drawLabel(215, 240, "EGT", "");
	drawLabel(215, 350, "N2", "");
	drawLabel(215, 465, "FF", "");
	drawLabel(215, 535, "OIL", "PRESS");
	drawLabel(215, 690, "OIL", "TEMP");
	drawLabel(215, 790, "OIL QTY", "");
	drawLabel(215, 890, "VIB", "");

}

auto EICASMasterControl::drawLabel(double x, double y, std::string label, std::string label2) -> void {
	nvgFontFace(getContext(), "heavy-fmc");
	nvgFillColor(getContext(), Tools::Colors::cyan);
	nvgFontSize(getContext(), 16.0f);
	nvgTextAlign(getContext(), NVG_ALIGN_CENTER);

	nvgBeginPath(getContext());
	{
		nvgText(getContext(), x, y, label.c_str(), nullptr);
		if (label2 == "") {

		}
		nvgText(getContext(), x, y + 25, label2.c_str(), nullptr);
		nvgFill(getContext());
	}
}


