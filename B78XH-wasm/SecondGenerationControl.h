#pragma once
#include "BaseControl.h"

class SecondGenerationControl : public BaseControl {
	public:
		void prepareControls();
		auto render(sGaugeDrawData* data) -> void override;
	private:
		double lastZuluTime = 0;
};
