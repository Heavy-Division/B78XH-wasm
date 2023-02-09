#pragma once
#include "TCPPageControl.h"

class TCPMENUPageControl : public TCPPageControl {
	public:
		TCPMENUPageControl(const string& name, std::shared_ptr<TCPScratchpadControl>& scratchPad)
			: TCPPageControl(name, scratchPad) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
};
