#pragma once
#include "Line.h"

class TCPLeftLine : public Line {
	protected:
	public:
		auto render() -> void override;
};
