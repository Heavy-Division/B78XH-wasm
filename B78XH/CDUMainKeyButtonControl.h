#pragma once
#include "CDUButtonControl.h"

class CDUMainKeyButtonControl : public CDUButtonControl {
	public:
		CDUMainKeyButtonControl(const string& name,
				string const& title, const string& title2 = "")
			: CDUButtonControl(name, title, title2) {
			borderWidth_ = 3;
		}
};
