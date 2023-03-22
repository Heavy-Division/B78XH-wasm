#pragma once

#include "EICASBaseControl.h"

class OilTempControlRight : public EICASBaseControl {
public:
	explicit OilTempControlRight(const string& name)
		: EICASBaseControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};