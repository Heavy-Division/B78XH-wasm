#include "TCPPagesLineControl.h"

auto TCPPagesLineControl::setupControl() -> void {
	LineControl::setupControl();

	getRelativePosition().setPosition(320, 30, 0, 0);
	getContentHolder().setAlign(ContentHolder::ALIGN::RIGHT);
	getContentHolder().setContentVerticalAlign(NVG_ALIGN_BOTTOM);
	getContentHolder().setDefaultFontSize(17);
}
