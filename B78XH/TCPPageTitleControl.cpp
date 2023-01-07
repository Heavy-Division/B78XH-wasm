#include "TCPPageTitleControl.h"

auto TCPPageTitleControl::setupControl() -> void {
	LineControl::setupControl();
	getPosition().setPosition(170, 30, 0, 0);
	getContentHolder().setAlign(ContentHolder::ALIGN::CENTER);
	getContentHolder().setContentVerticalAlign(NVG_ALIGN_BOTTOM);
	getContentHolder().setDefaultFontSize(25);
}
