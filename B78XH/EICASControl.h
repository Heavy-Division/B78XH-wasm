#pragma once

#include "MasterControl.h"
#include "TATControl.h"
#include "WeightTempBoxControl.h"
#include "LineSeparatorControl.h"
#include "EngineN1GaugeControl.h"
#include "Control.h"

class EICASControl : public Control {
public:
	explicit EICASControl(const string& name)
		: Control(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;

};