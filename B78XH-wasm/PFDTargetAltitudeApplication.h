#pragma once
#include "Application.h"

class PFDTargetAltitudeApplication : public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;
	private:
		void drawBackground() const;
		void drawValue() const;
};
