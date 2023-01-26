#include "CDUIdentPageControl.h"

#include "CDULineControl.h"

auto CDUIdentPageControl::prepareControls() -> void {
	CDUPageControl::prepareControls();
	add(std::make_shared<CDULineControl>("TEST"));
	add(std::make_shared<CDULineControl>("TEST2"));
}

auto CDUIdentPageControl::setupControls() -> void {
	CDUPageControl::setupControls();

	auto& line = getControl("TEST");
	line->position.setPosition(100, 50, 0, 0);
	line->getContentHolder().setAlign(ContentHolder::ALIGN::RIGHT);
	line->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({ {"RIGHT", "settable"}, {"NOT SETTABLE"}, {"SETTABLE AGAIN", "settable"} });
		return true;
		});

	auto& line2 = getControl("TEST2");
	line2->position.setPosition(100, 100, 0, 0);
	line2->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({ {"LEFT", "settable"}, {"NOT SETTABLE"}, {"SETTABLE AGAIN", "settable"}});
	return true;
		});
}
