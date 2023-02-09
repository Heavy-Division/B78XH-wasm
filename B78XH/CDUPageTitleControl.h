#pragma once
#include "LineControl.h"

class CDUPageTitleControl : public LineControl {
	public:
		explicit CDUPageTitleControl(const string& name)
			: LineControl(name) {
			getContentHolder().setDefaultFontSize(32);
			getContentHolder().setAlign(ContentHolder::ALIGN::CENTER);
			getRelativePosition().setPosition(280, 21, 0, 0);
		}
};
