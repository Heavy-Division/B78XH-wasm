#pragma once
#include "TCPPageControl.h"

class TCPHFPageControl: public TCPPageControl {
	public:
		explicit TCPHFPageControl(const string& name)
			: TCPPageControl(name, "") {
		}

		TCPHFPageControl(const string& name, const std::string& scratchpadBuffer)
			: TCPPageControl(name, scratchpadBuffer) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
};
