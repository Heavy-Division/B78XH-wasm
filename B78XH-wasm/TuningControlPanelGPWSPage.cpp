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


#include "TuningControlPanelGPWSPage.h"

void TuningControlPanelGPWSPage::render(NVGcontext* context,
                                        float windowWidth,
                                        float windowHeight,
                                        float devicePixelRatio) {
	nvgBeginFrame(context, windowWidth, windowHeight, devicePixelRatio);
	{
		nvgFillColor(context, nvgRGB(0, 0, 0));
		nvgBeginPath(context);
		nvgRect(context, 0, 0, windowWidth, windowHeight);
		nvgFill(context);

		nvgFontFace(context, "heavy-fmc");
		nvgFillColor(context, nvgRGBA(255, 255, 255, 255));

		renderTitle(context);
		renderLines(context);
	}
	nvgEndFrame(context);
}

void TuningControlPanelGPWSPage::renderTitle(NVGcontext* context) {
	const std::string title = "GPWS";

	nvgTextAlign(context, NVG_ALIGN_CENTER | NVG_ALIGN_BASELINE);
	nvgFontSize(context, 25.0f);
	nvgText(context, 170.0f, 28.0f, title.c_str(), nullptr);
}

void TuningControlPanelGPWSPage::renderRightColoredLines(NVGcontext* context, float offset) {
	nvgFontSize(context, 25.0f);
	nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);

	float boundsSegment2[4];
	float boundsSegment3[4];
	float boundsSegment4[4];

	const std::string segment1 = "OVRD";
	const std::string segment2 = "←→";
	const std::string segment3 = "NORM";
	const std::string segment4 = ">";


	nvgText(context, 335.0f, offset, segment4.c_str(), nullptr);
	nvgTextBounds(context, 335.0f, offset, segment4.c_str(), nullptr, boundsSegment4);
	nvgFillColor(context, nvgRGBA(29, 170, 5, 255));
	nvgText(context, boundsSegment4[0], offset, segment3.c_str(), nullptr);
	nvgTextBounds(context, boundsSegment4[0], offset, segment3.c_str(), nullptr, boundsSegment3);
	nvgFillColor(context, nvgRGBA(255, 255, 255, 255));
	nvgFontSize(context, 17.0f);
	nvgText(context, boundsSegment3[0], offset - 2, segment2.c_str(), nullptr);
	nvgTextBounds(context, boundsSegment3[0], 65.0f, segment2.c_str(), nullptr, boundsSegment2);
	nvgFontSize(context, 25.0f);
	nvgText(context, boundsSegment2[0], offset, segment1.c_str(), nullptr);
}

void TuningControlPanelGPWSPage::renderLeftColoredLines(NVGcontext* context, float offset) {
	nvgFontSize(context, 25.0f);
	nvgTextAlign(context, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);

	float boundsSegment1[4];
	float boundsSegment2[4];
	float boundsSegment3[4];
	float boundsSegment4[4];

	const std::string segment1 = "<";
	const std::string segment2 = "L";
	const std::string segment3 = "←→";
	const std::string segment4 = "R";


	nvgText(context, 5.0f, offset, segment1.c_str(), nullptr);
	nvgTextBounds(context, 5.0f, offset, segment1.c_str(), nullptr, boundsSegment1);
	nvgFillColor(context, nvgRGBA(29, 170, 5, 255));
	nvgText(context, boundsSegment1[2], offset, segment2.c_str(), nullptr);
	nvgTextBounds(context, boundsSegment1[2], offset, segment2.c_str(), nullptr, boundsSegment2);
	nvgFillColor(context, nvgRGBA(255, 255, 255, 255));
	nvgFontSize(context, 17.0f);
	nvgText(context, boundsSegment2[2], offset - 2, segment3.c_str(), nullptr);
	nvgTextBounds(context, boundsSegment2[2], 65.0f, segment3.c_str(), nullptr, boundsSegment3);
	nvgFontSize(context, 25.0f);
	nvgText(context, boundsSegment3[2], offset, segment4.c_str(), nullptr);
}

void TuningControlPanelGPWSPage::renderLines(NVGcontext* context) {


	constexpr float offsets[4]{0, 53, 103, 150};

	nvgTextAlign(context, NVG_ALIGN_LEFT | NVG_ALIGN_BASELINE);
	nvgFontSize(context, 17.0f);

	nvgText(context, 20.0f, 50.0f + offsets[3], "GND PROX SYS", nullptr);

	nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_BASELINE);
	nvgText(context, 320.0f, 50.0f + offsets[0], "FLAP OVRD", nullptr);
	nvgText(context, 320.0f, 50.0f + offsets[1], "GEAR OVRD", nullptr);
	nvgText(context, 320.0f, 50.0f + offsets[2], "TERR OVRD", nullptr);

	this->renderLeftColoredLines(context, 215.0f);
	this->renderRightColoredLines(context, 65.0f);
	this->renderRightColoredLines(context, 118.0f);
	this->renderRightColoredLines(context, 168.0f);

	this->resetOnPressEvents();
}
