#pragma once
#include "LineControl.h"
#include "TCPLineControl.h"

class TCPCenterLineControl: public TCPLineControl {
	public:
		explicit TCPCenterLineControl(const string& name)
			: TCPLineControl(name) {
		}

		explicit TCPCenterLineControl(const string& name, LINE_NUMBER lineNumber)
			: TCPLineControl(name) {
			lineNumber_ = lineNumber;
		}

	protected:
		auto setupControl() -> void override;
};
