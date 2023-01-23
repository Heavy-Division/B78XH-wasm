#include "TCPVHFPageControl.h"

#include <string>
#include <string>

#include "fmt/format.h"
#include "TCPCenterLineControl.h"
#include "TCPLineControl.h"
#include "TCPRightLineControl.h"
#include "TCPLeftLineControl.h"
#include "TCPPageTitleControl.h"
#include "SimConnectData.h"
#include "TCPCenterLineTitleControl.h"
#include "TCPLeftLineTitleControl.h"
#include "TCPPagesLineControl.h"
#include "TCPRightLineTitleControl.h"
#include "TuningControlPanelVHFStorage.h"

auto TCPVHFPageControl::prepareControls() -> void {
	TCPPageControl::prepareControls();
	add(std::make_shared<TCPPageTitleControl>("PAGE_TITLE"));
	add(std::make_shared<TCPPagesLineControl>("PAGES"));
	/*
	 * Line titles
	 */
	add(std::make_shared<TCPLeftLineTitleControl>("LEFT_ONE_TITLE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPLeftLineTitleControl>("LEFT_TWO_TITLE", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_shared<TCPLeftLineTitleControl>("LEFT_THREE_TITLE", TCPLineControl::LINE_NUMBER::THREE));
	add(std::make_shared<TCPLeftLineTitleControl>("LEFT_FOUR_TITLE", TCPLineControl::LINE_NUMBER::FOUR));

	add(std::make_shared<TCPCenterLineTitleControl>("CENTER_ONE_TITLE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPCenterLineTitleControl>("CENTER_TWO_TITLE", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_shared<TCPCenterLineTitleControl>("CENTER_THREE_TITLE", TCPLineControl::LINE_NUMBER::THREE));
	add(std::make_shared<TCPCenterLineTitleControl>("CENTER_FOUR_TITLE", TCPLineControl::LINE_NUMBER::FOUR));

	add(std::make_shared<TCPRightLineTitleControl>("RIGHT_ONE_TITLE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPRightLineTitleControl>("RIGHT_TWO_TITLE", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_shared<TCPRightLineTitleControl>("RIGHT_THREE_TITLE", TCPLineControl::LINE_NUMBER::THREE));
	add(std::make_shared<TCPRightLineTitleControl>("RIGHT_FOUR_TITLE", TCPLineControl::LINE_NUMBER::FOUR));
	/*
	 * Lines
	 */
	add(std::make_shared<TCPLeftLineControl>("LEFT_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPLeftLineControl>("LEFT_TWO", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_shared<TCPLeftLineControl>("LEFT_THREE", TCPLineControl::LINE_NUMBER::THREE));
	add(std::make_shared<TCPLeftLineControl>("LEFT_FOUR", TCPLineControl::LINE_NUMBER::FOUR));
	add(std::make_shared<TCPCenterLineControl>("CENTER_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPCenterLineControl>("CENTER_TWO", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_shared<TCPCenterLineControl>("CENTER_THREE", TCPLineControl::LINE_NUMBER::THREE));
	add(std::make_shared<TCPCenterLineControl>("CENTER_FOUR", TCPLineControl::LINE_NUMBER::FOUR));
	add(std::make_shared<TCPRightLineControl>("RIGHT_ONE", TCPLineControl::LINE_NUMBER::ONE));
	add(std::make_shared<TCPRightLineControl>("RIGHT_TWO", TCPLineControl::LINE_NUMBER::TWO));
	add(std::make_shared<TCPRightLineControl>("RIGHT_THREE", TCPLineControl::LINE_NUMBER::THREE));
	add(std::make_shared<TCPRightLineControl>("RIGHT_FOUR", TCPLineControl::LINE_NUMBER::FOUR));
	add(scratchPad_);
}

auto TCPVHFPageControl::setupControls() -> void {
	TCPPageControl::setupControls();

	scratchPad_->position.setPosition(5, 240, 0, 0);

	auto& pageTitle = getControl("PAGE_TITLE");
	auto& pages = getControl("PAGES");

	auto& leftOneTitle = getControl("LEFT_ONE_TITLE");
	auto& leftTwoTitle = getControl("LEFT_TWO_TITLE");
	auto& leftThreeTitle = getControl("LEFT_THREE_TITLE");
	auto& leftFourTitle = getControl("LEFT_FOUR_TITLE");

	auto& centerOneTitle = getControl("CENTER_ONE_TITLE");
	auto& centerTwoTitle = getControl("CENTER_TWO_TITLE");
	auto& centerThreeTitle = getControl("CENTER_THREE_TITLE");
	auto& centerFourTitle = getControl("CENTER_FOUR_TITLE");

	auto& rightOneTitle = getControl("RIGHT_ONE_TITLE");
	auto& rightTwoTitle = getControl("RIGHT_TWO_TITLE");
	auto& rightThreeTitle = getControl("RIGHT_THREE_TITLE");
	auto& rightFourTitle = getControl("RIGHT_FOUR_TITLE");

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

	pages->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{std::to_string(getPages()->currentPageNumber)}, {"/"}, {std::to_string(getPages()->numberOfPages)}});
		return true;
	});

	/*
	 * Line titles
	 */

	leftOneTitle->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lineTitles.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_ONE)).content);
		return true;
	});

	leftTwoTitle->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lineTitles.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_TWO)).content);
		return true;
	});

	leftThreeTitle->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lineTitles.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_THREE)).content);
		return true;
	});

	leftFourTitle->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lineTitles.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_FOUR)).content);
		return true;
	});

	centerOneTitle->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lineTitles.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_ONE)).content);
		return true;
	});

	centerTwoTitle->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lineTitles.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_TWO)).content);
		return true;
	});

	centerThreeTitle->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lineTitles.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_THREE)).content);
		return true;
	});

	centerFourTitle->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lineTitles.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_FOUR)).content);
		return true;
	});

	rightOneTitle->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lineTitles.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_ONE)).content);
		return true;
	});

	rightTwoTitle->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lineTitles.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_TWO)).content);
		return true;
	});

	rightThreeTitle->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lineTitles.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_THREE)).content);
		return true;
	});

	rightFourTitle->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lineTitles.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_FOUR)).content);
		return true;
	});

	/*
	 * Lines
	 */
	leftOne->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_ONE)).content);
		return true;
	});

	leftTwo->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_TWO)).content);
		return true;
	});

	leftThree->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_THREE)).content);
		return true;
	});

	leftFour->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_FOUR)).content);
		return true;
	});

	centerOne->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_ONE)).content);
		return true;
	});

	centerTwo->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_TWO)).content);
		return true;
	});

	centerThree->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_THREE)).content);
		return true;
	});

	centerFour->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_FOUR)).content);
		return true;
	});

	rightOne->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_ONE)).content);
		return true;
	});

	rightTwo->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_TWO)).content);
		return true;
	});

	rightThree->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_THREE)).content);
		return true;
	});

	rightFour->addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent(lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_FOUR)).content);
		return true;
	});

	Console::log("{}", scratchPad_->getOnBeforeRender().size());
}

