// Tools.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include "MSFS/Render/nanovg.h"
#include <MSFS/Legacy/gauges.h>
#include <string>

namespace Tools {
	class Colors {
	public:
		inline static const NVGcolor black = nvgRGB(0, 0, 0);
		inline static const NVGcolor white = nvgRGB(255, 255, 255);
		inline static const NVGcolor red = nvgRGB(255, 0, 0);
		inline static const NVGcolor cyan = nvgRGB(54, 201, 210);
		inline static const NVGcolor amber = nvgRGB(255, 192, 0);
		inline static const NVGcolor blue = nvgRGB(0, 0, 255);
		inline static const NVGcolor greenBoeing = nvgRGB(131, 246, 4);
		inline static const NVGcolor greenPure = nvgRGB(0, 255, 0);
		inline static const NVGcolor green = greenBoeing;
		inline static const NVGcolor magentaPure = nvgRGB(255, 0, 255);
		inline static const NVGcolor magentaBoeing = nvgRGB(252, 174, 253);
		inline static const NVGcolor magenta = magentaBoeing;
		inline static const NVGcolor cduButtonGray = nvgRGB(106, 107, 120);
		inline static const NVGcolor cduButtonBorderTopGray = nvgRGB(185, 175, 196);
		inline static const NVGcolor cduButtonBorderRightGray = nvgRGB(35, 34, 36);
		inline static const NVGcolor cduButtonBorderBottomGray = nvgRGB(26, 25, 28);
		inline static const NVGcolor cduButtonBorderLeftGray = nvgRGB(196, 176, 200);
		inline static const NVGcolor cduSettableBorderBottomGray = nvgRGB(185, 175, 196);
		inline static const NVGcolor cduSettableBorderLeftGray = nvgRGB(35, 34, 36);
		inline static const NVGcolor cduSettableBorderTopGray = nvgRGB(26, 25, 28);
		inline static const NVGcolor cduSettableBorderRightGray = nvgRGB(196, 176, 200);
	};

	/*
	 * TODO: Move to different namespace
	 */
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

		static auto setVHFFrequency(vhf_index index, state state, FLOAT64 value) -> void;
		static auto setVHFActiveFrequency(vhf_index index, FLOAT64 value) -> void;
		static auto setVHFStandbyFrequency(vhf_index index, FLOAT64 value) -> void;
		static auto swapVHFFrequencies(vhf_index index) -> void;
		static auto isVHFFrequencyValid(FLOAT64 MHz) -> bool;
		static auto isHz833Compliant(FLOAT64 MHz) -> bool;
		static auto isHz25Compliant(FLOAT64 MHz) -> bool;
		static auto isHz50Compliant(FLOAT64 MHz) -> bool;
	};

	/*
	 * TODO: Move to different namespace
	 */
	class Transponder {
	public:
		static auto isXPDRCompliant(std::string value) -> bool;
		static auto setCode(std::string value) -> void;
		static auto ident() -> void;
	};

	auto smoothPow(double start, double end, double factor, double deltaTime) -> double;
	auto clamp(double value, double lo, double hi) -> double;
	auto fwsColorHandler(double data, double advisoryThreshold, double warningThreshold, NVGcolor defaultColor) -> NVGcolor;
	auto formatToFixed(int data, int decimals) -> std::string;
	auto formatToFixed(double data, int decimals) -> std::string;
	auto formatToFixed(float data, int decimals) -> std::string;
}