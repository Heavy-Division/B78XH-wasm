#include "TCPVHFPageControl.h"

#include <string>
#include "Simplane.h"

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
#include "Tools/Tools.h"

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

	pageTitle->addOnBeforeRender([this](BaseControl& control) -> bool {
		if (getPages()->currentPageNumber <= 1) {
			control.getContentHolder().setContent({ {"VHF"} });
		} else {
			control.getContentHolder().setContent({ {"STORED VHF"} });
		}
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
}

auto TCPVHFPageControl::createSTDYTitle() -> string {
	if (TuningControlPanelVHFStorage::standbyFrequencies.empty()) {
		return "STBY";
	}

	return fmt::format("STBY - {}/{}", selectedStandbyFrequency + 1, TuningControlPanelVHFStorage::standbyFrequencies.size() + 1);
}

auto TCPVHFPageControl::prepareLines() -> void {
	if (pages->currentPageNumber <= 1) {
		pages->currentPageNumber = 1;
		const auto activeCom = Simplane::comFrequencies::active_com_id();
		const auto standbyFrequencyValue1 = (selectedStandbyFrequency > 0 && activeCom == 1 ? TuningControlPanelVHFStorage::standbyFrequencies.at(selectedStandbyFrequency - 1) : SimConnectData::comFrequencies.standbyFrequency1);
		const auto standbyFrequencyValue2 = (selectedStandbyFrequency > 0 && activeCom == 2 ? TuningControlPanelVHFStorage::standbyFrequencies.at(selectedStandbyFrequency - 1) : SimConnectData::comFrequencies.standbyFrequency2);
		const auto standbyFrequencyValue3 = (selectedStandbyFrequency > 0 && activeCom == 3 ? TuningControlPanelVHFStorage::standbyFrequencies.at(selectedStandbyFrequency - 1) : SimConnectData::comFrequencies.standbyFrequency3);
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_ONE)).content = {{fmt::format("<{:7.3f}", SimConnectData::comFrequencies.activeFrequency1)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_TWO)).content = {{fmt::format("<{:7.3f}", SimConnectData::comFrequencies.activeFrequency2)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_THREE)).content = {{fmt::format("<{:7.3f}", SimConnectData::comFrequencies.activeFrequency3)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_FOUR)).content = {{"<STORE ACTIVE"}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_ONE)).content = {{fmt::format("{:7.3f}>", standbyFrequencyValue1)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_TWO)).content = {{fmt::format("{:7.3f}>", standbyFrequencyValue2)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_THREE)).content = {{fmt::format("{:7.3f}>", standbyFrequencyValue3)}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_FOUR)).content = {{""}};

		switch (activeCom) {
			case 1: {
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::LEFT_ONE)).content = {{"ACTIVE", "cyan"}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::RIGHT_ONE)).content = {{createSTDYTitle(), "cyan"}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::LEFT_TWO)).content = {{""}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::RIGHT_TWO)).content = {{""}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::LEFT_THREE)).content = {{""}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::RIGHT_THREE)).content = {{""}};
				lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_ONE)).content = {{"L"}};
				lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_TWO)).content = {{"- C -"}};
				lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_THREE)).content = {{"- R -"}};
				lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_FOUR)).content = {{""}};
				break;
			}
			case 2: {
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::LEFT_ONE)).content = {{""}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::RIGHT_ONE)).content = {{""}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::LEFT_TWO)).content = {{"ACTIVE", "cyan"}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::RIGHT_TWO)).content = {{createSTDYTitle(), "cyan"}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::LEFT_THREE)).content = {{""}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::RIGHT_THREE)).content = {{""}};
				lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_ONE)).content = {{"- L -"}};
				lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_TWO)).content = {{"C"}};
				lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_THREE)).content = {{"- R -"}};
				lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_FOUR)).content = {{""}};
				break;
			}
			case 3: {
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::LEFT_ONE)).content = {{""}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::RIGHT_ONE)).content = {{""}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::LEFT_TWO)).content = {{""}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::RIGHT_TWO)).content = {{""}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::LEFT_THREE)).content = {{"ACTIVE", "cyan"}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::RIGHT_THREE)).content = {{createSTDYTitle(), "cyan"}};
				lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_ONE)).content = {{"- L -"}};
				lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_TWO)).content = {{"- C -"}};
				lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_THREE)).content = {{"R"}};
				lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_FOUR)).content = {{""}};
				break;
			}
			default: {
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::LEFT_ONE)).content = {{""}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::RIGHT_ONE)).content = {{""}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::LEFT_TWO)).content = {{""}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::RIGHT_TWO)).content = {{""}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::LEFT_THREE)).content = {{""}};
				lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::RIGHT_THREE)).content = {{""}};
			};
		}

		resetOnPressEvents();

		onL1Pressed = [this](void) -> void {
			const double data = std::atof(scratchPad_->getBuffer().c_str());
			if (Tools::Frequencies::isVHFFrequencyValid(data)) {
				Tools::Frequencies::setVHFActiveFrequency(Tools::Frequencies::ONE, data);
				scratchPad_->clear();
			}
		};

		onL2Pressed = [this](void) -> void {
			const double data = std::atof(scratchPad_->getBuffer().c_str());
			if (Tools::Frequencies::isVHFFrequencyValid(data)) {
				Tools::Frequencies::setVHFActiveFrequency(Tools::Frequencies::TWO, data);
				scratchPad_->clear();
			}
		};

		onL3Pressed = [this](void) -> void {
			const double data = std::atof(scratchPad_->getBuffer().c_str());
			if (Tools::Frequencies::isVHFFrequencyValid(data)) {
				Tools::Frequencies::setVHFActiveFrequency(Tools::Frequencies::THREE, data);
				scratchPad_->clear();
			}
		};

		onL4Pressed = [this](void) -> void {
			double data;
			switch (Simplane::comFrequencies::active_com_id()) {
				case 1: {
					data = Simplane::comFrequencies::activeFrequency1();
					break;
				}
				case 2: {
					data = Simplane::comFrequencies::activeFrequency2();
					break;
				}
				case 3: {
					data = Simplane::comFrequencies::activeFrequency3();
					break;
				}
				default: {
					return;
					break;
				}
			}

			if (Tools::Frequencies::isVHFFrequencyValid(data)) {
				TuningControlPanelVHFStorage::standbyFrequencies.push_back(data);
			}
		};

		onR1Pressed = [this](void) -> void {
			const double data = std::atof(scratchPad_->getBuffer().c_str());
			if (Tools::Frequencies::isVHFFrequencyValid(data)) {
				Tools::Frequencies::setVHFStandbyFrequency(Tools::Frequencies::ONE, data);
				scratchPad_->clear();
			}
		};

		onR2Pressed = [this](void) -> void {
			const double data = std::atof(scratchPad_->getBuffer().c_str());
			if (Tools::Frequencies::isVHFFrequencyValid(data)) {
				Tools::Frequencies::setVHFStandbyFrequency(Tools::Frequencies::TWO, data);
				scratchPad_->clear();
			}
		};

		onR3Pressed = [this](void) -> void {
			const double data = std::atof(scratchPad_->getBuffer().c_str());
			if (Tools::Frequencies::isVHFFrequencyValid(data)) {
				Tools::Frequencies::setVHFStandbyFrequency(Tools::Frequencies::THREE, data);
				scratchPad_->clear();
			}
		};

		onStbyUpPressed = [this](void) -> void {
			selectedStandbyFrequency = std::min<int>(selectedStandbyFrequency + 1, TuningControlPanelVHFStorage::standbyFrequencies.size());
		};

		onStbyDownPressed = [this](void) -> void {
			selectedStandbyFrequency = std::max<int>(selectedStandbyFrequency - 1, 0);
		};

		onXfrPressed = [this](void) -> void {
			const int activeCom = Simplane::comFrequencies::active_com_id();
			const auto activeVhfIndex = static_cast<Tools::Frequencies::vhf_index>((activeCom == 0 ? 1 : activeCom));

			if(selectedStandbyFrequency != 0) {
				Tools::Frequencies::setVHFStandbyFrequency(activeVhfIndex, TuningControlPanelVHFStorage::standbyFrequencies.at(selectedStandbyFrequency - 1));
			}

			Tools::Frequencies::swapVHFFrequencies(activeVhfIndex);
			selectedStandbyFrequency = 0;

		};
	}
	else {
		lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::LEFT_ONE)).content = {{""}};
		lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::RIGHT_ONE)).content = {{""}};
		lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::LEFT_TWO)).content = {{""}};
		lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::RIGHT_TWO)).content = {{""}};
		lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::LEFT_THREE)).content = {{""}};
		lineTitles.at(static_cast<array<LineTitle, 12>::size_type>(LineTitles::RIGHT_THREE)).content = {{""}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_ONE)).content = {{""}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_TWO)).content = {{""}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_THREE)).content = {{""}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::CENTER_FOUR)).content = {{""}};

		const size_t offset = (getPages()->currentPageNumber - 2) * 8;
		string values[8];
		const string newValue = " ------";

		for (int i = 0; i < 8; i++) {
			if (offset + i < TuningControlPanelVHFStorage::standbyFrequencies.size()) {
				values[i] = fmt::format("{:7.3f}", TuningControlPanelVHFStorage::standbyFrequencies.at(offset + i));
			}
			else {
				values[i] = newValue;
				break;
			}
		}

		lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_ONE)).content = {{values[0]}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_TWO)).content = {{values[1]}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_THREE)).content = {{values[2]}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::LEFT_FOUR)).content = {{values[3]}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_ONE)).content = {{values[4]}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_TWO)).content = {{values[5]}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_THREE)).content = {{values[6]}};
		lines.at(static_cast<array<Line, 12>::size_type>(Lines::RIGHT_FOUR)).content = {{values[7]}};


		resetOnPressEvents();

		const auto lambdaNewFrequency = [this](void) -> void {
			if (!scratchPad_->getBuffer().empty()) {
				const double data = std::atof(scratchPad_->getBuffer().c_str());
				if (Tools::Frequencies::isVHFFrequencyValid(data)) {
					TuningControlPanelVHFStorage::standbyFrequencies.push_back(data);
					scratchPad_->clear();
				}
			}
		};

		const auto lambdaRemoveFrequency = [this](int index, string newValue) {
			return [this, index, newValue]() -> void {
				if (!scratchPad_->getBuffer().empty() && scratchPad_->getBuffer() == newValue) {
					auto frequencies = &TuningControlPanelVHFStorage::standbyFrequencies;
					frequencies->erase(frequencies->begin() + index);
					scratchPad_->clear();
				}
			};
		};

		const string clearValue = "CLEAR";

		if (values[0] == newValue) {
			onL1Pressed = lambdaNewFrequency;
		}
		else if (!values[0].empty()) {
			onL1Pressed = lambdaRemoveFrequency(0 + offset, clearValue);
		}

		if (values[1] == newValue) {
			onL2Pressed = lambdaNewFrequency;
		}
		else if (!values[1].empty()) {
			onL2Pressed = lambdaRemoveFrequency(1 + offset, clearValue);
		}

		if (values[2] == newValue) {
			onL3Pressed = lambdaNewFrequency;
		}
		else if (!values[2].empty()) {
			onL3Pressed = lambdaRemoveFrequency(2 + offset, clearValue);
		}

		if (values[3] == newValue) {
			onL4Pressed = lambdaNewFrequency;
		}
		else if (!values[3].empty()) {
			onL4Pressed = lambdaRemoveFrequency(3 + offset, clearValue);
		}

		if (values[4] == newValue) {
			onR1Pressed = lambdaNewFrequency;
		}
		else if (!values[4].empty()) {
			onR1Pressed = lambdaRemoveFrequency(4 + offset, clearValue);
		}

		if (values[5] == newValue) {
			onR2Pressed = lambdaNewFrequency;
		}
		else if (!values[5].empty()) {
			onR2Pressed = lambdaRemoveFrequency(5 + offset, clearValue);
		}

		if (values[6] == newValue) {
			onR3Pressed = lambdaNewFrequency;
		}
		else if (!values[6].empty()) {
			onR3Pressed = lambdaRemoveFrequency(6 + offset, clearValue);
		}

		if (values[7] == newValue) {
			onR4Pressed = lambdaNewFrequency;
		}
		else if (!values[7].empty()) {
			onR4Pressed = lambdaRemoveFrequency(7 + offset, clearValue);
		}
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

