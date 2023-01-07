#pragma once
#include "TCPLineControl.h"

class TCPCenterLineTitleControl: public TCPLineControl {
public:
	explicit TCPCenterLineTitleControl(const string& name)
		: TCPLineControl(name) {
	}

	explicit TCPCenterLineTitleControl(const string& name, LINE_NUMBER lineNumber)
		: TCPLineControl(name) {
		TCPLineControl::lineNumber_ = lineNumber;
	}

protected:
	auto setupControl() -> void override;
};
