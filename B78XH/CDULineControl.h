#pragma once
#include "LineControl.h"

class CDULineControl: public LineControl {
	public:
		explicit CDULineControl(const string& name)
			: LineControl(name) {
		}

	protected:
		auto renderContentAlignLeft() -> void override;
		auto isSettable(int chunkNumber) -> bool;
		auto renderSelectable(float x1, float x2, bool backward) -> void;
		auto renderContentAlignCenter() -> void override;
		auto renderContentAlignRight() -> void override;
};
