#pragma once

#include "MSFS\MSFS_Render.h"
#include <MSFS\Legacy\gauges.h>
#include <vector>
#include "Application.h"
#include "MSFS/Render/nanovg.h"

class Display {
	protected:
		FsContext fsContext = 0;
		NVGcontext* nvgContext = nullptr;
		sGaugeDrawData* storedGaugeDrawData = nullptr;
		std::vector<int> fonts;
		std::vector<std::reference_wrapper<Application>> applications;
		virtual auto prepareApplications() -> void = 0;
		virtual auto setupApplications() -> void = 0;
		virtual auto addApplication(Application& application) -> void;
		virtual auto addFont(int font) -> void;
		virtual auto clearDisplay(double width, double height) -> void;
	public:
		virtual ~Display() = default;
		virtual auto preInstall() -> bool;
		virtual auto postInstall(FsContext context) -> bool final;
		virtual auto setupFonts() -> void;
		virtual auto preDraw(sGaugeDrawData* data) -> bool;
		virtual auto preKill() -> bool;
	private:
		virtual auto setupApplicationsContext() -> void final;
		virtual auto runApplicationsPostInstall() -> void final;
		virtual auto runApplicationsPreKill() -> void final;
};