auto TCPVHFPageControl::prepareLines() -> void {
	if (pages->currentPageNumber <= 1) {
		pages->currentPageNumber = 1;
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_ONE)).content = {{fmt::format("<{:7.3f}", SimConnectData::comFrequencies.activeFrequency1)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_TWO)).content = {{fmt::format("<{:7.3f}", SimConnectData::comFrequencies.activeFrequency2)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_THREE)).content = {{fmt::format("<{:7.3f}", SimConnectData::comFrequencies.activeFrequency3)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_FOUR)).content = {{"<STORE ACTIVE"}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_ONE)).content = {{""}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_TWO)).content = {{""}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_THREE)).content = {{""}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_FOUR)).content = {{""}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_ONE)).content = {{fmt::format("{:7.3f}>", SimConnectData::comFrequencies.standbyFrequency1)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_TWO)).content = {{fmt::format("{:7.3f}>", SimConnectData::comFrequencies.standbyFrequency2)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_THREE)).content = {{fmt::format("{:7.3f}>", SimConnectData::comFrequencies.standbyFrequency3)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_FOUR)).content = {{""}};
	}
	else {
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_ONE)).content = {{"TEST"}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_TWO)).content = {{fmt::format("<{:7.3f}", SimConnectData::comFrequencies.activeFrequency2)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_THREE)).content = {{fmt::format("<{:7.3f}", SimConnectData::comFrequencies.activeFrequency3)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_FOUR)).content = {{"<STORE ACTIVE"}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_ONE)).content = {{""}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_TWO)).content = {{""}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_THREE)).content = {{""}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_FOUR)).content = {{""}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_ONE)).content = {{fmt::format("{:7.3f}>", SimConnectData::comFrequencies.standbyFrequency1)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_TWO)).content = {{fmt::format("{:7.3f}>", SimConnectData::comFrequencies.standbyFrequency2)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_THREE)).content = {{fmt::format("{:7.3f}>", SimConnectData::comFrequencies.standbyFrequency3)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_FOUR)).content = {{""}};
	}
}

auto TCPVHFPageControl::calculateNumberOfPages() -> void {
	if (TuningControlPanelVHFStorage::standbyFrequencies.size() > 24) {
		TuningControlPanelVHFStorage::standbyFrequencies.resize(24);
	}

	getPages()->numberOfPages = std::min<int>(4, std::max<int>(2, std::ceil(TuningControlPanelVHFStorage::standbyFrequencies.size() / 8 + 2)));
}


auto TCPVHFPageControl::setupControl() -> void {
	TCPPageControl::setupControl();
	addOnBeforeRender([this](BaseControl& control) {
		calculateNumberOfPages();
		prepareLines();
		return true;
	});
}
