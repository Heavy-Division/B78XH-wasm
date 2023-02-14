#pragma once
#include "MFDBaseControl.h"
#include "CheckListLine.h"
#include "CheckListDimensions.h"

class MFDCHKLControl : public MFDBaseControl {
public:
	explicit MFDCHKLControl(const string& name)
		: MFDBaseControl(name) {
		ident_ = CONTROL_IDENT::CHKL;
	}

	auto render() -> void override;
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
};
