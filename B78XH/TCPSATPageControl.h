#pragma once
#include "TCPPageControl.h"

class TCPSATPageControl: public TCPPageControl {
	public:
		explicit TCPSATPageControl(const string& name)
			: TCPPageControl(name, "") {
		}

		TCPSATPageControl(const string& name, const std::string& scratchpadBuffer)
			: TCPPageControl(name, scratchpadBuffer) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
};
