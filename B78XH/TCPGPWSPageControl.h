﻿#pragma once
#include "TCPPageControl.h"

class TCPGPWSPageControl: public TCPPageControl {
	public:
		explicit TCPGPWSPageControl(const string& name)
			: TCPPageControl(name, "") {
		}

		TCPGPWSPageControl(const string& name, const std::string& scratchpadBuffer)
			: TCPPageControl(name, scratchpadBuffer) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
};
