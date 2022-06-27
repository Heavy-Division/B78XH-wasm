#pragma once
#include <MSFS/Legacy/gauges.h>
#include <string>

namespace Tools {
	class Frequencies {
		public:
			enum type {
				VHF
			};

			enum state {
				ACTIVE,
				STANDBY
			};

			enum vhf_index {
				ONE = 1,
				TWO = 2,
				THREE = 3
			};

			static void setVHFFrequency(vhf_index index, state state, FLOAT64 value);
			static void setVHFActiveFrequency(vhf_index index, FLOAT64 value);
			static void setVHFStandbyFrequency(vhf_index index, FLOAT64 value);
			static void swapVHFFrequencies(vhf_index index);
			static bool isVHFFrequencyValid(FLOAT64 MHz);
			static bool isHz833Compliant(FLOAT64 MHz);
			static bool isHz25Compliant(FLOAT64 MHz);
			static bool isHz50Compliant(FLOAT64 MHz);
	};

	class Transponder {
		public:
			static bool isXPDRCompliant(std::string value);
			static void setCode(std::string value);
			static void ident();
	};
}