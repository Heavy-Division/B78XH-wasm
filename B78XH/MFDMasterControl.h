#pragma once

#include "MasterControl.h"
#include "MFDControl.h"

class MFDMasterControl : public MasterControl {
public:
	explicit MFDMasterControl(const string& name)
		: MasterControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;

public:
	~MFDMasterControl() override;
};