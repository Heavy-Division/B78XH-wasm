#pragma once
#include "CDUMouseClickResolver.h"
#include "CDUMouseMoveResolver.h"
#include "Control.h"
#include "LineControl.h"

class CDUButtonControl : public Control {
	public:
		CDUButtonControl(const string& name, const string& title, const string& title2)
			: Control(name),
			  title_(title),
			  title2_(title2) {
		}

		auto render() -> void override;

		std::function<void()> event;

	protected:
		string title_;
		string title2_;
		float bounds_[4] = {0, 0, 0, 0};
		float borderWidth_ = 3.0f;
		auto drawBackground() -> void;
		auto drawButtonBorders() -> void;
		auto drawBackBorders(NVGcolor color, float width) -> void;
		auto drawBackBorders() -> void;
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
		virtual auto calculateBounds() -> void;
		auto isInFocus() -> bool;
		auto shouldTriggerEvent() -> bool;
		auto setupControl() -> void override;
};
