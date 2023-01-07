#include "TCPLineControl.h"

auto TCPLineControl::getLineVerticalPosition() const -> float {
	switch (lineNumber_) {
		case LINE_NUMBER::ONE: {
			return 63;
		}
		case LINE_NUMBER::TWO: {
			return 116;
		}
		case LINE_NUMBER::THREE: {
			return 165;
		}
		case LINE_NUMBER::FOUR: {
			return 214;
		}
	}
	return 0;
}

auto TCPLineControl::setupControl() -> void {
	LineControl::setupControl();
	getContentHolder().setDefaultFontSize(25);
}
