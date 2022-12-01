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


#include "TuningControlPanelXPDRPage.h"
#include "SimConnectData.h"
#include "fmt/core.h"
#include "Tools/Tools.h"

TuningControlPanelXPDRPage::TuningControlPanelXPDRPage(TuningControlPanelScratchpad* scratchpad) {
	this->scratchpad = scratchpad;
	this->scratchpad->buffer.clear();
}

void TuningControlPanelXPDRPage::render(NVGcontext* context,
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
		renderScratchpad(context);
	}
	nvgEndFrame(context);
}

void TuningControlPanelXPDRPage::handleEvent(TuningControlPanelControlPageEventsID eventId) {
	switch(eventId) {
		case tcp_page_event_l1:
			this->onL1Pressed();
			break;
		case tcp_page_event_l2:
			this->onL2Pressed();
			break;
		case tcp_page_event_l3:
			this->onL3Pressed();
			break;
		case tcp_page_event_l4:
			this->onL4Pressed();
			break;
		case tcp_page_event_r1:
			this->onR1Pressed();
			break;
		case tcp_page_event_r2:
			this->onR2Pressed();
			break;
		case tcp_page_event_r3:
			this->onR3Pressed();
			break;
		case tcp_page_event_r4:
			this->onR4Pressed();
			break;
		case tcp_page_event_prev:
			break;
		case tcp_page_event_next:
			break;
		case tcp_page_event_off:
			break;
		case tcp_page_event_stbyup:
			break;
		case tcp_page_event_stbydown:
			break;
		case tcp_page_event_swap:
			break;
		default: ;
	}

}

void TuningControlPanelXPDRPage::renderTitle(NVGcontext* context) {
	const std::string title = "TRANSPONDER";

	nvgTextAlign(context, NVG_ALIGN_CENTER | NVG_ALIGN_BASELINE);
	nvgFontSize(context, 25.0f);
	nvgText(context, 170.0f, 28.0f, title.c_str(), nullptr);
}


void TuningControlPanelXPDRPage::renderLines(NVGcontext* context) {


	const std::string transponderCode = fmt::format(" {:04}", SimConnectData::transponder.code);

	nvgTextAlign(context, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
	nvgFillColor(context, nvgRGBA(255, 255, 255, 255));
	nvgText(context, 5.0f, 65.0f, transponderCode.c_str(), nullptr);

	nvgText(context, 5.0f, 118.0f, "<IDENT", nullptr);

	this->renderLeftColoredLines(context, 215.0f);
	this->renderRightLines(context, "ABOVE", 65.0f);
	NVGcolor greenColor = nvgRGBA(29, 170, 5, 255);
	this->renderRightLines(context, "NORM", 118.0f, &greenColor);
	this->renderRightLines(context, "BELOW", 168.0f);
	this->renderRightColoredLines(context, 215.0f);

	/*
	 * TITLES
	 */

	constexpr float offsets[4]{0, 53, 103, 150};

	nvgTextAlign(context, NVG_ALIGN_LEFT | NVG_ALIGN_BASELINE);
	nvgFontSize(context, 17.0f);

	nvgText(context, 20.0f, 50.0f + offsets[0], "XPDR CODE", nullptr);
	nvgText(context, 20.0f, 50.0f + offsets[3], "XPDR SYS", nullptr);

	nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_BASELINE);
	nvgText(context, 320.0f, 50.0f + offsets[0], "CAPT TCAS", nullptr);
	nvgText(context, 320.0f, 50.0f + offsets[3], "CAT TCAS ALT", nullptr);

	this->resetOnPressEvents();

	this->onL1Pressed = [this](void) {
		Tools::Transponder::setCode(this->scratchpad->buffer);
		this->scratchpad->buffer.clear();
	};

	this->onL2Pressed = [](void) {
		Tools::Transponder::ident();
	};
}

void TuningControlPanelXPDRPage::renderRightColoredLines(NVGcontext* context, float offset) {
	nvgFontSize(context, 25.0f);
	nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);

	float boundsSegment2[4];
	float boundsSegment3[4];
	float boundsSegment4[4];

	std::string segment1 = "ABS";
	std::string segment2 = "←→";
	std::string segment3 = "REL";
	std::string segment4 = ">";


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

void TuningControlPanelXPDRPage::renderRightLines(NVGcontext* context, std::string text, float offset, FsColor* color) {
	const std::string delimiter = ">";

	if(color == nullptr) {
		const std::string concatedString = text + delimiter;
		nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgFillColor(context, nvgRGBA(255, 255, 255, 255));
		nvgText(context, 335.0f, offset, concatedString.c_str(), nullptr);
		return;
	}

	nvgFontSize(context, 25.0f);
	nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);

	float boundsDelimiter[4];

	const std::string segment1 = text;


	nvgText(context, 335.0f, offset, delimiter.c_str(), nullptr);
	nvgTextBounds(context, 335.0f, offset, delimiter.c_str(), nullptr, boundsDelimiter);
	nvgFillColor(context, (*color));
	nvgText(context, boundsDelimiter[0], offset, segment1.c_str(), nullptr);
	nvgFillColor(context, nvgRGBA(255, 255, 255, 255));
}

void TuningControlPanelXPDRPage::renderLeftColoredLines(NVGcontext* context, float offset) {
	nvgFontSize(context, 25.0f);
	nvgTextAlign(context, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);

	float boundsSegment1[4];
	float boundsSegment2[4];
	float boundsSegment3[4];

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
