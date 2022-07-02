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

std::vector<CDULeftLine> CDUIdentPage::getLeftLines() {
	std::vector<CDULeftLine> lines;
	lines.push_back(CDULeftLine(CDULineNumber::ONE, "787-10"));
	lines.push_back(CDULeftLine(CDULineNumber::TWO, "AIRAC"));
	lines.push_back(CDULeftLine(CDULineNumber::FIVE, "HD-P000-1-16-1"));
	lines.push_back(CDULeftLine(CDULineNumber::SIX, "HD-C000-1-16-1"));
	return lines;
}

std::vector<CDUCenterLine> CDUIdentPage::getCenterLines() {
	std::vector<CDUCenterLine> lines;
	return lines;

}

std::vector<CDURightLine> CDUIdentPage::getRightLines() {
	std::vector<CDURightLine> lines;
	//lines.push_back(CDURightLine(CDULineNumber::ONE, "GENX-1B76"));
	//lines.push_back(CDURightLine(CDULineNumber::TWO, "APR21MAY18/22"));
	//lines.push_back(CDURightLine(CDULineNumber::FIVE, "VS1001"));
	return lines;
}