#pragma once

#include "MFDBaseControl.h"

class EICASMasterControl : public MFDBaseControl {

public:
	explicit EICASMasterControl(const string& name)
		: MFDBaseControl(name) {
		ident_ = CONTROL_IDENT::SYS;
	}
	auto render() -> void override;

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
	auto setupControl() -> void override;


private:
	auto drawLabel(double x, double y, std::string label, std::string label2) -> void;
};