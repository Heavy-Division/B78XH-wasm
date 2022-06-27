#pragma once
#include "TuningControlPanelBasePage.h"

#include "BaseGauge.h"
#include "TuningControlPanelINOPPage.h"
#include "TuningControlPanelScratpad.h"

class TuningControlPanelRenderer {
	public:
		void render(TuningControlPanelControlSwitchID page, sGaugeDrawData* data);
		void renderOff(sGaugeDrawData* data);
		void setContext(FsContext context);
		void kill();
	private:
		NVGcontext* nvgContext = nullptr;
		void checkPage(TuningControlPanelControlSwitchID);
		TuningControlPanelBasePage* page = new TuningControlPanelINOPPage("INOP");
		TuningControlPanelScratchpad scratchpad = TuningControlPanelScratchpad();
};