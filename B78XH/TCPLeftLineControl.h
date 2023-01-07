#pragma once
#include "LineControl.h"
#include "TCPLineControl.h"

class TCPLeftLineControl: public TCPLineControl {
	public:
		explicit TCPLeftLineControl(const string& name)
			: TCPLineControl(name) {
		}

		explicit TCPLeftLineControl(const string& name, LINE_NUMBER lineNumber)
			: TCPLineControl(name) {
			TCPLineControl::lineNumber_ = lineNumber;
		}

	protected:
		auto setupControl() -> void override;
};
