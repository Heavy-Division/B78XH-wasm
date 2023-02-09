#pragma once
#include "CDUPageControl.h"

class CDURoutePageControl : public CDUPageControl {
	public:
		explicit CDURoutePageControl(const string& name)
			: CDUPageControl(name) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
};
