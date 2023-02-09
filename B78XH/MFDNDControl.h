#pragma once

#include <MSFS/MSFS_MapView.h>
#include "MFDBaseControl.h"
#include "Tools/Console.h"

class MFDNDControl : public MFDBaseControl {
	public:
		explicit MFDNDControl(const string& name)
			: MFDBaseControl(name) {
		}

		auto render() -> void override;

	protected:
		auto setupControl() -> void override;
		auto calculateCoordinates() -> void;
		auto latLongToXY(double lat, double lon) -> std::vector<double>;

	private:
		int mapViewTextureId = -1;

		static struct {
			FsMapViewMode viewMode = FS_MAP_VIEW_MODE_AERIAL;
			FsMapViewAltitudeReference altitudeReference = FS_MAP_VIEW_ALTITUDE_REFERENCE_GEOID;
			bool followPlane = true;
			bool showIsoLines = false;
			bool needUpdate = false;
			unsigned counter = 0;
		} mapViewParams;

		/*
		 * HardCoded LKPR RW 24
		 */

		double centerLat = 50.115175;
		double centerLong = 14.270752;

		/*
		 * HardCoded LKPR end of runway
		 */

		double endOfRW24Lat = 50.1018058;
		double endOfRW24Long = 14.2261339;

		/*
		 * HardCoded PR402 from BALTU4A
		 */

		double pr402Lat = 50.038278;
		double pr402Long = 14.015472;

		/*
		 * HardCoded PR405 from BALTU4A
		 */

		double pr405Lat = 50.199389;
		double pr405Long = 13.842194;


		/*
		 * FOR TEST
		 */

		double ratio = 1;
		double nmWidth = 1;
		double ftWidth = 0;
		double angularHeight = 0;
		double angularWidth = 0;
		double angularWidthNorth = 0;
		double angularWidthSouth = 0;
		double topRightLat = 0;
		double topRightLong = 0;
		double bottomLeftLat = 0;
		double bottomLeftLong = 0;

		double cosPlaneDirection = 0;
		double sinPlaneDirection = 0;
};

