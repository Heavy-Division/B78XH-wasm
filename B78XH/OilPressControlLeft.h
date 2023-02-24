#pragma once
#include "EICASCircularControl.h"


class OilPressControlLeft : public EICASCircularControl {
public:
	explicit OilPressControlLeft(const string& name)
		: EICASCircularControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;
};
