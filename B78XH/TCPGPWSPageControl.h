#pragma once
#include "TCPPageControl.h"

class TCPGPWSPageControl: public TCPPageControl {
	public:
		TCPGPWSPageControl(const string& name, std::shared_ptr<TCPScratchpadControl>& scratchPad)
			: TCPPageControl(name, scratchPad) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
};
