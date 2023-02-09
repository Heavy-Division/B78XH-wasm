#pragma once
#include "MFDBaseControl.h"
#include "Tools/Tools.h"

class MFDEmptyControl : public MFDBaseControl {
	public:
		explicit MFDEmptyControl(const string& name)
			: MFDBaseControl(name) {
			ident_ = CONTROL_IDENT::EMPTY;
		}
};