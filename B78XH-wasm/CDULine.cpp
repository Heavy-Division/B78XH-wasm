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


#include "CDULine.h"

CDULine::CDULine(CDULineNumber lineNumber, std::vector<std::vector<std::string>> content) : lineNumber(lineNumber) {
	this->setContent(content);
	this->type = CDULineType::COMPLEX;
}

CDULine::CDULine(CDULineNumber lineNumber, std::string content) : lineNumber(lineNumber), basicContent(content) {
	this->type = CDULineType::BASIC;
}

void CDULine::setContent(std::string content) {
	this->basicContent = content;
}

void CDULine::setContent(std::vector<std::vector<std::string>> content, bool settable) {
	this->reset();
	for(int i = 0; i < content.size(); i++) {
		for(int j = 0; j < content.at(i)[0].length(); j++) {
			const std::string character = content.at(i)[0].substr(j, 1);
			this->complexContent.push_back(character);
			if(content.at(i)[1].find("cred") != std::string::npos) {
				this->r.push_back(255);
				this->g.push_back(0);
				this->b.push_back(0);
			} else {
				this->r.push_back(255);
				this->g.push_back(255);
				this->b.push_back(255);
			}

			if(settable) {
				this->settable.push_back(true);
			} else {
				if (content.at(i)[1].find("settable") != std::string::npos) {
					this->settable.push_back(true);
				} else {
					this->settable.push_back(false);
				}
			}
		}
	}
	this->reverseContent();
};

void CDULine::reverseContent() {
	std::reverse(this->complexContent.begin(), this->complexContent.end());
	std::reverse(this->r.begin(), this->r.end());
	std::reverse(this->g.begin(), this->g.end());
	std::reverse(this->b.begin(), this->b.end());
	std::reverse(this->settable.begin(), this->settable.end());
}

void CDULine::reset() {
	this->complexContent.clear();
	this->r.clear();
	this->g.clear();
	this->b.clear();
	this->settable.clear();
}

double CDULine::getOffset() {
	return CDULine::baseYOffset + CDULine::yOffsetFactor * static_cast<int>(this->lineNumber);
}

CDULineType CDULine::getLineType() const {
	return this->type;
}

std::string CDULine::getBasicContent() {
	return this->basicContent;
}

std::vector<std::string> CDULine::getComplexContent() {
	return this->complexContent;
}
