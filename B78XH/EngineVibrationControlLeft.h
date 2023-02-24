#pragma once

#include "LowerEICASControl.h"

class EngineVibrationControlLeft : public LowerEICASControl {
public:
	explicit EngineVibrationControlLeft(const string& name)
		: LowerEICASControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};