#include "CDUPageControl.h"

#include "Tools/Console.h"

auto CDUPageControl::render() -> void {
	Control::render();

	nvgBeginPath(getContext());
	{
		nvgFillColor(getContext(), nvgRGB(0, 0, 0));
		nvgRect(getContext(), 0, 0, getPosition().getWidth(), getPosition().getHeight());
		nvgFill(getContext());
	}
	nvgClosePath(getContext());
}
