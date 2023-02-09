#pragma once
#include "SimConnectAirportPreloader.h"
#include "SimConnectRoutePreloader.h"

class FacilityLoader {
	public:

	private:
		static inline std::unique_ptr<SimConnectAirportPreloader> airportPreloader = std::make_unique<SimConnectAirportPreloader>();
		static inline std::unique_ptr<SimConnectRoutePreloader> routePreloader = std::make_unique<SimConnectRoutePreloader>();
};

inline FacilityLoader facilityLoader;