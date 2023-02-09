#pragma once
#include "LineControl.h"
#include "Tools/Tools.h"

class TempCHKLControl : public LineControl {
public:
	explicit TempCHKLControl(const string& name)
		: LineControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
	auto setupControl() -> void override;
};

void TempCHKLControl::prepareControls() {
	LineControl::prepareControls();
	add(std::make_unique<LineControl>("TempCHKL"));
}

void TempCHKLControl::setupControls() {
	LineControl::setupControls();
	auto& line = getControl("TempCHKL");

	line->getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
	line->getContentHolder().setDefaultFontSize(20);
	line->getContentHolder().setDefaultFontColor(Tools::Colors::white);
	line->position.setPosition(660, 25, 0, 0);
	line->getContentHolder().setContent({ {"TempCHKL"} });
}

void TempCHKLControl::setupControl() {
	LineControl::setupControl();
}
