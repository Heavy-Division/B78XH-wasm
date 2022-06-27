#pragma once
#include "BaseGauge.h"

class MCPVSpeedGauge: public BaseGauge {
	private:
		FsContext fsContext = 0;
		NVGcontext* nvgContext = nullptr;
		int verticalSpeedFont = 0;
		int typeFont = 0;
		int verticalSpeedValueVariable = 0;
		int isFPAModeActiveVariable = 0;
		bool lastFPAModeActive = false;
		bool lastVerticalSpeedActive = false;

	public:
		bool preInstall() override;
		bool postInstall(FsContext context) override;
		bool preDraw(sGaugeDrawData* data) override;
		bool preKill() override;
};