#pragma once
#include "Control.h"

class OilTempControl : public Control {
public:
	explicit OilTempControl(const string& name)
		: Control(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};