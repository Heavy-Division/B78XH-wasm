#pragma once
#include "BaseControl.h"

class FirstGenerationControl : public BaseControl {
public:
	void prepareControls();
	auto render(sGaugeDrawData* data) -> void override;
	std::string name = "-[FIRSTCONTROL]";
};
