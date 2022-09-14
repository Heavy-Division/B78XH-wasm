//    B78XH-wasm
//    Copyright (C) 2022  Heavy Division
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.


#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "fmt/core.h"

using namespace std;

class Waypoint {
	public:
		Waypoint(int id, const std::string& ident, double lat, double lon)
			: id(id), ident(ident),
			  lat(lat),
			  lon(lon) {
		}

		int id;
		std::string ident;
		double lat;
		double lon;
};

namespace NavData {
	std::unordered_map<std::string, std::vector<Waypoint>> waypoints;

	auto prepareWaypoints() -> void {
		// Should use fopen_s
		//FILE* file;
		//fopen_s(&file, "C:\\Users\\etch\\source\\repos\\BGLConvertor\\x64\\Debug\\main_waypoint.csv", "r");
		FILE* file = fopen("./data/main_waypoint.csv", "r");

		if (file != nullptr) {
			std::unordered_map<std::string, std::vector<Waypoint>>& reference = NavData::waypoints;
			int one;
			double two;
			double three;
			char four[6];
			std::string ident;
			while (fscanf(file, "%d,%lf,%lf,%s", &one, &two, &three, &four, 6) == 4) {
				ident = four;
				const auto check = reference.find(ident);
				if (check != reference.end()) {
					check->second.push_back(Waypoint(one, ident, two, three));
				}
				else {
					vector<Waypoint> vector;
					vector.push_back(Waypoint(one, ident, two, three));
					reference.emplace(std::make_pair(ident, vector));
				}
			}
		} else {
			fmt::print(stderr, "FILE NOT FOUND");
		}
	}
}
