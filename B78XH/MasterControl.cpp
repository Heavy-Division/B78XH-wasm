#include "MasterControl.h"

auto MasterControl::getMouseMoveResolver() -> CDUMouseMoveResolver& {
	return mouseMoveResolver_;
}

auto MasterControl::getMouseClickResolver() -> CDUMouseClickResolver& {
	return mouseClickResolver_;
}
