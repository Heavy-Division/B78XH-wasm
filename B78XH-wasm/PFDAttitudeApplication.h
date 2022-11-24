#pragma once
#include "Application.h"

class PFDAttitudeApplication : public Application {
public:
		PFDAttitudeApplication() {
			this->setAutoCrop(true);
		}
		auto render(sGaugeDrawData* data) -> void override;
		auto postInstall() -> void override;
		void renderMainBackground();
		void renderAttitude();
		void renderPitch();
		void renderTriangle();
		void renderDashes();
		void renderDash(int angle, int length);
		void renderCursor();
		void renderSlipSkid();
	private:
		int slipSkidVariableId = 0;
		int slipSkidUnitsId = 0;

		double pitchPosition = 0;
		double centerPosition = 0;
};
