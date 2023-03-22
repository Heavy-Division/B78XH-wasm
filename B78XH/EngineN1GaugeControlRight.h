#pragma once
#include "EICASCircularControl.h"

class EngineN1GaugeControlRight : public EICASCircularControl {
public:
	explicit EngineN1GaugeControlRight(const string& name)
		: EICASCircularControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
