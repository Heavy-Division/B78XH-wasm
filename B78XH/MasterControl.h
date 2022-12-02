#pragma once
#include "BaseControl.h"

class MasterControl : public BaseControl {
	public:
		auto prepareControls() -> void override;
		auto render(sGaugeDrawData* pData) -> void override;
		std::string name = "[MASTERCONTROL]";
};
