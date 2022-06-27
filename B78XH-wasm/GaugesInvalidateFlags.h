#pragma once
inline struct GaugesInvalidateFlags {
	bool MCPAltitudeGauge = true;
	bool MCPVSpeedGauge = true;
	bool PEDESTALTuningControlGauge [3] = {true, true, true};
} GaugesInvalidateFlags;