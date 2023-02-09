#pragma once
#include "Control.h"
#include "TCPScratchpadControl.h"
#include "Tools/Console.h"
#include <memory>

class TCPPageControl : public Control {
	public:
		explicit TCPPageControl(const string& name, std::shared_ptr<TCPScratchpadControl>& scratchPad)
			: Control(name),
			  scratchPad_(scratchPad) {
			scratchPad_->setEventsDisabled(false);
		}

		/*
		 * Events
		 */

		std::function<void()> EMTPY_PRESS_EVENT = [](void)-> void {
		};

		std::function<void()> onL1Pressed = EMTPY_PRESS_EVENT;
		std::function<void()> onL2Pressed = EMTPY_PRESS_EVENT;
		std::function<void()> onL3Pressed = EMTPY_PRESS_EVENT;
		std::function<void()> onL4Pressed = EMTPY_PRESS_EVENT;
		std::function<void()> onR1Pressed = EMTPY_PRESS_EVENT;
		std::function<void()> onR2Pressed = EMTPY_PRESS_EVENT;
		std::function<void()> onR3Pressed = EMTPY_PRESS_EVENT;
		std::function<void()> onR4Pressed = EMTPY_PRESS_EVENT;
		std::function<void()> onStbyUpPressed = EMTPY_PRESS_EVENT;
		std::function<void()> onStbyDownPressed = EMTPY_PRESS_EVENT;
		std::function<void()> onXfrPressed = EMTPY_PRESS_EVENT;

		std::shared_ptr<TCPScratchpadControl>& scratchPad_;

		/*
		 * Pages
		 */

		class Pages {
			public:
				int numberOfPages = 1;
				int currentPageNumber = 1;
		};

		[[nodiscard]] auto getPages() const -> const std::unique_ptr<Pages>&;

	protected:
		std::unique_ptr<Pages> pages = nullptr;

		auto resetOnPressEvents() -> void {
			onL1Pressed = EMTPY_PRESS_EVENT;
			onL2Pressed = EMTPY_PRESS_EVENT;
			onL3Pressed = EMTPY_PRESS_EVENT;
			onL4Pressed = EMTPY_PRESS_EVENT;
			onR1Pressed = EMTPY_PRESS_EVENT;
			onR2Pressed = EMTPY_PRESS_EVENT;
			onR3Pressed = EMTPY_PRESS_EVENT;
			onR4Pressed = EMTPY_PRESS_EVENT;
			onStbyUpPressed = EMTPY_PRESS_EVENT;
			onStbyDownPressed = EMTPY_PRESS_EVENT;
			onXfrPressed = EMTPY_PRESS_EVENT;
		}
};
