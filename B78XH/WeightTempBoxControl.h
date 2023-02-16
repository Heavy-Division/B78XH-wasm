#pragma once
#include "Control.h"

class WeightTempBoxControl : public Control {
public:
	explicit WeightTempBoxControl(const string& name)
		: Control(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
