#pragma once
#include <MSFS/MSFS_Render.h>
#include <MSFS/Legacy/gauges.h>
#include "fmt/core.h"
#include "MSFS/Render/nanovg.h"
#include "GaugesInvalidateFlags.h"

class BaseGauge {
	public:
		virtual ~BaseGauge() = default;
		virtual bool preInstall() = 0;
		virtual bool postInstall(FsContext context) = 0;
		virtual bool preDraw(sGaugeDrawData* data) = 0;
		virtual bool preDraw(FsContext context, sGaugeDrawData* data) {
			return true;
		};
		virtual bool preKill() = 0;
};
