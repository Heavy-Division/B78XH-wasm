#pragma once

#include "EICASGauge.h"

class EngineEGTGaugeControlRight : public EICASGauge {
public:
	explicit EngineEGTGaugeControlRight(const string& name)
		: EICASGauge(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;

};
