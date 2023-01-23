#include "TCPSATPageControl.h"

#include "TCPLeftLineControl.h"
#include "TCPLeftLineTitleControl.h"
#include "TCPLineControl.h"
#include "TCPPagesLineControl.h"
#include "TCPPageTitleControl.h"
#include "TCPRightLineControl.h"
#include "TCPRightLineTitleControl.h"

auto TCPSATPageControl::prepareControls() -> void {
	TCPPageControl::prepareControls();

	add(std::make_shared<TCPPageTitleControl>("PAGE_TITLE"));
	add(std::make_shared<TCPPagesLineControl>("PAGES"));
	add(std::make_shared<TCPLeftLineTitleControl>("LEFT_ONE_TITLE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPLeftLineControl>("LEFT_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPLeftLineControl>("LEFT_THREE", TCPLineControl::LINE_NUMBER::THREE));
	add(std::make_shared<TCPLeftLineTitleControl>("LEFT_THREE_TITLE", TCPLineControl::LINE_NUMBER::THREE));


	add(std::make_shared<TCPRightLineControl>("RIGHT_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPRightLineTitleControl>("RIGHT_ONE_TITLE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPRightLineControl>("RIGHT_TWO", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_shared<TCPRightLineControl>("RIGHT_THREE", TCPLineControl::LINE_NUMBER::THREE));
	add(scratchPad_);
}

auto TCPSATPageControl::setupControls() -> void {
	TCPPageControl::setupControls();

	scratchPad_->position.setPosition(5, 240, 0, 0);

	auto& pageTitle = getControl("PAGE_TITLE");
	auto& pages = getControl("PAGES");
	auto& leftOneTitle = getControl("LEFT_ONE_TITLE");
	auto& leftOne = getControl("LEFT_ONE");
	auto& leftThree = getControl("LEFT_THREE");
	auto& leftThreeTitle = getControl("LEFT_THREE_TITLE");

	auto& rightOne = getControl("RIGHT_ONE");
	auto& rightOneTitle = getControl("RIGHT_ONE_TITLE");
	auto& rightTwo = getControl("RIGHT_TWO");
	auto& rightThree = getControl("RIGHT_THREE");
	auto& rightThreeTitle = getControl("RIGHT_THREE_TITLE");

	pageTitle->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"SATCOM"}});
		return true;
	});

	pages->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"1/2"}});
		return true;
	});

	leftOneTitle->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"SAT-1: NOT READY"}});
		return true;
	});

	leftOne->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"<MAKE CALL"}});
		return true;
	});

	leftThreeTitle->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"SAT-2: NOT READY"}});
		return true;
	});

	leftThree->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"<MAKE CALL"}});
		return true;
	});


	rightOneTitle->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"PRIORITY"}});
		return true;
	});

	rightOne->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"LOW>"}});
		return true;
	});

	rightTwo->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"DIRECTORY>"}});
		return true;
	});

	rightThreeTitle->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"PRIORITY"}});
		return true;
	});

	rightThree->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"LOW>"}});
		return true;
	});
}
