#pragma once
#include <iostream>

using std::string;

class BaseLogger {
	public:
		BaseLogger(const BaseLogger& other) = delete;

		BaseLogger(BaseLogger&& other) noexcept {
		}

		auto operator=(const BaseLogger& other) -> BaseLogger& = delete;

		auto operator=(BaseLogger&& other) noexcept -> BaseLogger& {
			if (this == &other)
				return *this;
			return *this;
		}

		BaseLogger();

		virtual ~BaseLogger();

		virtual auto info(string message) -> void;
		virtual auto error(string message) -> void;
		virtual auto warning(string message) -> void;
		virtual auto debug(string message) -> void;
};
