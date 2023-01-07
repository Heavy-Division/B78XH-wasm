﻿#pragma once
#include "TCPPageControl.h"

class TCPCABPageControl: public TCPPageControl {
	public:
		explicit TCPCABPageControl(const string& name)
			: TCPPageControl(name) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
};
