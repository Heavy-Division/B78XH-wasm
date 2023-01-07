#pragma once
#include <array>

class ControlPosition {
	public:
		[[nodiscard]] auto getLeft() const -> float;
		auto setLeft(const float left) -> void;
		__declspec(property(get = getLeft, put = setLeft)) float left;
		[[nodiscard]] auto getTop() const -> float;
		auto setTop(const float top) -> void;
		__declspec(property(get = getTop, put = setTop)) float top;
		[[nodiscard]] auto getRight() const -> float;
		auto setRight(const float right) -> void;
		__declspec(property(get = getRight, put = setRight)) float right;
		[[nodiscard]] auto getBottom() const -> float;
		auto setBottom(const float bottom) -> void;
		__declspec(property(get = getBottom, put = setBottom)) float bottom;
		auto setPosition(float left, float top, float right, float bottom) -> void;
		[[nodiscard]] auto getPosition() const -> const std::array<float, 4>&;
		auto setPosition(const std::array<float, 4>& position) -> void;
		__declspec(property(get = getPosition, put = setPosition)) std::array<float, 4>& position;
		[[nodiscard]]auto getSize() const -> std::array<float, 2>;
		__declspec(property(get = getSize)) const std::array<float, 2> size;
		[[nodiscard]] auto getWidth() const -> float;
		__declspec(property(get = getWidth)) const float width;
		[[nodiscard]] auto getHeight() const -> float;
		__declspec(property(get = getHeight)) const float height;
		[[nodiscard]] auto isPositionSet() const -> bool;
	protected:
		std::array<float, 4> position_ = {0,0,0,0};
		bool positionSet_ = false;
	private:
		auto setPositionSet(const bool positionSet) -> void;
		__declspec(property(get = isPositionSet, put = setPositionSet)) bool positionSet;
};
