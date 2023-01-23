#include "TCPPageControl.h"

auto TCPPageControl::getPages() const -> const std::unique_ptr<Pages>& {
	return pages;
}
