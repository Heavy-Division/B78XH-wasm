#pragma once
#include "MSFS/Render/nanovg.h"

class Line {
	public:
		virtual auto render() -> void;
		auto setContext(NVGcontext* nvgContext) -> void;
	protected:
		~Line() = default;
		double height = 0;
		double width = 0;
		double marginLeft = 0;
		double marginRight = 0;
		NVGcontext* nvgContext = nullptr;
};
