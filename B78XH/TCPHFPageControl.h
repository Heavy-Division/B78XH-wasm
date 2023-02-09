#pragma once
#include "TCPPageControl.h"

class TCPHFPageControl: public TCPPageControl {
	public:
		TCPHFPageControl(const string& name, std::shared_ptr<TCPScratchpadControl>& scratchPad)
			: TCPPageControl(name, scratchPad) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
};
