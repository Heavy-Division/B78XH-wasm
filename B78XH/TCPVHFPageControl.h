#pragma once
#include "TCPPageControl.h"

class TCPVHFPageControl : public TCPPageControl {
	public:
		explicit TCPVHFPageControl(const string& name)
			: TCPPageControl(name, "") {
			pages = std::make_unique<Pages>();
		}

		TCPVHFPageControl(const string& name, const std::string& scratchpadBuffer)
			: TCPPageControl(name, scratchpadBuffer) {
			pages = std::make_unique<Pages>();
		}

	protected:
		auto prepareControls() -> void override;
		auto setupControls() -> void override;

		auto prepareLines() -> void;
		auto calculateNumberOfPages() -> void;
		auto setupControl() -> void override;

	private:
		enum class Lines {
			LEFT_ONE,
			LEFT_TWO,
			LEFT_THREE,
			LEFT_FOUR,
			CENTER_ONE,
			CENTER_TWO,
			CENTER_THREE,
			CENTER_FOUR,
			RIGHT_ONE,
			RIGHT_TWO,
			RIGHT_THREE,
			RIGHT_FOUR,
		};

		enum class LineTitles {
			LEFT_ONE,
			LEFT_TWO,
			LEFT_THREE,
			LEFT_FOUR,
			CENTER_ONE,
			CENTER_TWO,
			CENTER_THREE,
			CENTER_FOUR,
			RIGHT_ONE,
			RIGHT_TWO,
			RIGHT_THREE,
			RIGHT_FOUR,
		};

		class Line {
			public:
				vector<array<string, 2>> content = {{}};
				std::function<void()> callback = [](void)-> void {
				};;
		};

		class LineTitle {
			public:
				vector<array<string, 2>> content = {{}};
		};

		std::array<Line, 12> lines;
		std::array<LineTitle, 12> lineTitles;
};
