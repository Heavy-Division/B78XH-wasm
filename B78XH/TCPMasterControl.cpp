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
	add(std::move(currentPage_));
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

	auto& page = getControl("CURRENT_PAGE");
	page->addOnValidate(SKIP_VALIDATION_EVENT);
}

auto TCPMasterControl::setCurrentPage(std::unique_ptr<TCPPageControl> currentPage) -> void {
	currentPage_ = std::move(currentPage);
	restart();
}

auto TCPMasterControl::processEvent(TCPEventDispatcher::EVENT_LIST event) -> void {
	TCPPageControl* page = static_cast<TCPPageControl*>(getControl("CURRENT_PAGE").get());

	switch (event) {
		case TCPEventDispatcher::EVENT_LIST::NONE: break;
		case TCPEventDispatcher::EVENT_LIST::VHF: {
			setCurrentPage(std::make_unique<TCPVHFPageControl>("TCPVHFPageControl", page->getScratchpadBuffer()));
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::HF: {
			setCurrentPage(std::make_unique<TCPHFPageControl>("TCPHFPageControl", page->getScratchpadBuffer()));
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::SAT: {
			setCurrentPage(std::make_unique<TCPSATPageControl>("TCPSATPageControl", page->getScratchpadBuffer()));
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::CAB: {
			setCurrentPage(std::make_unique<TCPCABPageControl>("TCPCABPageControl", page->getScratchpadBuffer()));
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::GPWS: {
			setCurrentPage(std::make_unique<TCPGPWSPageControl>("TCPGPWSPageControl", page->getScratchpadBuffer()));
			break;
		};
		case TCPEventDispatcher::EVENT_LIST::WXR: {
			setCurrentPage(std::make_unique<TCPWXRPageControl>("TCPWXRPageControl", page->getScratchpadBuffer()));
			break;
		};
		case TCPEventDispatcher::EVENT_LIST::XPDR: {
			setCurrentPage(std::make_unique<TCPXPDRPageControl>("TCPXPDRPageControl", page->getScratchpadBuffer()));
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::LSK1: {
			if (page != nullptr) {
				page->onL1Pressed();
			}
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::LSK2: {
			if (page != nullptr) {
				page->onL2Pressed();
			}
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::LSK3: {
			if (page != nullptr) {
				page->onL3Pressed();
			}
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::LSK4: {
			if (page != nullptr) {
				page->onL4Pressed();
			}
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::RSK1: {
			if (page != nullptr) {
				page->onR1Pressed();
			}
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::RSK2: {
			if (page != nullptr) {
				page->onR2Pressed();
			}
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::RSK3: {
			if (page != nullptr) {
				page->onR3Pressed();
			}
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::RSK4: {
			if (page != nullptr) {
				page->onR4Pressed();
			}
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::PREV: {
			if (page->getPages() != nullptr) {
				if (page->getPages()->currentPageNumber > 1) {
					page->getPages()->currentPageNumber--;
				}
			}
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::NEXT: {
			if (page->getPages() != nullptr) {
				if (page->getPages()->currentPageNumber < page->getPages()->numberOfPages) {
					page->getPages()->currentPageNumber++;
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
			page->processScratchpadEvent(TCPScratchpadControl::events::CLR);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::DOT: {
			page->processScratchpadEvent(TCPScratchpadControl::events::STAR);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::ONE: {
			page->processScratchpadEvent(TCPScratchpadControl::events::NUM1);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::TWO: {
			page->processScratchpadEvent(TCPScratchpadControl::events::NUM2);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::THREE: {
			page->processScratchpadEvent(TCPScratchpadControl::events::NUM3);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::FOUR: {
			page->processScratchpadEvent(TCPScratchpadControl::events::NUM4);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::FIVE: {
			page->processScratchpadEvent(TCPScratchpadControl::events::NUM5);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::SIX: {
			page->processScratchpadEvent(TCPScratchpadControl::events::NUM6);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::SEVEN: {
			page->processScratchpadEvent(TCPScratchpadControl::events::NUM7);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::EIGHT: {
			page->processScratchpadEvent(TCPScratchpadControl::events::NUM8);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::NINE: {
			page->processScratchpadEvent(TCPScratchpadControl::events::NUM9);
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::ZERO: {
			page->processScratchpadEvent(TCPScratchpadControl::events::NUM0);
			break;
		}
		default: {
		};
	}
}
