#pragma once
#include <vector>

#include "Application.h"
#include "Line.h"


class LineDisplay: public Application {
	public:
		virtual auto init() -> void;
		void setContext(NVGcontext* nvgContext);
	protected:
		~LineDisplay() = default;
		NVGcontext* nvgContext = nullptr;
		std::vector<std::reference_wrapper<Line>> lines{};
		auto addLine(Line& line) -> void;
		virtual auto prepareLines() -> void;
		virtual auto setupLines() -> void;
	private:
		virtual auto setupLinesContext() -> void final;
};
