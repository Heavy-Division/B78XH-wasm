#pragma once
#include "TCPLineControl.h"

class TCPLeftLineTitleControl: public TCPLineControl {
	public:
		explicit TCPLeftLineTitleControl(const string& name)
			: TCPLineControl(name) {
		}

		explicit TCPLeftLineTitleControl(const string& name, LINE_NUMBER lineNumber)
			: TCPLineControl(name) {
			TCPLineControl::lineNumber_ = lineNumber;
		}

	protected:
		auto setupControl() -> void override;
};
