#include "CDULineTitleControl.h"

auto CDULineTitleControl::getLineVerticalPosition() const -> float {
	constexpr auto initialOffset = 52.0f;
	constexpr auto offset = 68.0f;
	return initialOffset + (static_cast<float>(lineNumber_) * offset);
}
