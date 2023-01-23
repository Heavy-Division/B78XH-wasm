#pragma once
#include "MasterControl.h"
#include "TCPEventDispatcher.h"
#include "TCPPageControl.h"
#include "TCPScratchpadControl.h"
#include "TCPVHFPageControl.h"

class TCPMasterControl: public MasterControl {
	public:
		explicit TCPMasterControl(const string& name)
			: MasterControl(name) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControl() -> void override;
		auto setupControls() -> void override;
		auto setCurrentPage(std::shared_ptr<TCPPageControl> currentPage) -> void;

	private:
		std::shared_ptr<TCPScratchpadControl> scratchpad_ = std::make_shared<TCPScratchpadControl>("SCRATCHPAD");
		std::shared_ptr<TCPPageControl> currentPage_ = std::make_shared<TCPVHFPageControl>("CURRENT_PAGE", scratchpad_);
		auto processEvent(TCPEventDispatcher::EVENT_LIST event) -> void;
};
