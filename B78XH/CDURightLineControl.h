#pragma once
#include "CDULineControl.h"

class CDURightLineControl : public CDULineControl {
	public:
		CDURightLineControl(const string& name, const LINE_NUMBER lineNumber)
			: CDULineControl(name, lineNumber) {
			getContentHolder().setAlign(ContentHolder::ALIGN::RIGHT);
			getRelativePosition().setPosition(544, getLineVerticalPosition(), 0, 0);
		}
};
