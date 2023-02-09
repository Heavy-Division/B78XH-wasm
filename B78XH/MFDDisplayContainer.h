#pragma once
#include <memory>

#include "MFDBaseControl.h"
#include "MFDEmptyControl.h"

class MFDDisplayContainer {
	public:
		MFDDisplayContainer(const std::shared_ptr<MFDBaseControl>& leftSide, const std::shared_ptr<MFDBaseControl>& rightSide)
			: leftSide_(leftSide),
			  rightSide_(rightSide), invalid_(false) {
			leftSide_->setName("LEFT_SIDE");
			rightSide_->setName("RIGHT_SIDE");
		}

		[[nodiscard]] auto getLeftSide() const -> const std::shared_ptr<MFDBaseControl>&;
		[[nodiscard]] auto getRightSide() const -> const std::shared_ptr<MFDBaseControl>&;
		[[nodiscard]] auto isHasEicas() const -> bool;
		auto setHasEicas(const bool hasEicas) -> void;
		[[nodiscard]] auto isInvalid() const -> bool;
		auto setInvalid(const bool invalid) -> void;

	private:
		const std::shared_ptr<MFDBaseControl>& leftSide_;
		const std::shared_ptr<MFDBaseControl>& rightSide_;
		bool hasEICAS = false;
		bool invalid_;
};
