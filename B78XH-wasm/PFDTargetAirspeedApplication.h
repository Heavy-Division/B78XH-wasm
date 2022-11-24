#pragma once
#include "Application.h"

class PFDTargetAirspeedApplication : public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;

	private:
		void drawBackground() const;
		void drawValue() const;
};
