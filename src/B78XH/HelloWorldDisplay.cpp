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


#include "HelloWorldDisplay.h"

auto HelloWorldDisplay::prepareApplications() -> void {
	this->addApplication(this->helloWorldApplication);
	this->addApplication(this->helloWorldApplicationGreen);
	this->addApplication(this->helloWorldApplicationAutoCrop);
	this->addApplication(this->helloWorldApplicationCropMargin);
}

auto HelloWorldDisplay::setupApplications() -> void {
	this->helloWorldApplication.setMargin(200.0, 200.0);

	this->helloWorldApplicationGreen.setMargin(200.0, 400.0);
	this->helloWorldApplicationGreen.setColor(Colors::green);

	this->helloWorldApplicationAutoCrop.setMargin(200.0, 600.0);
	this->helloWorldApplicationAutoCrop.setSize(375.0, 60.0);
	this->helloWorldApplicationAutoCrop.setColor(Colors::red);
	this->helloWorldApplicationAutoCrop.setAutoCrop(true);

	this->helloWorldApplicationCropMargin.setMargin(200.0, 800.0);
	this->helloWorldApplicationCropMargin.setSize(375.0, 30.0);
	this->helloWorldApplicationCropMargin.setColor(Colors::blue);
	this->helloWorldApplicationCropMargin.setAutoCrop(true);
	this->helloWorldApplicationCropMargin.setCropMargin(75.0, 30.0);

}
