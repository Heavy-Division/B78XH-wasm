#include "EngineN1GaugeControlLeft.h"
#include "EngineN1GaugeControlRight.h"
#include "EngineEGTGaugeControlRight.h"
#include "EngineEGTGaugeControlLeft.h"
#include "EngineN2GaugeControlLeft.h"
#include "EngineN2GaugeControlRight.h"
#include "LineSeparatorControl.h"
#include "MFDMasterControl.h"
#include "TATControl.h"
#include "WeightTempBoxControl.h"


void EICASControl::prepareControls() {
	MFDBaseControl::prepareControls();
	add(std::make_unique<EngineN1GaugeControlLeft>("EngineN1GaugeControlLeft"));
	add(std::make_unique<EngineN1GaugeControlRight>("EngineN1GaugeControlRight"));

	add(std::make_unique<EngineEGTGaugeControlRight>("EngineEGTGaugeControlRight"));
	add(std::make_unique<EngineEGTGaugeControlLeft>("EngineEGTGaugeControlLeft"));

	add(std::make_unique<EngineN2GaugeControlLeft>("EngineN2GaugeControlLeft"));
	add(std::make_unique<EngineN2GaugeControlRight>("EngineN2GaugeControlRight"));

	// add(std::make_unique<WeightTempBoxControl>("WeightTempBoxControl"));
	// add(std::make_unique<LineSeparatorControl>("LineSeparatorControl"));
}


void EICASControl::setupControls() {
	MFDBaseControl::setupControls();

	double const x_offset = 175;

	double const x = 100;

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

}



