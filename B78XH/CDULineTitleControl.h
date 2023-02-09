#pragma once
#include "CDULineControl.h"

class CDULineTitleControl : public CDULineControl {
	public:
		CDULineTitleControl(const string& name, const LINE_NUMBER lineNumber)
			: CDULineControl(name, lineNumber) {
			getContentHolder().setDefaultFontSize(22);
		}

	protected:
		auto getLineVerticalPosition() const -> float override;
};
