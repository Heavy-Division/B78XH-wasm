#pragma once
#include "MSFS/Render/nanovg.h"

class PFDVerticalSpeedIndicator {
	public:
		static void draw(NVGcontext* context, float windowWidth, float windowHeight);
	private:
		static void drawBackground(NVGcontext* context, float windowWidth, float windowHeight);
		static void drawGraduations(NVGcontext* context, float windowWidth, float windowHeight);
		static void drawCursor(NVGcontext* context, float windowWidth, float windowHeight);
		static void drawTargetPointer(NVGcontext* context, float windowWidth, float windowHeight);
};
