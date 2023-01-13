#pragma once

#include "MasterControl.h"

class ExampleControl : public MasterControl {
public:
	explicit ExampleControl(const string& name)
		: MasterControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;

};
