#include "LineDisplay.h"

auto LineDisplay::addLine(Line& line) -> void {
	this->lines.emplace_back(line);
}

auto LineDisplay::prepareLines() -> void {

}

auto LineDisplay::setupLines() -> void {

}

auto LineDisplay::setupLinesContext() -> void {
	for (auto line : lines) {
		line.get().setContext(this->nvgContext);
	}
}

auto LineDisplay::init() -> void {
}

auto LineDisplay::setContext(NVGcontext* nvgContext) -> void {
	this->nvgContext = nvgContext;
}
