#pragma once
#include "Control.h"

class HorizontalStabilizerControl : public Control {
public:
	explicit HorizontalStabilizerControl(const string& name)
		: Control(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;

private:

	void drawIndicator();


};

