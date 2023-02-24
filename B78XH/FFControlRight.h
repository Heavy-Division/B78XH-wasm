#pragma once

#include "EICASCircularControl.h"

class FFControlRight : public EICASCircularControl {
public:
	explicit FFControlRight(const string& name)
		: EICASCircularControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
