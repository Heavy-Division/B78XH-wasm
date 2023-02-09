#include "CDURoutePageControl.h"

auto CDURoutePageControl::prepareControls() -> void {
	CDUPageControl::prepareControls();

}

auto CDURoutePageControl::setupControls() -> void {
	CDUPageControl::setupControls();

	pageTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({ {"RTE 1"} });
	return true;
		});
}
