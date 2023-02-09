#pragma once
#include "CDULineControl.h"

class CDUCenterLineControl : public CDULineControl {
	public:
		CDUCenterLineControl(const string& name, const LINE_NUMBER lineNumber)
			: CDULineControl(name, lineNumber) {
			getRelativePosition().setPosition(280, getLineVerticalPosition(), 0, 0);
			getContentHolder().setAlign(ContentHolder::ALIGN::CENTER);
		}
};
