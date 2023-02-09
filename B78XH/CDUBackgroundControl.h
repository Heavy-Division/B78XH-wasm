#pragma once
#include "Control.h"

class CDUBackgroundControl: public Control {
	public:
		explicit CDUBackgroundControl(const string& name)
			: Control(name) {
		}

		auto render() -> void override;
};
