#pragma once
#include "Control.h"


class MFDControl : public Control {
public:
	explicit MFDControl(const string& name)
		: Control(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
}; 