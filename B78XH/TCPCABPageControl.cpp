#include "TCPCABPageControl.h"

#include "TCPCenterLineTitleControl.h"
#include "TCPLeftLineControl.h"
#include "TCPLeftLineTitleControl.h"
#include "TCPPageTitleControl.h"
#include "TCPRightLineControl.h"
#include "TCPRightLineTitleControl.h"

auto TCPCABPageControl::prepareControls() -> void {
	TCPPageControl::prepareControls();
	add(std::make_unique<TCPPageTitleControl>("PAGE_TITLE"));
	add(std::make_unique<TCPLeftLineTitleControl>("LEFT_ONE_TITLE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_unique<TCPLeftLineControl>("LEFT_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_unique<TCPLeftLineControl>("LEFT_TWO", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_unique<TCPLeftLineControl>("LEFT_THREE", TCPLineControl::LINE_NUMBER::THREE));
	add(std::make_unique<TCPLeftLineControl>("LEFT_FOUR", TCPLineControl::LINE_NUMBER::FOUR));

	add(std::make_unique<TCPCenterLineTitleControl>("CENTER_FOUR_TITLE", TCPLineControl::LINE_NUMBER::FOUR));

	add(std::make_unique<TCPRightLineControl>("RIGHT_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_unique<TCPRightLineTitleControl>("RIGHT_ONE_TITLE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_unique<TCPRightLineControl>("RIGHT_TWO", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_unique<TCPRightLineControl>("RIGHT_THREE", TCPLineControl::LINE_NUMBER::THREE));
	add(std::make_unique<TCPRightLineControl>("RIGHT_FOUR", TCPLineControl::LINE_NUMBER::FOUR));
	add(std::move(scratchPad_));
}

auto TCPCABPageControl::setupControls() -> void {
	TCPPageControl::setupControls();

	auto& scratchpad = getControl("SCRATCHPAD");
	scratchpad->position.setPosition(5, 240, 0, 0);

	auto& pageTitle = getControl("PAGE_TITLE");
	auto& leftOneTitle = getControl("LEFT_ONE_TITLE");
	auto& leftOne = getControl("LEFT_ONE");
	auto& leftTwo = getControl("LEFT_TWO");
	auto& leftThree = getControl("LEFT_THREE");
	auto& leftFour = getControl("LEFT_FOUR");

	auto& centerFourTitle = getControl("CENTER_FOUR_TITLE");

	auto& rightOne = getControl("RIGHT_ONE");
	auto& rightOneTitle = getControl("RIGHT_ONE_TITLE");
	auto& rightTwo = getControl("RIGHT_TWO");
	auto& rightThree = getControl("RIGHT_THREE");
	auto& rightFour = getControl("RIGHT_FOUR");

	pageTitle->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"CABIN INTERPHONE"}});
		return true;
	});

	leftOneTitle->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"SPEED DIAL"}});
		return true;
	});

	int x = 10;
	leftOneTitle->getPosition().setPosition(x, x, x, x);

	leftOne->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"<DOOR 1L"}});
		return true;
	});

	leftTwo->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"<ALL CALL"}});
		return true;
	});

	leftThree->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"<PURSER"}});
		return true;
	});

	leftFour->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"<MAKE CALL"}});
		return true;
	});

	centerFourTitle->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"------------ PA IN USE ------------"}});
		return true;
	});

	rightOneTitle->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"CALL QUEUE"}});
		return true;
	});

	rightOne->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"DOOR 1R>"}});
		return true;
	});

	rightTwo->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"GALLEY FWD>"}});
		return true;
	});

	rightThree->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"DOOR 3L>"}});
		return true;
	});

	rightFour->addOnBeforeRender([](BaseControl& control)-> bool {
		control.getContentHolder().setContent({{"DIRECTORY>"}});
		return true;
	});
}
