#pragma once
#include "TCPPageControl.h"

class TCPVHFPageControl: public TCPPageControl {
	public:
		explicit TCPVHFPageControl(const string& name)
			: TCPPageControl(name) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
};
