#pragma once
#include "Application.h"

class RedApplication : public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;
};
