#pragma once
#include "LineControl.h"
#include "Tools/Tools.h"

class TempSelectMFDControl : public LineControl {
public:
	explicit TempSelectMFDControl(const string& name)
		: LineControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
	auto setupControl() -> void override;
};

void TempSelectMFDControl::prepareControls() {
	LineControl::prepareControls();
	add(std::make_unique<LineControl>("SelectMFD"));
}

void TempSelectMFDControl::setupControls() {
	LineControl::setupControls();
	auto& line = getControl("SelectMFD");

	line->getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
	line->getContentHolder().setDefaultFontSize(20);
	line->getContentHolder().setDefaultFontColor(Tools::Colors::white);
	line->position.setPosition(660, 25, 0, 0);
	line->getContentHolder().setContent({ {"SelectMFD"} });
}

void TempSelectMFDControl::setupControl() {
	LineControl::setupControl();
}
