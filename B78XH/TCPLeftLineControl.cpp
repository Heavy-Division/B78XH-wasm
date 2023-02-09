#include "TCPLeftLineControl.h"

auto TCPLeftLineControl::setupControl() -> void {
	TCPLineControl::setupControl();
	getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
	getRelativePosition().setPosition(5, getLineVerticalPosition(), 0, 0);
}
