#pragma once

#include "LowerEICASControl.h"


class OilQuantityControlRight : public LowerEICASControl {
public:
	explicit OilQuantityControlRight(const string& name)
		: LowerEICASControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;

};