#pragma once
#include <string>
#include "ScratchpadEvents.h"

class BaseScratchpad {
	public:
	int position[2] = { 0, 0 };
	int size[2] = { 0, 0 };
	std::string buffer;
	virtual void render() = 0;
	virtual void handleEvent(TuningControlPanelControlScratchpadEventsID event){};
		void clearBuffer() {
			this->buffer = "";
		}
};
