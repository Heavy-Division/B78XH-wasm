#include "TCPGPWSPageControl.h"

#include "TCPLeftLineControl.h"
#include "TCPLeftLineTitleControl.h"
#include "TCPPageTitleControl.h"
#include "TCPRightLineControl.h"
#include "TCPRightLineTitleControl.h"

auto TCPGPWSPageControl::prepareControls() -> void {
	TCPPageControl::prepareControls();
	add(std::make_unique<TCPPageTitleControl>("PAGE_TITLE"));
	add(std::make_unique<TCPLeftLineTitleControl>("LEFT_FOUR_TITLE", TCPLineControl::LINE_NUMBER::FOUR));
	add(std::make_unique<TCPLeftLineControl>("LEFT_FOUR", TCPLineControl::LINE_NUMBER::FOUR));

	add(std::make_unique<TCPRightLineTitleControl>("RIGHT_ONE_TITLE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_unique<TCPRightLineControl>("RIGHT_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_unique<TCPRightLineTitleControl>("RIGHT_TWO_TITLE", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_unique<TCPRightLineControl>("RIGHT_TWO", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_unique<TCPRightLineTitleControl>("RIGHT_THREE_TITLE", TCPLineControl::LINE_NUMBER::THREE));
	add(std::make_unique<TCPRightLineControl>("RIGHT_THREE", TCPLineControl::LINE_NUMBER::THREE));
	add(std::move(scratchPad_));
}

auto TCPGPWSPageControl::setupControls() -> void {
	TCPPageControl::setupControls();

	auto& scratchpad = getControl("SCRATCHPAD");
	scratchpad->position.setPosition(5, 240, 0, 0);

	auto& pageTitle = getControl("PAGE_TITLE");

	auto& leftFourTitle = getControl("LEFT_FOUR_TITLE");
	auto& leftFour = getControl("LEFT_FOUR");

	auto& rightOneTitle = getControl("RIGHT_ONE_TITLE");
	auto& rightOne = getControl("RIGHT_ONE");
	auto& rightTwoTitle = getControl("RIGHT_TWO_TITLE");
	auto& rightTwo = getControl("RIGHT_TWO");
	auto& rightThreeTitle = getControl("RIGHT_THREE_TITLE");
	auto& rightThree = getControl("RIGHT_THREE");



	leftFour->getContentHolder().addColor("green", nvgRGB(29, 170, 5));
	leftFour->getContentHolder().addSize("small", 17);
	leftFour->getContentHolder().addContentVerticalOffset("offset-2", -2);

	rightOne->getContentHolder().addColor("green", nvgRGB(29, 170, 5));
	rightOne->getContentHolder().addSize("small", 17);
	rightOne->getContentHolder().addContentVerticalOffset("offset-2", -2);


	rightTwo->getContentHolder().addColor("green", nvgRGB(29, 170, 5));
	rightTwo->getContentHolder().addSize("small", 17);
	rightTwo->getContentHolder().addContentVerticalOffset("offset-2", -2);

	rightThree->getContentHolder().addColor("green", nvgRGB(29, 170, 5));
	rightThree->getContentHolder().addSize("small", 17);
	rightThree->getContentHolder().addContentVerticalOffset("offset-2", -2);

	pageTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"GPWS"}});
		return true;
	});

	leftFourTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"GND PROX SYS"}});
		return true;
	});

	leftFour->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"<"}, {"L", "green"}, {"←→", "small|offset-2"}, {"R"}});
		return true;
	});

	rightOneTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"FLAP OVRD"}});
		return true;
	});

	rightOne->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"OVRD"}, {"←→", "small|offset-2"}, {"NORM", "green"}, {">"}});
		return true;
	});

	rightTwoTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"GEAR OVRD"}});
		return true;
	});

	rightTwo->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"OVRD"}, {"←→", "small|offset-2"}, {"NORM", "green"}, {">"}});
		return true;
	});

	rightThreeTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"TERR OVRD"}});
		return true;
	});

	rightThree->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"OVRD"}, {"←→", "small|offset-2"}, {"NORM", "green"}, {">"}});
		return true;
	});
}
