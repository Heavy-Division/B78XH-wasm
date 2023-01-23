#include "MFDMasterControl.h"


void MFDMasterControl::prepareControls() {
	MasterControl::prepareControls();
	add(std::make_unique<TATControl>("MFDMasterControl"));
	add(std::make_unique<EngineN1GaugeControl>("EngineN1GaugeControl"));
	add(std::make_unique<WeightTempBoxControl>("WeightTempBoxControl"));
	add(std::make_unique<LineSeparatorControl>("LineSeparatorControl"));
}

void MFDMasterControl::setupControls() {
	MasterControl::setupControls();
}



