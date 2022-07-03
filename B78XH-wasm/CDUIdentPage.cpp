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
#include "CDURightTitleLine.h"

std::vector<CDULine> CDUIdentPage::getLines() {
	std::vector<CDULine> lines = {};
	/*
	 * LEFT SIDE
	 */
	lines.push_back(CDULeftTitleLine(this->context, CDULineNumber::ONE, "MODEL"));
	lines.push_back(CDULeftLine(this->context, CDULineNumber::ONE, "787-10"));

	lines.push_back(CDULeftTitleLine(this->context, CDULineNumber::TWO, "NAV DATA"));
	lines.push_back(CDULeftLine(this->context, CDULineNumber::TWO, "AIRAC"));

	lines.push_back(CDULeftTitleLine(this->context, CDULineNumber::THREE, "DRAG/FF"));

	lines.push_back(CDULeftTitleLine(this->context, CDULineNumber::FOUR, "OP PROGRAM"));
	lines.push_back(CDULeftLine(this->context, CDULineNumber::FOUR, "HD-P000-1-16-1"));

	lines.push_back(CDULeftTitleLine(this->context, CDULineNumber::FIVE, "OPC"));
	lines.push_back(CDULeftLine(this->context, CDULineNumber::FIVE, "HD-C000-1-16-1"));

	/*
	 * RIGHT SIDE
	 */
	lines.push_back(CDURightTitleLine(this->context, CDULineNumber::ONE, "ENGINES"));
	lines.push_back(CDURightLine(this->context, CDULineNumber::ONE, "GENX-1B76"));

	lines.push_back(CDURightTitleLine(this->context, CDULineNumber::TWO, "ACTIVE"));
	lines.push_back(CDURightLine(this->context, CDULineNumber::TWO, "APR21MAY18/22"));


	lines.push_back(CDURightTitleLine(this->context, CDULineNumber::FOUR, "CO DATA"));
	lines.push_back(CDURightLine(this->context, CDULineNumber::FOUR, "VS1001"));



	return lines;
}
