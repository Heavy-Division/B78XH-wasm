//    B78XH-wasm
//    Copyright (C) 2022  Heavy Division
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.


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
		bool autoClearing = true;
		virtual auto prepareApplications() -> void = 0;
		virtual auto setupApplications() -> void = 0;
		virtual auto addApplication(Application& application) -> void;
		virtual auto addFont(int font) -> void;
		virtual auto clearDisplay(double width, double height) -> void;
		virtual auto setAutoClearing(bool autoClearing) -> void final;
		virtual auto setupDisplay() -> void;
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
