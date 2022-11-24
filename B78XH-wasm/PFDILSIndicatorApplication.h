#pragma once
#include "Application.h"
#include "NavBeacon.h"
#include "SimEnums.h"

class PFDILSIndicatorApplication : public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;

	private:
		NavBeacon beacon = NavBeacon(NavEquipmentType::UNKNOWN, NavEquipmentIndex::UNKNOWN);
		bool isApproachLoaded = false;
		bool tested = false;
		SimApproachType approachType = SimApproachType::APPROACH_TYPE_UNKNOWN;
		void drawLocalizerIndicator();
		void drawGlideSlopeIndicator();
		void drawlocalizerCursor();
		void drawGlideSlopeCursor();
		void drawInfo();
};
