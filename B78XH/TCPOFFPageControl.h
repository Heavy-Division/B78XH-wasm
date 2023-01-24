#pragma once
#include "TCPPageControl.h"

class TCPOFFPageControl : public TCPPageControl {
	public:
		TCPOFFPageControl(const string& name, std::shared_ptr<TCPScratchpadControl>& scratchPad)
			: TCPPageControl(name, scratchPad) {
			scratchPad_->setEventsDisabled(true);
		}
};
