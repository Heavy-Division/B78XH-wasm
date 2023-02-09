#pragma once
#include "LineControl.h"
#include "Tools/Tools.h"

class TempNDControl : public LineControl {
public:
	explicit TempNDControl(const string& name)
		: LineControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
	auto setupControl() -> void override;
};

void TempNDControl::prepareControls() {
	LineControl::prepareControls();
	add(std::make_unique<LineControl>("TempND"));
}

void TempNDControl::setupControls() {
	LineControl::setupControls();
	auto& line = getControl("TempND");

	line->getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
	line->getContentHolder().setDefaultFontSize(20);
	line->getContentHolder().setDefaultFontColor(Tools::Colors::white);
	line->position.setPosition(660, 25, 0, 0);
	line->getContentHolder().setContent({ {"TempND"} });
}

void TempNDControl::setupControl() {
	LineControl::setupControl();
}
