#pragma once

#include "EICASCircularControl.h"

class FFControlLeft : public EICASCircularControl {
public:
	explicit FFControlLeft(const string& name)
		: EICASCircularControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
