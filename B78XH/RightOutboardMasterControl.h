#pragma once

#include "MasterControl.h"

class RightOutboardMasterControl : public MasterControl {
public:
	explicit RightOutboardMasterControl(const string& name)
		: MasterControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
};
