#pragma once
#include "TCPPageControl.h"

class TCPGPWSPageControl: public TCPPageControl {
	public:
		explicit TCPGPWSPageControl(const string& name)
			: TCPPageControl(name) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
};
