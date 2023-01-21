#pragma once
#include "TCPPageControl.h"

class TCPCABPageControl: public TCPPageControl {
	public:
		explicit TCPCABPageControl(const string& name)
			: TCPPageControl(name, "") {
		}

		TCPCABPageControl(const string& name, const std::string& scratchpadBuffer)
			: TCPPageControl(name, scratchpadBuffer) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
};
