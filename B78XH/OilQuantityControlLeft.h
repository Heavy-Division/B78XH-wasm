#pragma once

#include "LowerEICASControl.h"

class OilQuantityControlLeft : public LowerEICASControl {
public:
	explicit OilQuantityControlLeft(const string& name)
		: LowerEICASControl(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;

};