#include "ControlPosition.h"
#include <cmath>

#include "Tools/Console.h"

auto ControlPosition::getLeft() const -> float {
	return position_[0];
}

auto ControlPosition::setLeft(const float left) -> void {
	setPositionSet(true);
	position_[0] = left;
}

auto ControlPosition::getTop() const -> float {
	return position_[1];
}

auto ControlPosition::setTop(const float top) -> void {
	setPositionSet(true);
	position_[1] = top;
}

auto ControlPosition::getRight() const -> float {
	return position_[2];
}

auto ControlPosition::setRight(const float right) -> void {
	setPositionSet(true);
	position_[2] = right;
}

auto ControlPosition::getBottom() const -> float {
	return position_[3];
}

auto ControlPosition::setBottom(const float bottom) -> void {
	setPositionSet(true);
	position_[3] = bottom;
}

auto ControlPosition::setPosition(float left, float top, float right, float bottom) -> void {
	setLeft(left);
	setTop(top);
	setRight(right);
	setBottom(bottom);
}

auto ControlPosition::getPosition() const -> const std::array<float, 4>& {
	return position_;
}

auto ControlPosition::setPosition(const std::array<float, 4>& position) -> void {
	position_ = position;
}

auto ControlPosition::getSize() const -> std::array<float, 2> {
	return { getWidth(), getHeight() };
}

auto ControlPosition::getWidth() const -> float {
	return std::abs(left - right);
}

auto ControlPosition::getHeight()  const -> float {
	return std::abs(top - bottom);
}

auto ControlPosition::isPositionSet() const -> bool {
	return positionSet_;
}

auto ControlPosition::setPositionSet(const bool positionSet) -> void {
	positionSet_ = positionSet;
}
