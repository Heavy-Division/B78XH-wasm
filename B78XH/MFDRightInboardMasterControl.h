#pragma once

#include "MasterControl.h"

class MFDRightInboardMasterControl : public MasterControl {
public:
	explicit MFDRightInboardMasterControl(const string& name)
		: MasterControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
};
