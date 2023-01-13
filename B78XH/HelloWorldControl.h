#pragma once
#include "Control.h"

class HelloWorldControl : public Control {
public:
	explicit HelloWorldControl(const string& name)
		: Control(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
