#pragma once

#include "Control.h"
#include "Simplane.h"

class OilQuantityControl : public Control {
public:
	explicit OilQuantityControl(const string& name)
		: Control(name) {}

	auto render() -> void override;

protected:
	auto setupControl() -> void override;

private:
	double oilQty_eng1;
	double oilQty_eng2;


};