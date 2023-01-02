#pragma once
#include <unordered_map>

// Remote Power Distribution Unit
struct RPDU {
	int id;
	double load;
	double voltage;
	double voltageNormal;
	bool isOn;

	auto supplyCurrent() -> void;
};

// Remote Power Distribution System
class RPDSRepository {
protected:

	std::unordered_map<RPDU*, int> rpdu;

public:
	virtual ~RPDSRepository() = default;
	

	virtual auto getTotalLoad(int id) -> double;
	virtual auto getTotalVoltage(int id) -> double;
	virtual bool isOn(int id);
	virtual auto calcuateLoadShed(int id) -> double;

};

