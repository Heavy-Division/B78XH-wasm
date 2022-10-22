// Defines values from the "Principal Characteristics" table from page 9 of B787 syst document

#pragma once

const struct PrincipalCharacteristics {
	// max weights
	inline static double maxTaxiWeightPounds = 537000;
	inline static double maxTakeoffWeightPounds = 535000;
	inline static double maxLandingWeightPounds = 445000;
	inline static double maxZeroFuelWeightPounds = 425200;

	// max thrust, same value for genx or trent
	inline static double maxThrustPounds = 76000;

	// passenger capacity
	inline static int threeClassPassengerCapacity = 295;
	inline static int twoClassPassengerCapacity = 356;
	inline static int economyPassengerCapacity = 440;
};
