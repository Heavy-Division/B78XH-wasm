#include "MFDPanelResolver.h"

#include "LVars.h"
#include "Tools/Console.h"

auto MFDPanelResolver::getMFD(MFD index) -> std::unique_ptr<MFDDisplayContainer>& {
	switch (index) {
		case MFD::ONE: {
			return mfdDisplayOne;
		};
		case MFD::TWO: {
			return mfdDisplayTwo;
		};
		case MFD::THREE: {
			return mfdDisplayThree;
		};
	}
}

auto MFDPanelResolver::resolveSide(MFD index) -> int {
	switch (index) {
		case MFD::ONE: {
			return LVars::get(LVars::LEFT_MFD_SIDE).getValue();
		}
		case MFD::TWO: {
			return LVars::get(LVars::RIGHT_MFD_SIDE).getValue();
		}
		case MFD::THREE: {
			return 0;
		}
		default: {
			return 0;
		}
	}
}

auto MFDPanelResolver::getCDUPanel(MFD mfdIndex) const -> const std::shared_ptr<MFDBaseControl>& {
	switch (mfdIndex) {
		case MFD::ONE: {
			return mfdCDUs[0];
		}
		case MFD::TWO: {
			return mfdCDUs[1];
		}
		/*
		 * TODO: Handling for switching over displays
		 */
		case MFD::THREE: {
			return empty;
		}
		default: {
			return empty;
		}
	}
}

auto MFDPanelResolver::getPanel(MFD mfdIndex, int panelIndex) const -> const std::shared_ptr<MFDBaseControl>& {
	switch (mfdIndex) {
		case MFD::ONE: {
			return mfdOnePanels[panelIndex];
		}
		case MFD::TWO: {
			return mfdTwoPanels[panelIndex];
		}
		case MFD::THREE: {
			return mfdThreePanels[panelIndex];
		}
		default: {
			return empty;
		}
	}
}

auto MFDPanelResolver::resolveRequestedPanel(PANEL_EVENT_ID eventId, MFD mfdIndex) const -> const std::shared_ptr<MFDBaseControl>& {
	switch (eventId) {
		case PANEL_EVENT_ID::SYS: {
			return getPanel(mfdIndex, 0);
		}
		case PANEL_EVENT_ID::CDU: {
			return getCDUPanel(mfdIndex);
		}
		case PANEL_EVENT_ID::INFO: {
			return getPanel(mfdIndex, 1);
		}
		case PANEL_EVENT_ID::CHKL: {
			return getPanel(mfdIndex, 2);
		}
		case PANEL_EVENT_ID::COMM: {
			return getPanel(mfdIndex, 3);
		}
		case PANEL_EVENT_ID::ND: {
			return getPanel(mfdIndex, 4);
		}
		case PANEL_EVENT_ID::ENG: {
			/*
			 * TODO: This is not a panel -> should be handled like sending the event to EICAS
			 *
			 * returning empty panel right now
			 */
			return getPanel(mfdIndex, 5);
		}
		case PANEL_EVENT_ID::EICAS: {
			return eicas;
		}
		default: {
			return getPanel(mfdIndex, 5);
		}
	}
}

auto MFDPanelResolver::isPanelOnMFD(MFDBaseControl::CONTROL_IDENT leftIdent, MFDBaseControl::CONTROL_IDENT rightIdent, MFDBaseControl::CONTROL_IDENT requstedIdent) -> bool {
	if (leftIdent == requstedIdent || rightIdent == requstedIdent) {
		return true;
	}

	return false;
}

auto MFDPanelResolver::hasNDPanel(MFDBaseControl::CONTROL_IDENT leftIdent, MFDBaseControl::CONTROL_IDENT rightIdent) -> bool {
	if (leftIdent == MFDBaseControl::CONTROL_IDENT::ND || rightIdent == MFDBaseControl::CONTROL_IDENT::ND) {
		return true;
	}

	return false;
}

auto MFDPanelResolver::isRequestedPanelOnSameSide(MFDBaseControl::CONTROL_IDENT leftIdent, MFDBaseControl::CONTROL_IDENT rightIdent, MFDBaseControl::CONTROL_IDENT requstedIdent,
                                                  int requestedSide) -> bool {
	if (requestedSide == 0) {
		return leftIdent == requstedIdent;
	}

	return rightIdent == requstedIdent;
}

