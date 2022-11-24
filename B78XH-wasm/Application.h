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

};
