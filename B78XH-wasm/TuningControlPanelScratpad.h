#pragma once
#include "BaseScratchpad.h"

class TuningControlPanelScratchpad : public BaseScratchpad {
	public:
		void render() override;
		void handleEvent(TuningControlPanelControlScratchpadEventsID event) override;
};
