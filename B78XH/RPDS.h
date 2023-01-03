#pragma once

#include "Systems/RPDSRepository.h"

class RPDS : public RPDSRepository {

public:

	RPDS() {
		rpdus.emplace(1, RPDU{ RPDU_21_DOOR_2L, 500.0, 220.0, 240.0, true  });
		rpdus.emplace(2, RPDU{ RPDU_22_DOOR_2R, 600.0, 210.0, 240.0, false });
		rpdus.emplace(3, RPDU{ RPDU_42_DOOR_4R, 400.0, 230.0, 240.0, true  });
	}

	~RPDS() = default;

	auto getTotalLoad() -> double override;
	auto getTotalVoltage() -> double override;
	auto getLoad(int id) -> double override;
	auto getVoltage(int id) -> double override;
	auto isOn(int id) -> bool override;
	auto calculateLoadShed(int id) -> double override;
	auto supplyCurrent() -> void override;
};
