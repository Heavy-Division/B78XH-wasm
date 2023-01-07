#pragma once
#include "BaseLogger.h"

class NullLogger: public BaseLogger {
	public:
		auto info(string message) -> void override;
		auto error(string message) -> void override;
		auto warning(string message) -> void override;
		auto debug(string message) -> void override;
};
