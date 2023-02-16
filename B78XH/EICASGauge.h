#pragma once

#include "Control.h"
#include "Tools/Tools.h"
#include "Simplane.h"


class EICASGauge : public Control {
public:
	explicit EICASGauge(const string& name)
		: Control(name), data(data) {

	}
protected:

	enum Side {
		LEFT,
		RIGHT
	};

	auto setupControl() -> void override;
	auto drawCircle(double data) -> void;
	auto drawArc(double data, double max) -> void;
	auto drawHeader(double data) -> void;
	auto drawHeader(string data) -> void;
	auto drawDataBox(double width, double height, double data, Side side) -> void;
	auto drawLabel(std::string label) -> void;
	auto drawRedLine() -> void;
	auto drawDeltaIndicator() -> void;

	auto fwsColorHandler(double data, NVGcolor defaultColor) -> NVGcolor;

	inline static double radius = 60;
	inline static double max_angle = 3.69;

	double data;
	
	double render_cutoff = 0;
	double advisory_threshold = 0;
	double warning_threshold = 0;
	double x = 0;
	double y = 0;
};