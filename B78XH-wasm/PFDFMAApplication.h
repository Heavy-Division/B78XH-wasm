#pragma once
#include "Application.h"

class PFDFMAApplication : public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;

	private:
		struct ThrottleMode {
			static constexpr auto HOLD = "HOLD";
			static constexpr auto IDLE = "IDLE";
			static constexpr auto SPD = "SPD";
			static constexpr auto THR = "THR";
			static constexpr auto THR_REF = "THR REF";
			static constexpr auto NONE = "";
		};

		struct PitchMode {
			static constexpr auto ALT = "ALT";
			static constexpr auto FLARE = "FLARE";
			static constexpr auto FLCH_SPD = "FLCH SPD";
			static constexpr auto FPA = "FPA";
			static constexpr auto GS = "G/S";
			static constexpr auto GP = "G/P";
			static constexpr auto TOGA = "TO/GA";
			static constexpr auto VNAV_PTH = "VNAV PTH";
			static constexpr auto VNAV_SPD = "VNAV SPD";
			static constexpr auto VNAV_ALT = "VNAV ALT";
			static constexpr auto VNAV = "VNAV";
			static constexpr auto VS = "V/S";
			static constexpr auto NONE = "";
		};

		struct RollMode {
			static constexpr auto B_CRS = "B/CRS";
			static constexpr auto FAC = "FAC";
			static constexpr auto HDG_HOLD = "HDG HOLD";
			static constexpr auto HDG_SEL = "HDG SEL";
			static constexpr auto HUD_TOGA = "HUD TO/GA";
			static constexpr auto LNAV = "LNAV";
			static constexpr auto LOC = "LOC";
			static constexpr auto ROLLOUT = "ROLLOUT";
			static constexpr auto TOGA = "TO/GA";
			static constexpr auto TRK_SEL = "TRK SEL";
			static constexpr auto TRK_HOLD = "TRK HOLD";
			static constexpr auto ATT = "ATT";
			static constexpr auto NONE = "";
		};

		void drawBackground();
		void drawTexts();
		const char* resolveActiveThrustMode();
		const char* resolveActiveRollMode();
		const char* resolveArmedRollMode();
		const char* resolveActivePitchMode();
		const char* resolveArmedPitchMode();
};
