#pragma once
#include "Application.h"

class PFDMinimumIndicatorApplication: public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;
};
