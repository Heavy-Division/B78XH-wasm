#pragma once

#include "BaseControl.h"

class Control : public BaseControl {
	protected:
		explicit Control(const string& name)
			: BaseControl(name) {
			setControlType(ControlType::NORMAL);
		}

	private:
		using BaseControl::setControlType;
};
