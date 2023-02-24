#pragma once

#include "EICASBaseControl.h"

class OilTempControlLeft : public EICASBaseControl {
public:
	explicit OilTempControlLeft(const string& name)
		: EICASBaseControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};