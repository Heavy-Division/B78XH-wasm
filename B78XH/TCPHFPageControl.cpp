#include "TCPHFPageControl.h"

#include "TCPCenterLineControl.h"
#include "TCPPageTitleControl.h"

auto TCPHFPageControl::prepareControls() -> void {
	TCPPageControl::prepareControls();
	add(std::make_unique<TCPPageTitleControl>("PAGE_TITLE"));
	add(std::make_unique<TCPCenterLineControl>("CenterLineOne"));
}

auto TCPHFPageControl::setupControls() -> void {
	TCPPageControl::setupControls();
	const auto& pageTitle = getControl("PAGE_TITLE");
	const auto& centerLineOne = getControl("CenterLineOne");

	pageTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"HF"}});
		return true;
	});


	centerLineOne->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"- INOP - "}});
		return true;
	});
}
