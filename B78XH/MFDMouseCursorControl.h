#pragma once
#include "CDUMouseMoveResolver.h"
#include "Control.h"

class MFDMouseCursorControl : public Control {
	public:
		MFDMouseCursorControl(const string& name)
			: Control(name) {
		}

		auto render() -> void override;
};
