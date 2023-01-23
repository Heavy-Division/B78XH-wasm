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
		}

		/*
		 * Events
		 */

		std::function<void()> onL1Pressed = [](void)-> void {
		};
		std::function<void()> onL2Pressed = [](void)-> void {
		};
		std::function<void()> onL3Pressed = [](void)-> void {
		};
		std::function<void()> onL4Pressed = [](void)-> void {
		};
		std::function<void()> onR1Pressed = [](void)-> void {
		};
		std::function<void()> onR2Pressed = [](void)-> void {
		};
		std::function<void()> onR3Pressed = [](void)-> void {
		};
		std::function<void()> onR4Pressed = [](void)-> void {
		};

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
};
