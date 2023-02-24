#pragma once

#include "EICASCircularControl.h"


class OilPressControlRight : public EICASCircularControl {
public:
	explicit OilPressControlRight(const string& name)
		: EICASCircularControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
