#include "CDUPageControl.h"

#include "Tools/Console.h"

auto CDUPageControl::render() -> void {
	Control::render();

	nvgBeginPath(getContext());
	{
		nvgStrokeColor(getContext(), nvgRGB(255, 255, 255));
		nvgStrokeWidth(getContext(), 2.0f);
		nvgFillColor(getContext(), nvgRGB(0, 0, 0));
		nvgRect(getContext(), 0, 0, getRelativePosition().getWidth(), getRelativePosition().getHeight());
		nvgFill(getContext());
		nvgStroke(getContext());
	}
	nvgClosePath(getContext());
}

auto CDUPageControl::prepareControls() -> void {
	Control::prepareControls();
	add(pageTitle);

	add(leftLineTitleOne);
	add(leftLineTitleTwo);
	add(leftLineTitleThree);
	add(leftLineTitleFour);
	add(leftLineTitleFive);
	add(leftLineTitleSix);

	add(rightLineTitleOne);
	add(rightLineTitleTwo);
	add(rightLineTitleThree);
	add(rightLineTitleFour);
	add(rightLineTitleFive);
	add(rightLineTitleSix);

	add(leftLineOne);
	add(leftLineTwo);
	add(leftLineThree);
	add(leftLineFour);
	add(leftLineFive);
	add(leftLineSix);

	add(rightLineOne);
	add(rightLineTwo);
	add(rightLineThree);
	add(rightLineFour);
	add(rightLineFive);
	add(rightLineSix);

	add(centerLineOne);
	add(centerLineTwo);
	add(centerLineThree);
	add(centerLineFour);
	add(centerLineFive);
	add(centerLineSix);
}

void CDUPageControl::setupControls() {
	Control::setupControls();
}
