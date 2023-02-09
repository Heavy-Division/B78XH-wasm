#pragma once
#include "LineControl.h"
#include "Tools/Tools.h"

class TempHalfNDControl : public LineControl {
public:
	explicit TempHalfNDControl(const string& name)
		: LineControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
	auto setupControl() -> void override;
};


void TempHalfNDControl::prepareControls() {
	LineControl::prepareControls();
	add(std::make_unique<LineControl>("TempHalfND"));
}

void TempHalfNDControl::setupControls() {
	LineControl::setupControls();
	auto& line = getControl("TempHalfND");

	line->getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
	line->getContentHolder().setDefaultFontSize(20);
	line->getContentHolder().setDefaultFontColor(Tools::Colors::white);
	line->position.setPosition(660, 25, 0, 0);
	line->getContentHolder().setContent({ {"TempHalfND"} });
}

void TempHalfNDControl::setupControl() {
	LineControl::setupControl();
}
