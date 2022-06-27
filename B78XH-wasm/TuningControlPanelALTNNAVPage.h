#pragma once
#include "TuningControlPanelBasePage.h"

class TuningControlPanelALTNNAVPage: public TuningControlPanelBasePage {
	public:
		void render(NVGcontext* context, float windowWidth, float windowHeight, float devicePixelRatio) override;
	private:
		void renderLines(NVGcontext* context);
		void renderTitle(NVGcontext* context);
};
