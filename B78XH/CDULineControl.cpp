#include "CDULineControl.h"

#include "Tools/Console.h"
#include "Tools/Tools.h"

auto CDULineControl::renderContentAlignLeft() -> void {
	prepareDefaults();

	float prevBounds[4] = {0, 0, 0, 0};
	float nextBounds[4] = {0, 0, 0, 0};
	float bounds[4] = {0, 0, 0, 0};


	nvgBeginPath(getContext());
	{
		for (int i = 0; i < getContentHolder().getContent().size(); i++) {
			prepareColor(i);
			prepareFontSize(i);
			prepareAlign(i);
			float verticalOffset = getContentHolder().getChunkContentVerticalOffset(i);
			auto textToRender = getContentHolder().getContent().at(i)[0].c_str();
			prevBounds[0] = bounds[0];
			prevBounds[1] = bounds[1];
			prevBounds[2] = bounds[2];
			prevBounds[3] = bounds[3];
			nvgTextBounds(getContext(), bounds[2], verticalOffset, textToRender, nullptr, nextBounds);
			if (isSettable(i)) {
				renderSelectable(prevBounds[0], nextBounds[2], false);
			}
			nvgText(getContext(), bounds[2], verticalOffset, textToRender, nullptr);
			nvgTextBounds(getContext(), bounds[2], verticalOffset, textToRender, nullptr, bounds);
		}
	}
	nvgClosePath(getContext());
	nvgFill(getContext());
}

auto CDULineControl::isSettable(int chunkNumber) -> bool {
	if (getContentHolder().getContent().at(chunkNumber)[1].find("settable") != std::string::npos) {
		return true;
	}
	return false;
}

auto CDULineControl::renderContentAlignRight() -> void {
	prepareDefaults();
	float bounds[4] = { 0, 0, 0, 0 };
	float prevBounds[4] = { 0, 0, 0, 0 };
	float nextBounds[4] = { 0, 0, 0, 0 };
	float fixedNextBounds[4] = { 0, 0, 0, 0 };
	float fixedPrevBounds[4] = { 0, 0, 0, 0 };

	float width = 0;

	nvgBeginPath(getContext());
	{
		for (int i = 0; i < getContentHolder().getContent().size(); i++) {
			prepareColor(i);
			prepareFontSize(i);
			prepareAlign(i);
			float verticalOffset = getContentHolder().getChunkContentVerticalOffset(i);
			auto textToRender = getContentHolder().getContent().at(i)[0].c_str();
			prevBounds[0] = bounds[0];
			prevBounds[1] = bounds[1];
			prevBounds[2] = bounds[2];
			prevBounds[3] = bounds[3];
			nvgTextBounds(getContext(), 0, verticalOffset, textToRender, nullptr, nextBounds);
			width = width + (nextBounds[2] - nextBounds[0]);
			fixedNextBounds[0] = nextBounds[0];
			fixedNextBounds[1] = nextBounds[1];
			fixedNextBounds[2] = prevBounds[2];
			fixedNextBounds[3] = nextBounds[3];
			fixedPrevBounds[0] = nextBounds[2];
			fixedPrevBounds[1] = prevBounds[1];
			fixedPrevBounds[2] = prevBounds[2];
			fixedPrevBounds[0] = prevBounds[0];
			if (isSettable(i)) {
				renderSelectable(-nextBounds[2], nextBounds[0], true);
			}
			nvgText(getContext(), -width, verticalOffset, textToRender, nullptr);
		}
	}
	nvgClosePath(getContext());
	nvgFill(getContext());
}

