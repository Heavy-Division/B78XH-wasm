#include "BaseLogger.h"

BaseLogger::BaseLogger() = default;

BaseLogger::~BaseLogger() = default;

auto BaseLogger::info(string message) -> void {
	string prefix = "INFO: ";
	std::cout << prefix.append(message) << std::endl << std::flush;
}

auto BaseLogger::error(string message) -> void {
	string prefix = "ERROR: ";
	std::cerr << prefix.append(message);
}

auto BaseLogger::warning(string message) -> void {
	string prefix = "WARNING: ";
	std::cerr << prefix.append(message);
}

auto BaseLogger::debug(string message) -> void {
	string prefix = "DEBUG: ";
	std::cerr << prefix.append(message);
}