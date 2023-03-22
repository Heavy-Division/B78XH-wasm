#pragma once
#include "LineControl.h"

class ThrustReferenceModeControl : public LineControl {
public:
	explicit ThrustReferenceModeControl(const string& name)
		: LineControl(name) {}

protected:
	auto setupControl() -> void override;
};
