#pragma once
#include "Application.h"

class GreenApplication : public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;

};
