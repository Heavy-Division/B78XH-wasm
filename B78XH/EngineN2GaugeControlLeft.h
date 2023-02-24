#pragma once

#include "EICASCircularControl.h"

class EngineN2GaugeControlLeft : public EICASCircularControl {
public:
	explicit EngineN2GaugeControlLeft(const string& name)
		: EICASCircularControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
