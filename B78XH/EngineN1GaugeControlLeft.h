#pragma once
#include "EICASGauge.h"

class EngineN1GaugeControlLeft : public EICASGauge {
public:
	explicit EngineN1GaugeControlLeft(const string& name)
		: EICASGauge(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
