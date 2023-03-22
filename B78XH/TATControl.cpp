#include "TATControl.h"
#include "Tools/Tools.h"
#include "Simplane.h"


void TATControl::setupControl() {
	LineControl::setupControl();

	getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
	getContentHolder().setDefaultFontSize(25.0f);
	getContentHolder().setDefaultFontColor(Tools::Colors::white);
	getContentHolder().addColor("blue", Tools::Colors::lightBlue);

	getRelativePosition().setPosition(25, 25, 0, 0);
	getContentHolder().addSize("small", 20.0f);
	getContentHolder().addContentVerticalOffset("tempOffset", 2.0f);

	auto tempSignHandler = []() -> std::string {
		if (Simplane::environment::temperature::trueAirTemp() > 0) {
			return "+";
		}
		return "";
	};

	addOnBeforeRender([tempSignHandler](BaseControl& control) -> bool {
		control.getContentHolder().setContent({
	{"TAT", "blue"},
	{tempSignHandler(), "large"},
	{std::to_string(static_cast<int>(Simplane::environment::temperature::trueAirTemp()))},
    {"c", "small|tempOffset"}});
		return true;
	});

	addOnValidate([](BaseControl& control) -> bool {
		return false;
	});
}

