#pragma once
#include "Application.h"


class PFDFlightDirectorApplication : public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;

	private:
		void drawHeading(double deltaTime);
		void drawPitch(double deltaTime);
		double flightDirectorBank = 0;
		double flightDirectorPitch = 0;
};
