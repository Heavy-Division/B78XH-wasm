#pragma once
#include "CDULeftLineControl.h"
#include "CDULineControl.h"
#include "Control.h"

#include <memory>

#include "CDUCenterLineControl.h"
#include "CDULeftLineTitleControl.h"
#include "CDUPageTitleControl.h"
#include "CDURightLineControl.h"
#include "CDURightLineTitleControl.h"

class CDUPageControl : public Control {
	public:
		explicit CDUPageControl(const string& name)
			: Control(name) {
		}

		auto render() -> void override;

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;

		/*
		 * Page title
		 */

		std::shared_ptr<LineControl> pageTitle = std::make_shared<CDUPageTitleControl>("PAGE_TITLE");
		/*
		 * Lines
		 */

		std::shared_ptr<CDULineControl> leftLineOne = std::make_shared<CDULeftLineControl>("LL1", CDULineControl::LINE_NUMBER::ONE);
		std::shared_ptr<CDULineControl> leftLineTwo = std::make_shared<CDULeftLineControl>("LL2", CDULineControl::LINE_NUMBER::TWO);
		std::shared_ptr<CDULineControl> leftLineThree = std::make_shared<CDULeftLineControl>("LL3", CDULineControl::LINE_NUMBER::THREE);
		std::shared_ptr<CDULineControl> leftLineFour = std::make_shared<CDULeftLineControl>("LL4", CDULineControl::LINE_NUMBER::FOUR);
		std::shared_ptr<CDULineControl> leftLineFive = std::make_shared<CDULeftLineControl>("LL5", CDULineControl::LINE_NUMBER::FIVE);
		std::shared_ptr<CDULineControl> leftLineSix = std::make_shared<CDULeftLineControl>("LL6", CDULineControl::LINE_NUMBER::SIX);

		std::shared_ptr<CDULineControl> rightLineOne = std::make_shared<CDURightLineControl>("RL1", CDULineControl::LINE_NUMBER::ONE);
		std::shared_ptr<CDULineControl> rightLineTwo = std::make_shared<CDURightLineControl>("RL2", CDULineControl::LINE_NUMBER::TWO);
		std::shared_ptr<CDULineControl> rightLineThree = std::make_shared<CDURightLineControl>("RL3", CDULineControl::LINE_NUMBER::THREE);
		std::shared_ptr<CDULineControl> rightLineFour = std::make_shared<CDURightLineControl>("RL4", CDULineControl::LINE_NUMBER::FOUR);
		std::shared_ptr<CDULineControl> rightLineFive = std::make_shared<CDURightLineControl>("RL5", CDULineControl::LINE_NUMBER::FIVE);
		std::shared_ptr<CDULineControl> rightLineSix = std::make_shared<CDURightLineControl>("RL6", CDULineControl::LINE_NUMBER::SIX);

		std::shared_ptr<CDULineControl> centerLineOne = std::make_shared<CDUCenterLineControl>("CL1", CDULineControl::LINE_NUMBER::ONE);
		std::shared_ptr<CDULineControl> centerLineTwo = std::make_shared<CDUCenterLineControl>("CL2", CDULineControl::LINE_NUMBER::TWO);
		std::shared_ptr<CDULineControl> centerLineThree = std::make_shared<CDUCenterLineControl>("CL3", CDULineControl::LINE_NUMBER::THREE);
		std::shared_ptr<CDULineControl> centerLineFour = std::make_shared<CDUCenterLineControl>("CL4", CDULineControl::LINE_NUMBER::FOUR);
		std::shared_ptr<CDULineControl> centerLineFive = std::make_shared<CDUCenterLineControl>("CL5", CDULineControl::LINE_NUMBER::FIVE);
		std::shared_ptr<CDULineControl> centerLineSix = std::make_shared<CDUCenterLineControl>("CL6", CDULineControl::LINE_NUMBER::SIX);

	/*
	 * Titles
	 */

		std::shared_ptr<CDULineControl> leftLineTitleOne = std::make_shared<CDULeftLineTitleControl>("LT1", CDULineControl::LINE_NUMBER::ONE);
		std::shared_ptr<CDULineControl> leftLineTitleTwo = std::make_shared<CDULeftLineTitleControl>("LT2", CDULineControl::LINE_NUMBER::TWO);
		std::shared_ptr<CDULineControl> leftLineTitleThree = std::make_shared<CDULeftLineTitleControl>("LT3", CDULineControl::LINE_NUMBER::THREE);
		std::shared_ptr<CDULineControl> leftLineTitleFour = std::make_shared<CDULeftLineTitleControl>("LT4", CDULineControl::LINE_NUMBER::FOUR);
		std::shared_ptr<CDULineControl> leftLineTitleFive = std::make_shared<CDULeftLineTitleControl>("LT5", CDULineControl::LINE_NUMBER::FIVE);
		std::shared_ptr<CDULineControl> leftLineTitleSix = std::make_shared<CDULeftLineTitleControl>("LT6", CDULineControl::LINE_NUMBER::SIX);

		std::shared_ptr<CDULineControl> rightLineTitleOne = std::make_shared<CDURightLineTitleControl>("RT1", CDULineControl::LINE_NUMBER::ONE);
		std::shared_ptr<CDULineControl> rightLineTitleTwo = std::make_shared<CDURightLineTitleControl>("RT2", CDULineControl::LINE_NUMBER::TWO);
		std::shared_ptr<CDULineControl> rightLineTitleThree = std::make_shared<CDURightLineTitleControl>("RT3", CDULineControl::LINE_NUMBER::THREE);
		std::shared_ptr<CDULineControl> rightLineTitleFour = std::make_shared<CDURightLineTitleControl>("RT4", CDULineControl::LINE_NUMBER::FOUR);
		std::shared_ptr<CDULineControl> rightLineTitleFive = std::make_shared<CDURightLineTitleControl>("RT5", CDULineControl::LINE_NUMBER::FIVE);
		std::shared_ptr<CDULineControl> rightLineTitleSix = std::make_shared<CDURightLineTitleControl>("RT6", CDULineControl::LINE_NUMBER::SIX);
};
