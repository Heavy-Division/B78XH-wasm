#include "MFDDisplayContainer.h"

auto MFDDisplayContainer::getLeftSide() const -> const std::shared_ptr<MFDBaseControl>& {
	return leftSide_;
}

auto MFDDisplayContainer::getRightSide() const -> const std::shared_ptr<MFDBaseControl>& {
	return rightSide_;
}

auto MFDDisplayContainer::isHasEicas() const -> bool {
	return hasEICAS;
}

auto MFDDisplayContainer::setHasEicas(const bool hasEicas) -> void {
	hasEICAS = hasEicas;
}

auto MFDDisplayContainer::isInvalid() const -> bool {
	return invalid_;
}

auto MFDDisplayContainer::setInvalid(const bool invalid) -> void {
	invalid_ = invalid;
}
