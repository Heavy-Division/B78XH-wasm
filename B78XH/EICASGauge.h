#pragma once

#include "Control.h"
#include "Tools/Tools.h"


class EICASGauge : public Control {
public:
	explicit EICASGauge(const string& name)
		: Control(name), advisory_threshold(advisory_threshold), warn_threshold(warn_threshold), data(data) {}

	auto render() -> void override;
	

protected:
	auto setupControl() -> void override;
	auto drawCircle(double origin_x, double origin_y) -> void;
	auto drawDataBox(double x_pos, double y_pos, double width, double height) -> void;
	auto drawLabel(std::string label) -> void;
	auto drawRedLine() -> void;
	auto drawDeltaIndicator() -> void;
	auto fwsColorHandler(double advisory_threshold, double warning_threshold) -> void;

private:
	double radius = 60;
	double data = 0;
	double advisory_threshold;
	double warn_threshold;
	double max_angle = 3.69;
};