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

#include "Tools.h"

CDULine::CDULine(NVGcontext*& context,
                 CDULineNumber lineNumber,
                 std::vector<std::vector<std::string>> content
) : context(context),
    lineNumber(lineNumber) {
	this->setContent(content);
	this->lineRenderingType = CDULineRenderingType::COMPLEX;
}

CDULine::CDULine(NVGcontext*& context, CDULineNumber lineNumber, std::string content) : context(context),
	lineNumber(lineNumber),
	basicContent(content) {
	this->lineRenderingType = CDULineRenderingType::BASIC;
}

void CDULine::setContent(std::string content) {
	this->basicContent = content;
}

void CDULine::draw() {
	if(this->lineRenderingType == CDULineRenderingType::COMPLEX) {
		this->drawComplexLine();
	} else {
		this->drawBasicLine();
	}
}

void CDULine::setContent(std::vector<std::vector<std::string>> content, bool settable) {
	this->reset();
	for(int i = 0; i < content.size(); i++) {
		for(int j = 0; j < content.at(i)[0].length(); j++) {
			const std::string character = content.at(i)[0].substr(j, 1);
			this->basicContent.append(character);
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
				if(content.at(i)[1].find("settable") != std::string::npos) {
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
	this->basicContent.clear();
	this->complexContent.clear();
	this->r.clear();
	this->g.clear();
	this->b.clear();
	this->settable.clear();
}

float CDULine::getVerticalOffset() {
	return CDULine::baseVerticalOffset + CDULine::yOffsetFactor * static_cast<float>(this->lineNumber) + (
		this->lineType == CDULineType::TITLE ? CDULine::titleVerticalOffset : 0);
}

void CDULine::calculateHorizontalOffset() {

}

CDULineRenderingType CDULine::getLineType() const {
	return this->lineRenderingType;
}

std::string CDULine::getBasicContent() {
	return this->basicContent;
}

std::vector<std::string> CDULine::getComplexContent() {
	return this->complexContent;
}

void CDULine::drawBasicLine() {
	nvgSave(this->context);
	{
		nvgFillColor(this->context, Tools::Colors::white);
		nvgFontSize(this->context, this->fontSize);
		nvgTextAlign(this->context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgTranslate(this->context, this->horizontalOffset, this->getVerticalOffset());
		{
			nvgBeginPath(this->context);
			{
				nvgText(this->context, 0, 0, this->getBasicContent().c_str(), nullptr);
			}
			nvgClosePath(this->context);
			nvgFill(this->context);
		}
		nvgResetTransform(this->context);
	}
	nvgRestore(this->context);
}

void CDULine::drawComplexLine() {
	std::vector<std::string> complexContent = this->complexContent;
	const auto complexContentSize = complexContent.size();
	std::vector<bool> settable = this->settable;
	const auto settableSize = settable.size();

	nvgSave(this->context);
	{
		nvgFillColor(this->context, Tools::Colors::white);
		nvgFontSize(this->context, this->fontSize);
		nvgTextAlign(this->context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);

		nvgTranslate(this->context, this->horizontalOffset, this->getVerticalOffset());
		{
			float lastBounds[4] = {0, 0, 0, 0};
			float nextBounds[4];
			float preSettableBounds[4];
			float endSettableBounds[4];

			int firstSettable = -1;
			int lastSettable = -1;
			for(int i = 0; i < settableSize; i++) {
				if(settable.at(i) && firstSettable == -1) {
					firstSettable = i;
					lastSettable = i;
				} else if(settable.at(i) && firstSettable != -1) {
					lastSettable = i;
				}
			}

			if(firstSettable != -1) {
				std::string preSettableText;
				std::string endSettableText;
				for(int i = 0; i < firstSettable; i++) {
					preSettableText += complexContent.at(i);
				}

				for(int i = firstSettable; i <= lastSettable; i++) {
					endSettableText += complexContent.at(i);
				}

				nvgTextBounds(this->context, lastBounds[2], 0, preSettableText.c_str(), nullptr, preSettableBounds);
				nvgTextBounds(this->context, preSettableBounds[2], 0, endSettableText.c_str(), nullptr,
				              endSettableBounds);

				nvgBeginPath(this->context);
				{
					for(int i = 0; i < complexContentSize; i++) {
						const std::string character = complexContent.at(i);
						nvgTextBounds(this->context, lastBounds[2], 0, character.c_str(), nullptr, nextBounds);
						nvgFillColor(this->context, nvgRGB(255, 100, 100));
						nvgRect(this->context, preSettableBounds[0], -14,
						        -(endSettableBounds[2] - endSettableBounds[0]), 28);
					}
				}
				nvgClosePath(this->context);
				nvgFill(this->context);
			}

			nvgBeginPath(this->context);
			{
				for(int i = 0; i < complexContentSize; i++) {
					const std::string character = complexContent.at(i);
					nvgTextBounds(this->context, lastBounds[0], 0, character.c_str(), nullptr, nextBounds);
					const int r = this->r.at(i);
					const int g = this->g.at(i);
					const int b = this->b.at(i);
					nvgFillColor(this->context, nvgRGB(r, g, b));
					nvgText(this->context, lastBounds[0], 0, character.c_str(), nullptr);
					lastBounds[0] = nextBounds[0];
					lastBounds[1] = nextBounds[1];
					lastBounds[2] = nextBounds[2];
					lastBounds[3] = nextBounds[3];
				}
			}
			nvgClosePath(this->context);
			nvgFill(this->context);
		}
		nvgResetTransform(this->context);
	}
	nvgRestore(this->context);
}
