#pragma once
#include "Application.h"

class PFDAltitudeIndicatorApplication : public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;

	private:
		void drawBackground();
		void drawGraduations();
		void drawCursor();
		void drawTargetPointer();
		void drawGroundRibbon(double deltaTime);
		double groundReference = 0.0;
};
