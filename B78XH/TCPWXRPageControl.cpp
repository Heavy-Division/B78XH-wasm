#include "TCPWXRPageControl.h"

#include "TCPCenterLineControl.h"
#include "TCPPageTitleControl.h"

auto TCPWXRPageControl::prepareControls() -> void {
	TCPPageControl::prepareControls();
	add(std::make_shared<TCPPageTitleControl>("PAGE_TITLE"));
	add(std::make_shared<TCPCenterLineControl>("CenterLineOne"));
	add(scratchPad_);
}

auto TCPWXRPageControl::setupControls() -> void {
	TCPPageControl::setupControls();

	scratchPad_->position.setPosition(5, 240, 0, 0);

	const auto& pageTitle = getControl("PAGE_TITLE");
	const auto& centerLineOne = getControl("CenterLineOne");

	pageTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"WEATHER RADAR"}});
		return true;
	});


	centerLineOne->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"- INOP - "}});
		return true;
	});
}
