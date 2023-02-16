#pragma once

#include "Control.h"

class FFControl : public Control {
public:
	explicit FFControl(const string& name)
		: Control(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
