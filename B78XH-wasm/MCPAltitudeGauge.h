#pragma once
#include "BaseGauge.h"

class MCPAltitudeGauge: public BaseGauge {
	private:
		FsContext fsContext = 0;
		NVGcontext* nvgContext = nullptr;
		int altitudeFont = 0;

	public:
		bool preInstall() override;
		bool postInstall(FsContext context) override;
		bool preDraw(sGaugeDrawData* data) override;
		bool preKill() override;
};
