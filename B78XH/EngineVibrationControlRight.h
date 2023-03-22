#pragma once
#include "LowerEICASControl.h"

class EngineVibrationControlRight : public LowerEICASControl {
public:
	explicit EngineVibrationControlRight(const string& name)
		: LowerEICASControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
