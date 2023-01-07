#pragma once
#include "BaseControl.h"

class MasterControl : public BaseControl {
	public:
		explicit MasterControl(const string& name)
			: BaseControl(name) {
			setControlType(ControlType::MASTER);
		}
	private:
		using BaseControl::setControlType;
};
