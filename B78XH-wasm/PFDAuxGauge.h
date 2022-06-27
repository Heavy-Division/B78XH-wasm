
#pragma once

#include "BaseGauge.h"
#include "MSFS/Render/nanovg.h"

class PFDAuxGauge: public BaseGauge {
	public:
		bool preInstall() override;
		bool postInstall(FsContext context) override;
		bool preDraw(sGaugeDrawData* data) override;
		bool preDraw(FsContext context, sGaugeDrawData* data) override;
		void renderMainBackground();
		void renderBackground();
		void renderMainBorders();
		void renderBorders();
		void renderAnalogClock();
		void renderAnalogClockBody();
		void renderAnalogClockMarkers();
		void renderTexts();
		void drawAnalogClockMarker(int angle, bool isBold = false);
		void drawAnalogClockHands(int hours, int minutes, double seconds);
		void renderChronoDigital();
		void renderBottomSection();
		bool preKill() override;
	private:
		FsContext fsContext = 0;
		NVGcontext* nvgContext = 0;
		float devicePixelRatio = 0;
		float windowWidth = 0;
		float windowHeight = 0;
		double chronoTime = 0;
		double flightStartTime = 0;
		double upscaleRatio = 1;
		double throttleTimeCheck = 0;
};
