#include "TCPCenterLineTitleControl.h"

auto TCPCenterLineTitleControl::setupControl() -> void {
	TCPLineControl::setupControl();
	getRelativePosition().setPosition(170, getLineVerticalPosition() - 13, 0, 0);
	getContentHolder().setAlign(ContentHolder::ALIGN::CENTER);
	getContentHolder().setContentVerticalAlign(NVG_ALIGN_BOTTOM);
	getContentHolder().setDefaultFontSize(17);
}
