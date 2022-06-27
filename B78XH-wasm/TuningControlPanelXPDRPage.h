#pragma once
#include "TuningControlPanelBasePage.h"

class TuningControlPanelXPDRPage: public TuningControlPanelBasePage {
	public:
		TuningControlPanelXPDRPage(TuningControlPanelScratchpad* scratchpad);
		void render(NVGcontext* context, float windowWidth, float windowHeight, float devicePixelRatio) override;
		void handleEvent(TuningControlPanelControlPageEventsID eventId) override;
	private:
		void renderLines(NVGcontext* context);
		void renderTitle(NVGcontext* context);
		void renderRightColoredLines(NVGcontext* context, float offset);
		void renderRightLines(NVGcontext* context, std::string text, float offset, FsColor* color = nullptr);
		void renderLeftColoredLines(NVGcontext* context, float offset);
};
