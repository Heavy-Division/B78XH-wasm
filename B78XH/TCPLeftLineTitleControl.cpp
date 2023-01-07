#include "TCPLeftLineTitleControl.h"

auto TCPLeftLineTitleControl::setupControl() -> void {
	TCPLineControl::setupControl();
	getPosition().setPosition(20, getLineVerticalPosition() - 13, 0, 0);
	getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
	getContentHolder().setContentVerticalAlign(NVG_ALIGN_BOTTOM);
	getContentHolder().setDefaultFontSize(17);
}
