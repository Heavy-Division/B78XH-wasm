#pragma once
#include "TCPPageControl.h"

class TCPWXRPageControl : public TCPPageControl {
	public:
		explicit TCPWXRPageControl(const string& name)
			: TCPPageControl(name, "") {
		}

		TCPWXRPageControl(const string& name, const std::string& scratchpadBuffer)
			: TCPPageControl(name, scratchpadBuffer) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
};
