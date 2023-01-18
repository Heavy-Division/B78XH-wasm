#pragma once

#include "Control.h"

class TATControl : public Control {
public:
	explicit TATControl(const string& name)
		: Control(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
	auto setupControl() -> void override;
};