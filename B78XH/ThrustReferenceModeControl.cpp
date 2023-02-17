#include "ThrestReferenceModeControl.h"
#include "Tools/Tools.h"

auto ThrustReferenceModeControl::setupControl() -> void {
	LineControl::setupControl();


	getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
	getContentHolder().setDefaultFontSize(25.0f);
	getContentHolder().setDefaultFontColor(Tools::Colors::greenPure);
	getContentHolder().addColor("cyan", Tools::Colors::cyan);

	// TODO: Set position in EICASControl.cpp
	getRelativePosition().setPosition(160, 25, 0, 0);
	getContentHolder().addSize("small", 20.0f);
	getContentHolder().addContentVerticalOffset("tempOffset", 2.0f);


	addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({ 
			{"D-TO"}
		});

		return true;
	});

	addOnValidate([](BaseControl& control) -> bool {
		return false;
	});
};