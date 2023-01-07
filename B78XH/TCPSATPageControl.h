#pragma once
#include "TCPPageControl.h"

class TCPSATPageControl: public TCPPageControl {
	public:
		explicit TCPSATPageControl(const string& name)
			: TCPPageControl(name) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
};
