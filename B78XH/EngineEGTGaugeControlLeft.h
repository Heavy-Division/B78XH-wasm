#pragma once

#include "EICASGauge.h"

class EngineEGTGaugeControlLeft : public EICASGauge {
public:
	explicit EngineEGTGaugeControlLeft(const string& name)
		: EICASGauge(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;

};
