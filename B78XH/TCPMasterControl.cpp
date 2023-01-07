#include "TCPMasterControl.h"

#include "EventDispatchers.h"
#include "LineControl.h"
#include "TCPCABPageControl.h"
#include "TCPGPWSPageControl.h"
#include "TCPHFPageControl.h"
#include "TCPSATPageControl.h"

auto TCPMasterControl::prepareControls() -> void {
	MasterControl::prepareControls();
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

auto TCPMasterControl::setCurrentPage(ControlUniquePointer currentPage) -> void {
	currentPage_ = std::move(currentPage);
	restart();
}

auto TCPMasterControl::processEvent(TCPEventDispatcher::EVENT_LIST event) -> void {
	switch (event) {
		case TCPEventDispatcher::EVENT_LIST::NONE: break;
		case TCPEventDispatcher::EVENT_LIST::VHF: {
			setCurrentPage(std::make_unique<TCPVHFPageControl>("TCPVHFPageControl"));
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::HF: {
			setCurrentPage(std::make_unique<TCPHFPageControl>("TCPHFPageControl"));
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::SAT: {
			setCurrentPage(std::make_unique<TCPSATPageControl>("TCPSATPageControl"));
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::CAB: {
			setCurrentPage(std::make_unique<TCPCABPageControl>("TCPCABPageControl"));
			break;
		}
		case TCPEventDispatcher::EVENT_LIST::GPWS: {
			setCurrentPage(std::make_unique<TCPGPWSPageControl>("TCPGPWSPageControl"));
			break;
		};
		case TCPEventDispatcher::EVENT_LIST::WXR: break;
		case TCPEventDispatcher::EVENT_LIST::XPDR: break;
		case TCPEventDispatcher::EVENT_LIST::LSK1: break;
		case TCPEventDispatcher::EVENT_LIST::LSK2: break;
		case TCPEventDispatcher::EVENT_LIST::LSK3: break;
		case TCPEventDispatcher::EVENT_LIST::LSK4: break;
		case TCPEventDispatcher::EVENT_LIST::RSK1: break;
		case TCPEventDispatcher::EVENT_LIST::RSK2: break;
		case TCPEventDispatcher::EVENT_LIST::RSK3: break;
		case TCPEventDispatcher::EVENT_LIST::RSK4: break;
		case TCPEventDispatcher::EVENT_LIST::PREV: break;
		case TCPEventDispatcher::EVENT_LIST::NEXT: break;
		case TCPEventDispatcher::EVENT_LIST::OFF: break;
		case TCPEventDispatcher::EVENT_LIST::NAV: break;
		case TCPEventDispatcher::EVENT_LIST::MENU: break;
		case TCPEventDispatcher::EVENT_LIST::STBY_UP: break;
		case TCPEventDispatcher::EVENT_LIST::STBY_DOWN: break;
		case TCPEventDispatcher::EVENT_LIST::XFR: break;
		case TCPEventDispatcher::EVENT_LIST::CLR: break;
		case TCPEventDispatcher::EVENT_LIST::DOT: break;
		case TCPEventDispatcher::EVENT_LIST::ONE: break;
		case TCPEventDispatcher::EVENT_LIST::TWO: break;
		case TCPEventDispatcher::EVENT_LIST::THREE: break;
		case TCPEventDispatcher::EVENT_LIST::FOUR: break;
		case TCPEventDispatcher::EVENT_LIST::FIVE: break;
		case TCPEventDispatcher::EVENT_LIST::SIX: break;
		case TCPEventDispatcher::EVENT_LIST::SEVEN: break;
		case TCPEventDispatcher::EVENT_LIST::EIGHT: break;
		case TCPEventDispatcher::EVENT_LIST::NINE: break;
		case TCPEventDispatcher::EVENT_LIST::ZERO: break;
		default: {
		};
	}
}
