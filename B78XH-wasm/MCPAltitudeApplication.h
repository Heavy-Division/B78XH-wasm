#pragma once
#include "Application.h"

class MCPAltitudeApplication: public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;
	private:
		auto clearApplication() -> void;
};
