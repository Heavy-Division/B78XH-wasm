#include "TCPPageControl.h"

auto TCPPageControl::getScratchpadBuffer() -> std::string {
	if(scratchPad_ != nullptr) {
		return scratchPad_->getBuffer();
	}

	const TCPScratchpadControl* scratchpad = static_cast<TCPScratchpadControl*>(getControl("SCRATCHPAD").get());

	if(scratchpad != nullptr) {
		return scratchpad->getBuffer();
	}

	return "";
}

auto TCPPageControl::processScratchpadEvent(TCPScratchpadControl::events event) -> void {
	TCPScratchpadControl* scratchpad = static_cast<TCPScratchpadControl*>(getControl("SCRATCHPAD").get());
	scratchpad->processEvent(event);
}

auto TCPPageControl::getPages() const -> const std::unique_ptr<Pages>& {
	return pages;
}
