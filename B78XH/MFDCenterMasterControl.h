#pragma once

#include "MasterControl.h"

class MFDCenterMasterControl : public MasterControl {
public:
	explicit MFDCenterMasterControl(const string& name)
		: MasterControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
};
