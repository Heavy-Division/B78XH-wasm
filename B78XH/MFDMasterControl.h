#pragma once

#include "MasterControl.h"
#include "TATControl.h"
#include "WeightTempBoxControl.h"
#include "LineSeparatorControl.h"

class MFDMasterControl : public MasterControl {
public:
	explicit MFDMasterControl(const string& name)
		: MasterControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;

};