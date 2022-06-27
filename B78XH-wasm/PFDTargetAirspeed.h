#pragma once
#include "MSFS/Render/nanovg.h"

class PFDTargetAirspeed {
	public:
		static void draw(NVGcontext* context, float windowWidth, float windowHeight);
	private:
		static void drawBackground(NVGcontext* context, float windowWidth, float windowHeight);
		static void drawValue(NVGcontext* context, float windowWidth, float windowHeight);

};

