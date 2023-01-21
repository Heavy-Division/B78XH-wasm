#pragma once
#include "TCPPageControl.h"

class TCPXPDRPageControl: public TCPPageControl {
	public:
		explicit TCPXPDRPageControl(const string& name)
			: TCPPageControl(name, "") {
		}

		TCPXPDRPageControl(const string& name, const std::string& scratchpadBuffer)
			: TCPPageControl(name, scratchpadBuffer) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
};
