#pragma once
#include "Control.h"


class FlapsIndicatorControl : public Control {
public:
	explicit FlapsIndicatorControl(const string& name)
		: Control(name) {}

protected:
	auto setupControl() -> void override;

public:
	auto render() -> void override;
};