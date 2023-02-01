#pragma once
#include "LineControl.h"

class EICASAdvisoryDispatch : public LineControl {
public:
	explicit EICASAdvisoryDispatch(const string& name)
		: LineControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
};
