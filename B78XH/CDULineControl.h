#pragma once
#include "LineControl.h"

class CDULineControl: public LineControl {
	public:
		enum class LINE_NUMBER {
			ONE,
			TWO,
			THREE,
			FOUR,
			FIVE,
			SIX,
		};

		explicit CDULineControl(const string& name)
			: LineControl(name) {
		}

		CDULineControl(const string& name, const LINE_NUMBER lineNumber)
			: LineControl(name),
			  lineNumber_(lineNumber) {
			getContentHolder().setDefaultFontSize(28);
		}

	protected:
		LINE_NUMBER lineNumber_ = LINE_NUMBER::ONE;

		auto renderContentAlignLeft() -> void override;
		auto isSettable(int chunkNumber) -> bool;
		auto renderSelectable(float x1, float x2, bool backward) -> void;
		auto renderContentAlignCenter() -> void override;
		auto renderContentAlignRight() -> void override;
		virtual auto getLineVerticalPosition() const -> float;
};
