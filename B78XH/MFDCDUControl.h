#pragma once
#include "CDUBackgroundControl.h"
#include "CDUIdentPageControl.h"
#include "CDUPageControl.h"
#include "MFDBaseControl.h"

class MFDCDUControl : public MFDBaseControl {
	public:
		explicit MFDCDUControl(const string& name)
			: MFDBaseControl(name) {
			ident_ = CONTROL_IDENT::CDU;
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControl() -> void override;
		auto setupControls() -> void override;
		auto setCurrentPage(std::shared_ptr<CDUPageControl> currentPage) -> void;

	private:
		std::shared_ptr<CDUBackgroundControl> backgroundControl_ = std::make_shared<CDUBackgroundControl>("BACKGROUND");
		//std::shared_ptr<TCPScratchpadControl> scratchpad_ = std::make_shared<TCPScratchpadControl>("SCRATCHPAD");
		std::shared_ptr<CDUPageControl> currentPage_ = std::make_shared<CDUIdentPageControl>("CURRENT_PAGE");
};
