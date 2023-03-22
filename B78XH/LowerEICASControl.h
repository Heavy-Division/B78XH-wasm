#pragma once
#include "EICASBaseControl.h"

class LowerEICASControl : public EICASBaseControl {
public:
	explicit LowerEICASControl(const string& name)
		: EICASBaseControl(name) {}

protected:
	auto drawDataBox(double width, double height, int decimals, float fontSize) -> void override;
	auto setBoxStyle() -> void;

	// Determines if warning is triggered on falling below advisory threshold (MIN) or going above (MAX) 
	enum MinMax {
		MIN,
		MAX
	};

	bool isDataNonNormal();

	MinMax minmax;
	NVGcolor fillColor = Tools::Colors::black;
	NVGcolor textColor = Tools::Colors::white;
};
