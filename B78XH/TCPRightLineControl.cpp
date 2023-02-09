#include "TCPRightLineControl.h"

auto TCPRightLineControl::setupControl() -> void {
	TCPLineControl::setupControl();
	getContentHolder().setAlign(ContentHolder::ALIGN::RIGHT);
	getRelativePosition().setPosition(335, getLineVerticalPosition(), 0, 0);
}
