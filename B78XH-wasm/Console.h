//    B78XH-wasm
//    Copyright (C) 2022  Heavy Division
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.


#pragma once

#include "fmt/core.h"

namespace Console {
	const std::string PREFIX_NONE = "";
	const std::string PREFIX_WARNING = "WARNING: ";
	const std::string PREFIX_ERROR = "ERROR: ";
	const std::string PREFIX_INFO = "INFO: ";
	const std::string LOG_SEPARATOR = "------------------------------------------------------------------------------------------------------------------------------------";

	/*
	 * Default LOG template (internal).
	 * This template should not be called directly outside Console namespace!
	 */
	template <typename... T>
	FMT_INLINE void _log(std::string prefix, std::FILE* f, std::string fmt, T&&... args) {
		fmt::print(f, prefix + fmt, args...);
		if(f == stdout) {
			fflush(stdout);
		}
	}

	/*
	 * Logs a message to console (stdout = INFO, stderr = ERROR)
	 */
	template <typename... T>
	FMT_INLINE void log(std::FILE* f, std::string fmt, T&&... args) {
		_log(PREFIX_NONE, f, fmt, args...);
	}

	/*
	 * Logs a message to stdout (MSFS console INFO)
	 */
	template <typename... T>
	FMT_INLINE void log(std::string fmt, T&&... args) {
		_log(PREFIX_NONE, stdout, fmt, args...);
	}

	/*
	 * Logs a message to stdout (MSFS console INFO) [NO PREFIX]
	 */
	template <typename... T>
	FMT_INLINE void cinfo(std::string fmt, T&&... args) {
		_log(PREFIX_NONE, stdout, fmt, args...);
	}

	/*
	 * Logs a message to stdout (MSFS console INFO) [WITH PREFIX]
	 * Prefix: "INFO: "
	 */
	template <typename... T>
	FMT_INLINE void info(std::string fmt, T&&... args) {
		_log(PREFIX_INFO, stdout, fmt, args...);
	}

	/*
	 * Logs a message to stderr (MSFS console ERROR) [NO PREFIX]
	 */
	template <typename... T>
	FMT_INLINE void cerror(std::string fmt, T&&... args) {
		_log(PREFIX_NONE, stderr, fmt, args...);
	}

	/*
	 * Logs a message to stderr (MSFS console ERROR) [WITH PREFIX]
	 * Prefix: "ERROR: "
	 */
	template <typename... T>
	FMT_INLINE void error(std::string fmt, T&&... args) {
		_log(PREFIX_ERROR, stderr, fmt, args...);
	}

	/*
	 * Logs a message to stderr (MSFS console ERROR) [NO PREFIX]
	 */
	template <typename... T>
	FMT_INLINE void cwarning(std::string fmt, T&&... args) {
		_log(PREFIX_NONE, stderr, fmt, args...);
	}

	/*
	 * Logs a message to stderr (MSFS console ERROR) [WITH PREFIX]
	 * Prefix: "WARNING: "
	 */
	template <typename... T>
	FMT_INLINE void warning(std::string fmt, T&&... args) {
		_log(PREFIX_WARNING, stderr, fmt, args...);
	}

	/*
	 * Prints separator to MSFS console.
	 */
	FMT_INLINE void logSeparator(std::FILE* f) {
		/*
		 * MSFS Console stack same strings into one message and increase "OCCURRENCES" even if the messages are sent to different std::FILE (stdout, stderr)
		 * The code below add 0 - 100 whitespaces to separator message to fix the MSFS console behavior.
		 * NOTE: There is still possibility that MSFS will stack the messages if rand() generates two same numbers in row
		 */
		std::string random = "";
		const int places = 0 + rand() % (100 + 1);
		for(int i = 0; i <= places; i++) {
			random.append(" ");
		}
		_log(PREFIX_NONE, f, LOG_SEPARATOR + random);
	}

	/*
	 * Prints separator to stdout (MSFS console INFO)
	 */
	FMT_INLINE void infoSeparator() {
		logSeparator(stdout);
	}

	/*
	 * Prints separator to stderr (MSFS console INFO)
	 */
	FMT_INLINE void warningSeparator() {
		logSeparator(stderr);
	}

	/*
	 * Prints separator to stderr (MSFS console INFO)
	 */
	FMT_INLINE void errorSeparator() {
		logSeparator(stderr);
	}

	/*
	 * Prints separator to MSFS console (Default: stderr).
	 */
	FMT_INLINE void separator(std::FILE* f = stderr) {
		logSeparator(f);
	}

}