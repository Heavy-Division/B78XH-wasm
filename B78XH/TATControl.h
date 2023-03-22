#pragma once

#include "LineControl.h"

class TATControl : public LineControl {
public:
	explicit TATControl(const string& name)
		: LineControl(name) {}

protected:
	auto setupControl() -> void override;

};