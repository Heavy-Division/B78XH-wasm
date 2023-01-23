#pragma once

#include "MasterControl.h"

class MFDLeftInboardMasterControl : public MasterControl {
public:
	explicit MFDLeftInboardMasterControl(const string& name)
		: MasterControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
};