auto CDULineControl::renderSelectable(float x1, float x2, bool backward) -> void {
	constexpr float borderWidth = 3.0f;
	//const float rightXPosition = nextBounds[2] + 5.0f;
	const float rightXPosition = x2 + 5.0f;
	//const float leftXPosition = -(prevBounds[2] -prevBounds[0]) - 5.0f;
	const float leftXPosition = x1 - 5.0f;
	constexpr float topYPosition = -16.0f;
	constexpr float bottomYPosition = 12.0f;

	nvgBeginPath(this->context);
	{
		nvgFillColor(this->context, Tools::Colors::cduButtonGray);
		nvgRect(this->context, leftXPosition, -16, std::abs(leftXPosition - rightXPosition), 28);
	}
	nvgClosePath(this->context);
	nvgFill(this->context);

	/*
	 * Settable borders
	 */

	/*
	 * Be aware:
	 * Borders do not have shape:
	 *  ________________
	 *  \              /
	 *   \____________/
	 *
	 * the shape is:
	 *   _______________
	 *  |              /
	 *  |_____________/
	 *
	 * this shape prevent background leak in corners
	 *
	 */
	{
		/*
		 * Top Border
		 * Be aware the rendering is reversed!! Because of backward rendering of text the preSettableBounds are actually bounds for right side
		 */
		nvgFillColor(this->context, Tools::Colors::cduSettableBorderTopGray);
		nvgBeginPath(this->context);
		{
			/*
			 * Begin
			 */
			nvgMoveTo(this->context, rightXPosition, topYPosition);
			/*
			 * Top line
			 */
			nvgLineTo(this->context, leftXPosition, topYPosition);
			/*
			 * Left line
			 */
			nvgLineTo(this->context, leftXPosition, topYPosition + borderWidth);
			/*
			 * Bottom line
			 */
			nvgLineTo(this->context, rightXPosition, topYPosition + borderWidth);
			/*
			 * Right line
			 */
			nvgLineTo(this->context, rightXPosition, topYPosition);
		}
		nvgClosePath(this->context);
		nvgFill(this->context);

		/*
		 * RIGHT
		 */
		nvgFillColor(this->context, Tools::Colors::cduSettableBorderRightGray);
		nvgBeginPath(this->context);
		{
			/*
			 * Begin
			 */
			nvgMoveTo(this->context, rightXPosition, topYPosition);
			/*
			 * Top line
			 */
			nvgLineTo(this->context, rightXPosition - borderWidth, topYPosition + borderWidth);
			/*
			 * Left line
			 */
			nvgLineTo(this->context, rightXPosition - borderWidth, bottomYPosition);
			/*
			 * Bottom line
			 */
			nvgLineTo(this->context, rightXPosition, bottomYPosition);
			/*
			 * Right line
			 */
			nvgLineTo(this->context, rightXPosition, topYPosition);
		}
		nvgClosePath(this->context);
		nvgFill(this->context);

		/*
		 * Bottom Border
		 * Be aware the rendering is reversed!! Because of backward rendering of text the preSettableBounds are actually bounds for right side
		 */
		nvgFillColor(this->context, Tools::Colors::cduSettableBorderBottomGray);
		nvgBeginPath(this->context);
		{
			/*
			 * Begin
			 */
			nvgMoveTo(this->context, rightXPosition - borderWidth, bottomYPosition - borderWidth);
			/*
			 * Top line
			 */
			nvgLineTo(this->context, leftXPosition, bottomYPosition - borderWidth);
			/*
			 * Left line
			 */
			nvgLineTo(this->context, leftXPosition, bottomYPosition);
			/*
			 * Bottom line
			 */
			nvgLineTo(this->context, rightXPosition, bottomYPosition);
			/*
			 * Right line
			 */
			nvgLineTo(this->context, rightXPosition - borderWidth, bottomYPosition - borderWidth);
		}
		nvgClosePath(this->context);
		nvgFill(this->context);

		/*
		 * Left
		 */
		nvgFillColor(this->context, Tools::Colors::cduSettableBorderLeftGray);
		nvgBeginPath(this->context);
		{
			/*
			 * Begin
			 */
			nvgMoveTo(this->context, leftXPosition, topYPosition);
			/*
			 * Top line
			 */
			nvgLineTo(this->context, leftXPosition + borderWidth, topYPosition + borderWidth);
			/*
			 * Left line
			 */
			nvgLineTo(this->context, leftXPosition + borderWidth, bottomYPosition - borderWidth);
			/*
			 * Bottom line
			 */
			nvgLineTo(this->context, leftXPosition, bottomYPosition);
			/*
			 * Right line
			 */
			nvgLineTo(this->context, leftXPosition, topYPosition);
		}
		nvgClosePath(this->context);
		nvgFill(this->context);
	}
}

void CDULineControl::renderContentAlignCenter() {
	prepareDefaults();

	float boundsPreCalculated[4] = { 0, 0, 0, 0 };
	float width = 0;

	for (int i = 0; i < getContentHolder().getContent().size(); i++) {
		prepareFontSize(i);
		nvgTextBounds(getContext(), 0, 0, getContentHolder().getContent().at(i)[0].c_str(), nullptr, boundsPreCalculated);
		width = width + boundsPreCalculated[2];
	}

	float bounds[4] = { 0, 0, 0, 0 };
	nvgSave(getContext());
	{
		nvgTranslate(getContext(), -(width / 2), 0);
		{
			nvgBeginPath(getContext());
			{
				for (int i = 0; i < getContentHolder().getContent().size(); i++) {
					prepareColor(i);
					prepareFontSize(i);
					prepareAlign(i);
					float verticalOffset = getContentHolder().getChunkContentVerticalOffset(i);
					auto textToRender = getContentHolder().getContent().at(i)[0].c_str();
					nvgText(getContext(), bounds[2], verticalOffset, textToRender, nullptr);
					nvgTextBounds(getContext(), bounds[2], verticalOffset, textToRender, nullptr, bounds);
				}
			}
			nvgClosePath(getContext());
			nvgFill(getContext());
		}
		nvgResetTransform(getContext());
	}
	nvgRestore(getContext());
}
