#pragma once
#include "TCPPageControl.h"

class TCPHFPageControl: public TCPPageControl {
	public:
		explicit TCPHFPageControl(const string& name)
			: TCPPageControl(name) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
};
