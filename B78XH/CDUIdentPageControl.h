#pragma once
#include "CDUPageControl.h"
#include "Control.h"

class CDUIdentPageControl : public CDUPageControl {
	public:
		explicit CDUIdentPageControl(const string& name)
			: CDUPageControl(name) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
};
