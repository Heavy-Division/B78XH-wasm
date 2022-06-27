#include "Tools.h"

#include <cctype>
#include <cmath>
#include <string>
#include "fmt/core.h"

#include <MSFS/Legacy/gauges.h>

namespace Tools {
	void Frequencies::setVHFFrequency(vhf_index index, state state, FLOAT64 value) {
		std::string countedIndex;
		switch(index) {
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

	void Frequencies::setVHFActiveFrequency(vhf_index index, FLOAT64 value) {
		setVHFFrequency(index, ACTIVE, value);
	}

	void Frequencies::setVHFStandbyFrequency(vhf_index index, FLOAT64 value) {
		setVHFFrequency(index, STANDBY, value);
	}

	void Frequencies::swapVHFFrequencies(vhf_index index) {
		const std::string event = "1 (>K:COM" + std::to_string(index) + "_RADIO_SWAP)";
		execute_calculator_code(event.c_str(), nullptr, nullptr, nullptr);
	}

	bool Frequencies::isVHFFrequencyValid(FLOAT64 MHz) {
		if (MHz >= 118 && MHz <= 136.9 && isHz833Compliant(MHz)) {
			return true;
		}
		return false;
	}

	bool Frequencies::isHz833Compliant(FLOAT64 MHz) {
		const int spacing[16] = {0, 5, 10, 15, 25, 30, 35, 40, 50, 55, 60, 65, 75, 80, 85, 90};
		const FLOAT64 frequency = round(MHz * 1000) / 1000;
		fmt::print(stderr, "{}", frequency);


		fmt::print(stderr, "{}", "ENFORCE STOP");
		const FLOAT64 modulo = fmod(frequency * 10, 1);
		fmt::print(stderr, "{}", "ENFORCE STOP 2");
		const FLOAT64 fixedModulo = floor(modulo * 100);
		fmt::print(stderr, "{}", "ENFORCE STOP 3");
		for(const auto &value : spacing) {
			if(fabs(value - fixedModulo) < REAL_EPSILON) {
				return true;
			}
		}
		return false;
	}

	bool Frequencies::isHz25Compliant(FLOAT64 MHz) {
		const FLOAT64 frequency = round(MHz * 1000) / 1000;
		const FLOAT64 modulo = fmod(frequency, 0.025);
		return (modulo < 0.001 ? true : false);
	}

	bool Frequencies::isHz50Compliant(FLOAT64 MHz) {
		const FLOAT64 frequency = round(MHz * 100) / 100;
		const FLOAT64 modulo = fmod(frequency, 0.05);
		return (modulo < 0.001 ? true : false);
	}

	bool Transponder::isXPDRCompliant(std::string value) {
		if(value.length() == 4) {
			for(const auto character : value) {
				if(!std::isdigit(character)) {
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

	void Transponder::setCode(std::string value) {
		if(Transponder::isXPDRCompliant(value)) {
			const int number = std::stoi(value, nullptr, 16);
			const std::string command = fmt::format("{} (>K:XPNDR_SET, number)", number);
			execute_calculator_code(command.c_str(), nullptr, nullptr, nullptr);	
		}
	}

	void Transponder::ident() {
		execute_calculator_code("1 (>K:XPNDR_IDENT_ON, bool)", nullptr, nullptr, nullptr);
	}
}
