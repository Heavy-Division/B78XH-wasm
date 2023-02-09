#include "TCPCenterLineControl.h"

auto TCPCenterLineControl::setupControl() -> void {
	TCPLineControl::setupControl();
	getContentHolder().setAlign(ContentHolder::ALIGN::CENTER);
	getRelativePosition().setPosition(170, getLineVerticalPosition(), 0, 0);
}
