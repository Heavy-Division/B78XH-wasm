#pragma once
#include "Application.h"

class PFDBaroIndicatorApplication : public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;

	private:
		void drawValue(bool isBaroInHPA) const;
		void drawUnits(bool isBaroInHPA) const;
		void drawSTD() const;
};
