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


#include "CDUPageRenderer.h"

#include "CDULine.h"
#include "CDUCenterLine.h"
#include "CDUIdentPage.h"
#include "CDULeftLine.h"
#include "CDURightLine.h"
#include "fmt/core.h"

void CDUPageRenderer::render() {
	this->drawBackground();
	this->drawLines();
}

void CDUPageRenderer::drawBackground() {
	nvgFillColor(this->context, nvgRGB(0, 0, 0));
	nvgBeginPath(this->context);
	{
		nvgRect(this->context, 0, 0, 498, 398);
	}
	nvgClosePath(this->context);
	nvgFill(this->context);
}

void CDUPageRenderer::drawLines() {
	CDUIdentPage page = CDUIdentPage();
	
	for(int i = 0; i < page.getLeftLines().size(); i++) {
		this->drawLine(page.getLeftLines().at(i));
	}
}

void CDUPageRenderer::drawLine(CDULeftLine line) {
	if(line.getLineType() == CDULineType::COMPLEX) {
		this->drawComplexLine(line);
	} else {
		this->drawBasicLine(line);
	}
}

void CDUPageRenderer::drawLine(CDURightLine line) {
	if(line.getLineType() == CDULineType::COMPLEX) {
		this->drawComplexLine(line);
	} else {
		this->drawBasicLine(line);
	}
}

void CDUPageRenderer::drawLine(CDUCenterLine line) {
	if(line.getLineType() == CDULineType::COMPLEX) {
		this->drawComplexLine(line);
	} else {
		this->drawBasicLine(line);
	}
}

void CDUPageRenderer::drawBasicLine(CDULeftLine line) {

	nvgSave(this->context);
	{
		nvgTranslate(this->context, 0, line.getOffset());
		{
			nvgFillColor(this->context, nvgRGB(255, 255, 255));
			nvgFontSize(this->context, 20.0f);
			nvgTextAlign(this->context, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);

			nvgBeginPath(this->context);
			{
				nvgText(this->context, 20, 0, line.getBasicContent().c_str(), nullptr);
			}
			nvgClosePath(this->context);
			nvgFill(this->context);
		}
		nvgResetTransform(this->context);
	}
	nvgRestore(this->context);
}

void CDUPageRenderer::drawBasicLine(CDUCenterLine line) {
	nvgSave(this->context);
	{
		nvgTranslate(this->context, 249, line.getOffset());
		{
			nvgFillColor(this->context, nvgRGB(255, 255, 255));
			nvgFontSize(this->context, 20.0f);
			nvgTextAlign(this->context, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);

			nvgBeginPath(this->context);
			{
				nvgText(this->context, 0, 0, line.getBasicContent().c_str(), nullptr);
			}
			nvgClosePath(this->context);
			nvgFill(this->context);
		}
		nvgResetTransform(this->context);
	}
	nvgRestore(this->context);
}

void CDUPageRenderer::drawBasicLine(CDURightLine line) {
	nvgSave(this->context);
	{
		nvgTranslate(this->context, 498, line.getOffset());
		{
			nvgFillColor(this->context, nvgRGB(255, 255, 255));
			nvgFontSize(this->context, 20.0f);
			nvgTextAlign(this->context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);

			nvgBeginPath(this->context);
			{
				nvgText(this->context, -20, 0, line.getBasicContent().c_str(), nullptr);
			}
			nvgClosePath(this->context);
			nvgFill(this->context);
		}
		nvgResetTransform(this->context);
	}
	nvgRestore(this->context);
}

