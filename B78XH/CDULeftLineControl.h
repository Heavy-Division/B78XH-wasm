#pragma once
#include "CDULineControl.h"

class CDULeftLineControl: public CDULineControl {
	public:

		CDULeftLineControl(const string& name, const LINE_NUMBER lineNumber)
			: CDULineControl(name, lineNumber) {
			getRelativePosition().setPosition(14, getLineVerticalPosition(), 0, 0);
		}
};
