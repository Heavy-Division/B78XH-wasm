#pragma once
#include "LineControl.h"
#include "Tools/Tools.h"

class TempCOMMControl : public LineControl {
public:
	explicit TempCOMMControl(const string& name)
		: LineControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
	auto setupControl() -> void override;
};

void TempCOMMControl::prepareControls() {
	LineControl::prepareControls();
	add(std::make_unique<LineControl>("TempComm"));
}

void TempCOMMControl::setupControls() {
	LineControl::setupControls();
	auto& line = getControl("TempComm");

	line->getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
	line->getContentHolder().setDefaultFontSize(20);
	line->getContentHolder().setDefaultFontColor(Tools::Colors::white);
	line->position.setPosition(660, 25, 0, 0);
	line->getContentHolder().setContent({ {"TempComm"} });
}

void TempCOMMControl::setupControl() {
	LineControl::setupControl();
}
