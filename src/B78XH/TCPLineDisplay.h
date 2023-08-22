#pragma once
#include "LineDisplay.h"
#include "TCPLeftLine.h"
#include <string>

class TCPLineDisplay : public LineDisplay {
	private:
		TCPLeftLine leftLineOne;
		void prepareLines();
		void setupLines();
		void init();
};