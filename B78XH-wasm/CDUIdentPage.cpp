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


#include "CDUIdentPage.h"

#include "CDUCenterTitleLine.h"
#include "CDULeftTitleLine.h"
#include "CDURightLine.h"
#include "CDULeftLine.h"
#include "CDURightTitleLine.h"
#include "fmt/core.h"

std::vector<CDULine>& CDUIdentPage::getLines() {
	this->lines.clear();
	/*
	this->lsk1Event = []() {
		fmt::print(stderr, "LSK1 EVENT");
	};

	this->lsk2Event = []() {
		fmt::print(stderr, "LSK2 EVENT");
	};

	this->rsk1Event = []() {
		fmt::print(stderr, "RSK1 EVENT");
	};
	*/
	/*
	 * LEFT SIDE
	 */
	this->lines.push_back(CDULeftTitleLine(this->context, CDULineNumber::ONE, { {"MODEL", ""} }));
	this->lines.push_back(CDULeftLine(this->context, CDULineNumber::ONE, { {"787-10", ""} }));

	this->lines.push_back(CDULeftTitleLine(this->context, CDULineNumber::TWO, { {"NAV DATA", ""} }));
	this->lines.push_back(CDULeftLine(this->context, CDULineNumber::TWO, { {"AIRAC", ""} }));

	this->lines.push_back(CDULeftTitleLine(this->context, CDULineNumber::THREE, { {"DRAG/FF", ""} }));

	this->lines.push_back(CDULeftTitleLine(this->context, CDULineNumber::FOUR, { {"OP PROGRAM", ""} }));
	this->lines.push_back(CDULeftLine(this->context, CDULineNumber::FOUR, { {"HD-P000-1-16-1", ""} }));

	this->lines.push_back(CDULeftTitleLine(this->context, CDULineNumber::FIVE, { {"OPC", ""} }));
	this->lines.push_back(CDULeftLine(this->context, CDULineNumber::FIVE, { {"HD-C000-1-16-1", ""} }));

	/*
	 * RIGHT SIDE
	 */
	this->lines.push_back(CDURightTitleLine(this->context, CDULineNumber::ONE, { {"ENGINES", ""} }));
	this->lines.push_back(CDURightLine(this->context, CDULineNumber::ONE, { {"GENX-1B76", ""} }));

	this->lines.push_back(CDURightTitleLine(this->context, CDULineNumber::TWO, { {"ACTIVE", ""} }));
	this->lines.push_back(CDURightLine(this->context, CDULineNumber::TWO, { {"APR21MAY18/22", ""} }));


	this->lines.push_back(CDURightTitleLine(this->context, CDULineNumber::FOUR, { {"CO DATA", ""} }));
	this->lines.push_back(CDURightLine(this->context, CDULineNumber::FOUR, { {"VS1001", ""} }));
	return this->lines;
}
