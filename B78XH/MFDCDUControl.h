#pragma once
#include "CDUBackgroundControl.h"
#include "CDUIdentPageControl.h"
#include "CDUMainKeyButtonControl.h"
#include "CDUPageControl.h"
#include "CDUScratchpadControl.h"
#include "CDUSelectKeyButtonControl.h"
#include "MFDBaseControl.h"

class MFDCDUControl : public MFDBaseControl {
	public:
		MFDCDUControl(const string& name)
			: MFDBaseControl(name) {
		}

		[[nodiscard]] auto getScratchpad() -> std::shared_ptr<CDUScratchpadControl>&;

	protected:
		auto prepareControls() -> void override;
		auto setupControl() -> void override;
		auto setupControls() -> void override;
		auto setCurrentPage(std::shared_ptr<CDUPageControl> currentPage) -> void;

	private:
		std::shared_ptr<CDUBackgroundControl> backgroundControl_ = std::make_shared<CDUBackgroundControl>("BACKGROUND");
		std::shared_ptr<CDUScratchpadControl> scratchpad_ = std::make_shared<CDUScratchpadControl>("SCRATCHPAD");
		std::shared_ptr<CDUPageControl> currentPage_ = std::make_shared<CDUIdentPageControl>("CURRENT_PAGE");

		const std::shared_ptr<CDUMainKeyButtonControl> mkInitRef_ = std::make_shared<CDUMainKeyButtonControl>("MK_INIT_REF", "INIT", "REF");
		const std::shared_ptr<CDUMainKeyButtonControl> mkRte_ = std::make_shared<CDUMainKeyButtonControl>("MK_RTE", "RTE");
		const std::shared_ptr<CDUMainKeyButtonControl> mkDepArr_ = std::make_shared<CDUMainKeyButtonControl>("MK_DEP_ARR", "DEP", "ARR");
		const std::shared_ptr<CDUMainKeyButtonControl> mkAltn_ = std::make_shared<CDUMainKeyButtonControl>("MK_ALTN", "ALTN");
		const std::shared_ptr<CDUMainKeyButtonControl> mkVnav_ = std::make_shared<CDUMainKeyButtonControl>("MK_VNAV", "VNAV");
		const std::shared_ptr<CDUMainKeyButtonControl> mkFix_ = std::make_shared<CDUMainKeyButtonControl>("MK_FIX", "FIX");
		const std::shared_ptr<CDUMainKeyButtonControl> mkLegs_ = std::make_shared<CDUMainKeyButtonControl>("MK_LEGS", "LEGS");
		const std::shared_ptr<CDUMainKeyButtonControl> mkHold_ = std::make_shared<CDUMainKeyButtonControl>("MK_HOLD", "HOLD");
		const std::shared_ptr<CDUMainKeyButtonControl> mkFmcComm_ = std::make_shared<CDUMainKeyButtonControl>("MK_FMC_COMM", "FMC", "COMM");
		const std::shared_ptr<CDUMainKeyButtonControl> mkProg_ = std::make_shared<CDUMainKeyButtonControl>("MK_PROG", "PROG");
		const std::shared_ptr<CDUMainKeyButtonControl> mkNavRad_ = std::make_shared<CDUMainKeyButtonControl>("MK_NAV_RAD", "NAV", "RAD");
		const std::shared_ptr<CDUMainKeyButtonControl> mkOfst_ = std::make_shared<CDUMainKeyButtonControl>("MK_OFST", "OFST");
		const std::shared_ptr<CDUMainKeyButtonControl> mkRta_ = std::make_shared<CDUMainKeyButtonControl>("MK_RTA", "RTA");
		const std::shared_ptr<CDUMainKeyButtonControl> mkHeavy_ = std::make_shared<CDUMainKeyButtonControl>("MK_HEAVY", "HEAVY");

		const std::shared_ptr<CDUSelectKeyButtonControl> lsk1_ = std::make_shared<CDUSelectKeyButtonControl>("LSK1", CDUSelectKeyButtonControl::SelectKeySide::LEFT);
		const std::shared_ptr<CDUSelectKeyButtonControl> lsk2_ = std::make_shared<CDUSelectKeyButtonControl>("LSK2", CDUSelectKeyButtonControl::SelectKeySide::LEFT);
		const std::shared_ptr<CDUSelectKeyButtonControl> lsk3_ = std::make_shared<CDUSelectKeyButtonControl>("LSK3", CDUSelectKeyButtonControl::SelectKeySide::LEFT);
		const std::shared_ptr<CDUSelectKeyButtonControl> lsk4_ = std::make_shared<CDUSelectKeyButtonControl>("LSK4", CDUSelectKeyButtonControl::SelectKeySide::LEFT);
		const std::shared_ptr<CDUSelectKeyButtonControl> lsk5_ = std::make_shared<CDUSelectKeyButtonControl>("LSK5", CDUSelectKeyButtonControl::SelectKeySide::LEFT);
		const std::shared_ptr<CDUSelectKeyButtonControl> lsk6_ = std::make_shared<CDUSelectKeyButtonControl>("LSK6", CDUSelectKeyButtonControl::SelectKeySide::LEFT);

		const std::shared_ptr<CDUSelectKeyButtonControl> rsk1_ = std::make_shared<CDUSelectKeyButtonControl>("RSK1", CDUSelectKeyButtonControl::SelectKeySide::RIGHT);
		const std::shared_ptr<CDUSelectKeyButtonControl> rsk2_ = std::make_shared<CDUSelectKeyButtonControl>("RSK2", CDUSelectKeyButtonControl::SelectKeySide::RIGHT);
		const std::shared_ptr<CDUSelectKeyButtonControl> rsk3_ = std::make_shared<CDUSelectKeyButtonControl>("RSK3", CDUSelectKeyButtonControl::SelectKeySide::RIGHT);
		const std::shared_ptr<CDUSelectKeyButtonControl> rsk4_ = std::make_shared<CDUSelectKeyButtonControl>("RSK4", CDUSelectKeyButtonControl::SelectKeySide::RIGHT);
		const std::shared_ptr<CDUSelectKeyButtonControl> rsk5_ = std::make_shared<CDUSelectKeyButtonControl>("RSK5", CDUSelectKeyButtonControl::SelectKeySide::RIGHT);
		const std::shared_ptr<CDUSelectKeyButtonControl> rsk6_ = std::make_shared<CDUSelectKeyButtonControl>("RSK6", CDUSelectKeyButtonControl::SelectKeySide::RIGHT);
};
