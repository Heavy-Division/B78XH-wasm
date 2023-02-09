#pragma once
#include "CDUButtonControl.h"

class CDUSelectKeyButtonControl : public CDUButtonControl {
	public:
		enum class SelectKeySide {
			LEFT,
			RIGHT
		};

		CDUSelectKeyButtonControl(const string& name, SelectKeySide side)
			: CDUButtonControl(name, "", ""), side_(side) {
			borderWidth_ = 2.0f;
		}

		auto render() -> void override;

	protected:
		auto calculateBounds() -> void override;
	private:
		SelectKeySide side_;
		auto drawBorder() -> void;
		auto drawPointers() -> void;
};
