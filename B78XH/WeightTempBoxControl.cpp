#include "WeightTempBoxControl.h"
#include "LineControl.h"
#include "Tools/Tools.h"


void WeightTempBoxControl::prepareControls() {
	Control::prepareControls();
	add(std::make_unique<LineControl>("WeightTempBoxControl"));
}

void WeightTempBoxControl::setupControl() {
	Control::setupControl();
	auto& line = getControl("WeightTempBoxControl");
	line->getContentHolder().setAlign(ContentHolder::ALIGN::CENTER);
	line->getContentHolder().setDefaultFontSize(90);
	line->getContentHolder().setDefaultFontColor(Tools::Colors::white);
	line->getContentHolder().addSize("regular", 30);
	line->getContentHolder().addColor("cyan", Tools::Colors::cyan);
	line->position.setPosition(1200, 920, 0, 0);
	line->getContentHolder().setContent({{"TEST"}});

}


void WeightTempBoxControl::setupControls() {
	Control::setupControls();
}
