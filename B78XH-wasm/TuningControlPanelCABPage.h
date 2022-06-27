#pragma once
#include "TuningControlPanelBasePage.h"

class TuningControlPanelCABPage: public TuningControlPanelBasePage {
	public:
		void render(NVGcontext* context, float windowWidth, float windowHeight, float devicePixelRatio) override;
		void renderLines(NVGcontext* context);
		void renderTitle(NVGcontext* context);
};
