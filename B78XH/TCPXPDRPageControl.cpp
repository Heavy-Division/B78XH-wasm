#include "TCPXPDRPageControl.h"

#include "SimConnectData.h"
#include "TCPLeftLineControl.h"
#include "TCPLeftLineTitleControl.h"
#include "TCPPageTitleControl.h"
#include "TCPRightLineControl.h"
#include "TCPRightLineTitleControl.h"
#include "Tools/Console.h"
#include "Tools/Tools.h"

auto TCPXPDRPageControl::prepareControls() -> void {
	TCPPageControl::prepareControls();

	add(std::make_shared<TCPPageTitleControl>("PAGE_TITLE"));
	add(std::make_shared<TCPLeftLineTitleControl>("LEFT_ONE_TITLE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPLeftLineControl>("LEFT_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPLeftLineControl>("LEFT_TWO", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_shared<TCPLeftLineTitleControl>("LEFT_FOUR_TITLE", TCPLineControl::LINE_NUMBER::FOUR));
	add(std::make_shared<TCPLeftLineControl>("LEFT_FOUR", TCPLineControl::LINE_NUMBER::FOUR));

	add(std::make_shared<TCPRightLineTitleControl>("RIGHT_ONE_TITLE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPRightLineControl>("RIGHT_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPRightLineControl>("RIGHT_TWO", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_shared<TCPRightLineControl>("RIGHT_THREE", TCPLineControl::LINE_NUMBER::THREE));
	add(std::make_shared<TCPRightLineTitleControl>("RIGHT_FOUR_TITLE", TCPLineControl::LINE_NUMBER::FOUR));
	add(std::make_shared<TCPRightLineControl>("RIGHT_FOUR", TCPLineControl::LINE_NUMBER::FOUR));

	add(scratchPad_);
}

auto TCPXPDRPageControl::setupControls() -> void {
	TCPPageControl::setupControls();

	scratchPad_->position.setPosition(5, 240, 0, 0);

	auto& pageTitle = getControl("PAGE_TITLE");

	auto& leftOneTitle = getControl("LEFT_ONE_TITLE");
	auto& leftOne = getControl("LEFT_ONE");
	auto& leftTwo = getControl("LEFT_TWO");
	auto& leftFourTitle = getControl("LEFT_FOUR_TITLE");
	auto& leftFour = getControl("LEFT_FOUR");


	auto& rightOneTitle = getControl("RIGHT_ONE_TITLE");
	auto& rightOne = getControl("RIGHT_ONE");
	auto& rightTwo = getControl("RIGHT_TWO");
	auto& rightThree = getControl("RIGHT_THREE");
	auto& rightFourTitle = getControl("RIGHT_FOUR_TITLE");
	auto& rightFour = getControl("RIGHT_FOUR");


	leftFour->getContentHolder().addColor("green", nvgRGB(29, 170, 5));
	leftFour->getContentHolder().addSize("small", 17);
	leftFour->getContentHolder().addContentVerticalOffset("offset-2", -2);

	rightTwo->getContentHolder().addColor("green", nvgRGB(29, 170, 5));

	rightFour->getContentHolder().addColor("green", nvgRGB(29, 170, 5));
	rightFour->getContentHolder().addSize("small", 17);
	rightFour->getContentHolder().addContentVerticalOffset("offset-2", -2);

	pageTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"TRANSPONDER"}});
		return true;
	});

	leftOneTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"XPDR CODE"}});
		return true;
	});

	leftOne->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{fmt::format(" {:04}", SimConnectData::transponder.code)}});
		return true;
	});


	leftTwo->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"<IDENT"}});
		return true;
	});

	leftFourTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"XPDR SYS"}});
		return true;
	});

	leftFour->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({
			                                      {"<"},
			                                      {"L", "green"},
			                                      {"←→", "small|offset-2"},
			                                      {"R"}
		                                      });
		return true;
	});

	rightOneTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"CAPT TCAS"}});
		return true;
	});

	rightOne->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"ABOVE>"}});
		return true;
	});

	rightTwo->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"NORM", "green"}, {">"}});
		return true;
	});

	rightThree->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"BELOW>"}});
		return true;
	});

	rightFourTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"CAT TCAS ALT"}});
		return true;
	});

	rightFour->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({
			                                      {"ABS"},
			                                      {"←→", "small|offset-2"},
			                                      {"REL", "green"},
			                                      {">"}
		                                      });
		return true;
	});

	onL1Pressed = [this]() -> void {
		Tools::Transponder::setCode(scratchPad_->getBuffer());
		scratchPad_->processEvent(TCPScratchpadControl::events::FORCE_CLR);
	};
}
