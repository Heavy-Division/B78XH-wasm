#pragma once
#include "EICASGauge.h"

class EngineN1GaugeControlRight : public EICASGauge {
public:
	explicit EngineN1GaugeControlRight(const string& name)
		: EICASGauge(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
