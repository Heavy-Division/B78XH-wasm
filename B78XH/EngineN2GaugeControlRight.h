#pragma once

#include "EICASCircularControl.h"

class EngineN2GaugeControlRight : public EICASCircularControl {
public:
	explicit EngineN2GaugeControlRight(const string& name)
		: EICASCircularControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
