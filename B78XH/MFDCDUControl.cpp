#include "MFDCDUControl.h"

#include "CDURoutePageControl.h"
#include "Tools/Console.h"

auto MFDCDUControl::getScratchpad() -> std::shared_ptr<CDUScratchpadControl>& {
	return scratchpad_;
}

auto MFDCDUControl::prepareControls() -> void {
	MFDBaseControl::prepareControls();

	add(backgroundControl_);
	add(currentPage_);
	add(mkInitRef_);
	add(mkRte_);
	add(mkDepArr_);
	add(mkAltn_);
	add(mkVnav_);
	add(mkFix_);
	add(mkLegs_);
	add(mkHold_);
	add(mkFmcComm_);
	add(mkProg_);
	add(mkNavRad_);
	add(mkOfst_);
	add(mkRta_);
	add(mkHeavy_);

	add(lsk1_);
	add(lsk2_);
	add(lsk3_);
	add(lsk4_);
	add(lsk5_);
	add(lsk6_);

	add(rsk1_);
	add(rsk2_);
	add(rsk3_);
	add(rsk4_);
	add(rsk5_);
	add(rsk6_);

	add(scratchpad_);
}

auto MFDCDUControl::setupControl() -> void {
	MFDBaseControl::setupControl();
	addOnValidate(SKIP_VALIDATION_EVENT);
}

auto MFDCDUControl::setupControls() -> void {
	MFDBaseControl::setupControls();


	//Console::error("Buffer: {}", scratchpad_->getBuffer());
	backgroundControl_->position.setPosition(0, 0, getRelativePosition().getWidth(), getRelativePosition().getHeight());
	currentPage_->position.setPosition(getRelativePosition().getWidth() / 2 - 280, 37,  getRelativePosition().getWidth() / 2 + 280, 442 + 37);
	scratchpad_->position.setPosition(getRelativePosition().getWidth() / 2 - 254, 442 + 37 + 10, getRelativePosition().getWidth() / 2 + 254, 442 + 37 + 50);
	/*
	 * First MK line
	 */
	mkInitRef_->getRelativePosition().setPosition(5, 540, 87, 593);
	mkRte_->getRelativePosition().setPosition(91, 540, 173, 593);
	mkDepArr_->getRelativePosition().setPosition(177, 540, 259, 593);
	mkAltn_->getRelativePosition().setPosition(263, 540, 345, 593);
	mkVnav_->getRelativePosition().setPosition(349, 540, 431, 593);

	/*
	 * Second MK line
	 */

	mkFix_->getRelativePosition().setPosition(5, 595, 87, 648);
	mkLegs_->getRelativePosition().setPosition(91, 595, 173, 648);
	mkHold_->getRelativePosition().setPosition(177, 595, 259, 648);
	mkFmcComm_->getRelativePosition().setPosition(263, 595, 345, 648);
	mkProg_->getRelativePosition().setPosition(349, 595, 431, 648);

	/*
	 * Third MK Line
	 */

	mkNavRad_->getRelativePosition().setPosition(5, 650, 87, 703);
	mkOfst_->getRelativePosition().setPosition(91, 650, 173, 703);
	mkRta_->getRelativePosition().setPosition(177, 650, 259, 703);
	mkHeavy_->getRelativePosition().setPosition(263, 650, 345, 703);

	mkInitRef_->event = []() ->void {
	};

	mkRte_->event = [this]() ->void {
		setCurrentPage(std::make_shared<CDURoutePageControl>("CURRENT_PAGE"));

	};

	lsk1_->position.setPosition(12, 96, 42, 144);
	lsk2_->position.setPosition(12, 164, 42, 212);
	lsk3_->position.setPosition(12, 232, 42, 280);
	lsk4_->position.setPosition(12, 300, 42, 348);
	lsk5_->position.setPosition(12, 368, 42, 416);
	lsk6_->position.setPosition(12, 436, 42, 484);

	lsk2_->event = []() -> void {

	};


	Console::error("LEFT: {}; Right: {};", position.width - 12 - 30, position.width - 12);

	rsk1_->position.setPosition(658, 96, 688, 144);
	rsk2_->position.setPosition(658, 164, 688, 212);
	rsk3_->position.setPosition(658, 232, 688, 280);
	rsk4_->position.setPosition(658, 300, 688, 348);
	rsk5_->position.setPosition(658, 368, 688, 416);
	rsk6_->position.setPosition(658, 436, 688, 484);
	rsk2_->event = []() -> void {

	};

}

auto MFDCDUControl::setCurrentPage(std::shared_ptr<CDUPageControl> currentPage) -> void {
	currentPage_ = currentPage;
}