auto MFDPanelResolver::processSwitchEvent(MFD index, PANEL_EVENT_ID panelId) -> void {
	const int side = resolveSide(index);
	const MFDBaseControl::CONTROL_IDENT currentLeftSideIdent = getMFD(index)->getLeftSide()->getIdent();
	const MFDBaseControl::CONTROL_IDENT currentRightSideIdent = getMFD(index)->getRightSide()->getIdent();
	const MFDBaseControl::CONTROL_IDENT requestedPanelIdent = resolveRequestedPanel(panelId, index)->getIdent();

	const bool hasND = hasNDPanel(currentLeftSideIdent, currentRightSideIdent);
	const bool isPanelAlreadyOnMFD = isPanelOnMFD(currentLeftSideIdent, currentRightSideIdent, requestedPanelIdent);

	if (!isPanelAlreadyOnMFD) {
		const auto& requestedPanel = resolveRequestedPanel(panelId, index);
		switch (index) {
			case MFD::ONE: {
				if (side == 0) {
					mfdDisplayOne = std::make_unique<MFDDisplayContainer>(requestedPanel, getMFD(index)->getRightSide());
				}
				else {
					mfdDisplayOne = std::make_unique<MFDDisplayContainer>(getMFD(index)->getLeftSide(), requestedPanel);
				}
				break;
			}

			case MFD::TWO: {
				if (side == 0) {
					mfdDisplayTwo = std::make_unique<MFDDisplayContainer>(requestedPanel, getMFD(index)->getRightSide());
				}
				else {
					mfdDisplayTwo = std::make_unique<MFDDisplayContainer>(getMFD(index)->getLeftSide(), requestedPanel);
				}
				break;
			}
			case MFD::THREE: {
				if (side == 0) {
					mfdDisplayThree = std::make_unique<MFDDisplayContainer>(requestedPanel, getMFD(index)->getRightSide());
				}
				else {
					mfdDisplayThree = std::make_unique<MFDDisplayContainer>(getMFD(index)->getLeftSide(), requestedPanel);
				}
				break;
			}
			default: ;
		}
	}
	else {
		/*
		 * TODO: Make ENUM
		 * 0 = remove panel
		 * 1 = switch panels
		 */
		int mode = 0;
		if (isRequestedPanelOnSameSide(currentLeftSideIdent, currentRightSideIdent, requestedPanelIdent, side)) {
			mode = 0;
		}
		else {
			mode = 1;
		}
		switch (mode) {
			case 0: {
				switch (index) {
					case MFD::ONE: {
						if (side == 0) {
							Console::error("MODE 0; SIDE 0;");
							mfdDisplayOne = std::make_unique<MFDDisplayContainer>(getPanel(index, 5), getMFD(index)->getRightSide());
						}
						else {
							mfdDisplayOne = std::make_unique<MFDDisplayContainer>(getMFD(index)->getLeftSide(), getPanel(index, 5));
						}
						break;
					}

					case MFD::TWO: {
						if (side == 0) {
							mfdDisplayTwo = std::make_unique<MFDDisplayContainer>(getPanel(index, 5), getMFD(index)->getRightSide());
						}
						else {
							mfdDisplayTwo = std::make_unique<MFDDisplayContainer>(getMFD(index)->getLeftSide(), getPanel(index, 5));
						}
						break;
					}
					case MFD::THREE: {
						if (side == 0) {
							mfdDisplayThree = std::make_unique<MFDDisplayContainer>(getPanel(index, 5), getMFD(index)->getRightSide());
						}
						else {
							mfdDisplayThree = std::make_unique<MFDDisplayContainer>(getMFD(index)->getLeftSide(), getPanel(index, 5));
						}
						break;
					}
					default: ;
				}
				break;
			}
			case 1: {
				switch (index) {
					case MFD::ONE: {
						mfdDisplayOne = std::make_unique<MFDDisplayContainer>(getMFD(index)->getRightSide(), getMFD(index)->getLeftSide());
						break;
					}

					case MFD::TWO: {
						mfdDisplayTwo = std::make_unique<MFDDisplayContainer>(getMFD(index)->getRightSide(), getMFD(index)->getLeftSide());

						break;
					}
					case MFD::THREE: {
						mfdDisplayThree = std::make_unique<MFDDisplayContainer>(getMFD(index)->getRightSide(), getMFD(index)->getLeftSide());

						break;
					}
					default: ;
				}
				break;
			}
		}
	}
}
