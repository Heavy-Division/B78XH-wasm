#include "MFDNDControl.h"

#include "Simplane.h"
#include "Tools/Console.h"

#include <cmath>

auto MFDNDControl::render() -> void {
	Control::render();
	if (mapViewTextureId >= 0) {
		auto mapViewPaint = nvgImagePattern(getContext(), (648 / 2), (998 / 2), 2048, 2048, 0.0f, mapViewTextureId, 1.0f);

			nvgSave(getContext());
			{
				/*
				 * Move the map to center of display ( 648 = 2048 - 1400, 998 = 2048 - 1050) 
				 */
				/*
				 * Centered version (Plan/Centered)
				 */
				//nvgTranslate(getContext(), -(648 / 2), -(998 / 2));
				/*
				 * Follow mod (Map)
				 */


				/*
				 * 10% = 105 pixels
				 * 20% = 210 pixels
				 * 50% = 525 pixels
				 * 998/2 = texture offset
				 * -(998/2) + 50% = center on bottom of display
				 * follow offset
				 * -(998/2) + (50% - 20%);
				 * -(998/2) + (525 - 210);
				 */
				//nvgTranslate(getContext(), -(648 / 2), -(998 / 2) + (525 - 210));

				nvgTranslate(getContext(), 2048 / 2, 2048 / 2);
				double trueHeading = Simplane::aircraft::state::headingTrue();
				const float fixedHeading = 360 - fmod(trueHeading, 360);
				nvgRotate(getContext(), fixedHeading * NVG_PI / 180);

				nvgTranslate(getContext(), -(2048 / 2), -(2048 / 2));

				nvgBeginPath(getContext());
				{
					nvgRect(getContext(), 0, 0, 2048, 2048);
					nvgFillPaint(getContext(), mapViewPaint);
					nvgFill(getContext());
				}
				nvgClosePath(getContext());
			}
			nvgRestore(getContext());

		this->calculateCoordinates();


		const auto ndTranslateX = (1000 / 2) - 500;
		const auto ndTranslateY = (1000 / 2) - 500;


		/*
		 * This is center point
		 */

		nvgFillColor(getContext(), nvgRGB(0, 0, 255));
		nvgSave(getContext());
		{
			nvgTranslate(getContext(), ndTranslateX, ndTranslateY);
			{
				nvgBeginPath(getContext());
				{
					nvgRect(getContext(), 700 - 5, 525 - 5, 10, 10);
				}
				nvgFill(getContext());
			}
			nvgResetTransform(getContext());
		}
		nvgRestore(getContext());


		std::vector<double> endOfRunway = this->latLongToXY(this->endOfRW24Lat, this->endOfRW24Long);
		Console::error("PixelX: {}, PixelY: {}", endOfRunway.at(0), endOfRunway.at(1));
		//fmt::print(stderr, "X: {}", pr.at(0));
		//fmt::print(stderr, "Y: {}", pr.at(1));

		nvgFillColor(getContext(), nvgRGB(0, 255, 255));

		nvgSave(getContext());
		{
			nvgTranslate(getContext(), ndTranslateX, ndTranslateY);
			{
				nvgBeginPath(getContext());
				{
					nvgRect(getContext(), endOfRunway.at(0), endOfRunway.at(1), 10, 10);
				}
				nvgFill(getContext());
			}
			nvgResetTransform(getContext());
		}
		nvgRestore(getContext());


		std::vector<double> pr = this->latLongToXY(this->pr402Lat, this->pr402Long);

		//fmt::print(stderr, "X: {}", pr.at(0));
		//fmt::print(stderr, "Y: {}", pr.at(1));

		nvgFillColor(getContext(), nvgRGB(0, 255, 0));

		nvgSave(getContext());
		{
			nvgTranslate(getContext(), ndTranslateX, ndTranslateY);
			{
				nvgBeginPath(getContext());
				{
					nvgRect(getContext(), pr.at(0), pr.at(1), 10, 10);
				}
				nvgFill(getContext());
			}
			nvgResetTransform(getContext());
		}
		nvgRestore(getContext());

		std::vector<double> pr2 = this->latLongToXY(this->pr405Lat, this->pr405Long);

		//fmt::print(stderr, "X: {}", pr.at(0));
		//fmt::print(stderr, "Y: {}", pr.at(1));

		nvgFillColor(getContext(), nvgRGB(0, 255, 0));

		nvgSave(getContext());
		{
			nvgTranslate(getContext(), ndTranslateX, ndTranslateY);
			{
				nvgBeginPath(getContext());
				{
					nvgRect(getContext(), pr2.at(0), pr2.at(1), 10, 10);
				}
				nvgFill(getContext());
			}
			nvgResetTransform(getContext());
		}
		nvgRestore(getContext());
	}
}

