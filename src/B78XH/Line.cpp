#include "Line.h"

#include "MSFS/Render/nanovg.h"

auto Line::render() -> void {
}

auto Line::setContext(NVGcontext* nvgContext) -> void {
	this->nvgContext = nvgContext;
}
