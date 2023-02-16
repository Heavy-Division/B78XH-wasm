#pragma once
#include "Control.h"


class OilPressControl : public Control {
public:
	explicit OilPressControl(const string& name)
		: Control(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
