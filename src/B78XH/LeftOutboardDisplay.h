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

class LeftOutboardDisplay : public Display {
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
