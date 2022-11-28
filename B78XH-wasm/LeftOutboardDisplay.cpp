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


#include "LeftOutboardDisplay.h"

auto LeftOutboardDisplay::prepareApplications() -> void {
	this->addApplication(this->pfdAttitudeApplication);
	this->addApplication(this->pfdVerticalSpeedIndicatorApplication);
	this->addApplication(this->pfdAirspeedIndicatorApplication);
	this->addApplication(this->pfdAltitudeIndicatorApplication);
	this->addApplication(this->pfdFMAApplication);
	this->addApplication(this->pfdTargetAirspeedApplication);
	this->addApplication(this->pfdTargetAltitudeApplication);
	this->addApplication(this->pfdRadioAltitudeIndicatorApplication);
	this->addApplication(this->pfdBaroIndicatorApplication);
	this->addApplication(this->pfdFlightDirectorApplication);
	this->addApplication(this->pfdILSIndicatorApplication);
	this->addApplication(this->pfdMinimumIndicatorApplication);
	this->addApplication(this->pfdAuxApplication);
}

auto LeftOutboardDisplay::setupApplications() -> void {
	this->pfdAttitudeApplication.setMargin(425, 0);
	this->pfdAttitudeApplication.setSize(855, 622);
	this->pfdVerticalSpeedIndicatorApplication.setMargin(425 + 735, (622 / 2) - (161));
	this->pfdVerticalSpeedIndicatorApplication.setSize(54, 322);

	this->pfdAirspeedIndicatorApplication.setMargin(425 + 155, (622 / 2 - 465 / 2));
	this->pfdAirspeedIndicatorApplication.setSize(80, 465);


	this->pfdAltitudeIndicatorApplication.setMargin(425 + 635, (622 / 2 - 465 / 2));
	this->pfdAltitudeIndicatorApplication.setSize(80, 465);

	this->pfdFMAApplication.setMargin(425 + 855/2 - 376/2, 5);
	this->pfdFMAApplication.setSize(376, 42);


	this->pfdTargetAirspeedApplication.setMargin(425 + 157, 30);
	this->pfdTargetAirspeedApplication.setSize(78, 38);

	this->pfdTargetAltitudeApplication.setMargin(425 + 635, 30);
	this->pfdTargetAltitudeApplication.setSize(80, 38);

	this->pfdRadioAltitudeIndicatorApplication.setMargin(425 + (855 / 2) - 50, 520);
	this->pfdRadioAltitudeIndicatorApplication.setSize(100, 40);

	this->pfdBaroIndicatorApplication.setMargin(425 + 635, 570);
	this->pfdBaroIndicatorApplication.setSize(100, 40);

	this->pfdFlightDirectorApplication.setMargin(425 + 855 / 2, 622 / 2);
	this->pfdFlightDirectorApplication.setSize(0,0);

	this->pfdILSIndicatorApplication.setMargin(425 + 855 / 2, 622 / 2);
	this->pfdILSIndicatorApplication.setSize(0, 0);

	this->pfdMinimumIndicatorApplication.setMargin(425 + 556, 520);
	this->pfdMinimumIndicatorApplication.setSize(0, 0);

	this->pfdAuxApplication.setMargin(0, 0);
	this->pfdAuxApplication.setSize(425, 950);
}
