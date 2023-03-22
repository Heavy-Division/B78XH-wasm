#pragma once

#include "EICASCircularControl.h"

class EngineEGTGaugeControlRight : public EICASCircularControl {
public:
	explicit EngineEGTGaugeControlRight(const string& name)
		: EICASCircularControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;

};
