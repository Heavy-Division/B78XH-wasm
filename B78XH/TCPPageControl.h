#pragma once
#include "Control.h"

class TCPPageControl: public Control {
	public:
		explicit TCPPageControl(const string& name)
			: Control(name) {
		}
};
