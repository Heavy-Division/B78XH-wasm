#pragma once
#include "LineControl.h"
#include "TCPLineControl.h"

class TCPRightLineControl: public TCPLineControl {
	public:
		explicit TCPRightLineControl(const string& name)
			: TCPLineControl(name) {
		}

		explicit TCPRightLineControl(const string& name, LINE_NUMBER lineNumber)
			: TCPLineControl(name) {
			lineNumber_ = lineNumber;
		}

	protected:
		auto setupControl() -> void override;
};
