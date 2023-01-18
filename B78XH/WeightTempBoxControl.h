#pragma once

#include "Control.h"

class WeightTempBoxControl : public Control {
public:
	explicit WeightTempBoxControl(const string& name)
		: Control(name) {}

protected:
	auto setupControl() -> void override;
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
};
