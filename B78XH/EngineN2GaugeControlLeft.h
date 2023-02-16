#pragma once

#include "EICASGauge.h"

class EngineN2GaugeControlLeft : public EICASGauge {
public:
	explicit EngineN2GaugeControlLeft(const string& name)
		: EICASGauge(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
