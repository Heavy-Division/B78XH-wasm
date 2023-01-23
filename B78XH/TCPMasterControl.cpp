#include "TCPMasterControl.h"

#include "EventDispatchers.h"
#include "LineControl.h"
#include "SimConnectData.h"
#include "TCPCABPageControl.h"
#include "TCPGPWSPageControl.h"
#include "TCPHFPageControl.h"
#include "TCPSATPageControl.h"
#include "TCPWXRPageControl.h"
#include "TCPXPDRPageControl.h"
#include "Tools/Console.h"

auto TCPMasterControl::prepareControls() -> void {
	MasterControl::prepareControls();
	currentPage_->setName("CURRENT_PAGE");
	add(currentPage_);
}

auto TCPMasterControl::setupControl() -> void {
	MasterControl::setupControl();
	addOnValidate(SKIP_VALIDATION_EVENT);
	addOnBeforeRender([this](BaseControl& control)-> bool {
		this->processEvent(EventDispatchers::tcpEventDispatcher[0].get());
		return true;
	});
}

auto TCPMasterControl::setupControls() -> void {
	MasterControl::setupControls();
	currentPage_->addOnValidate(SKIP_VALIDATION_EVENT);
}

auto TCPMasterControl::setCurrentPage(std::shared_ptr<TCPPageControl> currentPage) -> void {
	currentPage_ = currentPage;
	restart();
}

auto TCPMasterControl::processEvent(TCPEventDispatcher::EVENT_LIST event) -> void {
	switch (event) {
		case TCPEventDispatcher::EVENT_LIST::NONE: break;
		case TCPEventDispatcher::EVENT_LIST::VHF: {
			setCurrentPage(std::make_shared<TCPVHFPageControl>("TCPVHFPageControl", scratchpad_));
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::HF: {
			setCurrentPage(std::make_shared<TCPHFPageControl>("TCPHFPageControl", scratchpad_));
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::SAT: {
			setCurrentPage(std::make_shared<TCPSATPageControl>("TCPSATPageControl", scratchpad_));
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::CAB: {
			setCurrentPage(std::make_shared<TCPCABPageControl>("TCPCABPageControl", scratchpad_));
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::GPWS: {
			setCurrentPage(std::make_shared<TCPGPWSPageControl>("TCPGPWSPageControl", scratchpad_));
			break;
		};
		case TCPEventDispatcher::EVENT_LIST::WXR: {
			setCurrentPage(std::make_shared<TCPWXRPageControl>("TCPWXRPageControl", scratchpad_));
			break;
		};
		case TCPEventDispatcher::EVENT_LIST::XPDR: {
			setCurrentPage(std::make_shared<TCPXPDRPageControl>("TCPXPDRPageControl", scratchpad_));
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::LSK1: {
			currentPage_->onL1Pressed();
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::LSK2: {
			currentPage_->onL2Pressed();
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::LSK3: {
			currentPage_->onL3Pressed();
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::LSK4: {
			currentPage_->onL4Pressed();
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::RSK1: {
			currentPage_->onR1Pressed();
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::RSK2: {
			currentPage_->onR2Pressed();
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::RSK3: {
			currentPage_->onR3Pressed();
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::RSK4: {
			currentPage_->onR4Pressed();
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::PREV: {
			if (currentPage_->getPages() != nullptr) {
				if (currentPage_->getPages()->currentPageNumber > 1) {
					currentPage_->getPages()->currentPageNumber--;
				}
			}
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::NEXT: {
			if (currentPage_->getPages() != nullptr) {
				if (currentPage_->getPages()->currentPageNumber < currentPage_->getPages()->numberOfPages) {
					currentPage_->getPages()->currentPageNumber++;
				}
			}
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::OFF: break;
		case TCPEventDispatcher::EVENT_LIST::NAV: break;
		case TCPEventDispatcher::EVENT_LIST::MENU: break;
		case TCPEventDispatcher::EVENT_LIST::STBY_UP: break;
		case TCPEventDispatcher::EVENT_LIST::STBY_DOWN: break;
		case TCPEventDispatcher::EVENT_LIST::XFR: break;
		case TCPEventDispatcher::EVENT_LIST::CLR: {
			currentPage_->scratchPad_->processEvent(TCPScratchpadControl::events::CLR);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::DOT: {
			currentPage_->scratchPad_->processEvent(TCPScratchpadControl::events::STAR);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::ONE: {
			currentPage_->scratchPad_->processEvent(TCPScratchpadControl::events::NUM1);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::TWO: {
			currentPage_->scratchPad_->processEvent(TCPScratchpadControl::events::NUM2);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::THREE: {
			currentPage_->scratchPad_->processEvent(TCPScratchpadControl::events::NUM3);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::FOUR: {
			currentPage_->scratchPad_->processEvent(TCPScratchpadControl::events::NUM4);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::FIVE: {
			currentPage_->scratchPad_->processEvent(TCPScratchpadControl::events::NUM5);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::SIX: {
			currentPage_->scratchPad_->processEvent(TCPScratchpadControl::events::NUM6);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::SEVEN: {
			currentPage_->scratchPad_->processEvent(TCPScratchpadControl::events::NUM7);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::EIGHT: {
			currentPage_->scratchPad_->processEvent(TCPScratchpadControl::events::NUM8);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::NINE: {
			currentPage_->scratchPad_->processEvent(TCPScratchpadControl::events::NUM9);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::ZERO: {
			currentPage_->scratchPad_->processEvent(TCPScratchpadControl::events::NUM0);
			break;
		}
		default: {
		};
	}
}
