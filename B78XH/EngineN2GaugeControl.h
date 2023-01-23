#pragma once

#include "Control.h"

class EngineN2GaugeControl : public Control {
public:
	explicit EngineN2GaugeControl(const string& name)
		: Control(name) {}

	auto render() -> void override;

protected:
	auto setupControls() -> void override;
};