void TCPVHFPageControl::render() {
	TCPPageControl::render();
	/*
	 * Active arrows
	 */
	const int activeCom = Simplane::comFrequencies::active_com_id();
	if (getPages()->currentPageNumber > 1 || activeCom == 0) {
		return;
	}

	const int verticalOffset[3]{-1, 52, 102};
	const int offset = activeCom - 1;

	auto beginX = 158;
	auto endX = 140;
	auto Y = 61 + verticalOffset[offset];

	auto width = 4.0f;
	auto angle = atan2(0, endX - beginX);
	auto arrowX1 = endX - 4 * cos(angle - NVG_PI / 7);
	auto arrowY1 = Y - 4 * sin(angle - NVG_PI / 7);
	auto arrowX2 = endX - 4 * cos(angle + NVG_PI / 7);
	auto arrowY2 = Y - 4 * sin(angle + NVG_PI / 7);

	/*
	 * Left arrow
	 */
	nvgBeginPath(context);
	{
		nvgMoveTo(context, beginX, Y);
		nvgLineTo(context, endX, Y);
		nvgStrokeColor(context, nvgRGBA(59, 183, 213, 255));
		nvgStrokeWidth(context, width);
		nvgLineCap(context, NVG_ROUND);
		nvgStroke(context);
	}
	nvgClosePath(context);

	nvgBeginPath(context);
	{
		nvgStrokeColor(context, nvgRGBA(59, 183, 213, 255));
		nvgStrokeWidth(context, width);
		nvgLineJoin(context, NVG_MITER);

		nvgMoveTo(context, endX, Y);
		nvgLineTo(context, arrowX1, arrowY1);
		nvgLineTo(context, arrowX2, arrowY2);
		nvgLineTo(context, endX, Y);
		nvgStroke(context);
	}
	nvgClosePath(context);

	/**
	 * Right arrow
	 */

	beginX = 181;
	endX = 199;

	angle = atan2(0, endX - beginX);
	arrowX1 = endX - 4 * cos(angle - NVG_PI / 7);
	arrowY1 = Y - 4 * sin(angle - NVG_PI / 7);
	arrowX2 = endX - 4 * cos(angle + NVG_PI / 7);
	arrowY2 = Y - 4 * sin(angle + NVG_PI / 7);

	nvgBeginPath(context);
	{
		nvgMoveTo(context, beginX, Y);
		nvgLineTo(context, endX, Y);
		nvgStrokeColor(context, Tools::Colors::cyan);
		nvgStrokeWidth(context, width);
		nvgLineCap(context, NVG_ROUND);
		nvgStroke(context);
	}
	nvgClosePath(context);

	nvgBeginPath(context);
	{
		nvgStrokeColor(context, Tools::Colors::cyan);
		nvgStrokeWidth(context, width);
		nvgLineJoin(context, NVG_MITER);

		nvgMoveTo(context, endX, Y);
		nvgLineTo(context, arrowX1, arrowY1);
		nvgLineTo(context, arrowX2, arrowY2);
		nvgLineTo(context, endX, Y);
		nvgStroke(context);
	}
	nvgClosePath(context);
}
