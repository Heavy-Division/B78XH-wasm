#include "MFDMouseCursorControl.h"

#include "Tools/Tools.h"

auto MFDMouseCursorControl::render() -> void {
	Control::render();
	nvgStrokeColor(getContext(), Tools::Colors::magenta);
	nvgStrokeWidth(getContext(), 2.0f);
	nvgBeginPath(getContext());
	{
		nvgMoveTo(getContext(), 10, 0);
		nvgLineTo(getContext(), 10, 10);
		nvgLineTo(getContext(), 0, 10);

		nvgMoveTo(getContext(), 15, 0);
		nvgLineTo(getContext(), 15, 10);
		nvgLineTo(getContext(), 25, 10);

		nvgMoveTo(getContext(), 0, 15);
		nvgLineTo(getContext(), 10, 15);
		nvgLineTo(getContext(), 10, 25);

		nvgMoveTo(getContext(), 25, 15);
		nvgLineTo(getContext(), 15, 15);
		nvgLineTo(getContext(), 15, 25);
		nvgMoveTo(getContext(), 10, 0);
	}
	nvgClosePath(getContext());
	nvgStroke(getContext());
}
