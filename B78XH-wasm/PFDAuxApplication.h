#pragma once
#include "Application.h"

class PFDAuxApplication: public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;
	protected:
		void renderMainBackground() const;
		void renderBackground() const;
		void renderMainBorders() const;
		void renderBorders() const;
		void renderAnalogClock();
		void renderAnalogClockBody() const;
		void renderAnalogClockMarkers();
		void renderTexts() const;
		void drawAnalogClockMarker(int angle, bool isBold = false) const;
		void drawAnalogClockHands(int hours, int minutes, double seconds) const;
		void renderChronoDigital();
		void renderBottomSection();
	private:
		double chronoTime = 0;
		double flightStartTime = 0;
};
