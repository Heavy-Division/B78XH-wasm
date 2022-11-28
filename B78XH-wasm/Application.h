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
#include "Console.h"
#include <MSFS/Legacy/gauges.h>
#include "MSFS/Render/nanovg.h"

class Application {
	public:
		virtual ~Application() = default;

		auto setAutoCrop(bool autoCrop) -> void {
			this->autoCrop = autoCrop;
		}

		auto getAutoCrop() const -> bool {
			return this->autoCrop;
		}

		void setContext(NVGcontext* nvgContext) {
			this->nvgContext = nvgContext;
		}

		void setMargin(double left, double top) {
			this->marginLeft = left;
			this->marginTop = top;
		}

		void setCropMargin(double left, double top) {
			this->cropMarginLeft = left;
			this->cropMarginTop = top;
		}

		void setSize(double width, double height) {
			this->width = width;
			this->height = height;
		}

		void setWidth(double width) {
			this->width = width;
		}

		void setHeight(double height) {
			this->height = height;
		}

		auto getWidth() const -> double {
			return this->width;
		}

		auto getHeight() const -> double {
			return this->height;
		}

		auto getMarginLeft() const -> double {
			return this->marginLeft;
		}

		auto getMarginTop() const -> double {
			return this->marginTop;
		}

		auto getCropMarginLeft() const -> double {
			return this->cropMarginLeft;
		}

		auto getCropMarginTop() const -> double {
			return this->cropMarginTop;
		}

		virtual auto postInstall() -> void {
			
		};

		virtual auto preKill() -> void {

		};

		virtual auto render(sGaugeDrawData* data) -> void {

		};


	protected:
		NVGcontext* nvgContext = nullptr;
		bool autoCrop = false;
		double marginLeft = 0;
		double marginTop = 0;
		double width = 0;
		double height = 0;
		double cropMarginLeft = 0;
		double cropMarginTop = 0;

};
