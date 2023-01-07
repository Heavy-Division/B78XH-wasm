#include "TCPVHFPageControl.h"
#include "fmt/format.h"
#include "TCPCenterLineControl.h"
#include "TCPLineControl.h"
#include "TCPRightLineControl.h"
#include "TCPLeftLineControl.h"
#include "TCPPageTitleControl.h"
#include "SimConnectData.h"
#include "TCPLeftLineTitleControl.h"

void TCPVHFPageControl::prepareControls() {
	TCPPageControl::prepareControls();
	add(std::make_unique<TCPPageTitleControl>("PAGE_TITLE"));
	add(std::make_unique<TCPLeftLineTitleControl>("LEFT_ONE_TITLE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_unique<TCPLeftLineControl>("LEFT_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_unique<TCPLeftLineControl>("LEFT_TWO", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_unique<TCPLeftLineControl>("LEFT_THREE", TCPLineControl::LINE_NUMBER::THREE));
	add(std::make_unique<TCPLeftLineControl>("LEFT_FOUR", TCPLineControl::LINE_NUMBER::FOUR));

	add(std::make_unique<TCPCenterLineControl>("CENTER_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_unique<TCPCenterLineControl>("CENTER_TWO", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_unique<TCPCenterLineControl>("CENTER_THREE", TCPLineControl::LINE_NUMBER::THREE));
	add(std::make_unique<TCPCenterLineControl>("CENTER_FOUR", TCPLineControl::LINE_NUMBER::FOUR));

	add(std::make_unique<TCPRightLineControl>("RIGHT_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_unique<TCPRightLineControl>("RIGHT_TWO", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_unique<TCPRightLineControl>("RIGHT_THREE", TCPLineControl::LINE_NUMBER::THREE));
	add(std::make_unique<TCPRightLineControl>("RIGHT_FOUR", TCPLineControl::LINE_NUMBER::FOUR));
}

void TCPVHFPageControl::setupControls() {
	TCPPageControl::setupControls();
	auto& pageTitle = getControl("PAGE_TITLE");
	auto& leftOneTitle = getControl("LEFT_ONE_TITLE");
	auto& leftOne = getControl("LEFT_ONE");
	auto& leftTwo = getControl("LEFT_TWO");
	auto& leftThree = getControl("LEFT_THREE");
	auto& leftFour = getControl("LEFT_FOUR");

	auto& centerOne = getControl("CENTER_ONE");
	auto& centerTwo = getControl("CENTER_TWO");
	auto& centerThree = getControl("CENTER_THREE");
	auto& centerFour = getControl("CENTER_FOUR");

	auto& rightOne = getControl("RIGHT_ONE");
	auto& rightTwo = getControl("RIGHT_TWO");
	auto& rightThree = getControl("RIGHT_THREE");
	auto& rightFour = getControl("RIGHT_FOUR");

	pageTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"VHF"}});
		return true;
	});

	leftOneTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"ACTIVE"}});
		return true;
	});

	leftOne->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{fmt::format("<{:7.3f}", SimConnectData::comFrequencies.activeFrequency1)}});
		return true;
	});

	leftTwo->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{fmt::format("<{:7.3f}", SimConnectData::comFrequencies.activeFrequency2)}});
		return true;
	});

	leftThree->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{fmt::format("<{:7.3f}", SimConnectData::comFrequencies.activeFrequency3)}});
		return true;
	});

	rightOne->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{fmt::format("{:7.3f}>", SimConnectData::comFrequencies.standbyFrequency1)}});
		return true;
	});

	rightTwo->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{fmt::format("{:7.3f}>", SimConnectData::comFrequencies.standbyFrequency2)}});
		return true;
	});

	rightThree->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{fmt::format("{:7.3f}>", SimConnectData::comFrequencies.standbyFrequency3)}});
		return true;
	});

	leftFour->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"<STORE ACTIVE"}});
		return true;
	});

	/*
	leftOne->addOnBeforeRender(getCurrentPage()->getLeftLineOneContentCallback());
	leftTwo->addOnBeforeRender(getCurrentPage()->getLeftLineTwoContentCallback());
	leftThree->addOnBeforeRender(getCurrentPage()->getLeftLineThreeContentCallback());
	leftFour->addOnBeforeRender(getCurrentPage()->getLeftLineFourContentCallback());


	centerOne->addOnBeforeRender(getCurrentPage()->getCenterLineOneContentCallback());
	centerTwo->addOnBeforeRender(getCurrentPage()->getCenterLineTwoContentCallback());
	centerThree->addOnBeforeRender(getCurrentPage()->getCenterLineThreeContentCallback());
	centerFour->addOnBeforeRender(getCurrentPage()->getCenterLineFourContentCallback());

	rightOne->addOnBeforeRender(getCurrentPage()->getRightLineOneContentCallback());
	rightTwo->addOnBeforeRender(getCurrentPage()->getRightLineTwoContentCallback());
	rightThree->addOnBeforeRender(getCurrentPage()->getRightLineThreeContentCallback());
	rightFour->addOnBeforeRender(getCurrentPage()->getRightLineFourContentCallback());
	*/
}
