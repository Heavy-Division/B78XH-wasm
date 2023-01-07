#pragma once
#include "LineControl.h"

class TCPPageTitleControl: public LineControl {
	public:
		explicit TCPPageTitleControl(const string& name)
			: LineControl(name) {
		}

	protected:
		auto setupControl() -> void override;
};
