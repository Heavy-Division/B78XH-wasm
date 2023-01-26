#pragma once
#include "Control.h"

class CDUPageControl : public Control {
	public:
		explicit CDUPageControl(const string& name)
			: Control(name) {
		}

		auto render() -> void override;
};
