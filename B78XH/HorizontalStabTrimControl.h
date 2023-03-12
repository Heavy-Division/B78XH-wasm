#pragma once

#include "EICASBaseControl.h"

class HorizontalStabTrimControl: public EICASBaseControl{
public:
	explicit HorizontalStabTrimControl(const string& name)
		: EICASBaseControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
	auto drawDataBox(double width, double height, int decimals, float fontSize) -> void override;
};



