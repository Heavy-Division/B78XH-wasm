#pragma once
#include "MasterControl.h"

class LeftOutBoardMasterControl : public MasterControl {
public:
	explicit LeftOutBoardMasterControl(const string& name)
		: MasterControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
};
