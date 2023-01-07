#pragma once
#include "LineControl.h"

class TCPPagesLineControl: public LineControl {
	public:
		explicit TCPPagesLineControl(const string& name)
			: LineControl(name) {
		}

	protected:
		auto setupControl() -> void override;
};
