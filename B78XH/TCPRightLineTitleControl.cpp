#include "TCPRightLineTitleControl.h"

auto TCPRightLineTitleControl::setupControl() -> void {
	TCPLineControl::setupControl();
	getPosition().setPosition(320, getLineVerticalPosition() - 13, 0, 0);
	getContentHolder().setAlign(ContentHolder::ALIGN::RIGHT);
	getContentHolder().setContentVerticalAlign(NVG_ALIGN_BOTTOM);
	getContentHolder().setDefaultFontSize(17);
	getContentHolder().addColor("cyan", Tools::Colors::cyan);
}
