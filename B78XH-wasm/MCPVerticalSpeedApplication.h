#pragma once
#include "Application.h"

class MCPVerticalSpeedApplication: public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;
	private:
		auto renderMode() -> void;
		auto renderValue() -> void;
		auto clearApplication() -> void;
		auto isControlInvalid() -> bool;
		auto invalidateControl() -> void;
		auto needRedraw() -> bool;
		bool fpaModeActive = false;
		bool verticalSpeedModeActive = false;
		bool lastFPAModeActive = false;
		bool lastVerticalSpeedModeActive = false;
};
