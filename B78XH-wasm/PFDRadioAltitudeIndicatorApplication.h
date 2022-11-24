#pragma once
#include "Application.h"
#include "Timer.h"

class PFDRadioAltitudeIndicatorApplication : public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;

	private:
		void drawBackground(bool highlight);
		void drawValue();
		bool shouldShowRadioAltitude() const;
		bool shouldHighlightRadioAltitude() const;
		bool shouldStartStartTimer() const;

		double passDelta = -1;
		double altitude = 0;
		double lastAltitude = 0;
		Timer deltaTimer = Timer(10);
};
