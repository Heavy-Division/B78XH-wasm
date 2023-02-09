#include "TCPNAVPageControl.h"

#include "TCPLeftLineControl.h"
#include "TCPLeftLineTitleControl.h"
#include "TCPPageTitleControl.h"
#include "TCPRightLineControl.h"
#include "TCPRightLineTitleControl.h"

auto TCPNAVPageControl::prepareControls() -> void {
	TCPPageControl::prepareControls();
	add(std::make_shared<TCPPageTitleControl>("PAGE_TITLE"));
	add(std::make_shared<TCPLeftLineTitleControl>("LEFT_ONE_TITLE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPLeftLineTitleControl>("LEFT_THREE_TITLE", TCPLineControl::LINE_NUMBER::THREE));
	add(std::make_shared<TCPRightLineTitleControl>("RIGHT_ONE_TITLE", TCPLineControl::LINE_NUMBER::ONE));

	add(std::make_shared<TCPLeftLineControl>("LEFT_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPLeftLineControl>("LEFT_TWO", TCPLineControl::LINE_NUMBER::TWO));

	add(std::make_shared<TCPRightLineControl>("RIGHT_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPRightLineControl>("RIGHT_TWO", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_shared<TCPRightLineControl>("RIGHT_THREE", TCPLineControl::LINE_NUMBER::THREE));
}

auto TCPNAVPageControl::setupControls() -> void {
	TCPPageControl::setupControls();

	auto& pageTitle = getControl("PAGE_TITLE");
	auto& leftOne = getControl("LEFT_ONE");
	auto& leftTwo = getControl("LEFT_TWO");

	auto& rightOne = getControl("RIGHT_ONE");
	auto& rightTwo = getControl("RIGHT_TWO");
	auto& rightThree = getControl("RIGHT_THREE");

	auto& leftOneTitle = getControl("LEFT_ONE_TITLE");
	auto& leftThreeTitle = getControl("LEFT_THREE_TITLE");

	auto& rightOneTitle = getControl("RIGHT_ONE_TITLE");

	rightOne->getContentHolder().addColor("green", nvgRGB(29, 170, 5));
	rightOne->getContentHolder().addSize("small", 17);
	rightOne->getContentHolder().addContentVerticalOffset("offset-2", -2);

	pageTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"ALTN NAV RADIO"}});
		return true;
	});

	leftOneTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"ILS-GLS"}});
		return true;
	});

	leftThreeTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"COURSE"}});
		return true;
	});

	rightOneTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"CTRL"}});
		return true;
	});

	leftOne->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"-------"}});
		return true;
	});

	leftTwo->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"---"}});
		return true;
	});


	rightOne->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({
			                                      {"ON"},
			                                      {"←→", "small|offset-2"},
			                                      {"OFF", "green"},
			                                      {">"}
		                                      });
		return true;
	});

	rightTwo->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"DIRECTORY>"}});
		return true;
	});

	rightThree->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"LOW>"}});
		return true;
	});
}
