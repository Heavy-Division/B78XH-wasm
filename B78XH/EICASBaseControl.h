#pragma once
#include "Control.h"
#include "Tools/Tools.h"
#include "Side.h"
#include "GaugeType.h"
#include "Simplane.h"

class EICASBaseControl : public Control {
public:
	explicit EICASBaseControl(const string& name)
		: Control(name), data(data) {}

	auto render() -> void override;

protected:

	enum MaxLines {
		TOP,
		BOTTOM,
		NONE,
		DUAL,
	};

	auto setupControl() -> void override;

	virtual auto drawDataBox(double width, double height, int decimals, float fontSize) -> void;

	auto fwsColorHandler(NVGcolor defaultColor) -> NVGcolor;
	auto drawLineGauge(double x, double y_pos, double line_height, MaxLines red_lines) -> void;
	auto drawRedLines(double x, double y, double line_height, MaxLines line_type) -> void;
	auto getGaugeType() -> GaugeType;

	GaugeType gauge_type = SECONDARY;
	Side fuel_valve_connection = LEFT;

	double data = 0;
	double x = 0;
	double y = 0;
	double max = 0;
	double advisory_threshold = 0;
	double warning_threshold = 0;
	double render_cutoff = 0;
	bool render_on_start = false;

};
