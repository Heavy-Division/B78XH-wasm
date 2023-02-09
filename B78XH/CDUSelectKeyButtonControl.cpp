#include "CDUSelectKeyButtonControl.h"

#include "Tools/Console.h"
#include "Tools/Tools.h"

auto CDUSelectKeyButtonControl::render() -> void {
	if(event) {
		CDUButtonControl::render();
	} else {
		drawBackBorders(Tools::Colors::cyan, 3.0f);
	}

	drawPointers();
	if (isInFocus() && event) {
		drawBorder();
	}
}

auto CDUSelectKeyButtonControl::calculateBounds() -> void {
	CDUButtonControl::calculateBounds();
	if (side_ == SelectKeySide::RIGHT) {
		bounds_[0] = bounds_[0] - 200;
	}
	else {
		bounds_[1] = bounds_[1] + 200;
	}
}

auto CDUSelectKeyButtonControl::drawBorder() -> void {
	nvgStrokeColor(getContext(), Tools::Colors::magenta);
	nvgStrokeWidth(getContext(), 5.0f);
	nvgBeginPath(getContext());
	{
		nvgMoveTo(getContext(), 0, 0);
		nvgLineTo(getContext(), (side_ == SelectKeySide::RIGHT ? (-200) : 200), 0);
		nvgLineTo(getContext(), (side_ == SelectKeySide::RIGHT ? (-200) : 200),  position.height);
		nvgLineTo(getContext(), 0, position.height);
		nvgStroke(getContext());
	}
	nvgClosePath(getContext());
}

auto CDUSelectKeyButtonControl::drawPointers() -> void {
	nvgStrokeWidth(getContext(), 1.5f);
	if(event) {
		nvgFillColor(getContext(), Tools::Colors::white);
	} else {
		nvgFillColor(getContext(), Tools::Colors::cyan);
	}

	nvgStrokeColor(getContext(), Tools::Colors::black);

	nvgBeginPath(getContext());
	{
		//nvgRoundedRect(getContext(), 0 + position.width + 5, position.height / 2 - 2, 19, 5, 2.0f);
		nvgRoundedRect(getContext(), (side_ == SelectKeySide::LEFT ? position.width + 5 : 0 - 5 - 19), position.height / 2 - 2, 19, 5, 2.0f);
	}
	nvgClosePath(getContext());
	nvgFill(getContext());
	nvgStroke(getContext());
}
