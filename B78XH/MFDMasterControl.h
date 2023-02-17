﻿#pragma once
#include "CDUButtonControl.h"
#include "MasterControl.h"
#include "MFDBaseControl.h"
#include "MFDMouseCursorControl.h"
#include "MFDPanelResolver.h"

class MFDMasterControl: public MasterControl {
	public:
		explicit MFDMasterControl(const string& name, MFDPanelResolver::MFD index)
			: MasterControl(name), mfdIndex_(index) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;
		auto setupControl() -> void override;

	private:
		MFDPanelResolver::MFD mfdIndex_;
		const std::shared_ptr<MFDBaseControl>& leftControl = MFD::resolver.getMFD(mfdIndex_)->getLeftSide();
		const std::shared_ptr<MFDBaseControl>& rightControl = MFD::resolver.getMFD(mfdIndex_)->getRightSide();
		const std::shared_ptr<MFDMouseCursorControl> mouseCursor_ = std::make_shared<MFDMouseCursorControl>("MOUSE_CURSOR");
};