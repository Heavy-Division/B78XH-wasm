#include "TCPLeftLineControl.h"

auto TCPLeftLineControl::setupControl() -> void {
	TCPLineControl::setupControl();
	getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
	getPosition().setPosition(5, getLineVerticalPosition(), 0, 0);
}
