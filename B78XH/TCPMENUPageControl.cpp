#include "TCPMENUPageControl.h"

#include "TCPLeftLineControl.h"
#include "TCPLeftLineTitleControl.h"
#include "TCPPageTitleControl.h"
#include "TCPRightLineControl.h"
#include "TCPRightLineTitleControl.h"

void TCPMENUPageControl::prepareControls() {
	TCPPageControl::prepareControls();
	add(std::make_shared<TCPPageTitleControl>("PAGE_TITLE"));
	add(std::make_shared<TCPLeftLineTitleControl>("LEFT_FOUR_TITLE", TCPLineControl::LINE_NUMBER::FOUR));
	add(std::make_shared<TCPRightLineTitleControl>("RIGHT_ONE_TITLE", TCPLineControl::LINE_NUMBER::ONE));

	add(std::make_shared<TCPLeftLineControl>("LEFT_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPLeftLineControl>("LEFT_FOUR", TCPLineControl::LINE_NUMBER::FOUR));

	add(std::make_shared<TCPRightLineControl>("RIGHT_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPRightLineControl>("RIGHT_FOUR", TCPLineControl::LINE_NUMBER::FOUR));
}

void TCPMENUPageControl::setupControls() {
	TCPPageControl::setupControls();

	auto& pageTitle = getControl("PAGE_TITLE");

	auto& leftFourTitle = getControl("LEFT_FOUR_TITLE");
	auto& rightOneTitle = getControl("RIGHT_ONE_TITLE");

	auto& leftOne = getControl("LEFT_ONE");
	auto& leftFour = getControl("LEFT_FOUR");

	auto& rightOne = getControl("RIGHT_ONE");
	auto& rightFour = getControl("RIGHT_FOUR");

	leftFour->getContentHolder().addColor("green", nvgRGB(29, 170, 5));
	leftFour->getContentHolder().addSize("small", 17);
	leftFour->getContentHolder().addContentVerticalOffset("offset-2", -2);

	rightOne->getContentHolder().addColor("green", nvgRGB(29, 170, 5));
	rightOne->getContentHolder().addSize("small", 17);
	rightOne->getContentHolder().addContentVerticalOffset("offset-2", -2);

	pageTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"MENU"}});
		return true;
	});

	leftOne->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"<SYS POWER"}});
		return true;
	});

	leftFour->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({
			                                      {"<"},
			                                      {"L", "green"},
			                                      {"←→", "small|offset-2"},
			                                      {"R"},
		                                      });
		return true;
	});

	rightOne->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({
			                                      {"ON"},
			                                      {"←→", "small|offset-2"},
			                                      {"OFF", "green"},
			                                      {">"},
		                                      });
		return true;
	});

	rightFour->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"RADIO MISC>"}});
		return true;
	});

	leftFourTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"SATCOM SYS"}});
		return true;
	});

	rightOneTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"ALERT/XPDR CTL"}});
		return true;
	});
}
