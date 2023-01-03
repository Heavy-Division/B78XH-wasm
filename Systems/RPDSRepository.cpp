#include "RPDSRepository.h"

auto RPDSRepository::getTotalLoad() -> double {
	double load = 0;
	for (int i = 0; i < rpdus.size(); i++) {
		load += rpdus[i].load;
	}

	return load;

}

auto RPDSRepository::getTotalVoltage() -> double {
	double voltage = 0;
	for (int i = 0; i < rpdus.size(); i++) {
		voltage += rpdus[i].voltage;
	}

	return voltage;
}

auto RPDSRepository::getLoad(int id) -> double {
	return rpdus[id].load;
}

auto RPDSRepository::getVoltage(int id) -> double {
	return rpdus[id].voltage;
}
auto RPDSRepository::isOn(int id) -> bool {
	return rpdus[id].isOn;
}

auto RPDSRepository::calculateLoadShed(int id) -> double {
	return 0.;
}

auto RPDSRepository::supplyCurrent() -> void {
	nullptr;
}
