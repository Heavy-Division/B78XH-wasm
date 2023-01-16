#pragma once

#include <string>
#include <unordered_map>
#include <list>

#include "RouteReference.h"
#include "FacilityDataStructs.h"

using std::string;
using icao = std::string;

class Airport {
	public:
		explicit Airport(std::string icao)
			: icao(icao),
			  name(""),
			  latitude(0),
			  longitude(0),
			  altitude(0) {
		}

		explicit Airport(std::string icao, std::string name, const double latitude, const double longitude, const double altitude)
			: icao(icao),
			  name(name),
			  latitude(latitude),
			  longitude(longitude),
			  altitude(altitude) {
		}

		auto update(AirportStruct airportStruct) -> void {
			name = airportStruct.name;
			latitude = airportStruct.latitude;
			longitude = airportStruct.longitude;
			altitude = airportStruct.altitude;
		}

		[[nodiscard]] auto getIcao() const -> const std::string&;
		[[nodiscard]] auto getName() const -> const std::string&;
		[[nodiscard]] auto getLatitude() const -> double;
		[[nodiscard]] auto getLongitude() const -> double;
		[[nodiscard]] auto getAltitude() const -> double;

	private:
		std::string icao;
		std::string name;
		double latitude;
		double longitude;
		double altitude;
};

class Waypoint {
	public:
		Waypoint(const string& icao, const string& region, const double latitude, const double longitude, const double altitude)
			: icao(icao),
			  region(region),
			  latitude(latitude),
			  longitude(longitude),
			  altitude(altitude) {
		}

		[[nodiscard]] auto getIcao() const -> const icao&;
		[[nodiscard]] auto getRegion() const -> const string&;
		[[nodiscard]] auto getLatitude() const -> double;
		[[nodiscard]] auto getLongitude() const -> double;
		[[nodiscard]] auto getAltitude() const -> double;

	private:
		icao icao;
		string region;
		double latitude;
		double longitude;
		double altitude;
};

inline auto Airport::getIcao() const -> const std::string& {
	return icao;
}

inline auto Airport::getName() const -> const std::string& {
	return name;
}

inline auto Airport::getLatitude() const -> double {
	return latitude;
}

inline auto Airport::getLongitude() const -> double {
	return longitude;
}

inline auto Airport::getAltitude() const -> double {
	return altitude;
}

inline auto Waypoint::getIcao() const -> const ::icao& {
	return icao;
}

inline auto Waypoint::getRegion() const -> const string& {
	return region;
}

inline auto Waypoint::getLatitude() const -> double {
	return latitude;
}

inline auto Waypoint::getLongitude() const -> double {
	return longitude;
}

inline auto Waypoint::getAltitude() const -> double {
	return altitude;
}

namespace NavDataCache {
	inline std::unordered_map<icao, std::unique_ptr<Airport>> airports{};
	/*
	 * !!!!!!!!!!!!!!!!!!!!!!!Only for testing purpose!!!!!!!!!!!!!!!!!!!!!!!
	 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!Read below!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	 *
	 *
	 * TODO: This is not proper definition -> waypoints/fixes icaos are not unique. So the fixes should use some custom holder:
	 * TODO: ( std::unordered_map<icao, std::vector<Waypoint>> ) with custom handling (getters/setters)
	 */
	inline std::unordered_map<icao, Waypoint> waypoints{};

	inline std::unordered_map<string, std::list<RouteWaypoint>> routes;

	inline std::unordered_map<string, RouteReference> routesPreloadQueue;
	inline std::unordered_map<string, string> airportsPreloadQueue;
}
