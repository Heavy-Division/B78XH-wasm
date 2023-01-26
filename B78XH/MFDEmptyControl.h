#pragma once
#include "MFDBaseControl.h"

class MFDEmptyControl : public MFDBaseControl {
	public:
		explicit MFDEmptyControl(const string& name)
			: MFDBaseControl(name) {
			ident_ = CONTROL_IDENT::EMPTY;
		}
};
