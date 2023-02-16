#pragma once

#include "EICASGauge.h"

class EngineN2GaugeControlRight : public EICASGauge {
public:
	explicit EngineN2GaugeControlRight(const string& name)
		: EICASGauge(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
