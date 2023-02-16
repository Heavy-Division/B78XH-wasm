// #include "TATControl.h"
//
// #include "LineControl.h"
// #include "Tools/Tools.h"
// #include "Simplane.h"
// #include "Tools/Console.h"
//
// void TATControl::setupControl() {
// 	EICASGauge::setupControl();
// 	auto& line = getControl("TATControl");
//
// 	line->getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
// 	line->getContentHolder().setDefaultFontSize(20);
// 	line->getContentHolder().setDefaultFontColor(Tools::Colors::white);
// 	line->getContentHolder().addColor("cyan", Tools::Colors::cyan);
// 	line->position.setPosition(25, 25, 0, 0);
// 	line->getContentHolder().addSize("large", 30);
//
// 	auto tempSignHandler = []() -> std::string {
// 		if (Simplane::environment::temperature::trueAirTemp() > 0) {
// 			return "+";
// 		}
// 		return "";
// 	};
//
// 	line->addOnBeforeRender([tempSignHandler](BaseControl& control) -> bool {
// 		control.getContentHolder().setContent({
// 	{"TAT", "cyan"},
// 	{tempSignHandler(), "large"},
// 	{std::to_string(static_cast<int>(Simplane::environment::temperature::trueAirTemp())), "large"},
// 		{"c", "large"} });
// 	return true;
// 		});
//
// 	line->addOnValidate([](BaseControl& control) -> bool {
// 		return false;
// 		});
// }
