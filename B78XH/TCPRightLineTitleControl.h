#pragma once
#include "TCPLineControl.h"
#include "Tools/Tools.h"

class TCPRightLineTitleControl : public TCPLineControl {
	public:
		explicit TCPRightLineTitleControl(const string& name)
			: TCPLineControl(name) {
		}

		explicit TCPRightLineTitleControl(const string& name, LINE_NUMBER lineNumber)
			: TCPLineControl(name) {
			TCPLineControl::lineNumber_ = lineNumber;
		}

	protected:
		auto setupControl() -> void override;
};
