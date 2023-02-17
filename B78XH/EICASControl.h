#pragma once

#include "MFDBaseControl.h"

class EICASControl : public MFDBaseControl {

public:
	explicit EICASControl(const string& name)
		: MFDBaseControl(name) {
		ident_ = CONTROL_IDENT::SYS;
	}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
	auto setupControl() -> void override;
};