#pragma once
#include "Control.h"

class EngineN1GaugeControl : public Control {
public:
	explicit EngineN1GaugeControl(const string& name)
		: Control(name) {}

	auto render() -> void override;

protected:
	auto setupControls() -> void override;
};
