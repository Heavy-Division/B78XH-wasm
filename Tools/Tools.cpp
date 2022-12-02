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

#include "Tools.h"

#include <cctype>
#include <cmath>

#include "fmt/core.h"


namespace Tools {
	auto Frequencies::setVHFFrequency(vhf_index index, state state, FLOAT64 value) -> void {
		std::string countedIndex;
		switch (index) {
		case ONE:
			countedIndex = "";
			break;
		case TWO:
			countedIndex = "2";
			break;
		case THREE:
			countedIndex = "3";
			break;
		default:
			countedIndex = "";
			break;
		}
		constexpr int factor = 1000000;
		const FLOAT64 toSet = value * factor;
		const std::string event = "(>K:COM" + countedIndex + (state == STANDBY ? "_STBY" : "") + "_RADIO_SET_HZ)";
		const std::string expression = std::to_string(toSet) + " " + event;
		execute_calculator_code(expression.c_str(), nullptr, nullptr, nullptr);
	}

	auto Frequencies::setVHFActiveFrequency(vhf_index index, FLOAT64 value) -> void {
		setVHFFrequency(index, ACTIVE, value);
	}

	auto Frequencies::setVHFStandbyFrequency(vhf_index index, FLOAT64 value) -> void {
		setVHFFrequency(index, STANDBY, value);
	}

	auto Frequencies::swapVHFFrequencies(vhf_index index) -> void {
		const std::string event = "1 (>K:COM" + std::to_string(index) + "_RADIO_SWAP)";
		execute_calculator_code(event.c_str(), nullptr, nullptr, nullptr);
	}

	auto Frequencies::isVHFFrequencyValid(FLOAT64 MHz) -> bool {
		if (MHz >= 118 && MHz <= 136.9 && isHz833Compliant(MHz)) {
			return true;
		}
		return false;
	}

	auto Frequencies::isHz833Compliant(FLOAT64 MHz) -> bool {
		const int spacing[16] = { 0, 5, 10, 15, 25, 30, 35, 40, 50, 55, 60, 65, 75, 80, 85, 90 };
		const FLOAT64 frequency = round(MHz * 1000) / 1000;
		const FLOAT64 modulo = fmod(frequency * 10, 1);
		const FLOAT64 fixedModulo = floor(modulo * 100);
		for (const auto& value : spacing) {
			if (fabs(value - fixedModulo) < REAL_EPSILON) {
				return true;
			}
		}
		return false;
	}

	auto Frequencies::isHz25Compliant(FLOAT64 MHz) -> bool {
		const FLOAT64 frequency = round(MHz * 1000) / 1000;
		const FLOAT64 modulo = fmod(frequency, 0.025);
		return (modulo < 0.001 ? true : false);
	}

	auto Frequencies::isHz50Compliant(FLOAT64 MHz) -> bool {
		const FLOAT64 frequency = round(MHz * 100) / 100;
		const FLOAT64 modulo = fmod(frequency, 0.05);
		return (modulo < 0.001 ? true : false);
	}

	auto Transponder::isXPDRCompliant(std::string value) -> bool {
		if (value.length() == 4) {
			for (const auto character : value) {
				if (!std::isdigit(character)) {
					return false;
				}
				const int intCharacter = std::atoi(&character);
				if (intCharacter < 0 || intCharacter > 7) {
					return false;
				}
			}
			return true;
		}
		return false;
	}

	auto Transponder::setCode(std::string value) -> void {
		if (isXPDRCompliant(value)) {
			const int number = std::stoi(value, nullptr, 16);
			const std::string command = fmt::format("{} (>K:XPNDR_SET, number)", number);
			execute_calculator_code(command.c_str(), nullptr, nullptr, nullptr);
		}
	}

	auto Transponder::ident() -> void {
		execute_calculator_code("1 (>K:XPNDR_IDENT_ON, bool)", nullptr, nullptr, nullptr);
	}

	auto smoothPow(double start, double end, double factor, double deltaTime) -> double {
		if (deltaTime <= 0 || factor <= 1.0) {
			return end;
		}
		const double calculatedFactor = 1.0 - (1.0 / pow(factor, deltaTime * (1.0 / 0.033)));
		return (end - start) * calculatedFactor + start;
	}

	auto clamp(double value, double lo, double hi) -> double {
		return std::min<double>(hi, std::max<double>(value, lo));
	};
}
