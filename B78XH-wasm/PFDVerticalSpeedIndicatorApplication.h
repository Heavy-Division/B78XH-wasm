#pragma once
#include "Application.h"

class PFDVerticalSpeedIndicatorApplication: public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;
		void drawGraduations();
		void drawCursor();
		void drawTargetPointer();
		void drawBackground();
};
