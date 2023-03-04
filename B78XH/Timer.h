#pragma once

#include <cmath>
#include "Counter.h"
#include "Simplane.h"

class Timer : public Counter {
public:
	Timer(double target_value, bool auto_start = false)
		: Counter(target_value, auto_start) {
	}
};

