#include "ExampleLineControl.h"

#include "LineControl.h"
#include "Tools/Tools.h"
#include "Simplane.h"
#include "Tools/Console.h"

void ::ExampleLineControl::prepareControls() {
	Control::prepareControls();
	add(std::make_unique<LineControl>("LineControl"));
}

void ::ExampleLineControl::setupControls() {
	Control::setupControls();
	auto& line = getControl("LineControl");

	line->getContentHolder().setAlign(ContentHolder::ALIGN::RIGHT);
	line->getContentHolder().setDefaultFontSize(90);
	line->getContentHolder().setDefaultFontColor(Tools::Colors::white);
	line->getContentHolder().addSize("large", 80.0);
	line->getContentHolder().addColor( "blue", Tools::Colors::blue);
	line->getContentHolder().setContent({{"TEST LINE CONTROL", "large|blue|voffset13"}});
	line->position.setPosition(1200, 200, 0, 0);

	// un-comment below to see dynamically rendered text

	// line->addOnBeforeRender([](BaseControl& control) -> bool {
	// 	Console::log("test");
	// 	control.getContentHolder().addContentVerticalOffset("voffset13", static_cast<float>(Simplane::aircraft::state::pitch() * 100));
	// 	control.getContentHolder().setContent({ {std::to_string(Simplane::aircraft::state::pitch() * 100)}, {"TEST LINE CONTROL", "large|blue|voffset13"}});
	// return true;
	// 	});
	//
	// line->addOnValidate([](BaseControl& control) -> bool {
	// 	Console::log("test2");
	// 	return false;
	// });



;}

void ::ExampleLineControl::setupControl() {
	Control::setupControl();
}
