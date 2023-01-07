#pragma once
#include "MasterControl.h"
#include "TCPEventDispatcher.h"
#include "TCPPageControl.h"
#include "TCPVHFPageControl.h"

class TCPMasterControl: public MasterControl {
	public:
		explicit TCPMasterControl(const string& name)
			: MasterControl(name) {
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControl() -> void override;
		auto setCurrentPage(ControlUniquePointer currentPage) -> void;

	private:
		ControlUniquePointer currentPage_ = std::make_unique<TCPVHFPageControl>("VHFPage");
		auto processEvent(TCPEventDispatcher::EVENT_LIST event) -> void;
};