void CDUPageRenderer::drawComplexLine(CDULeftLine line) {
	nvgSave(this->context);
	{
		nvgFillColor(this->context, nvgRGB(255, 255, 255));
		nvgFontSize(this->context, 20.0f);
		nvgTextAlign(this->context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);

		std::string translateXText = "";
		float translateXBounds[4];
		for (int i = 0; i < line.getComplexContent().size(); i++) {
			translateXText.append(line.getComplexContent().at(i));
		}

		nvgTextBounds(this->context, 0, 0, translateXText.c_str(), nullptr, translateXBounds);

		const float translateX = 20 + (translateXBounds[2] - translateXBounds[0]);

		nvgTranslate(this->context, translateX, line.getOffset());
		{
			nvgFillColor(this->context, nvgRGB(255, 255, 255));
			nvgFontSize(this->context, 20.0f);
			nvgTextAlign(this->context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);

			float lastBounds[4] = { 0, 0, 0, 0 };
			float nextBounds[4];
			float preSettableBounds[4];
			float endSettableBounds[4];

			int firstSettable = -1;
			int lastSettable = -1;
			for (int i = 0; i < line.settable.size(); i++) {
				if (line.settable.at(i) && firstSettable == -1) {
					firstSettable = i;
					lastSettable = i;
				}
				else if (line.settable.at(i) && firstSettable != -1) {
					lastSettable = i;
				}
			}

			if (firstSettable != -1) {
				std::string preSettableText;
				std::string endSettableText;
				for (int i = 0; i < firstSettable; i++) {
					preSettableText += line.getComplexContent().at(i);
				}

				for (int i = firstSettable; i <= lastSettable; i++) {
					endSettableText += line.getComplexContent().at(i);
				}

				nvgTextBounds(this->context, lastBounds[2], 0, preSettableText.c_str(), nullptr, preSettableBounds);
				nvgTextBounds(this->context, preSettableBounds[2], 0, endSettableText.c_str(), nullptr,
					endSettableBounds);

				nvgBeginPath(this->context);
				{
					for (int i = 0; i < line.getComplexContent().size(); i++) {
						const std::string character = line.getComplexContent().at(i);
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
				for (int i = 0; i < line.getComplexContent().size(); i++) {
					const std::string character = line.getComplexContent().at(i);
					nvgTextBounds(this->context, lastBounds[0], 0, character.c_str(), nullptr, nextBounds);
					const int r = line.r.at(i);
					const int g = line.g.at(i);
					const int b = line.b.at(i);
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

void CDUPageRenderer::drawComplexLine(CDUCenterLine line) {
	nvgSave(this->context);
	{
		nvgFillColor(this->context, nvgRGB(255, 255, 255));
		nvgFontSize(this->context, 20.0f);
		nvgTextAlign(this->context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);

		std::string translateXText = "";
		float translateXBounds[4];
		for (int i = 0; i < line.getComplexContent().size(); i++) {
			translateXText.append(line.getComplexContent().at(i));
		}

		nvgTextBounds(this->context, 0, 0, translateXText.c_str(), nullptr, translateXBounds);
		
		const float translateX = 249 + ((translateXBounds[2] - translateXBounds[0]) / 2);
		
		nvgTranslate(this->context, translateX, line.getOffset());
		{
			nvgFillColor(this->context, nvgRGB(255, 255, 255));
			nvgFontSize(this->context, 20.0f);
			nvgTextAlign(this->context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);

			float lastBounds[4] = {0, 0, 0, 0};
			float nextBounds[4];
			float preSettableBounds[4];
			float endSettableBounds[4];

			int firstSettable = -1;
			int lastSettable = -1;
			for(int i = 0; i < line.settable.size(); i++) {
				if(line.settable.at(i) && firstSettable == -1) {
					firstSettable = i;
					lastSettable = i;
				} else if(line.settable.at(i) && firstSettable != -1) {
					lastSettable = i;
				}
			}

			if(firstSettable != -1) {
				std::string preSettableText;
				std::string endSettableText;
				for(int i = 0; i < firstSettable; i++) {
					preSettableText += line.getComplexContent().at(i);
				}

				for(int i = firstSettable; i <= lastSettable; i++) {
					endSettableText += line.getComplexContent().at(i);
				}

				nvgTextBounds(this->context, lastBounds[2], 0, preSettableText.c_str(), nullptr, preSettableBounds);
				nvgTextBounds(this->context, preSettableBounds[2], 0, endSettableText.c_str(), nullptr,
				              endSettableBounds);

				nvgBeginPath(this->context);
				{
					for(int i = 0; i < line.getComplexContent().size(); i++) {
						const std::string character = line.getComplexContent().at(i);
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
				for(int i = 0; i < line.getComplexContent().size(); i++) {
					const std::string character = line.getComplexContent().at(i);
					nvgTextBounds(this->context, lastBounds[0], 0, character.c_str(), nullptr, nextBounds);
					const int r = line.r.at(i);
					const int g = line.g.at(i);
					const int b = line.b.at(i);
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

void CDUPageRenderer::drawComplexLine(CDURightLine line) {
	nvgSave(this->context);
	{
		nvgTranslate(this->context, 498, line.getOffset());
		{
			nvgFillColor(this->context, nvgRGB(255, 255, 255));
			nvgFontSize(this->context, 20.0f);
			nvgTextAlign(this->context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);

			float lastBounds[4] = {-20, 0, -20, 0};
			float nextBounds[4];
			float preSettableBounds[4];
			float endSettableBounds[4];

			int firstSettable = -1;
			int lastSettable = -1;
			for(int i = 0; i < line.settable.size(); i++) {
				if(line.settable.at(i) && firstSettable == -1) {
					firstSettable = i;
					lastSettable = i;
				} else if(line.settable.at(i) && firstSettable != -1) {
					lastSettable = i;
				}
			}

			if(firstSettable != -1) {
				std::string preSettableText;
				std::string endSettableText;
				for(int i = 0; i < firstSettable; i++) {
					preSettableText += line.getComplexContent().at(i);
				}

				for(int i = firstSettable; i <= lastSettable; i++) {
					endSettableText += line.getComplexContent().at(i);
				}

				nvgTextBounds(this->context, lastBounds[2], 0, preSettableText.c_str(), nullptr, preSettableBounds);
				nvgTextBounds(this->context, preSettableBounds[2], 0, endSettableText.c_str(), nullptr,
				              endSettableBounds);

				nvgBeginPath(this->context);
				{
					for(int i = 0; i < line.getComplexContent().size(); i++) {
						const std::string character = line.getComplexContent().at(i);
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
				for(int i = 0; i < line.getComplexContent().size(); i++) {
					const std::string character = line.getComplexContent().at(i);
					nvgTextBounds(this->context, lastBounds[0], 0, character.c_str(), nullptr, nextBounds);
					const int r = line.r.at(i);
					const int g = line.g.at(i);
					const int b = line.b.at(i);
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
