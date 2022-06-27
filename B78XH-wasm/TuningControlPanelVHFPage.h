#pragma once
#include "TuningControlPanelBasePage.h"

class TuningControlPanelVHFPage: public TuningControlPanelBasePage {
	public:
		TuningControlPanelVHFPage(TuningControlPanelScratchpad* scratchpad);
		void loadData() override;
		void render(NVGcontext* context, float windowWidth, float windowHeight, float devicePixelRatio) override;
		void handleEvent(TuningControlPanelControlPageEventsID eventId) override;
		int numberOfPages;
		int currentPage = 1;
		int selectedStandbyFrequency = 0;
	private:
		void renderLines(NVGcontext* context);
		void renderTitle(NVGcontext* context);
		void renderPages(NVGcontext* context);
		void renderActive(NVGcontext* context);
};
