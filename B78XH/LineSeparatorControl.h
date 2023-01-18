#pragma once
#include "Control.h"

class LineSeparatorControl : public Control {
public:
	explicit LineSeparatorControl(const string& name)
		: Control(name) {}

	auto render() -> void override;
protected:

	auto setupControl() -> void override;


};
