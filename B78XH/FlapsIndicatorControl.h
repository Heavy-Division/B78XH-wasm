#pragma once
#include "Control.h"


class FlapsIndicatorControl : public Control {
public:
	explicit FlapsIndicatorControl(const string& name)
		: Control(name) {}
	auto render() -> void override;
protected:
	auto setupControl() -> void override;

private:

	double flapsPercent = 0;
	int flapsAngleIndex();

	void drawFlapsAngleIndex();
	double flapsIndexIndicatorHeight();
};