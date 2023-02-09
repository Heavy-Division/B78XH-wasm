#pragma once
#include "LineControl.h"
#include "Tools/Tools.h"

class TempCHKL2Control : public LineControl {
public:
	explicit TempCHKL2Control(const string& name)
		: LineControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
	auto setupControl() -> void override;
};

void TempCHKL2Control::prepareControls() {
	LineControl::prepareControls();
	add(std::make_unique<LineControl>("TempCHKL2"));
}

void TempCHKL2Control::setupControls() {
	LineControl::setupControls();
	auto& line = getControl("TempCHKL2");

	line->getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
	line->getContentHolder().setDefaultFontSize(20);
	line->getContentHolder().setDefaultFontColor(Tools::Colors::white);
	line->position.setPosition(660, 25, 0, 0);
	line->getContentHolder().setContent({ {"TempCHKL2"} });
}

void TempCHKL2Control::setupControl() {
	LineControl::setupControl();
}