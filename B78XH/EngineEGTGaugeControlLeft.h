#pragma once

#include "EICASCircularControl.h"

class EngineEGTGaugeControlLeft : public EICASCircularControl {
public:
	explicit EngineEGTGaugeControlLeft(const string& name)
		: EICASCircularControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;

};
