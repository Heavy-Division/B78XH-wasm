#pragma once
#include <memory>

#include "MFDCDUControl.h"
#include "MFDDisplayContainer.h"
#include "MFDEmptyControl.h"
#include "MFDNDControl.h"
#include "MFDSYSControl.h"

class MFDPanelResolver {
	public:
		enum class PANEL_EVENT_ID {
			SYS = 1,
			CDU = 2,
			INFO = 3,
			CHKL = 4,
			COMM = 5,
			ND = 6,
			ENG = 7,
			EICAS = 8,
		};

		enum class PANEL {
			SYS_ONE,
			SYS_TWO,
			SYS_THREE,
			SYS_FOUR,
			INFO_ONE,
			INFO_TWO,
			INFO_THREE,
			INFO_FOUR,
			CHKL_ONE,
			CHKL_TWO,
			CHKL_THREE,
			CHKL_FOUR,
			COMM_ONE,
			COMM_TWO,
			COMM_THREE,
			COMM_FOUR,
			ND_ONE,
			ND_TWO,
			ND_THREE,
			CDU_ONE,
			CDU_TWO,
			EICAS,
			EMPTY
		};

		enum class MFD {
			ONE,
			TWO,
			THREE
		};

		auto getPanel(PANEL panel) -> std::shared_ptr<MFDBaseControl>;
		auto getMFD(MFD index) -> std::unique_ptr<MFDDisplayContainer>&;
		auto resolveSide(MFD index) -> int;
		auto getCDUPanel(MFD mfdIndex) const -> const std::shared_ptr<MFDBaseControl>&;
		auto getEICASPanel(MFD mfdIndex) const -> std::shared_ptr<MFDBaseControl>&;
		auto getPanel(MFD mfdIndex, int panelIndex) const -> const std::shared_ptr<MFDBaseControl>&;
		auto resolveRequestedPanel(PANEL_EVENT_ID eventId, MFD mfdIndex) const -> const std::shared_ptr<MFDBaseControl>&;
		auto isPanelOnMFD(MFDBaseControl::CONTROL_IDENT leftIdent, MFDBaseControl::CONTROL_IDENT rightIdent, MFDBaseControl::CONTROL_IDENT requstedIdent) -> bool;
		auto hasNDPanel(MFDBaseControl::CONTROL_IDENT leftIdent, MFDBaseControl::CONTROL_IDENT rightIdent) -> bool;
		auto isRequestedPanelOnSameSide(MFDBaseControl::CONTROL_IDENT leftIdent, MFDBaseControl::CONTROL_IDENT rightIdent, MFDBaseControl::CONTROL_IDENT requstedIdent,
		                                int requestedSide) -> bool;
		auto processSwitchEvent(MFD index, PANEL_EVENT_ID panelId) -> void;
		auto processScratchpadEvent(int index, CDUScratchpadControl::events event) -> void;

	private:
		std::array<std::shared_ptr<MFDBaseControl>, 6> mfdOnePanels{
			std::make_shared<MFDSYSControl>("MFDEmptyControl"),
			std::make_shared<MFDINFOControl>("MFDEmptyControl"),
			std::make_shared<MFDCHKLControl>("MFDEmptyControl"),
			std::make_shared<MFDCOMMControl>("MFDEmptyControl"),
			std::make_shared<MFDNDControl>("MFDEmptyControl"),
			std::make_shared<MFDEmptyControl>("MFDEmptyControl")
		};

		std::array<std::shared_ptr<MFDBaseControl>, 6> mfdTwoPanels{
			std::make_shared<MFDSYSControl>("MFDEmptyControl"),
			std::make_shared<MFDINFOControl>("MFDEmptyControl"),
			std::make_shared<MFDCHKLControl>("MFDEmptyControl"),
			std::make_shared<MFDCOMMControl>("MFDEmptyControl"),
			std::make_shared<MFDNDControl>("MFDEmptyControl"),
			std::make_shared<MFDEmptyControl>("MFDEmptyControl")
		};

		std::array<std::shared_ptr<MFDBaseControl>, 6> mfdThreePanels{
			std::make_shared<MFDSYSControl>("MFDEmptyControl"),
			std::make_shared<MFDINFOControl>("MFDEmptyControl"),
			std::make_shared<MFDCHKLControl>("MFDEmptyControl"),
			std::make_shared<MFDCOMMControl>("MFDEmptyControl"),
			std::make_shared<MFDNDControl>("MFDEmptyControl"),
			std::make_shared<MFDEmptyControl>("MFDEmptyControl")
		};

		std::array<std::shared_ptr<MFDBaseControl>, 2> mfdCDUs{
			std::make_shared<MFDCDUControl>("MFDEmptyControl"),
			std::make_shared<MFDCDUControl>("MFDEmptyControl")
		};

		std::shared_ptr<MFDBaseControl> empty = std::make_shared<MFDEmptyControl>("MFDEmptyControl");

		std::shared_ptr<MFDBaseControl> eicas = std::make_shared<MFDEmptyControl>("MFDEmptyControl");
		std::shared_ptr<MFDBaseControl> eicas2 = std::make_shared<MFDEmptyControl>("MFDEmptyControl");
		std::shared_ptr<MFDBaseControl> eicas3 = std::make_shared<MFDEmptyControl>("MFDEmptyControl");

		std::unique_ptr<MFDDisplayContainer> mfdDisplayOne = std::make_unique<MFDDisplayContainer>(eicas2, eicas3);
		std::unique_ptr<MFDDisplayContainer> mfdDisplayTwo = std::make_unique<MFDDisplayContainer>(eicas2, eicas3);
		std::unique_ptr<MFDDisplayContainer> mfdDisplayThree = std::make_unique<MFDDisplayContainer>(eicas2, eicas3);
};

namespace MFD {
	inline MFDPanelResolver resolver;
}
