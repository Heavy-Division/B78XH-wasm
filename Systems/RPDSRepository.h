#pragma once
#include <unordered_map>
#include "RPDUs.h"



// Remote Power Distribution System
class RPDSRepository {
	
protected:

	// Remote Power Distribution Unit
	struct RPDU {

		RPDUs id;
		double load;
		double voltage;
		double voltageNormal;
		bool isOn;

	};

	std::unordered_map<int, RPDU> rpdus;

public:
	virtual ~RPDSRepository() = default;
	
	virtual auto getTotalLoad() -> double;
	virtual auto getTotalVoltage() -> double;
	virtual auto getLoad(int id) -> double;
	virtual auto getVoltage(int id) -> double;
	virtual auto isOn(int id) -> bool;
	virtual auto calculateLoadShed(int id) -> double;
	virtual auto supplyCurrent() -> void;

};

