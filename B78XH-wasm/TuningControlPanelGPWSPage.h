#pragma once
#include "TuningControlPanelBasePage.h"

class TuningControlPanelGPWSPage: public TuningControlPanelBasePage {
	public:
		void render(NVGcontext* context, float windowWidth, float windowHeight, float devicePixelRatio) override;
	private:
		void renderLines(NVGcontext* context);
		void renderTitle(NVGcontext* context);
		void renderRightColoredLines(NVGcontext* context, float offset);
		void renderLeftColoredLines(NVGcontext* context, float offset);
};
