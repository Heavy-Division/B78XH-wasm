#pragma once
#include "LineControl.h"
#include "Tools/Tools.h"

class TempSYSControl : public LineControl {
public:
	explicit TempSYSControl(const string& name)
		: LineControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
	auto setupControl() -> void override;
};

void TempSYSControl::prepareControls() {
	LineControl::prepareControls();
	add(std::make_unique<LineControl>("TempSYS"));
}

void TempSYSControl::setupControls() {
	LineControl::setupControls();
	auto& line = getControl("TempSYS");

	line->getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
	line->getContentHolder().setDefaultFontSize(20);
	line->getContentHolder().setDefaultFontColor(Tools::Colors::white);
	line->position.setPosition(660, 25, 0, 0);
	line->getContentHolder().setContent({ {"TempSYS"} });
}

void TempSYSControl::setupControl() {
	LineControl::setupControl();
}
