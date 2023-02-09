#pragma once
#include "CDULineTitleControl.h"

class CDURightLineTitleControl : public CDULineTitleControl {
	public:
		CDURightLineTitleControl(const string& name, const LINE_NUMBER lineNumber)
			: CDULineTitleControl(name, lineNumber) {
			getRelativePosition().setPosition(540, CDULineTitleControl::getLineVerticalPosition(), 0, 0);
			getContentHolder().setAlign(ContentHolder::ALIGN::RIGHT);
		}
};
