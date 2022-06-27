#pragma once
#include "TuningControlPanelBasePage.h"


class TuningControlPanelINOPPage: public TuningControlPanelBasePage {
	public:
		void loadData() override;
		void render(NVGcontext* context, float windowWidth, float windowHeight, float devicePixelRatio) override;
		TuningControlPanelINOPPage(const char* title);

	private:
		void renderInop(NVGcontext* context);
		void renderTitle(NVGcontext* context);
		const char* title = "INOPERABLE";
};
