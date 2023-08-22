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


#pragma once
#include <functional>

#include "TuningControlPanelScratpad.h"
#include "MSFS/Render/nanovg.h"

enum TuningControlPanelControlSwitchID {
	doNothing = 0,
	vhf = 1,
	hf,
	sat,
	cab,
	gpws,
	wxr,
	xpdr,
	l1,
	l2,
	l3,
	l4,
	r1,
	r2,
	r3,
	r4,
	num1,
	num2,
	num3,
	num4,
	num5,
	num6,
	num7,
	num8,
	num9,
	num0,
	clr,
	star,
	prev,
	next,
	nav,
	menu,
	off,
	stbyup,
	stbydown,
	swap
};

enum TuningControlPanelControlPageEventsID {
	tcp_page_event_l1,
	tcp_page_event_l2,
	tcp_page_event_l3,
	tcp_page_event_l4,
	tcp_page_event_r1,
	tcp_page_event_r2,
	tcp_page_event_r3,
	tcp_page_event_r4,
	tcp_page_event_prev,
	tcp_page_event_next,
	tcp_page_event_off,
	tcp_page_event_stbyup,
	tcp_page_event_stbydown,
	tcp_page_event_swap
};

class TuningControlPanelBasePage {
	public:
		virtual ~TuningControlPanelBasePage() = default;

		virtual void loadData() {
		};

		virtual void render(NVGcontext* context, float windowWidth, float windowHeight, float devicePixelRatio);

		virtual void handleEvent(TuningControlPanelControlPageEventsID eventId) {
		};

		virtual void renderScratchpad(NVGcontext* context) {
			nvgFontSize(context, 25.0f);
			nvgFontFace(context, "heavy-fmc");
			nvgFillColor(context, nvgRGBA(255, 255, 255, 255));
			nvgTextAlign(context, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
			nvgText(context, (*this).scratchpad->position[0], (*this).scratchpad->position[1],
			        (*this).scratchpad->buffer.c_str(), nullptr);
		}

		TuningControlPanelControlSwitchID pageID = vhf;
		TuningControlPanelScratchpad* scratchpad;
		int numberOfPages;
		int currentPage = 1;
		std::function<void()> onL1Pressed = [](void) {
		};
		std::function<void()> onL2Pressed = [](void) {
		};
		std::function<void()> onL3Pressed = [](void) {
		};
		std::function<void()> onL4Pressed = [](void) {
		};
		std::function<void()> onR1Pressed = [](void) {
		};
		std::function<void()> onR2Pressed = [](void) {
		};
		std::function<void()> onR3Pressed = [](void) {
		};
		std::function<void()> onR4Pressed = [](void) {
		};

		void resetOnPressEvents() {
			this->onL1Pressed = [](void) {
			};
			this->onL2Pressed = [](void) {
			};
			this->onL3Pressed = [](void) {
			};
			this->onL4Pressed = [](void) {
			};
			this->onR1Pressed = [](void) {
			};
			this->onR2Pressed = [](void) {
			};
			this->onR3Pressed = [](void) {
			};
			this->onR4Pressed = [](void) {
			};
		}
};