auto MFDNDControl::setupControl() -> void {
	Control::setupControl();
	if (mapViewTextureId == -1) {
		FsContext ctx = nvgInternalParams(getContext())->userPtr;
		mapViewTextureId = fsMapViewCreate(ctx, 2048, 2048, 0);

		if (mapViewTextureId == -1) {
			return;
		}

		//const float range = (nmWidth * 1852) * sqrt(2);
		//const float range = (nmWidth * 1852) * sqrt(2);
		const float range = (nmWidth * 1852) / 2;

		Console::error("RANGE RADIUS: {}", range);


		fsMapViewSetVisibility(ctx, mapViewTextureId, true);
		fsMapViewSetViewMode(ctx, mapViewTextureId, FS_MAP_VIEW_MODE_ALTITUDE);
		fsMapViewSet3D(ctx, mapViewTextureId, false);
		fsMapViewSet2DViewFollowMode(ctx, mapViewTextureId, true);
		fsMapViewSetBackgroundColor(ctx, mapViewTextureId, {0.f, 0.0f, 0.0f, 1.f});
		fsMapViewSet2DViewRadiusInMeters(ctx, mapViewTextureId, range);
		fsMapViewSetWeatherRadarVisibility(ctx, mapViewTextureId, false);
		fsMapViewSetWeatherRadarMode(ctx, mapViewTextureId, FS_MAP_VIEW_WEATHER_RADAR_MODE_TOPVIEW);
		fsMapViewSetAltitudeRangeInFeet(ctx, mapViewTextureId, 5000, 15000);


		const int size = 22;
		/*
		FsRainRateColor colors[size] =

		{

			{{1.f, 0.7f, 0.25f, 0.33f}, 0.2f},
			{{.10f, 0.7f, .25525f, 0.33f}, 1.f},
			{{.20f, .307f, .6025f, 0.33f}, 5.f},
			{{.30f, .497f, .11125f, 0.33f}, 10.f},
			{{.40f, .107f, .9525f, 0.33f}, 15.f},
			{{.50f, .2457f, .3525f, 0.33f}, 20.f},
			{{.60f, .257f, .24925f, 0.33f}, 25.f},
			{{.70f, .1177f, .16825f, 0.33f}, 30.f},
			{{.80f, .1927f, .5625f, 0.33f}, 35.f},
			{{.90f, .677f, .8025f, 0.32f}, 40.f},
			{{.100f, .1487f, .15025f, 0.32f}, 45.f},
			{{.1108f, .803f, .2387f, 0.62f}, 50.f},
			{{.1208f, .103f, .497f, 0.62f}, 55.f},
			{{.1308f, .2333f, .77f, 0.62f}, 60.f},
			{{.1408f, .1863f, .1527f, 0.62f}, 65.f},
			{{.1508f, .253f, .1237f, 0.62f}, 70.f},
			{{.1608f, .713f, .807f, 0.62f}, 75.f},
			{{.1708f, .903f, .1917f, 0.62f}, 80.f},
			{{.1808f, .803f, .2517f, 0.62f}, 85.f},
			{{.1908f, .353f, .507f, 0.62f}, 90.f},
			{{.2008f, .503f, .907f, 0.62f}, 95.f},
			{{.255f, .1539f, .1f, 1.f}, 100.f}

		};

		*/
		//fsMapViewSetWeatherRadarRainColors(ctx, mapViewTextureId, colors, size);
	}


	//mapViewParams.needUpdate = true;

	addOnBeforeRender([this](BaseControl& control) -> bool {
		if (mapViewTextureId == -1) {
			return false;
		}
		centerLat = Simplane::aircraft::state::latitude();
		centerLong = Simplane::aircraft::state::longitude();
		this->calculateCoordinates();
		return true;
	});
}


