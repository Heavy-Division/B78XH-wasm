#pragma once

#include <string>

using std::string;

class RouteReference {
	public:
		RouteReference(const string& referenceWaypoint, const string& region, const char& type, const string& routeName, const bool preloaded)
			: referenceWaypoint(referenceWaypoint),
			  region(region),
			  type(type),
			  routeName(routeName),
			  preloaded(preloaded) {
		}

		[[nodiscard]] auto getReferenceWaypoint() const -> const string&;
		[[nodiscard]] auto getRegion() const -> const string&;
		[[nodiscard]] auto getType() const -> const char&;
		[[nodiscard]] auto getRouteName() const -> const string&;
		[[nodiscard]] auto isPreloaded() const -> bool;

		auto setPreloaded(const bool preloaded) -> void;

	private:
		string referenceWaypoint;
		string region;
		char type;
		string routeName;
		bool preloaded = false;
};
