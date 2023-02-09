#include "CDUButtonControl.h"
#include "Tools/Tools.h"

auto CDUButtonControl::render() -> void {
	Control::render();
	drawBackBorders();
	drawBackground();
	drawButtonBorders();
}

auto CDUButtonControl::drawBackground() -> void {
	nvgFillColor(getContext(), Tools::Colors::cduButtonGray);
	nvgBeginPath(getContext());
	{
		nvgRect(getContext(), 0, 0, getRelativePosition().getWidth(), getRelativePosition().getHeight());
		nvgFill(getContext());
	}
	nvgClosePath(getContext());
}

auto CDUButtonControl::drawButtonBorders() -> void {
	constexpr auto left = 0;
	constexpr auto top = 0;
	const auto width = getRelativePosition().getWidth();
	const auto height = getRelativePosition().getHeight();

	/*
	 * Top border
	 */

	nvgFillColor(getContext(), Tools::Colors::cduButtonBorderTopGray);
	nvgBeginPath(getContext());
	{
		nvgMoveTo(getContext(), left, top);
		nvgLineTo(getContext(), (left + width), top);
		nvgLineTo(getContext(), (left + width - borderWidth_), (top + borderWidth_));
		nvgLineTo(getContext(), (left + borderWidth_), (top + borderWidth_));
		nvgLineTo(getContext(), left, top);
	}
	nvgClosePath(getContext());
	nvgFill(getContext());

	/*
	 * Right Border
	 */

	nvgFillColor(getContext(), Tools::Colors::cduButtonBorderRightGray);
	nvgBeginPath(getContext());
	{
		nvgMoveTo(getContext(), (left + width), top);
		nvgLineTo(getContext(), (left + width), (top + height) + 1);
		nvgLineTo(getContext(), (left + width - borderWidth_), (top + height - borderWidth_) + 1);
		nvgLineTo(getContext(), (left + width - borderWidth_), (top + borderWidth_));
		nvgLineTo(getContext(), (left + width), (top));
	}
	nvgClosePath(getContext());
	nvgFill(getContext());

	/*
	 * Bottom Border
	 */

	nvgFillColor(getContext(), Tools::Colors::cduButtonBorderBottomGray);
	nvgBeginPath(getContext());
	{
		nvgMoveTo(getContext(), left, (top + height));
		nvgLineTo(getContext(), (left + width), (top + height));
		nvgLineTo(getContext(), (left + width - borderWidth_), (top + height - borderWidth_));
		nvgLineTo(getContext(), (left + borderWidth_), (top + height - borderWidth_));
		nvgLineTo(getContext(), (left), (top + height));
	}
	nvgClosePath(getContext());
	nvgFill(getContext());

	/*
	 * Left Border
	 */

	nvgFillColor(getContext(), Tools::Colors::cduButtonBorderLeftGray);
	nvgBeginPath(getContext());
	{
		nvgMoveTo(getContext(), left, top);
		nvgLineTo(getContext(), (left + borderWidth_), (top + borderWidth_));
		nvgLineTo(getContext(), (left + borderWidth_), (top + height - borderWidth_));
		nvgLineTo(getContext(), (left), (top + height));
		nvgLineTo(getContext(), (left), (top));
	}
	nvgClosePath(getContext());
	nvgFill(getContext());
}

auto CDUButtonControl::drawBackBorders(NVGcolor color, float width) -> void {
	nvgStrokeWidth(getContext(), width);
	nvgStrokeColor(getContext(), color);
	nvgBeginPath(getContext());
	{
		nvgRoundedRect(getContext(), -1, -1, getRelativePosition().width + 2, getRelativePosition().height + 2, 2.0f);
		nvgStroke(getContext());
	}
	nvgClosePath(getContext());
}

auto CDUButtonControl::drawBackBorders() -> void {
	drawBackBorders(Tools::Colors::black, 4.0f);
}

auto CDUButtonControl::prepareControls() -> void {
	Control::prepareControls();

	if (!title_.empty() && title2_.empty()) {
		add(std::make_shared<LineControl>("TITLE_ONE"));
	}
	else if (!title_.empty() && !title2_.empty()) {
		add(std::make_shared<LineControl>("TITLE_ONE"));
		add(std::make_shared<LineControl>("TITLE_TWO"));
	}
}

auto CDUButtonControl::setupControls() -> void {
	Control::setupControls();
	const auto left = 0;
	const auto top = 0;
	const auto width = getRelativePosition().getWidth();
	const auto height = getRelativePosition().getHeight();

	if (!title_.empty() && title2_.empty()) {
		auto& titleOne = getControl("TITLE_ONE");
		titleOne->getContentHolder().setAlign(ContentHolder::ALIGN::CENTER);
		titleOne->getRelativePosition().setPosition(left + (width / 2), top + (height / 2), 0, 0);
		titleOne->getContentHolder().setDefaultFontSize(26);
		titleOne->addOnBeforeRender([this](BaseControl& control) -> bool {
			control.getContentHolder().setContent({{title_}});
			return true;
		});
	}
	else if (!title_.empty() && !title2_.empty()) {
		auto& titleOne = getControl("TITLE_ONE");
		auto& titleTwo = getControl("TITLE_TWO");
		titleOne->getContentHolder().setDefaultFontSize(26);
		titleOne->getContentHolder().setAlign(ContentHolder::ALIGN::CENTER);
		titleOne->getRelativePosition().setPosition(left + (width / 2), top + (height / 2) - 10, 0, 0);
		titleOne->addOnBeforeRender([this](BaseControl& control) -> bool {
			control.getContentHolder().setContent({{title_}});
			return true;
		});

		titleTwo->getContentHolder().setDefaultFontSize(26);
		titleTwo->getContentHolder().setAlign(ContentHolder::ALIGN::CENTER);
		titleTwo->getRelativePosition().setPosition(left + (width / 2), top + (height / 2) + 14, 0, 0);
		titleTwo->addOnBeforeRender([this](BaseControl& control) -> bool {
			control.getContentHolder().setContent({{title2_}});
			return true;
		});
	}
}

auto CDUButtonControl::calculateBounds() -> void {
	bounds_[0] = absolutePosition.left;
	bounds_[1] = absolutePosition.left + position.width;
	bounds_[2] = absolutePosition.top;
	bounds_[3] = absolutePosition.top + position.height;
}

auto CDUButtonControl::isInFocus() -> bool {
	calculateBounds();
	if (mouseMove_.x >= bounds_[0] &&
		mouseMove_.x <= bounds_[1] &&
		mouseMove_.y >= bounds_[2] &&
		mouseMove_.y < bounds_[3]) {
		return true;
	}
	return false;
}

auto CDUButtonControl::shouldTriggerEvent() -> bool {
	calculateBounds();
	if (mouseClick_.x >= bounds_[0] &&
		mouseClick_.x <= bounds_[1] &&
		mouseClick_.y >= bounds_[2] &&
		mouseClick_.y <= bounds_[3]) {
		return true;
	}
	return false;
}

auto CDUButtonControl::setupControl() -> void {
	Control::setupControl();

	addOnBeforeRender([this](BaseControl& control) -> bool {
		if(shouldTriggerEvent()) {
			if(event) {
				event();
			}
		}
		return true;
	});
}
