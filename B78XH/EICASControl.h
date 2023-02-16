#pragma once

#include <memory>
#include "MasterControl.h"
#include "TATControl.h"
#include "WeightTempBoxControl.h"
#include "LineSeparatorControl.h"
#include "MFDBaseControl.h"
#include "EngineN1GaugeControlLeft.h"
#include "EngineN1GaugeControlRight.h"
#include "EngineEGTGaugeControlRight.h"
#include "EngineEGTGaugeControlLeft.h"
#include "EngineN2GaugeControlLeft.h"
#include "EngineN2GaugeControlRight.h"
#include "LineSeparatorControl.h"
#include "MFDMasterControl.h"
// #include "TATControl.h"
#include "WeightTempBoxControl.h"


class EICASControl : public MFDBaseControl {

public:
	explicit EICASControl(const string& name)
		: MFDBaseControl(name) {
		ident_ = CONTROL_IDENT::COMM;
	}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;

private:
	// const std::shared_ptr<EICASGauge> tat_ = std::make_shared<TATControl>("TATControl");
	//
	// const std::shared_ptr<EICASGauge> n1_left_ = std::make_shared<EngineN1GaugeControlLeft>("EngineN1GaugeControlLeft");
	// const std::shared_ptr<EICASGauge> n1_right_ = std::make_shared<EngineN1GaugeControlRight>("EngineN1GaugeControlRight");
	//
	// const std::shared_ptr<EICASGauge> egt_left_ =  std::make_shared<EngineEGTGaugeControlLeft>("EngineEGTGaugeControlLeft");
	// const std::shared_ptr<EICASGauge> egt_right_ = std::make_shared<EngineEGTGaugeControlRight>("EngineEGTGaugeControlRight");
	//
	// const std::shared_ptr<EICASGauge> n2_left_ = std::make_shared<EngineN2GaugeControlLeft>("EngineN2GaugeControlLeft");
	// const std::shared_ptr<EICASGauge> n2_right_ = std::make_shared<EngineN2GaugeControlRight>("EngineN2GaugeControlRight");
	
};