#pragma once
#include "EICASCircularControl.h"

class EngineN1GaugeControlLeft : public EICASCircularControl {
public:
	explicit EngineN1GaugeControlLeft(const string& name)
		: EICASCircularControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
