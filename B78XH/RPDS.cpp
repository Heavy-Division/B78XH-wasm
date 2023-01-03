#include "RPDS.h"



auto RPDS::getTotalLoad() -> double {
	double load = 0;
	for (int i = 0; i < rpdus.size(); i++) {
		load += rpdus[i].load;
	}

	return load;
}

auto RPDS::getTotalVoltage() -> double {
	double voltage = 0;
	for (int i = 0; i < rpdus.size(); i++) {
		voltage += rpdus[i].voltage;
	}

	return voltage;
}

auto RPDS::getLoad(int id) -> double {
	return rpdus[id].load;
}

auto RPDS::getVoltage(int id) -> double {
	return rpdus[id].voltage;
}

auto RPDS::isOn(int id) -> bool {
	return rpdus[id].isOn;
}

auto RPDS::calculateLoadShed(int id) -> double {
	return 0.;
}

auto RPDS::supplyCurrent() -> void {
	nullptr;
}
