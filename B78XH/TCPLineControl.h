#pragma once
#include "LineControl.h"

class TCPLineControl : public LineControl {
	public:
		enum class LINE_NUMBER {
			ONE,
			TWO,
			THREE,
			FOUR
		};

		explicit TCPLineControl(const string& name)
			: LineControl(name) {
		}
	protected:
		LINE_NUMBER lineNumber_ = LINE_NUMBER::ONE;
		auto getLineVerticalPosition() const -> float;
		auto setupControl() -> void override;
};
