#pragma once

#include "EICASBaseControl.h"


class EICASCircularControl : public EICASBaseControl {
public:
	explicit EICASCircularControl(const string& name)
		: EICASBaseControl(name) {
	}

protected:

	struct CircularDataBox {
		inline static double width = 65;
		inline static double height = 29;
		inline static float fontSize = 27.0f;
	};

	auto drawCircle() -> void;
	auto drawArc(double max, bool momentaryDifference) -> void;
	auto drawHeader(double data) -> void;
	auto drawHeader(string data) -> void;


	inline static double radius = 60;
	inline static double max_angle = 3.69;


	double commanded_data = data;
	

};

