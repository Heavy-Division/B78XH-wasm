#pragma once

#include "Control.h"

class EnginEGTGaugeControl : public Control {
public:
	explicit EnginEGTGaugeControl(const string& name)
		: Control(name) {}

	auto render() -> void override;

protected:
	auto setupControls() -> void override;
};
