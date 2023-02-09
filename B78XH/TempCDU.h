#pragma once
#include "LineControl.h"
#include "Tools/Tools.h"

class TempCDUControl : public LineControl {
public:
	explicit TempCDUControl(const string& name)
		: LineControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
	auto setupControl() -> void override;
};

void TempCDUControl::prepareControls() {
	LineControl::prepareControls();
	add(std::make_unique<LineControl>("TempCDU"));
}

void TempCDUControl::setupControls() {
	LineControl::setupControls();
	auto& line = getControl("TempCDU");

	line->getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
	line->getContentHolder().setDefaultFontSize(20);
	line->getContentHolder().setDefaultFontColor(Tools::Colors::white);
	line->position.setPosition(660, 25, 0, 0);
	line->getContentHolder().setContent({ {"TempCDU"} });
}

void TempCDUControl::setupControl() {
	LineControl::setupControl();
}
