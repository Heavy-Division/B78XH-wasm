#pragma once
#include "CDULineTitleControl.h"

class CDULeftLineTitleControl : public CDULineTitleControl {
	public:
		CDULeftLineTitleControl(const string& name, const LINE_NUMBER lineNumber)
			: CDULineTitleControl(name, lineNumber) {
			getRelativePosition().setPosition(28, CDULineTitleControl::getLineVerticalPosition(), 0, 0);
		}
};
