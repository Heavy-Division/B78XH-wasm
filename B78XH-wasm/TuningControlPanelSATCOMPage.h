#pragma once
#include "TuningControlPanelBasePage.h"

class TuningControlPanelSATCOMPage: public TuningControlPanelBasePage {
	public:
		void render(NVGcontext* context, float windowWidth, float windowHeight, float devicePixelRatio) override;
		void handleEvent(TuningControlPanelControlPageEventsID eventId) override;
		int numberOfPages = 2;
		int currentPage = 1;
	private:
		void renderLines(NVGcontext* context);
		void renderTitle(NVGcontext* context);
		void renderPages(NVGcontext* context);
};
