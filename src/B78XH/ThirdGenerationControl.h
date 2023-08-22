#pragma once
#include "BaseControl.h"

class ThirdGenerationControl: public BaseControl {
	public:
		auto render(sGaugeDrawData* data) -> void override;
		void prepareControls();
	private:
	double lastZuluTime = 0;
};
