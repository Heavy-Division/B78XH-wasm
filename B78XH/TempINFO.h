#pragma once
#include "LineControl.h"
#include "Tools/Tools.h"

class TempInfoControl : public LineControl {
public:
	explicit TempInfoControl(const string& name)
		: LineControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
	auto setupControl() -> void override;
};

void TempInfoControl::prepareControls() {
	LineControl::prepareControls();
	add(std::make_unique<LineControl>("TempInfo"));
}

void TempInfoControl::setupControls() {
	LineControl::setupControls();
	auto& line = getControl("TempInfo");

	line->getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
	line->getContentHolder().setDefaultFontSize(20);
	line->getContentHolder().setDefaultFontColor(Tools::Colors::white);
	line->position.setPosition(660, 25, 0, 0);
	line->getContentHolder().setContent({ {"TempInfo"} });
}

void TempInfoControl::setupControl() {
	LineControl::setupControl();
}
