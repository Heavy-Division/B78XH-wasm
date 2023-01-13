#pragma once

#include "Control.h"

class ExampleLineControl : public Control {
public:
	explicit ExampleLineControl(const string& name)
		: Control(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
	auto setupControl() -> void override;
};
