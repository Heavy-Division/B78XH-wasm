#include "TATControl.h"

#include "LineControl.h"
#include "Tools/Tools.h"
#include "Simplane.h"
#include "Tools/Console.h"

void TATControl::prepareControls() {
	Control::prepareControls();
	add(std::make_unique<LineControl>("TATControl"));
}

void TATControl::setupControls() {
	Control::setupControls();
	auto& line = getControl("TATControl");

	line->getContentHolder().setAlign(ContentHolder::ALIGN::CENTER);
	line->getContentHolder().setDefaultFontSize(90);
	line->getContentHolder().setDefaultFontColor(Tools::Colors::white);
	line->getContentHolder().addSize("regular", 30);
	line->getContentHolder().addColor("cyan", Tools::Colors::cyan); 
	line->position.setPosition(120, 50, 0, 0);

	auto tempSignHandler = []() -> std::string {
		if(Simplane::environment::temperature::trueAirTemp() > 0) {
			return "+";
		}
		return "";
	};

	line->addOnBeforeRender([tempSignHandler](BaseControl& control) -> bool {
		control.getContentHolder().setContent({ {"TAT  ", "cyan|regular"},
	{tempSignHandler(), "regular"},
    {std::to_string(static_cast<int>(Simplane::environment::temperature::trueAirTemp())), "regular"}});
		return true;
		});
	
	line->addOnValidate([](BaseControl& control) -> bool {
		return false;
	});

}

void TATControl::setupControl() {
	Control::setupControl();
}
