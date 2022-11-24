#pragma once
#include "Display.h"
#include "PFDAirspeedIndicatorApplication.h"
#include "PFDAttitudeApplication.h"
#include "PFDVerticalSpeedIndicatorApplication.h"
#include "PFDFMAApplication.h"
#include "PFDAltitudeIndicatorApplication.h"
#include "PFDTargetAirspeedApplication.h"
#include "PFDTargetAltitudeApplication.h"
#include "PFDRadioAltitudeIndicatorApplication.h"
#include "PFDBaroIndicatorApplication.h"
#include "PFDFlightDirectorApplication.h"
#include "PFDILSIndicatorApplication.h"
#include "PFDMinimumIndicatorApplication.h"
#include "PFDAuxApplication.h"

class PFDDisplay : public Display {
	protected:
		auto prepareApplications() -> void override;
		auto setupApplications() -> void override;
	private:
		PFDAttitudeApplication pfdAttitudeApplication;
		PFDVerticalSpeedIndicatorApplication pfdVerticalSpeedIndicatorApplication;
		PFDAirspeedIndicatorApplication pfdAirspeedIndicatorApplication;
		PFDFMAApplication pfdFMAApplication;
		PFDAltitudeIndicatorApplication pfdAltitudeIndicatorApplication;
		PFDTargetAirspeedApplication pfdTargetAirspeedApplication;
		PFDTargetAltitudeApplication pfdTargetAltitudeApplication;
		PFDRadioAltitudeIndicatorApplication pfdRadioAltitudeIndicatorApplication;
		PFDBaroIndicatorApplication pfdBaroIndicatorApplication;
		PFDFlightDirectorApplication pfdFlightDirectorApplication;
		PFDILSIndicatorApplication pfdILSIndicatorApplication;
		PFDMinimumIndicatorApplication pfdMinimumIndicatorApplication;
		PFDAuxApplication pfdAuxApplication;
};