auto MFDNDControl::latLongToXY(double lat, double lon) -> std::vector<double> {
	std::vector<double> vector = {};
	if (this->centerLong > 90) {
		if (lon < -90) {
			lon += 360;
		}
	}

	if (this->centerLong < -90) {
		if (lon > 90) {
			lon -= 360;
		}
	}
	/*
	double x = (lon - this->centerLong) / this->angularWidthNorth * 1000;
	double y = -((lat - this->centerLat) / this->angularWidthSouth) * 1000;
	*/
	/*
	 * FIXED NORTH Implementation
	 */
	/*
   vector.push_back(x + 500);
   vector.push_back(y + 500);
   */
	/*
	 * PLANE HEADING UP IMPLEMENTATION
	 */
	/*
  vector.push_back(x * this->cosPlaneDirection - y * this->sinPlaneDirection + 500);
  vector.push_back(x * this->sinPlaneDirection + y * this->cosPlaneDirection + 500);
  return vector;
  */

	/* This is final implementation (testing version)*/
	/*
	const double xNorth = (lon - this->centerLong) / this->angularWidthNorth * 1000;
	const double xSouth = (lon - this->centerLong) / this->angularWidthSouth * 1000;
	const double delta = (lat - this->centerLat) / this->angularHeight;
	const double delta2 = delta + 0.5;

	//const double x = xNorth * delta + xSouth * (1 - delta);
	//const double y = -delta * 1000;

	vector.push_back(x * this->cosPlaneDirection - y * this->sinPlaneDirection + 500);
	vector.push_back(x * this->sinPlaneDirection + y * this->cosPlaneDirection + 500);
	*/


	/*
	 * Final implementation
	 */

	const double x = (lon - centerLong) / angularWidth * 1000;
	const double y = -((lat - centerLat) / angularHeight) * 1000;

	//vector.push_back(x * cosPlaneDirection - y * sinPlaneDirection + 500);
	//vector.push_back(x * sinPlaneDirection + y * cosPlaneDirection + 500);

	vector.push_back(x + 500);
	vector.push_back(y + 500);

	return vector;
}

auto MFDNDControl::calculateCoordinates() -> void {
	this->ftWidth = 6076.11549 * this->nmWidth;
	this->angularWidth = this->nmWidth / 60.0 / std::cos(nvgDegToRad(this->centerLat));
	this->angularHeight = this->nmWidth / 60.0;
	this->bottomLeftLat = this->centerLat - this->angularHeight * 0.5;
	this->bottomLeftLong = this->centerLong - this->angularHeight * 0.5;

	this->topRightLat = this->centerLat + this->angularHeight * 0.5;
	this->topRightLong = this->centerLong + this->angularHeight * 0.5;

	this->angularWidthNorth = this->nmWidth / 60.0 / std::cos(nvgDegToRad(this->topRightLat));
	this->angularWidthSouth = this->nmWidth / 60.0 / std::cos(nvgDegToRad(this->bottomLeftLat));

	double trueHeading = Simplane::aircraft::state::headingTrue();
	const float fixedHeading = 360 - fmod(trueHeading, 360);

	this->cosPlaneDirection = std::cos(nvgDegToRad(fixedHeading));
	this->sinPlaneDirection = std::sin(nvgDegToRad(fixedHeading));

	Console::log("Center LAT: {}; LONG {};", centerLat, centerLong);
	Console::log("Coordinates calculated Corner LAT: {}; LONG {};", bottomLeftLat, bottomLeftLong);
}
