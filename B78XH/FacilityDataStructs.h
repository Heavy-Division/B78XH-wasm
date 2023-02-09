#pragma once


struct AirportStruct {
	double latitude;
	double longitude;
	double altitude;
	char name[32];
	int numberOfRunways;
};

struct RunwayStruct {
	double latitude;
	double longitude;
	double altitude;
	float heading;
	float length;
	float width;
	int primaryNumber;
	int secondaryNumber;
};

struct WaypointStruct {
	double latitude;
	double longitude;
	double altitude;
	int numberOFRoutes;
	char icao[8];
	char region[8];
};

struct WaypointMinimal {
	char icao[8];
	char region[8];
};

struct RouteStruct {
	char name[32];
	char nextIcao[8];
	char previousIcao[8];
	char nextRegion[8];
	char previousRegion[8];
	int nextType;
	int previousType;
};

struct RouteWaypoint {
	std::string icao;
	std::string region;
	char type;
};