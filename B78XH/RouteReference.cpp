#include "RouteReference.h"

auto RouteReference::getReferenceWaypoint() const -> const string& {
	return referenceWaypoint;
}

auto RouteReference::getRegion() const -> const string& {
	return region;
}

auto RouteReference::getType() const -> const char& {
	return type;
}

auto RouteReference::getRouteName() const -> const string& {
	return routeName;
}

auto RouteReference::isPreloaded() const -> bool {
	return preloaded;
}

auto RouteReference::setPreloaded(const bool preloaded) -> void {
	this->preloaded = preloaded;
}
